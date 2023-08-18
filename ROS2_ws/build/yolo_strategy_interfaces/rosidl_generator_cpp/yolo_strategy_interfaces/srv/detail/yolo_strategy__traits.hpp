// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
// generated code does not contain a copyright notice

#ifndef YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__TRAITS_HPP_
#define YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace yolo_strategy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const YoloStrategy_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: send_position
  {
    out << "send_position: ";
    rosidl_generator_traits::value_to_yaml(msg.send_position, out);
    out << ", ";
  }

  // member: update_position
  {
    if (msg.update_position.size() == 0) {
      out << "update_position: []";
    } else {
      out << "update_position: [";
      size_t pending_items = msg.update_position.size();
      for (auto item : msg.update_position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloStrategy_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: send_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "send_position: ";
    rosidl_generator_traits::value_to_yaml(msg.send_position, out);
    out << "\n";
  }

  // member: update_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.update_position.size() == 0) {
      out << "update_position: []\n";
    } else {
      out << "update_position:\n";
      for (auto item : msg.update_position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloStrategy_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace yolo_strategy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use yolo_strategy_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yolo_strategy_interfaces::srv::YoloStrategy_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  yolo_strategy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yolo_strategy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const yolo_strategy_interfaces::srv::YoloStrategy_Request & msg)
{
  return yolo_strategy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<yolo_strategy_interfaces::srv::YoloStrategy_Request>()
{
  return "yolo_strategy_interfaces::srv::YoloStrategy_Request";
}

template<>
inline const char * name<yolo_strategy_interfaces::srv::YoloStrategy_Request>()
{
  return "yolo_strategy_interfaces/srv/YoloStrategy_Request";
}

template<>
struct has_fixed_size<yolo_strategy_interfaces::srv::YoloStrategy_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yolo_strategy_interfaces::srv::YoloStrategy_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yolo_strategy_interfaces::srv::YoloStrategy_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace yolo_strategy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const YoloStrategy_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_position
  {
    if (msg.current_position.size() == 0) {
      out << "current_position: []";
    } else {
      out << "current_position: [";
      size_t pending_items = msg.current_position.size();
      for (auto item : msg.current_position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloStrategy_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_position.size() == 0) {
      out << "current_position: []\n";
    } else {
      out << "current_position:\n";
      for (auto item : msg.current_position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloStrategy_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace yolo_strategy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use yolo_strategy_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yolo_strategy_interfaces::srv::YoloStrategy_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  yolo_strategy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yolo_strategy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const yolo_strategy_interfaces::srv::YoloStrategy_Response & msg)
{
  return yolo_strategy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<yolo_strategy_interfaces::srv::YoloStrategy_Response>()
{
  return "yolo_strategy_interfaces::srv::YoloStrategy_Response";
}

template<>
inline const char * name<yolo_strategy_interfaces::srv::YoloStrategy_Response>()
{
  return "yolo_strategy_interfaces/srv/YoloStrategy_Response";
}

template<>
struct has_fixed_size<yolo_strategy_interfaces::srv::YoloStrategy_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yolo_strategy_interfaces::srv::YoloStrategy_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yolo_strategy_interfaces::srv::YoloStrategy_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<yolo_strategy_interfaces::srv::YoloStrategy>()
{
  return "yolo_strategy_interfaces::srv::YoloStrategy";
}

template<>
inline const char * name<yolo_strategy_interfaces::srv::YoloStrategy>()
{
  return "yolo_strategy_interfaces/srv/YoloStrategy";
}

template<>
struct has_fixed_size<yolo_strategy_interfaces::srv::YoloStrategy>
  : std::integral_constant<
    bool,
    has_fixed_size<yolo_strategy_interfaces::srv::YoloStrategy_Request>::value &&
    has_fixed_size<yolo_strategy_interfaces::srv::YoloStrategy_Response>::value
  >
{
};

template<>
struct has_bounded_size<yolo_strategy_interfaces::srv::YoloStrategy>
  : std::integral_constant<
    bool,
    has_bounded_size<yolo_strategy_interfaces::srv::YoloStrategy_Request>::value &&
    has_bounded_size<yolo_strategy_interfaces::srv::YoloStrategy_Response>::value
  >
{
};

template<>
struct is_service<yolo_strategy_interfaces::srv::YoloStrategy>
  : std::true_type
{
};

template<>
struct is_service_request<yolo_strategy_interfaces::srv::YoloStrategy_Request>
  : std::true_type
{
};

template<>
struct is_service_response<yolo_strategy_interfaces::srv::YoloStrategy_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__TRAITS_HPP_
