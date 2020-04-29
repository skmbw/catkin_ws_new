// Generated by gencpp from file learn_comm/AddTwoIntsResponse.msg
// DO NOT EDIT!


#ifndef LEARN_COMM_MESSAGE_ADDTWOINTSRESPONSE_H
#define LEARN_COMM_MESSAGE_ADDTWOINTSRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace learn_comm
{
template <class ContainerAllocator>
struct AddTwoIntsResponse_
{
  typedef AddTwoIntsResponse_<ContainerAllocator> Type;

  AddTwoIntsResponse_()
    : sum(0)  {
    }
  AddTwoIntsResponse_(const ContainerAllocator& _alloc)
    : sum(0)  {
  (void)_alloc;
    }



   typedef int64_t _sum_type;
  _sum_type sum;





  typedef boost::shared_ptr< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> const> ConstPtr;

}; // struct AddTwoIntsResponse_

typedef ::learn_comm::AddTwoIntsResponse_<std::allocator<void> > AddTwoIntsResponse;

typedef boost::shared_ptr< ::learn_comm::AddTwoIntsResponse > AddTwoIntsResponsePtr;
typedef boost::shared_ptr< ::learn_comm::AddTwoIntsResponse const> AddTwoIntsResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator1> & lhs, const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator2> & rhs)
{
  return lhs.sum == rhs.sum;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator1> & lhs, const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace learn_comm

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b88405221c77b1878a3cbbfff53428d7";
  }

  static const char* value(const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb88405221c77b187ULL;
  static const uint64_t static_value2 = 0x8a3cbbfff53428d7ULL;
};

template<class ContainerAllocator>
struct DataType< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "learn_comm/AddTwoIntsResponse";
  }

  static const char* value(const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 sum\n"
;
  }

  static const char* value(const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sum);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddTwoIntsResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::learn_comm::AddTwoIntsResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::learn_comm::AddTwoIntsResponse_<ContainerAllocator>& v)
  {
    s << indent << "sum: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sum);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LEARN_COMM_MESSAGE_ADDTWOINTSRESPONSE_H
