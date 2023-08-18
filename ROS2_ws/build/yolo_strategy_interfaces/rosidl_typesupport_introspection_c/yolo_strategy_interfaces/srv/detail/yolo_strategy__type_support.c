// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__rosidl_typesupport_introspection_c.h"
#include "yolo_strategy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__functions.h"
#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__struct.h"


// Include directives for member types
// Member `update_position`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yolo_strategy_interfaces__srv__YoloStrategy_Request__init(message_memory);
}

void yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_fini_function(void * message_memory)
{
  yolo_strategy_interfaces__srv__YoloStrategy_Request__fini(message_memory);
}

size_t yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__size_function__YoloStrategy_Request__update_position(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__get_const_function__YoloStrategy_Request__update_position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__get_function__YoloStrategy_Request__update_position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__fetch_function__YoloStrategy_Request__update_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__get_const_function__YoloStrategy_Request__update_position(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__assign_function__YoloStrategy_Request__update_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__get_function__YoloStrategy_Request__update_position(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__resize_function__YoloStrategy_Request__update_position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_member_array[2] = {
  {
    "send_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolo_strategy_interfaces__srv__YoloStrategy_Request, send_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "update_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolo_strategy_interfaces__srv__YoloStrategy_Request, update_position),  // bytes offset in struct
    NULL,  // default value
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__size_function__YoloStrategy_Request__update_position,  // size() function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__get_const_function__YoloStrategy_Request__update_position,  // get_const(index) function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__get_function__YoloStrategy_Request__update_position,  // get(index) function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__fetch_function__YoloStrategy_Request__update_position,  // fetch(index, &value) function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__assign_function__YoloStrategy_Request__update_position,  // assign(index, value) function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__resize_function__YoloStrategy_Request__update_position  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_members = {
  "yolo_strategy_interfaces__srv",  // message namespace
  "YoloStrategy_Request",  // message name
  2,  // number of fields
  sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Request),
  yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_member_array,  // message members
  yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_type_support_handle = {
  0,
  &yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yolo_strategy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolo_strategy_interfaces, srv, YoloStrategy_Request)() {
  if (!yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_type_support_handle.typesupport_identifier) {
    yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yolo_strategy_interfaces__srv__YoloStrategy_Request__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "yolo_strategy_interfaces/srv/detail/yolo_strategy__rosidl_typesupport_introspection_c.h"
// already included above
// #include "yolo_strategy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "yolo_strategy_interfaces/srv/detail/yolo_strategy__functions.h"
// already included above
// #include "yolo_strategy_interfaces/srv/detail/yolo_strategy__struct.h"


// Include directives for member types
// Member `current_position`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yolo_strategy_interfaces__srv__YoloStrategy_Response__init(message_memory);
}

void yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_fini_function(void * message_memory)
{
  yolo_strategy_interfaces__srv__YoloStrategy_Response__fini(message_memory);
}

size_t yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__size_function__YoloStrategy_Response__current_position(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__get_const_function__YoloStrategy_Response__current_position(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__get_function__YoloStrategy_Response__current_position(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__fetch_function__YoloStrategy_Response__current_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__get_const_function__YoloStrategy_Response__current_position(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__assign_function__YoloStrategy_Response__current_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__get_function__YoloStrategy_Response__current_position(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__resize_function__YoloStrategy_Response__current_position(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_member_array[1] = {
  {
    "current_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolo_strategy_interfaces__srv__YoloStrategy_Response, current_position),  // bytes offset in struct
    NULL,  // default value
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__size_function__YoloStrategy_Response__current_position,  // size() function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__get_const_function__YoloStrategy_Response__current_position,  // get_const(index) function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__get_function__YoloStrategy_Response__current_position,  // get(index) function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__fetch_function__YoloStrategy_Response__current_position,  // fetch(index, &value) function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__assign_function__YoloStrategy_Response__current_position,  // assign(index, value) function pointer
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__resize_function__YoloStrategy_Response__current_position  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_members = {
  "yolo_strategy_interfaces__srv",  // message namespace
  "YoloStrategy_Response",  // message name
  1,  // number of fields
  sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Response),
  yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_member_array,  // message members
  yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_type_support_handle = {
  0,
  &yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yolo_strategy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolo_strategy_interfaces, srv, YoloStrategy_Response)() {
  if (!yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_type_support_handle.typesupport_identifier) {
    yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yolo_strategy_interfaces__srv__YoloStrategy_Response__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "yolo_strategy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "yolo_strategy_interfaces/srv/detail/yolo_strategy__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_service_members = {
  "yolo_strategy_interfaces__srv",  // service namespace
  "YoloStrategy",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_Request_message_type_support_handle,
  NULL  // response message
  // yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_Response_message_type_support_handle
};

static rosidl_service_type_support_t yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_service_type_support_handle = {
  0,
  &yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolo_strategy_interfaces, srv, YoloStrategy_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolo_strategy_interfaces, srv, YoloStrategy_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yolo_strategy_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolo_strategy_interfaces, srv, YoloStrategy)() {
  if (!yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_service_type_support_handle.typesupport_identifier) {
    yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolo_strategy_interfaces, srv, YoloStrategy_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolo_strategy_interfaces, srv, YoloStrategy_Response)()->data;
  }

  return &yolo_strategy_interfaces__srv__detail__yolo_strategy__rosidl_typesupport_introspection_c__YoloStrategy_service_type_support_handle;
}
