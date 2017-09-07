#include "Arduino.h"
#include "MPU6050.h"
#include "NewPingESP8266.h"
#include "Servo.h"

#include <Math3D.h>

#ifdef ESP8266
extern "C" {
  #include "user_interface.h"
}
#endif



#include "data.h"
#include "config.h"



#define ENABLE_WIFI
#define ENABLE_STEER
#define ENABLE_MPU




void setup()
{
  delay(3000);
  Serial.begin(115200);
  Serial.printf("Version %s\n",_VER_);
  Serial.printf("Build at %s %s\n", __DATE__, __TIME__);
  Serial.printf("size of mpudata %d\n", SIZE_OF_MPU_DATA);
  Serial.printf("size of all data %d\n", SIZE_OF_ALL_DATA);

  // ENABLE_MPU
  //

  #if defined(ENABLE_MPU)

  mpu_setup();

  #endif // ENABLE_MPU

  // ENABLE_WIFI
  //

  #if defined(ENABLE_WIFI)

  wifi_setup();
  setup_OTA();

  #endif //ENABLE_WIFI



  // ENABLE_STEER
  //

  #if defined(ENABLE_STEER)

  steer_setup();

  #endif // ENABLE_STEER
}

uint32_t lastWIFITime = 0, lastLoopTime =0 , lastPrintTime = 0;

sGENERICSETPOINTS_t msetpts;

void loop()
{

  boolean data_received = false;
  if(true == loop_OTA())
    return; // skip all activity // or try how this works with this

  if(system_get_time()-lastLoopTime >=(LOOP_TIME))
  {
    lastLoopTime = system_get_time();
    // ENABLE_MPU
    //

    #if defined(ENABLE_MPU)

    sMPUDATA_t mpudata ;
    sSmoothData_t sdata;
    static debug_data debug_data;
    sMPUDATA_t rawmpudata;

    #if !defined(QUATERNION_BASED_CALC)
    mpu_loop(&rawmpudata);
    mpudata = rawmpudata;
    // #else
    // sMPUDATA_f_t mpudata;
    #endif // QUATERNION_BASED_CALC
    //Serial.print("RAW | "); printMPU(&mpudata);
    Vec3 YPR = mpu_calc(&mpudata);
    YPR = YPR;

    mpu_filter(&mpudata, &sdata);

    //if(system_get_time()-lastWIFITime >=(10*1000))
    {
      lastWIFITime = system_get_time();;


      debug_data.timestamp = millis();
      debug_data.yaw = mpudata.AcZ;
      debug_data.pitch = mpudata.AcY;
      debug_data.roll = mpudata.AcX;
      debug_data.pingheight = ping_loop();
      debug_data.mpuData = mpudata;
      debug_data.mpuRAW = rawmpudata;
      //debug_data.pplr =


      // ENABLE_WIFI
      //

      #if defined(ENABLE_WIFI)

      data_received = wifi_loop(&debug_data, &msetpts);
      debug_data.tune_type = msetpts.pid_tune_type;

      #endif // ENABLE_WIFI
    }
    //else
    {
      //data_received = false;
    }

    #if defined(ENABLE_STEER)

    //if(true == data_received)
    //{
    //  if( (msetpts.x != 0) && (msetpts.y != 0) )

    // Without this empty line esp is crashing ????
    Serial.print("");//check "); Serial.println(__LINE__); // Without this empty line esp is crashing ????
    steer_loop(&debug_data, &msetpts); // should be sent on next loop over wifi
    //}
    // Without this empty line esp is crashing ????
    Serial.print("");//check "); Serial.println(__LINE__) // Without this empty line esp is crashing ????;

    #endif  // ENABLE_STEER


    if(system_get_time()-lastPrintTime >=(500*1000))
    {
      //Serial.print("RAW | "); printMPU(&rawmpudata);

      lastPrintTime = system_get_time();
      //if(data_received)
      {
        //printgmpts(&msetpts);
        //printMPU(&debug_data.mpuRAW);
        //printMPU(&rawmpudata);

      }
      //else
      {
        //Serial.println("[ WARN] [.] Probable connection loss.");
      }


      //Serial.print("PRO | "); Serial.printf("png %lu cms | %d ", ping_loop(), msetpts.hat) ; //Serial.printf("dt %d uS ", (int)(dt));
      //Serial.printf("| %d %d | %d %d %d\n", msetpts.x, msetpts.y, mpudata.AcX, mpudata.AcY, mpudata.AcZ);

      Serial.printf("YPR | %d | ", system_get_time()/1000);
      Serial.print(_DEGREES(YPR.x));
      Serial.printf(" ");
      Serial.print(_DEGREES(YPR.y));
      Serial.printf(" ");
      Serial.print(_DEGREES(YPR.z));
      Serial.println(" ");

      // Serial.print("PID | S:");
      // Serial.print(debug_data.pplr.Setpoint);
      // Serial.print(" I:");
      // Serial.print(debug_data.pplr.Input);
      // Serial.print(" O:");
      // Serial.println(debug_data.pplr.Output);
    }

    // Serial.print("AcX = "); Serial.print(mpudata.AcX);
    // Serial.print(" | AcY = "); Serial.print(mpudata.AcY);
    // Serial.print(" | AcZ = "); Serial.print(mpudata.AcZ);
    // Serial.print(" | Tmp = "); Serial.print(mpudata.Tmp/340.00+36.53); //equation for temperature in degrees C from datasheet
    // Serial.print(" | GyX = "); Serial.print(mpudata.GyX);
    // Serial.print(" | GyY = "); Serial.print(mpudata.GyY);
    // Serial.print(" | GyZ = "); Serial.println(mpudata.GyZ);

    #endif // ENABLE_MPU



    //delay(250);
  }

}


