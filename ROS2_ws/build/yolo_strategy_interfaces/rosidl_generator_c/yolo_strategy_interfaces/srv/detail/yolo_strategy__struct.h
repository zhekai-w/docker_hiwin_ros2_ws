// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
// generated code does not contain a copyright notice

#ifndef YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__STRUCT_H_
#define YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'update_position'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/YoloStrategy in the package yolo_strategy_interfaces.
typedef struct yolo_strategy_interfaces__srv__YoloStrategy_Request
{
  uint8_t send_position;
  rosidl_runtime_c__double__Sequence update_position;
} yolo_strategy_interfaces__srv__YoloStrategy_Request;

// Struct for a sequence of yolo_strategy_interfaces__srv__YoloStrategy_Request.
typedef struct yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence
{
  yolo_strategy_interfaces__srv__YoloStrategy_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_position'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/YoloStrategy in the package yolo_strategy_interfaces.
typedef struct yolo_strategy_interfaces__srv__YoloStrategy_Response
{
  rosidl_runtime_c__double__Sequence current_position;
} yolo_strategy_interfaces__srv__YoloStrategy_Response;

// Struct for a sequence of yolo_strategy_interfaces__srv__YoloStrategy_Response.
typedef struct yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence
{
  yolo_strategy_interfaces__srv__YoloStrategy_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLO_STRATEGY_INTERFACES__SRV__DETAIL__YOLO_STRATEGY__STRUCT_H_
