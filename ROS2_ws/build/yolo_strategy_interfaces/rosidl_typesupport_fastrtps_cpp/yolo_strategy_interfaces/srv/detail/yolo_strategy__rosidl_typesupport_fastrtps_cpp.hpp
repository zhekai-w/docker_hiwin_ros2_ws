// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
// generated code does not contain a copyright notice

#ifndef YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "yolo_strategy_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace yolo_strategy_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
cdr_serialize(
  const yolo_strategy_interfaces::srv::YoloStrategy_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  yolo_strategy_interfaces::srv::YoloStrategy_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
get_serialized_size(
  const yolo_strategy_interfaces::srv::YoloStrategy_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
max_serialized_size_YoloStrategy_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace yolo_strategy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, yolo_strategy_interfaces, srv, YoloStrategy_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "yolo_strategy_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "yolo_strategy_interfaces/srv/detail/yolo_strategy__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace yolo_strategy_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
cdr_serialize(
  const yolo_strategy_interfaces::srv::YoloStrategy_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  yolo_strategy_interfaces::srv::YoloStrategy_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
get_serialized_size(
  const yolo_strategy_interfaces::srv::YoloStrategy_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
max_serialized_size_YoloStrategy_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace yolo_strategy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, yolo_strategy_interfaces, srv, YoloStrategy_Response)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "yolo_strategy_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_yolo_strategy_interfaces
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, yolo_strategy_interfaces, srv, YoloStrategy)();

#ifdef __cplusplus
}
#endif

#endif  // YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
