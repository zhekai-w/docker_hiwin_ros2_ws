// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
// generated code does not contain a copyright notice
#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "yolo_strategy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__struct.h"
#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // update_position
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // update_position

// forward declare type support functions


using _YoloStrategy_Request__ros_msg_type = yolo_strategy_interfaces__srv__YoloStrategy_Request;

static bool _YoloStrategy_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _YoloStrategy_Request__ros_msg_type * ros_message = static_cast<const _YoloStrategy_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: send_position
  {
    cdr << ros_message->send_position;
  }

  // Field name: update_position
  {
    size_t size = ros_message->update_position.size;
    auto array_ptr = ros_message->update_position.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _YoloStrategy_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _YoloStrategy_Request__ros_msg_type * ros_message = static_cast<_YoloStrategy_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: send_position
  {
    cdr >> ros_message->send_position;
  }

  // Field name: update_position
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->update_position.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->update_position);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->update_position, size)) {
      fprintf(stderr, "failed to create array for field 'update_position'");
      return false;
    }
    auto array_ptr = ros_message->update_position.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolo_strategy_interfaces
size_t get_serialized_size_yolo_strategy_interfaces__srv__YoloStrategy_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _YoloStrategy_Request__ros_msg_type * ros_message = static_cast<const _YoloStrategy_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name send_position
  {
    size_t item_size = sizeof(ros_message->send_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name update_position
  {
    size_t array_size = ros_message->update_position.size;
    auto array_ptr = ros_message->update_position.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _YoloStrategy_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yolo_strategy_interfaces__srv__YoloStrategy_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolo_strategy_interfaces
size_t max_serialized_size_yolo_strategy_interfaces__srv__YoloStrategy_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: send_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: update_position
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _YoloStrategy_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_yolo_strategy_interfaces__srv__YoloStrategy_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_YoloStrategy_Request = {
  "yolo_strategy_interfaces::srv",
  "YoloStrategy_Request",
  _YoloStrategy_Request__cdr_serialize,
  _YoloStrategy_Request__cdr_deserialize,
  _YoloStrategy_Request__get_serialized_size,
  _YoloStrategy_Request__max_serialized_size
};

static rosidl_message_type_support_t _YoloStrategy_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_YoloStrategy_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yolo_strategy_interfaces, srv, YoloStrategy_Request)() {
  return &_YoloStrategy_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "yolo_strategy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "yolo_strategy_interfaces/srv/detail/yolo_strategy__struct.h"
// already included above
// #include "yolo_strategy_interfaces/srv/detail/yolo_strategy__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // current_position
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // current_position

// forward declare type support functions


using _YoloStrategy_Response__ros_msg_type = yolo_strategy_interfaces__srv__YoloStrategy_Response;

static bool _YoloStrategy_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _YoloStrategy_Response__ros_msg_type * ros_message = static_cast<const _YoloStrategy_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: current_position
  {
    size_t size = ros_message->current_position.size;
    auto array_ptr = ros_message->current_position.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _YoloStrategy_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _YoloStrategy_Response__ros_msg_type * ros_message = static_cast<_YoloStrategy_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: current_position
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->current_position.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->current_position);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->current_position, size)) {
      fprintf(stderr, "failed to create array for field 'current_position'");
      return false;
    }
    auto array_ptr = ros_message->current_position.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolo_strategy_interfaces
size_t get_serialized_size_yolo_strategy_interfaces__srv__YoloStrategy_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _YoloStrategy_Response__ros_msg_type * ros_message = static_cast<const _YoloStrategy_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name current_position
  {
    size_t array_size = ros_message->current_position.size;
    auto array_ptr = ros_message->current_position.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _YoloStrategy_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yolo_strategy_interfaces__srv__YoloStrategy_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolo_strategy_interfaces
size_t max_serialized_size_yolo_strategy_interfaces__srv__YoloStrategy_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: current_position
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _YoloStrategy_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_yolo_strategy_interfaces__srv__YoloStrategy_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_YoloStrategy_Response = {
  "yolo_strategy_interfaces::srv",
  "YoloStrategy_Response",
  _YoloStrategy_Response__cdr_serialize,
  _YoloStrategy_Response__cdr_deserialize,
  _YoloStrategy_Response__get_serialized_size,
  _YoloStrategy_Response__max_serialized_size
};

static rosidl_message_type_support_t _YoloStrategy_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_YoloStrategy_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yolo_strategy_interfaces, srv, YoloStrategy_Response)() {
  return &_YoloStrategy_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "yolo_strategy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yolo_strategy_interfaces/srv/yolo_strategy.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t YoloStrategy__callbacks = {
  "yolo_strategy_interfaces::srv",
  "YoloStrategy",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yolo_strategy_interfaces, srv, YoloStrategy_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yolo_strategy_interfaces, srv, YoloStrategy_Response)(),
};

static rosidl_service_type_support_t YoloStrategy__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &YoloStrategy__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yolo_strategy_interfaces, srv, YoloStrategy)() {
  return &YoloStrategy__handle;
}

#if defined(__cplusplus)
}
#endif
