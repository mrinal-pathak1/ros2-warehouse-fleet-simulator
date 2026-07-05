// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from warehouse_interfaces:srv/AssignTask.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "warehouse_interfaces/srv/detail/assign_task__rosidl_typesupport_introspection_c.h"
#include "warehouse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "warehouse_interfaces/srv/detail/assign_task__functions.h"
#include "warehouse_interfaces/srv/detail/assign_task__struct.h"


// Include directives for member types
// Member `task_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  warehouse_interfaces__srv__AssignTask_Request__init(message_memory);
}

void warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_fini_function(void * message_memory)
{
  warehouse_interfaces__srv__AssignTask_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_message_member_array[5] = {
  {
    "pickup_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__AssignTask_Request, pickup_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pickup_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__AssignTask_Request, pickup_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__AssignTask_Request, target_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__AssignTask_Request, target_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "task_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__AssignTask_Request, task_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_message_members = {
  "warehouse_interfaces__srv",  // message namespace
  "AssignTask_Request",  // message name
  5,  // number of fields
  sizeof(warehouse_interfaces__srv__AssignTask_Request),
  warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_message_member_array,  // message members
  warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_message_type_support_handle = {
  0,
  &warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_warehouse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, AssignTask_Request)() {
  if (!warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_message_type_support_handle.typesupport_identifier) {
    warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &warehouse_interfaces__srv__AssignTask_Request__rosidl_typesupport_introspection_c__AssignTask_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "warehouse_interfaces/srv/detail/assign_task__rosidl_typesupport_introspection_c.h"
// already included above
// #include "warehouse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "warehouse_interfaces/srv/detail/assign_task__functions.h"
// already included above
// #include "warehouse_interfaces/srv/detail/assign_task__struct.h"


// Include directives for member types
// Member `assigned_robot`
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  warehouse_interfaces__srv__AssignTask_Response__init(message_memory);
}

void warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_fini_function(void * message_memory)
{
  warehouse_interfaces__srv__AssignTask_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_message_member_array[3] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__AssignTask_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "assigned_robot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__AssignTask_Response, assigned_robot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(warehouse_interfaces__srv__AssignTask_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_message_members = {
  "warehouse_interfaces__srv",  // message namespace
  "AssignTask_Response",  // message name
  3,  // number of fields
  sizeof(warehouse_interfaces__srv__AssignTask_Response),
  warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_message_member_array,  // message members
  warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_message_type_support_handle = {
  0,
  &warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_warehouse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, AssignTask_Response)() {
  if (!warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_message_type_support_handle.typesupport_identifier) {
    warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &warehouse_interfaces__srv__AssignTask_Response__rosidl_typesupport_introspection_c__AssignTask_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "warehouse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "warehouse_interfaces/srv/detail/assign_task__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_service_members = {
  "warehouse_interfaces__srv",  // service namespace
  "AssignTask",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_Request_message_type_support_handle,
  NULL  // response message
  // warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_Response_message_type_support_handle
};

static rosidl_service_type_support_t warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_service_type_support_handle = {
  0,
  &warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, AssignTask_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, AssignTask_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_warehouse_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, AssignTask)() {
  if (!warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_service_type_support_handle.typesupport_identifier) {
    warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, AssignTask_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, warehouse_interfaces, srv, AssignTask_Response)()->data;
  }

  return &warehouse_interfaces__srv__detail__assign_task__rosidl_typesupport_introspection_c__AssignTask_service_type_support_handle;
}
