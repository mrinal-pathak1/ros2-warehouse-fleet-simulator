// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from warehouse_interfaces:srv/AssignTask.idl
// generated code does not contain a copyright notice

#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__STRUCT_H_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/AssignTask in the package warehouse_interfaces.
typedef struct warehouse_interfaces__srv__AssignTask_Request
{
  double pickup_x;
  double pickup_y;
  double target_x;
  double target_y;
  rosidl_runtime_c__String task_id;
} warehouse_interfaces__srv__AssignTask_Request;

// Struct for a sequence of warehouse_interfaces__srv__AssignTask_Request.
typedef struct warehouse_interfaces__srv__AssignTask_Request__Sequence
{
  warehouse_interfaces__srv__AssignTask_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} warehouse_interfaces__srv__AssignTask_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'assigned_robot'
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/AssignTask in the package warehouse_interfaces.
typedef struct warehouse_interfaces__srv__AssignTask_Response
{
  bool success;
  rosidl_runtime_c__String assigned_robot;
  rosidl_runtime_c__String message;
} warehouse_interfaces__srv__AssignTask_Response;

// Struct for a sequence of warehouse_interfaces__srv__AssignTask_Response.
typedef struct warehouse_interfaces__srv__AssignTask_Response__Sequence
{
  warehouse_interfaces__srv__AssignTask_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} warehouse_interfaces__srv__AssignTask_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__STRUCT_H_
