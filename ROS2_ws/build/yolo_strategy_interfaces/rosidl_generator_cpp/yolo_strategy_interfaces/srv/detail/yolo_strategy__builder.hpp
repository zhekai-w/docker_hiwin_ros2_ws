// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
// generated code does not contain a copyright notice

#ifndef YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__BUILDER_HPP_
#define YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolo_strategy_interfaces
{

namespace srv
{

namespace builder
{

class Init_YoloStrategy_Request_update_position
{
public:
  explicit Init_YoloStrategy_Request_update_position(::yolo_strategy_interfaces::srv::YoloStrategy_Request & msg)
  : msg_(msg)
  {}
  ::yolo_strategy_interfaces::srv::YoloStrategy_Request update_position(::yolo_strategy_interfaces::srv::YoloStrategy_Request::_update_position_type arg)
  {
    msg_.update_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolo_strategy_interfaces::srv::YoloStrategy_Request msg_;
};

class Init_YoloStrategy_Request_send_position
{
public:
  Init_YoloStrategy_Request_send_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloStrategy_Request_update_position send_position(::yolo_strategy_interfaces::srv::YoloStrategy_Request::_send_position_type arg)
  {
    msg_.send_position = std::move(arg);
    return Init_YoloStrategy_Request_update_position(msg_);
  }

private:
  ::yolo_strategy_interfaces::srv::YoloStrategy_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolo_strategy_interfaces::srv::YoloStrategy_Request>()
{
  return yolo_strategy_interfaces::srv::builder::Init_YoloStrategy_Request_send_position();
}

}  // namespace yolo_strategy_interfaces


namespace yolo_strategy_interfaces
{

namespace srv
{

namespace builder
{

class Init_YoloStrategy_Response_current_position
{
public:
  Init_YoloStrategy_Response_current_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::yolo_strategy_interfaces::srv::YoloStrategy_Response current_position(::yolo_strategy_interfaces::srv::YoloStrategy_Response::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolo_strategy_interfaces::srv::YoloStrategy_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolo_strategy_interfaces::srv::YoloStrategy_Response>()
{
  return yolo_strategy_interfaces::srv::builder::Init_YoloStrategy_Response_current_position();
}

}  // namespace yolo_strategy_interfaces

#endif  // YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__BUILDER_HPP_
