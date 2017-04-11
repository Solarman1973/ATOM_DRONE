/*
    This sketch shows the WiFi event usage

*/

#include "Arduino.h"
#include "data.h"
#include <Esp.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <ESP8266WebServer.h>

#include "SerialCommand.h"
#include <Bounce2.h>

SerialCommand SCmd(&Serial);
WiFiUDP udp;
#define LOCAL_PORT (10000)
int remote_port = 20000;
IPAddress remote_ip(192, 168, 1, 3);

ESP8266WebServer server(80);

const char* www_username = "admin";
const char* www_password = "esp8266";

const char* _ssid     = "RICK";
const char* _password = "88888888";

const char* ssid     = "__ATOM__";
const char* password = "88888888";



int system_mode = -1;

#define BUTTON_PIN 0
Bounce debouncer = Bounce();

void sendmsg(char* msg, int size)
{
  udp.beginPacket(remote_ip, (uint16_t) remote_port);
  udp.write(msg, size);
  udp.endPacket();
}

void startUDPServer()
{
  Serial.println("ready");
  udp.begin(LOCAL_PORT);
  //sendmsg("I AM ON", 8);
  Serial.println(system_mode);
  Serial.println("OK");
}

void WiFiEvent(WiFiEvent_t event) {
  //Serial.printf("[WiFi-event] event: %d\n", event);

  switch (event) {
    case WIFI_EVENT_STAMODE_GOT_IP:
      startUDPServer();

      server.on("/", []() {
        if (!server.authenticate(www_username, www_password))
          return server.requestAuthentication();
        server.send(200, "text/plain", "Login OK");
      });
      server.begin();

      Serial.print("Open http://");
      Serial.print(WiFi.localIP());
      Serial.println("/ in your browser to see it working");

      //udp.beginPacket(addr, port)
      //Serial.println("IP address: ");
      //Serial.println(WiFi.localIP());
      break;
    case WIFI_EVENT_STAMODE_DISCONNECTED:
      Serial.println("WiFi lost connection");
      udp.stop();
      break;
  }
}

void setup() {
  Serial.begin(115200);
  //Serial.println("START DIRECTLY WITH TRANSPARENT MODE");
  //Serial.println("ISSUE with serial");
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  debouncer.attach(BUTTON_PIN);
  debouncer.interval(200);
  SCmd.addCommand("AT", check);
  SCmd.addCommand("AT+RST", resetESP8266);
  SCmd.addCommand("AT+RSTT", restartESP8266);
  //SCmd.addCommand("AT+MODE", operationMode);
  SCmd.addCommand("AT+START", startWiFi);
  SCmd.addCommand("AT+CIFSR", printIP);
  //SCmd.addCommand("AT+SEND", sendData);
  SCmd.addCommand("AT+SRIPP", setRemoteIPPort);

  SCmd.addDefaultHandler(unrecognized);

  // WiFi.onEvent(WiFiEvent);

  startWiFi();

}

