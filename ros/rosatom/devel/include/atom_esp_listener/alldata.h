// Generated by gencpp from file atom_esp_listener/alldata.msg
// DO NOT EDIT!


#ifndef ATOM_ESP_LISTENER_MESSAGE_ALLDATA_H
#define ATOM_ESP_LISTENER_MESSAGE_ALLDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace atom_esp_listener
{
template <class ContainerAllocator>
struct alldata_
{
  typedef alldata_<ContainerAllocator> Type;

  alldata_()
    : header()
    , mpuData_AcX(0)
    , mpuData_AcY(0)
    , mpuData_AcZ(0)
    , mpuData_timestamp(0)
    , mpuData_Tmp(0)
    , mpuData_GyX(0)
    , mpuData_GyY(0)
    , mpuData_GyZ(0)
    , mpuRAW_AcX(0)
    , mpuRAW_AcY(0)
    , mpuRAW_AcZ(0)
    , mpuRAW_timestamp(0)
    , mpuRAW_Tmp(0)
    , mpuRAW_GyX(0)
    , mpuRAW_GyY(0)
    , mpuRAW_GyZ(0)
    , pingheight(0.0)
    , ppfb_timestamp(0)
    , ppfb_Input(0.0)
    , ppfb_Kd(0.0)
    , ppfb_Ki(0.0)
    , ppfb_Kp(0.0)
    , ppfb_Output(0.0)
    , ppfb_Setpoint(0.0)
    , pplr_timestamp(0)
    , pplr_Input(0.0)
    , pplr_Kd(0.0)
    , pplr_Ki(0.0)
    , pplr_Kp(0.0)
    , pplr_Output(0.0)
    , pplr_Setpoint(0.0)
    , ppud_timestamp(0)
    , ppud_Input(0.0)
    , ppud_Kd(0.0)
    , ppud_Ki(0.0)
    , ppud_Kp(0.0)
    , ppud_Output(0.0)
    , ppud_Setpoint(0.0)
    , yaw(0.0)
    , pitch(0.0)
    , roll(0.0)
    , timestamp(0)
    , tune_type(0)  {
    }
  alldata_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , mpuData_AcX(0)
    , mpuData_AcY(0)
    , mpuData_AcZ(0)
    , mpuData_timestamp(0)
    , mpuData_Tmp(0)
    , mpuData_GyX(0)
    , mpuData_GyY(0)
    , mpuData_GyZ(0)
    , mpuRAW_AcX(0)
    , mpuRAW_AcY(0)
    , mpuRAW_AcZ(0)
    , mpuRAW_timestamp(0)
    , mpuRAW_Tmp(0)
    , mpuRAW_GyX(0)
    , mpuRAW_GyY(0)
    , mpuRAW_GyZ(0)
    , pingheight(0.0)
    , ppfb_timestamp(0)
    , ppfb_Input(0.0)
    , ppfb_Kd(0.0)
    , ppfb_Ki(0.0)
    , ppfb_Kp(0.0)
    , ppfb_Output(0.0)
    , ppfb_Setpoint(0.0)
    , pplr_timestamp(0)
    , pplr_Input(0.0)
    , pplr_Kd(0.0)
    , pplr_Ki(0.0)
    , pplr_Kp(0.0)
    , pplr_Output(0.0)
    , pplr_Setpoint(0.0)
    , ppud_timestamp(0)
    , ppud_Input(0.0)
    , ppud_Kd(0.0)
    , ppud_Ki(0.0)
    , ppud_Kp(0.0)
    , ppud_Output(0.0)
    , ppud_Setpoint(0.0)
    , yaw(0.0)
    , pitch(0.0)
    , roll(0.0)
    , timestamp(0)
    , tune_type(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int16_t _mpuData_AcX_type;
  _mpuData_AcX_type mpuData_AcX;

   typedef int16_t _mpuData_AcY_type;
  _mpuData_AcY_type mpuData_AcY;

   typedef int16_t _mpuData_AcZ_type;
  _mpuData_AcZ_type mpuData_AcZ;

   typedef uint32_t _mpuData_timestamp_type;
  _mpuData_timestamp_type mpuData_timestamp;

   typedef int16_t _mpuData_Tmp_type;
  _mpuData_Tmp_type mpuData_Tmp;

   typedef int16_t _mpuData_GyX_type;
  _mpuData_GyX_type mpuData_GyX;

   typedef int16_t _mpuData_GyY_type;
  _mpuData_GyY_type mpuData_GyY;

   typedef int16_t _mpuData_GyZ_type;
  _mpuData_GyZ_type mpuData_GyZ;

   typedef int16_t _mpuRAW_AcX_type;
  _mpuRAW_AcX_type mpuRAW_AcX;

   typedef int16_t _mpuRAW_AcY_type;
  _mpuRAW_AcY_type mpuRAW_AcY;

   typedef int16_t _mpuRAW_AcZ_type;
  _mpuRAW_AcZ_type mpuRAW_AcZ;

   typedef uint32_t _mpuRAW_timestamp_type;
  _mpuRAW_timestamp_type mpuRAW_timestamp;

   typedef int16_t _mpuRAW_Tmp_type;
  _mpuRAW_Tmp_type mpuRAW_Tmp;

   typedef int16_t _mpuRAW_GyX_type;
  _mpuRAW_GyX_type mpuRAW_GyX;

   typedef int16_t _mpuRAW_GyY_type;
  _mpuRAW_GyY_type mpuRAW_GyY;

   typedef int16_t _mpuRAW_GyZ_type;
  _mpuRAW_GyZ_type mpuRAW_GyZ;

   typedef float _pingheight_type;
  _pingheight_type pingheight;

   typedef uint32_t _ppfb_timestamp_type;
  _ppfb_timestamp_type ppfb_timestamp;

   typedef double _ppfb_Input_type;
  _ppfb_Input_type ppfb_Input;

   typedef double _ppfb_Kd_type;
  _ppfb_Kd_type ppfb_Kd;

   typedef double _ppfb_Ki_type;
  _ppfb_Ki_type ppfb_Ki;

   typedef double _ppfb_Kp_type;
  _ppfb_Kp_type ppfb_Kp;

   typedef double _ppfb_Output_type;
  _ppfb_Output_type ppfb_Output;

   typedef double _ppfb_Setpoint_type;
  _ppfb_Setpoint_type ppfb_Setpoint;

   typedef uint32_t _pplr_timestamp_type;
  _pplr_timestamp_type pplr_timestamp;

   typedef double _pplr_Input_type;
  _pplr_Input_type pplr_Input;

   typedef double _pplr_Kd_type;
  _pplr_Kd_type pplr_Kd;

   typedef double _pplr_Ki_type;
  _pplr_Ki_type pplr_Ki;

   typedef double _pplr_Kp_type;
  _pplr_Kp_type pplr_Kp;

   typedef double _pplr_Output_type;
  _pplr_Output_type pplr_Output;

   typedef double _pplr_Setpoint_type;
  _pplr_Setpoint_type pplr_Setpoint;

   typedef uint32_t _ppud_timestamp_type;
  _ppud_timestamp_type ppud_timestamp;

   typedef double _ppud_Input_type;
  _ppud_Input_type ppud_Input;

   typedef double _ppud_Kd_type;
  _ppud_Kd_type ppud_Kd;

   typedef double _ppud_Ki_type;
  _ppud_Ki_type ppud_Ki;

   typedef double _ppud_Kp_type;
  _ppud_Kp_type ppud_Kp;

   typedef double _ppud_Output_type;
  _ppud_Output_type ppud_Output;

   typedef double _ppud_Setpoint_type;
  _ppud_Setpoint_type ppud_Setpoint;

   typedef float _yaw_type;
  _yaw_type yaw;

   typedef float _pitch_type;
  _pitch_type pitch;

   typedef float _roll_type;
  _roll_type roll;

   typedef uint32_t _timestamp_type;
  _timestamp_type timestamp;

   typedef uint16_t _tune_type_type;
  _tune_type_type tune_type;




  typedef boost::shared_ptr< ::atom_esp_listener::alldata_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::atom_esp_listener::alldata_<ContainerAllocator> const> ConstPtr;

}; // struct alldata_

typedef ::atom_esp_listener::alldata_<std::allocator<void> > alldata;

typedef boost::shared_ptr< ::atom_esp_listener::alldata > alldataPtr;
typedef boost::shared_ptr< ::atom_esp_listener::alldata const> alldataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::atom_esp_listener::alldata_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::atom_esp_listener::alldata_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace atom_esp_listener

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'atom_esp_listener': ['/home/rahuldeo/ATOM/ATOM_DRONE/ros/rosatom/src/atom_esp_listener/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::atom_esp_listener::alldata_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::atom_esp_listener::alldata_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::atom_esp_listener::alldata_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::atom_esp_listener::alldata_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::atom_esp_listener::alldata_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::atom_esp_listener::alldata_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::atom_esp_listener::alldata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "586be2de32280a4c8bb4bc521bc4cf73";
  }

  static const char* value(const ::atom_esp_listener::alldata_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x586be2de32280a4cULL;
  static const uint64_t static_value2 = 0x8bb4bc521bc4cf73ULL;
};

template<class ContainerAllocator>
struct DataType< ::atom_esp_listener::alldata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "atom_esp_listener/alldata";
  }

  static const char* value(const ::atom_esp_listener::alldata_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::atom_esp_listener::alldata_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
int16  mpuData_AcX\n\
int16  mpuData_AcY\n\
int16  mpuData_AcZ\n\
uint32  mpuData_timestamp\n\
int16  mpuData_Tmp\n\
int16  mpuData_GyX\n\
int16  mpuData_GyY\n\
int16  mpuData_GyZ\n\
\n\
int16  mpuRAW_AcX\n\
int16  mpuRAW_AcY\n\
int16  mpuRAW_AcZ\n\
uint32  mpuRAW_timestamp\n\
int16  mpuRAW_Tmp\n\
int16  mpuRAW_GyX\n\
int16  mpuRAW_GyY\n\
int16  mpuRAW_GyZ\n\
\n\
float32  pingheight\n\
\n\
uint32  ppfb_timestamp\n\
float64  ppfb_Input\n\
float64  ppfb_Kd\n\
float64  ppfb_Ki\n\
float64  ppfb_Kp\n\
float64  ppfb_Output\n\
float64  ppfb_Setpoint\n\
\n\
uint32  pplr_timestamp\n\
float64  pplr_Input\n\
float64  pplr_Kd\n\
float64  pplr_Ki\n\
float64  pplr_Kp\n\
float64  pplr_Output\n\
float64  pplr_Setpoint\n\
\n\
uint32  ppud_timestamp\n\
float64  ppud_Input\n\
float64  ppud_Kd\n\
float64  ppud_Ki\n\
float64  ppud_Kp\n\
float64  ppud_Output\n\
float64  ppud_Setpoint\n\
\n\
float32  yaw\n\
float32  pitch\n\
float32  roll\n\
\n\
uint32  timestamp\n\
uint16  tune_type\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::atom_esp_listener::alldata_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::atom_esp_listener::alldata_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.mpuData_AcX);
      stream.next(m.mpuData_AcY);
      stream.next(m.mpuData_AcZ);
      stream.next(m.mpuData_timestamp);
      stream.next(m.mpuData_Tmp);
      stream.next(m.mpuData_GyX);
      stream.next(m.mpuData_GyY);
      stream.next(m.mpuData_GyZ);
      stream.next(m.mpuRAW_AcX);
      stream.next(m.mpuRAW_AcY);
      stream.next(m.mpuRAW_AcZ);
      stream.next(m.mpuRAW_timestamp);
      stream.next(m.mpuRAW_Tmp);
      stream.next(m.mpuRAW_GyX);
      stream.next(m.mpuRAW_GyY);
      stream.next(m.mpuRAW_GyZ);
      stream.next(m.pingheight);
      stream.next(m.ppfb_timestamp);
      stream.next(m.ppfb_Input);
      stream.next(m.ppfb_Kd);
      stream.next(m.ppfb_Ki);
      stream.next(m.ppfb_Kp);
      stream.next(m.ppfb_Output);
      stream.next(m.ppfb_Setpoint);
      stream.next(m.pplr_timestamp);
      stream.next(m.pplr_Input);
      stream.next(m.pplr_Kd);
      stream.next(m.pplr_Ki);
      stream.next(m.pplr_Kp);
      stream.next(m.pplr_Output);
      stream.next(m.pplr_Setpoint);
      stream.next(m.ppud_timestamp);
      stream.next(m.ppud_Input);
      stream.next(m.ppud_Kd);
      stream.next(m.ppud_Ki);
      stream.next(m.ppud_Kp);
      stream.next(m.ppud_Output);
      stream.next(m.ppud_Setpoint);
      stream.next(m.yaw);
      stream.next(m.pitch);
      stream.next(m.roll);
      stream.next(m.timestamp);
      stream.next(m.tune_type);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct alldata_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::atom_esp_listener::alldata_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::atom_esp_listener::alldata_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "mpuData_AcX: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuData_AcX);
    s << indent << "mpuData_AcY: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuData_AcY);
    s << indent << "mpuData_AcZ: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuData_AcZ);
    s << indent << "mpuData_timestamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.mpuData_timestamp);
    s << indent << "mpuData_Tmp: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuData_Tmp);
    s << indent << "mpuData_GyX: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuData_GyX);
    s << indent << "mpuData_GyY: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuData_GyY);
    s << indent << "mpuData_GyZ: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuData_GyZ);
    s << indent << "mpuRAW_AcX: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuRAW_AcX);
    s << indent << "mpuRAW_AcY: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuRAW_AcY);
    s << indent << "mpuRAW_AcZ: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuRAW_AcZ);
    s << indent << "mpuRAW_timestamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.mpuRAW_timestamp);
    s << indent << "mpuRAW_Tmp: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuRAW_Tmp);
    s << indent << "mpuRAW_GyX: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuRAW_GyX);
    s << indent << "mpuRAW_GyY: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuRAW_GyY);
    s << indent << "mpuRAW_GyZ: ";
    Printer<int16_t>::stream(s, indent + "  ", v.mpuRAW_GyZ);
    s << indent << "pingheight: ";
    Printer<float>::stream(s, indent + "  ", v.pingheight);
    s << indent << "ppfb_timestamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.ppfb_timestamp);
    s << indent << "ppfb_Input: ";
    Printer<double>::stream(s, indent + "  ", v.ppfb_Input);
    s << indent << "ppfb_Kd: ";
    Printer<double>::stream(s, indent + "  ", v.ppfb_Kd);
    s << indent << "ppfb_Ki: ";
    Printer<double>::stream(s, indent + "  ", v.ppfb_Ki);
    s << indent << "ppfb_Kp: ";
    Printer<double>::stream(s, indent + "  ", v.ppfb_Kp);
    s << indent << "ppfb_Output: ";
    Printer<double>::stream(s, indent + "  ", v.ppfb_Output);
    s << indent << "ppfb_Setpoint: ";
    Printer<double>::stream(s, indent + "  ", v.ppfb_Setpoint);
    s << indent << "pplr_timestamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.pplr_timestamp);
    s << indent << "pplr_Input: ";
    Printer<double>::stream(s, indent + "  ", v.pplr_Input);
    s << indent << "pplr_Kd: ";
    Printer<double>::stream(s, indent + "  ", v.pplr_Kd);
    s << indent << "pplr_Ki: ";
    Printer<double>::stream(s, indent + "  ", v.pplr_Ki);
    s << indent << "pplr_Kp: ";
    Printer<double>::stream(s, indent + "  ", v.pplr_Kp);
    s << indent << "pplr_Output: ";
    Printer<double>::stream(s, indent + "  ", v.pplr_Output);
    s << indent << "pplr_Setpoint: ";
    Printer<double>::stream(s, indent + "  ", v.pplr_Setpoint);
    s << indent << "ppud_timestamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.ppud_timestamp);
    s << indent << "ppud_Input: ";
    Printer<double>::stream(s, indent + "  ", v.ppud_Input);
    s << indent << "ppud_Kd: ";
    Printer<double>::stream(s, indent + "  ", v.ppud_Kd);
    s << indent << "ppud_Ki: ";
    Printer<double>::stream(s, indent + "  ", v.ppud_Ki);
    s << indent << "ppud_Kp: ";
    Printer<double>::stream(s, indent + "  ", v.ppud_Kp);
    s << indent << "ppud_Output: ";
    Printer<double>::stream(s, indent + "  ", v.ppud_Output);
    s << indent << "ppud_Setpoint: ";
    Printer<double>::stream(s, indent + "  ", v.ppud_Setpoint);
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "timestamp: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.timestamp);
    s << indent << "tune_type: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.tune_type);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ATOM_ESP_LISTENER_MESSAGE_ALLDATA_H
