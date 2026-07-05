// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from warehouse_interfaces:srv/AssignTask.idl
// generated code does not contain a copyright notice
#include "warehouse_interfaces/srv/detail/assign_task__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `task_id`
#include "rosidl_runtime_c/string_functions.h"

bool
warehouse_interfaces__srv__AssignTask_Request__init(warehouse_interfaces__srv__AssignTask_Request * msg)
{
  if (!msg) {
    return false;
  }
  // pickup_x
  // pickup_y
  // target_x
  // target_y
  // task_id
  if (!rosidl_runtime_c__String__init(&msg->task_id)) {
    warehouse_interfaces__srv__AssignTask_Request__fini(msg);
    return false;
  }
  return true;
}

void
warehouse_interfaces__srv__AssignTask_Request__fini(warehouse_interfaces__srv__AssignTask_Request * msg)
{
  if (!msg) {
    return;
  }
  // pickup_x
  // pickup_y
  // target_x
  // target_y
  // task_id
  rosidl_runtime_c__String__fini(&msg->task_id);
}

bool
warehouse_interfaces__srv__AssignTask_Request__are_equal(const warehouse_interfaces__srv__AssignTask_Request * lhs, const warehouse_interfaces__srv__AssignTask_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pickup_x
  if (lhs->pickup_x != rhs->pickup_x) {
    return false;
  }
  // pickup_y
  if (lhs->pickup_y != rhs->pickup_y) {
    return false;
  }
  // target_x
  if (lhs->target_x != rhs->target_x) {
    return false;
  }
  // target_y
  if (lhs->target_y != rhs->target_y) {
    return false;
  }
  // task_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->task_id), &(rhs->task_id)))
  {
    return false;
  }
  return true;
}

bool
warehouse_interfaces__srv__AssignTask_Request__copy(
  const warehouse_interfaces__srv__AssignTask_Request * input,
  warehouse_interfaces__srv__AssignTask_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // pickup_x
  output->pickup_x = input->pickup_x;
  // pickup_y
  output->pickup_y = input->pickup_y;
  // target_x
  output->target_x = input->target_x;
  // target_y
  output->target_y = input->target_y;
  // task_id
  if (!rosidl_runtime_c__String__copy(
      &(input->task_id), &(output->task_id)))
  {
    return false;
  }
  return true;
}

