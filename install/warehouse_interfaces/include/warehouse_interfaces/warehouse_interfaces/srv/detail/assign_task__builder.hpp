// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from warehouse_interfaces:srv/AssignTask.idl
// generated code does not contain a copyright notice

#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__BUILDER_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "warehouse_interfaces/srv/detail/assign_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_AssignTask_Request_task_id
{
public:
  explicit Init_AssignTask_Request_task_id(::warehouse_interfaces::srv::AssignTask_Request & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::AssignTask_Request task_id(::warehouse_interfaces::srv::AssignTask_Request::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignTask_Request msg_;
};

class Init_AssignTask_Request_target_y
{
public:
  explicit Init_AssignTask_Request_target_y(::warehouse_interfaces::srv::AssignTask_Request & msg)
  : msg_(msg)
  {}
  Init_AssignTask_Request_task_id target_y(::warehouse_interfaces::srv::AssignTask_Request::_target_y_type arg)
  {
    msg_.target_y = std::move(arg);
    return Init_AssignTask_Request_task_id(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignTask_Request msg_;
};

class Init_AssignTask_Request_target_x
{
public:
  explicit Init_AssignTask_Request_target_x(::warehouse_interfaces::srv::AssignTask_Request & msg)
  : msg_(msg)
  {}
  Init_AssignTask_Request_target_y target_x(::warehouse_interfaces::srv::AssignTask_Request::_target_x_type arg)
  {
    msg_.target_x = std::move(arg);
    return Init_AssignTask_Request_target_y(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignTask_Request msg_;
};

class Init_AssignTask_Request_pickup_y
{
public:
  explicit Init_AssignTask_Request_pickup_y(::warehouse_interfaces::srv::AssignTask_Request & msg)
  : msg_(msg)
  {}
  Init_AssignTask_Request_target_x pickup_y(::warehouse_interfaces::srv::AssignTask_Request::_pickup_y_type arg)
  {
    msg_.pickup_y = std::move(arg);
    return Init_AssignTask_Request_target_x(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignTask_Request msg_;
};

class Init_AssignTask_Request_pickup_x
{
public:
  Init_AssignTask_Request_pickup_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AssignTask_Request_pickup_y pickup_x(::warehouse_interfaces::srv::AssignTask_Request::_pickup_x_type arg)
  {
    msg_.pickup_x = std::move(arg);
    return Init_AssignTask_Request_pickup_y(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignTask_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::AssignTask_Request>()
{
  return warehouse_interfaces::srv::builder::Init_AssignTask_Request_pickup_x();
}

}  // namespace warehouse_interfaces


namespace warehouse_interfaces
{

namespace srv
{

namespace builder
{

class Init_AssignTask_Response_message
{
public:
  explicit Init_AssignTask_Response_message(::warehouse_interfaces::srv::AssignTask_Response & msg)
  : msg_(msg)
  {}
  ::warehouse_interfaces::srv::AssignTask_Response message(::warehouse_interfaces::srv::AssignTask_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignTask_Response msg_;
};

class Init_AssignTask_Response_assigned_robot
{
public:
  explicit Init_AssignTask_Response_assigned_robot(::warehouse_interfaces::srv::AssignTask_Response & msg)
  : msg_(msg)
  {}
  Init_AssignTask_Response_message assigned_robot(::warehouse_interfaces::srv::AssignTask_Response::_assigned_robot_type arg)
  {
    msg_.assigned_robot = std::move(arg);
    return Init_AssignTask_Response_message(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignTask_Response msg_;
};

class Init_AssignTask_Response_success
{
public:
  Init_AssignTask_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AssignTask_Response_assigned_robot success(::warehouse_interfaces::srv::AssignTask_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_AssignTask_Response_assigned_robot(msg_);
  }

private:
  ::warehouse_interfaces::srv::AssignTask_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::warehouse_interfaces::srv::AssignTask_Response>()
{
  return warehouse_interfaces::srv::builder::Init_AssignTask_Response_success();
}

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__BUILDER_HPP_