// void mpu_calc(sMPURATA_t _mpudata)
// {
//   // Convert gyro values to degrees/sec
//   float FS_SEL = 131;
//   /*
//     float gyro_x = (accel_t_gyro.value.x_gyro - base_x_gyro)/FS_SEL;
//     float gyro_y = (accel_t_gyro.value.y_gyro - base_y_gyro)/FS_SEL;
//     float gyro_z = (accel_t_gyro.value.z_gyro - base_z_gyro)/FS_SEL;
//   */
//   float gyro_x = (accel_t_gyro.value.x_gyro - base_x_gyro) / FS_SEL;
//   float gyro_y = (accel_t_gyro.value.y_gyro - base_y_gyro) / FS_SEL;
//   float gyro_z = (accel_t_gyro.value.z_gyro - base_z_gyro) / FS_SEL;
//
//
//   // Get raw acceleration values
//   //float G_CONVERT = 16384;
//   float accel_x = accel_t_gyro.value.x_accel;
//   float accel_y = accel_t_gyro.value.y_accel;
//   float accel_z = accel_t_gyro.value.z_accel;
//
//   // Get angle values from accelerometer
//   float RADIANS_TO_DEGREES = 180 / 3.14159;
//   //  float accel_vector_length = sqrt(pow(accel_x,2) + pow(accel_y,2) + pow(accel_z,2));
//   float accel_angle_y = atan(-1 * accel_x / sqrt(pow(accel_y, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;
//   float accel_angle_x = atan(accel_y / sqrt(pow(accel_x, 2) + pow(accel_z, 2))) * RADIANS_TO_DEGREES;
//
//   float accel_angle_z = 0;
//
//   // Compute the (filtered) gyro angles
//   float dt = (t_now - get_last_time()) / 1000.0;
//   float gyro_angle_x = gyro_x * dt + get_last_x_angle();
//   float gyro_angle_y = gyro_y * dt + get_last_y_angle();
//   float gyro_angle_z = gyro_z * dt + get_last_z_angle();
//
//   // Compute the drifting gyro angles
//   float unfiltered_gyro_angle_x = gyro_x * dt + get_last_gyro_x_angle();
//   float unfiltered_gyro_angle_y = gyro_y * dt + get_last_gyro_y_angle();
//   float unfiltered_gyro_angle_z = gyro_z * dt + get_last_gyro_z_angle();
//
//   // Apply the complementary filter to figure out the change in angle - choice of alpha is
//   // estimated now.  Alpha depends on the sampling rate...
//   float alpha = 0.96;
//   float angle_x = alpha * gyro_angle_x + (1.0 - alpha) * accel_angle_x;
//   float angle_y = alpha * gyro_angle_y + (1.0 - alpha) * accel_angle_y;
//   float angle_z = gyro_angle_z;  //Accelerometer doesn't give z-angle
//
//   // Update the saved data with the latest values
//   set_last_read_angle_data(t_now, angle_x, angle_y, angle_z, unfiltered_gyro_angle_x, unfiltered_gyro_angle_y, unfiltered_gyro_angle_z);
//
//
// }