warehouse_interfaces__srv__AssignTask_Request *
warehouse_interfaces__srv__AssignTask_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__srv__AssignTask_Request * msg = (warehouse_interfaces__srv__AssignTask_Request *)allocator.allocate(sizeof(warehouse_interfaces__srv__AssignTask_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(warehouse_interfaces__srv__AssignTask_Request));
  bool success = warehouse_interfaces__srv__AssignTask_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
warehouse_interfaces__srv__AssignTask_Request__destroy(warehouse_interfaces__srv__AssignTask_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    warehouse_interfaces__srv__AssignTask_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
warehouse_interfaces__srv__AssignTask_Request__Sequence__init(warehouse_interfaces__srv__AssignTask_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__srv__AssignTask_Request * data = NULL;

  if (size) {
    data = (warehouse_interfaces__srv__AssignTask_Request *)allocator.zero_allocate(size, sizeof(warehouse_interfaces__srv__AssignTask_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = warehouse_interfaces__srv__AssignTask_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        warehouse_interfaces__srv__AssignTask_Request__fini(&data[i - 1]);
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
warehouse_interfaces__srv__AssignTask_Request__Sequence__fini(warehouse_interfaces__srv__AssignTask_Request__Sequence * array)
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
      warehouse_interfaces__srv__AssignTask_Request__fini(&array->data[i]);
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

warehouse_interfaces__srv__AssignTask_Request__Sequence *
warehouse_interfaces__srv__AssignTask_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__srv__AssignTask_Request__Sequence * array = (warehouse_interfaces__srv__AssignTask_Request__Sequence *)allocator.allocate(sizeof(warehouse_interfaces__srv__AssignTask_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = warehouse_interfaces__srv__AssignTask_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
warehouse_interfaces__srv__AssignTask_Request__Sequence__destroy(warehouse_interfaces__srv__AssignTask_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    warehouse_interfaces__srv__AssignTask_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
warehouse_interfaces__srv__AssignTask_Request__Sequence__are_equal(const warehouse_interfaces__srv__AssignTask_Request__Sequence * lhs, const warehouse_interfaces__srv__AssignTask_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!warehouse_interfaces__srv__AssignTask_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
warehouse_interfaces__srv__AssignTask_Request__Sequence__copy(
  const warehouse_interfaces__srv__AssignTask_Request__Sequence * input,
  warehouse_interfaces__srv__AssignTask_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(warehouse_interfaces__srv__AssignTask_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    warehouse_interfaces__srv__AssignTask_Request * data =
      (warehouse_interfaces__srv__AssignTask_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!warehouse_interfaces__srv__AssignTask_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          warehouse_interfaces__srv__AssignTask_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!warehouse_interfaces__srv__AssignTask_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `assigned_robot`
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
warehouse_interfaces__srv__AssignTask_Response__init(warehouse_interfaces__srv__AssignTask_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // assigned_robot
  if (!rosidl_runtime_c__String__init(&msg->assigned_robot)) {
    warehouse_interfaces__srv__AssignTask_Response__fini(msg);
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    warehouse_interfaces__srv__AssignTask_Response__fini(msg);
    return false;
  }
  return true;
}

void
warehouse_interfaces__srv__AssignTask_Response__fini(warehouse_interfaces__srv__AssignTask_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // assigned_robot
  rosidl_runtime_c__String__fini(&msg->assigned_robot);
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
warehouse_interfaces__srv__AssignTask_Response__are_equal(const warehouse_interfaces__srv__AssignTask_Response * lhs, const warehouse_interfaces__srv__AssignTask_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // assigned_robot
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->assigned_robot), &(rhs->assigned_robot)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
warehouse_interfaces__srv__AssignTask_Response__copy(
  const warehouse_interfaces__srv__AssignTask_Response * input,
  warehouse_interfaces__srv__AssignTask_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // assigned_robot
  if (!rosidl_runtime_c__String__copy(
      &(input->assigned_robot), &(output->assigned_robot)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

warehouse_interfaces__srv__AssignTask_Response *
warehouse_interfaces__srv__AssignTask_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__srv__AssignTask_Response * msg = (warehouse_interfaces__srv__AssignTask_Response *)allocator.allocate(sizeof(warehouse_interfaces__srv__AssignTask_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(warehouse_interfaces__srv__AssignTask_Response));
  bool success = warehouse_interfaces__srv__AssignTask_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
warehouse_interfaces__srv__AssignTask_Response__destroy(warehouse_interfaces__srv__AssignTask_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    warehouse_interfaces__srv__AssignTask_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
warehouse_interfaces__srv__AssignTask_Response__Sequence__init(warehouse_interfaces__srv__AssignTask_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__srv__AssignTask_Response * data = NULL;

  if (size) {
    data = (warehouse_interfaces__srv__AssignTask_Response *)allocator.zero_allocate(size, sizeof(warehouse_interfaces__srv__AssignTask_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = warehouse_interfaces__srv__AssignTask_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        warehouse_interfaces__srv__AssignTask_Response__fini(&data[i - 1]);
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
warehouse_interfaces__srv__AssignTask_Response__Sequence__fini(warehouse_interfaces__srv__AssignTask_Response__Sequence * array)
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
      warehouse_interfaces__srv__AssignTask_Response__fini(&array->data[i]);
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

warehouse_interfaces__srv__AssignTask_Response__Sequence *
warehouse_interfaces__srv__AssignTask_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  warehouse_interfaces__srv__AssignTask_Response__Sequence * array = (warehouse_interfaces__srv__AssignTask_Response__Sequence *)allocator.allocate(sizeof(warehouse_interfaces__srv__AssignTask_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = warehouse_interfaces__srv__AssignTask_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
warehouse_interfaces__srv__AssignTask_Response__Sequence__destroy(warehouse_interfaces__srv__AssignTask_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    warehouse_interfaces__srv__AssignTask_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
warehouse_interfaces__srv__AssignTask_Response__Sequence__are_equal(const warehouse_interfaces__srv__AssignTask_Response__Sequence * lhs, const warehouse_interfaces__srv__AssignTask_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!warehouse_interfaces__srv__AssignTask_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
warehouse_interfaces__srv__AssignTask_Response__Sequence__copy(
  const warehouse_interfaces__srv__AssignTask_Response__Sequence * input,
  warehouse_interfaces__srv__AssignTask_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(warehouse_interfaces__srv__AssignTask_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    warehouse_interfaces__srv__AssignTask_Response * data =
      (warehouse_interfaces__srv__AssignTask_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!warehouse_interfaces__srv__AssignTask_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          warehouse_interfaces__srv__AssignTask_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!warehouse_interfaces__srv__AssignTask_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
