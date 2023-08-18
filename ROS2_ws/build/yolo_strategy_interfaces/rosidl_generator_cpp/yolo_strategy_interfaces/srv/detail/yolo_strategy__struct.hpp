// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
// generated code does not contain a copyright notice

#ifndef YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__STRUCT_HPP_
#define YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__yolo_strategy_interfaces__srv__YoloStrategy_Request __attribute__((deprecated))
#else
# define DEPRECATED__yolo_strategy_interfaces__srv__YoloStrategy_Request __declspec(deprecated)
#endif

namespace yolo_strategy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct YoloStrategy_Request_
{
  using Type = YoloStrategy_Request_<ContainerAllocator>;

  explicit YoloStrategy_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_position = 0;
    }
  }

  explicit YoloStrategy_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->send_position = 0;
    }
  }

  // field types and members
  using _send_position_type =
    uint8_t;
  _send_position_type send_position;
  using _update_position_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _update_position_type update_position;

  // setters for named parameter idiom
  Type & set__send_position(
    const uint8_t & _arg)
  {
    this->send_position = _arg;
    return *this;
  }
  Type & set__update_position(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->update_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolo_strategy_interfaces__srv__YoloStrategy_Request
    std::shared_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolo_strategy_interfaces__srv__YoloStrategy_Request
    std::shared_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloStrategy_Request_ & other) const
  {
    if (this->send_position != other.send_position) {
      return false;
    }
    if (this->update_position != other.update_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloStrategy_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloStrategy_Request_

// alias to use template instance with default allocator
using YoloStrategy_Request =
  yolo_strategy_interfaces::srv::YoloStrategy_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace yolo_strategy_interfaces


#ifndef _WIN32
# define DEPRECATED__yolo_strategy_interfaces__srv__YoloStrategy_Response __attribute__((deprecated))
#else
# define DEPRECATED__yolo_strategy_interfaces__srv__YoloStrategy_Response __declspec(deprecated)
#endif

namespace yolo_strategy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct YoloStrategy_Response_
{
  using Type = YoloStrategy_Response_<ContainerAllocator>;

  explicit YoloStrategy_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit YoloStrategy_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _current_position_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _current_position_type current_position;

  // setters for named parameter idiom
  Type & set__current_position(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->current_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolo_strategy_interfaces__srv__YoloStrategy_Response
    std::shared_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolo_strategy_interfaces__srv__YoloStrategy_Response
    std::shared_ptr<yolo_strategy_interfaces::srv::YoloStrategy_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloStrategy_Response_ & other) const
  {
    if (this->current_position != other.current_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloStrategy_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloStrategy_Response_

// alias to use template instance with default allocator
using YoloStrategy_Response =
  yolo_strategy_interfaces::srv::YoloStrategy_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace yolo_strategy_interfaces

namespace yolo_strategy_interfaces
{

namespace srv
{

struct YoloStrategy
{
  using Request = yolo_strategy_interfaces::srv::YoloStrategy_Request;
  using Response = yolo_strategy_interfaces::srv::YoloStrategy_Response;
};

}  // namespace srv

}  // namespace yolo_strategy_interfaces

#endif  // YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__STRUCT_HPP_
