// Generated by gencpp from file learning_service/AddInts.msg
// DO NOT EDIT!


#ifndef LEARNING_SERVICE_MESSAGE_ADDINTS_H
#define LEARNING_SERVICE_MESSAGE_ADDINTS_H

#include <ros/service_traits.h>


#include <learning_service/AddIntsRequest.h>
#include <learning_service/AddIntsResponse.h>


namespace learning_service
{

struct AddInts
{

typedef AddIntsRequest Request;
typedef AddIntsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct AddInts
} // namespace learning_service


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::learning_service::AddInts > {
  static const char* value()
  {
    return "4781436a0c2affec8025955a6041e481";
  }

  static const char* value(const ::learning_service::AddInts&) { return value(); }
};

template<>
struct DataType< ::learning_service::AddInts > {
  static const char* value()
  {
    return "learning_service/AddInts";
  }

  static const char* value(const ::learning_service::AddInts&) { return value(); }
};


// service_traits::MD5Sum< ::learning_service::AddIntsRequest> should match
// service_traits::MD5Sum< ::learning_service::AddInts >
template<>
struct MD5Sum< ::learning_service::AddIntsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::learning_service::AddInts >::value();
  }
  static const char* value(const ::learning_service::AddIntsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::learning_service::AddIntsRequest> should match
// service_traits::DataType< ::learning_service::AddInts >
template<>
struct DataType< ::learning_service::AddIntsRequest>
{
  static const char* value()
  {
    return DataType< ::learning_service::AddInts >::value();
  }
  static const char* value(const ::learning_service::AddIntsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::learning_service::AddIntsResponse> should match
// service_traits::MD5Sum< ::learning_service::AddInts >
template<>
struct MD5Sum< ::learning_service::AddIntsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::learning_service::AddInts >::value();
  }
  static const char* value(const ::learning_service::AddIntsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::learning_service::AddIntsResponse> should match
// service_traits::DataType< ::learning_service::AddInts >
template<>
struct DataType< ::learning_service::AddIntsResponse>
{
  static const char* value()
  {
    return DataType< ::learning_service::AddInts >::value();
  }
  static const char* value(const ::learning_service::AddIntsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // LEARNING_SERVICE_MESSAGE_ADDINTS_H