int button_state = 0;
void loop() {
  Data data;
  data.data.header.header1 = 0x02;
  data.data.header.header2 = 0xFF;
  data.data.header.header3 = 0xFE;

  //delay(100);
  //  SCmd.readSerial();
  server.handleClient();
  boolean changed = debouncer.update();
  //int value = debouncer.read();
  //
  if (changed) // keep it low for cmd mode
  {
    //Serial.println(debouncer.read());
    button_state = !debouncer.read();
  }

  if (0 == button_state)
  {
    data.data.header.header1 = 0x02;
    data.data.header.header2 = 0xFF;
    data.data.header.header3 = 0xFE;
    data.data.header.type1 = DATA_TYPE1_SERIAL;
    data.data.header.type2 = 0;

    int datasize = udp.parsePacket(); //udp.available();//
    //char buff[64] = {0};
    if (datasize)
    {
      //datasize = udp.parsePacket();
      data.data.header.len = datasize; // this datasize is not valid

      udp.read(data.uc_buffer, datasize > MAX_PAYLOAD_SIZE ? MAX_PAYLOAD_SIZE : datasize);
      //server.send(data.uc_buffer);
      //server.send(200, "text/plain", data.c_buffer);
      //EthernetClient client = server.available();
      //Serial.print("+IPD,");
      //Serial.print("0,");
      //Serial.print(datasize);
      //Serial.print(":");

      // Validate Protocol

      if (DATA_validateHeader(&data, DATA_TYPE1_SERIAL, DATA_TYPE2_SERIAL_0))
      {
        Serial.write(data.data.c_payload, data.data.header.len);
        sendmsg("ERR: 0x0000", 11);// STR(DATA_TYPE2_ERROR_0), 11);
      }
      else
      {
        sendmsg("ERR: 0xFFFF", 11);// STR(DATA_TYPE2_ERROR), 11);
      }

    }

    datasize = Serial.available();
    if (datasize)
    {
      data.data.header.header1 = 0x02;
      data.data.header.header2 = 0xFF;
      data.data.header.header3 = 0xFE;
      data.data.header.chk = 0x00;
      data.data.header.type1 = DATA_TYPE1_SERIAL;
      data.data.header.type2 = DATA_TYPE2_SERIAL_0;
      data.data.header.res = 0x00;
      data.data.header.len = datasize ; //0xFFFF; // test
      //Serial.print("<");
      //Serial.print(datasize);
      //Serial.println(">");

      Serial.readBytes(data.data.c_payload, datasize > MAX_PAYLOAD_SIZE ? MAX_PAYLOAD_SIZE : datasize);
      //server.send(200, "text/plain", data.c_buffer);
      sendmsg(data.c_buffer, datasize + DATA_HEADER_LEN );
    }
  }
  else
  {
    SCmd.readSerial();
  }

}


// AT+SETREMOTEIPPORT IP1.IP2.IP3.IP4 PPORTT
void setRemoteIPPort()
{
  char *arg = NULL;
  arg = SCmd.next();

  if (arg != NULL)      // As long as it existed, take it
  {
    remote_ip.fromString(arg); // set IP
    Serial.print(remote_ip);
  }
  else {
    unrecognized();
    return;
  }

  Serial.print(" ");

  arg = SCmd.next();
  if (arg != NULL)      // As long as it existed, take it
  {
    remote_port = atoi(arg); // set PORT
    Serial.print(remote_port);
  }
  else {
    unrecognized();
    return;
  }

  //udp.begin(LOCAL_PORT);
  //sendmsg("I AM ON", 8);

  Serial.println();
  Serial.println("OK");
}
//AT+SEND 2 HI
//AT+SEND HI
void sendData()
{
  char *arg = NULL;
  //  arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    Serial.print("OK");
    sendmsg(arg, strlen(arg)); // coculd be danngerous
    //Serial.println(arg);
  }
  else {
    unrecognized();
  }

}

void printIP()
{
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.softAPIP());
  Serial.println("OK");
}

void startWiFi()
{

  // delete old config
  WiFi.disconnect(false);

  WiFi.mode(WIFI_AP);
  IPAddress ip(192, 168, 4, 4);
  IPAddress gateway(192, 168, 4, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(ssid, password); //Access point is open - See more at: http://www.esp8266.com/viewtopic.php?f=29&t=12124#sthash.HXUoeE1P.dpuf


  delay(200);
  //WiFi.onEvent(WiFiEvent);
  //WiFi.mode(WIFI_AP);
  //WiFi.softAP(ssid, password);
  //WiFi.begin(ssid, password);
  Serial.println("+STARTing...");
  startUDPServer();
}

void operationMode()
{
  char *arg;
  //  arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    Serial.print("+MODE");
    system_mode = atoi(arg); // check 0 or 1
    Serial.println(arg);
  }
  else {
    unrecognized();
  }
}

void restartESP8266()
{
  Serial.println("OK");
  delay(1000);
  ESP.restart();
}
void resetESP8266()
{
  Serial.println("OK");
  delay(1000);
  ESP.reset();
  //Serial.println("<Not_Implemented>");
}

void check()
{
  // wifi test
  Serial.println("OK");
}

void unrecognized()
{
  Serial.println("ERROR What?");
}
