// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from warehouse_interfaces:srv/AssignTask.idl
// generated code does not contain a copyright notice

#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__STRUCT_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__warehouse_interfaces__srv__AssignTask_Request __attribute__((deprecated))
#else
# define DEPRECATED__warehouse_interfaces__srv__AssignTask_Request __declspec(deprecated)
#endif

namespace warehouse_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AssignTask_Request_
{
  using Type = AssignTask_Request_<ContainerAllocator>;

  explicit AssignTask_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pickup_x = 0.0;
      this->pickup_y = 0.0;
      this->target_x = 0.0;
      this->target_y = 0.0;
      this->task_id = "";
    }
  }

  explicit AssignTask_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pickup_x = 0.0;
      this->pickup_y = 0.0;
      this->target_x = 0.0;
      this->target_y = 0.0;
      this->task_id = "";
    }
  }

  // field types and members
  using _pickup_x_type =
    double;
  _pickup_x_type pickup_x;
  using _pickup_y_type =
    double;
  _pickup_y_type pickup_y;
  using _target_x_type =
    double;
  _target_x_type target_x;
  using _target_y_type =
    double;
  _target_y_type target_y;
  using _task_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_id_type task_id;

  // setters for named parameter idiom
  Type & set__pickup_x(
    const double & _arg)
  {
    this->pickup_x = _arg;
    return *this;
  }
  Type & set__pickup_y(
    const double & _arg)
  {
    this->pickup_y = _arg;
    return *this;
  }
  Type & set__target_x(
    const double & _arg)
  {
    this->target_x = _arg;
    return *this;
  }
  Type & set__target_y(
    const double & _arg)
  {
    this->target_y = _arg;
    return *this;
  }
  Type & set__task_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__warehouse_interfaces__srv__AssignTask_Request
    std::shared_ptr<warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__warehouse_interfaces__srv__AssignTask_Request
    std::shared_ptr<warehouse_interfaces::srv::AssignTask_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AssignTask_Request_ & other) const
  {
    if (this->pickup_x != other.pickup_x) {
      return false;
    }
    if (this->pickup_y != other.pickup_y) {
      return false;
    }
    if (this->target_x != other.target_x) {
      return false;
    }
    if (this->target_y != other.target_y) {
      return false;
    }
    if (this->task_id != other.task_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const AssignTask_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AssignTask_Request_

// alias to use template instance with default allocator
using AssignTask_Request =
  warehouse_interfaces::srv::AssignTask_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace warehouse_interfaces


#ifndef _WIN32
# define DEPRECATED__warehouse_interfaces__srv__AssignTask_Response __attribute__((deprecated))
#else
# define DEPRECATED__warehouse_interfaces__srv__AssignTask_Response __declspec(deprecated)
#endif

namespace warehouse_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AssignTask_Response_
{
  using Type = AssignTask_Response_<ContainerAllocator>;

  explicit AssignTask_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->assigned_robot = "";
      this->message = "";
    }
  }

  explicit AssignTask_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : assigned_robot(_alloc),
    message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->assigned_robot = "";
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _assigned_robot_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _assigned_robot_type assigned_robot;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__assigned_robot(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->assigned_robot = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__warehouse_interfaces__srv__AssignTask_Response
    std::shared_ptr<warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__warehouse_interfaces__srv__AssignTask_Response
    std::shared_ptr<warehouse_interfaces::srv::AssignTask_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AssignTask_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->assigned_robot != other.assigned_robot) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const AssignTask_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AssignTask_Response_

// alias to use template instance with default allocator
using AssignTask_Response =
  warehouse_interfaces::srv::AssignTask_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace warehouse_interfaces

namespace warehouse_interfaces
{

namespace srv
{

struct AssignTask
{
  using Request = warehouse_interfaces::srv::AssignTask_Request;
  using Response = warehouse_interfaces::srv::AssignTask_Response;
};

}  // namespace srv

}  // namespace warehouse_interfaces

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__STRUCT_HPP_
