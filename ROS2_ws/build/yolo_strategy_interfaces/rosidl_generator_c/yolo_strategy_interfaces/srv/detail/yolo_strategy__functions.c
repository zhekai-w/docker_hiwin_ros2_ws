// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yolo_strategy_interfaces:srv/YoloStrategy.idl
// generated code does not contain a copyright notice
#include "yolo_strategy_interfaces/srv/detail/yolo_strategy__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `update_position`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
yolo_strategy_interfaces__srv__YoloStrategy_Request__init(yolo_strategy_interfaces__srv__YoloStrategy_Request * msg)
{
  if (!msg) {
    return false;
  }
  // send_position
  // update_position
  if (!rosidl_runtime_c__double__Sequence__init(&msg->update_position, 0)) {
    yolo_strategy_interfaces__srv__YoloStrategy_Request__fini(msg);
    return false;
  }
  return true;
}

void
yolo_strategy_interfaces__srv__YoloStrategy_Request__fini(yolo_strategy_interfaces__srv__YoloStrategy_Request * msg)
{
  if (!msg) {
    return;
  }
  // send_position
  // update_position
  rosidl_runtime_c__double__Sequence__fini(&msg->update_position);
}

bool
yolo_strategy_interfaces__srv__YoloStrategy_Request__are_equal(const yolo_strategy_interfaces__srv__YoloStrategy_Request * lhs, const yolo_strategy_interfaces__srv__YoloStrategy_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // send_position
  if (lhs->send_position != rhs->send_position) {
    return false;
  }
  // update_position
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->update_position), &(rhs->update_position)))
  {
    return false;
  }
  return true;
}

bool
yolo_strategy_interfaces__srv__YoloStrategy_Request__copy(
  const yolo_strategy_interfaces__srv__YoloStrategy_Request * input,
  yolo_strategy_interfaces__srv__YoloStrategy_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // send_position
  output->send_position = input->send_position;
  // update_position
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->update_position), &(output->update_position)))
  {
    return false;
  }
  return true;
}

yolo_strategy_interfaces__srv__YoloStrategy_Request *
yolo_strategy_interfaces__srv__YoloStrategy_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_strategy_interfaces__srv__YoloStrategy_Request * msg = (yolo_strategy_interfaces__srv__YoloStrategy_Request *)allocator.allocate(sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Request));
  bool success = yolo_strategy_interfaces__srv__YoloStrategy_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yolo_strategy_interfaces__srv__YoloStrategy_Request__destroy(yolo_strategy_interfaces__srv__YoloStrategy_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yolo_strategy_interfaces__srv__YoloStrategy_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence__init(yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_strategy_interfaces__srv__YoloStrategy_Request * data = NULL;

  if (size) {
    data = (yolo_strategy_interfaces__srv__YoloStrategy_Request *)allocator.zero_allocate(size, sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yolo_strategy_interfaces__srv__YoloStrategy_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yolo_strategy_interfaces__srv__YoloStrategy_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence__fini(yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      yolo_strategy_interfaces__srv__YoloStrategy_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence *
yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence * array = (yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence *)allocator.allocate(sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence__destroy(yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence__are_equal(const yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence * lhs, const yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yolo_strategy_interfaces__srv__YoloStrategy_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence__copy(
  const yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence * input,
  yolo_strategy_interfaces__srv__YoloStrategy_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yolo_strategy_interfaces__srv__YoloStrategy_Request * data =
      (yolo_strategy_interfaces__srv__YoloStrategy_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yolo_strategy_interfaces__srv__YoloStrategy_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yolo_strategy_interfaces__srv__YoloStrategy_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yolo_strategy_interfaces__srv__YoloStrategy_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `current_position`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
yolo_strategy_interfaces__srv__YoloStrategy_Response__init(yolo_strategy_interfaces__srv__YoloStrategy_Response * msg)
{
  if (!msg) {
    return false;
  }
  // current_position
  if (!rosidl_runtime_c__double__Sequence__init(&msg->current_position, 0)) {
    yolo_strategy_interfaces__srv__YoloStrategy_Response__fini(msg);
    return false;
  }
  return true;
}

void
yolo_strategy_interfaces__srv__YoloStrategy_Response__fini(yolo_strategy_interfaces__srv__YoloStrategy_Response * msg)
{
  if (!msg) {
    return;
  }
  // current_position
  rosidl_runtime_c__double__Sequence__fini(&msg->current_position);
}

bool
yolo_strategy_interfaces__srv__YoloStrategy_Response__are_equal(const yolo_strategy_interfaces__srv__YoloStrategy_Response * lhs, const yolo_strategy_interfaces__srv__YoloStrategy_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_position
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->current_position), &(rhs->current_position)))
  {
    return false;
  }
  return true;
}

bool
yolo_strategy_interfaces__srv__YoloStrategy_Response__copy(
  const yolo_strategy_interfaces__srv__YoloStrategy_Response * input,
  yolo_strategy_interfaces__srv__YoloStrategy_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // current_position
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->current_position), &(output->current_position)))
  {
    return false;
  }
  return true;
}

yolo_strategy_interfaces__srv__YoloStrategy_Response *
yolo_strategy_interfaces__srv__YoloStrategy_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_strategy_interfaces__srv__YoloStrategy_Response * msg = (yolo_strategy_interfaces__srv__YoloStrategy_Response *)allocator.allocate(sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Response));
  bool success = yolo_strategy_interfaces__srv__YoloStrategy_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yolo_strategy_interfaces__srv__YoloStrategy_Response__destroy(yolo_strategy_interfaces__srv__YoloStrategy_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yolo_strategy_interfaces__srv__YoloStrategy_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence__init(yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_strategy_interfaces__srv__YoloStrategy_Response * data = NULL;

  if (size) {
    data = (yolo_strategy_interfaces__srv__YoloStrategy_Response *)allocator.zero_allocate(size, sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yolo_strategy_interfaces__srv__YoloStrategy_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yolo_strategy_interfaces__srv__YoloStrategy_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence__fini(yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      yolo_strategy_interfaces__srv__YoloStrategy_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence *
yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence * array = (yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence *)allocator.allocate(sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence__destroy(yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence__are_equal(const yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence * lhs, const yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yolo_strategy_interfaces__srv__YoloStrategy_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence__copy(
  const yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence * input,
  yolo_strategy_interfaces__srv__YoloStrategy_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yolo_strategy_interfaces__srv__YoloStrategy_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yolo_strategy_interfaces__srv__YoloStrategy_Response * data =
      (yolo_strategy_interfaces__srv__YoloStrategy_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yolo_strategy_interfaces__srv__YoloStrategy_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yolo_strategy_interfaces__srv__YoloStrategy_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yolo_strategy_interfaces__srv__YoloStrategy_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
