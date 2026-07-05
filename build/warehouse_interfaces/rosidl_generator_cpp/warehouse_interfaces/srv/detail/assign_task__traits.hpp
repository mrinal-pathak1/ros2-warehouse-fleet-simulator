// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from warehouse_interfaces:srv/AssignTask.idl
// generated code does not contain a copyright notice

#ifndef WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__TRAITS_HPP_
#define WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "warehouse_interfaces/srv/detail/assign_task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace warehouse_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AssignTask_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pickup_x
  {
    out << "pickup_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pickup_x, out);
    out << ", ";
  }

  // member: pickup_y
  {
    out << "pickup_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pickup_y, out);
    out << ", ";
  }

  // member: target_x
  {
    out << "target_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_x, out);
    out << ", ";
  }

  // member: target_y
  {
    out << "target_y: ";
    rosidl_generator_traits::value_to_yaml(msg.target_y, out);
    out << ", ";
  }

  // member: task_id
  {
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AssignTask_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pickup_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pickup_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pickup_x, out);
    out << "\n";
  }

  // member: pickup_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pickup_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pickup_y, out);
    out << "\n";
  }

  // member: target_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_x: ";
    rosidl_generator_traits::value_to_yaml(msg.target_x, out);
    out << "\n";
  }

  // member: target_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_y: ";
    rosidl_generator_traits::value_to_yaml(msg.target_y, out);
    out << "\n";
  }

  // member: task_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AssignTask_Request & msg, bool use_flow_style = false)
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

}  // namespace warehouse_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use warehouse_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const warehouse_interfaces::srv::AssignTask_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  warehouse_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use warehouse_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const warehouse_interfaces::srv::AssignTask_Request & msg)
{
  return warehouse_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<warehouse_interfaces::srv::AssignTask_Request>()
{
  return "warehouse_interfaces::srv::AssignTask_Request";
}

template<>
inline const char * name<warehouse_interfaces::srv::AssignTask_Request>()
{
  return "warehouse_interfaces/srv/AssignTask_Request";
}

template<>
struct has_fixed_size<warehouse_interfaces::srv::AssignTask_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<warehouse_interfaces::srv::AssignTask_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<warehouse_interfaces::srv::AssignTask_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace warehouse_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const AssignTask_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: assigned_robot
  {
    out << "assigned_robot: ";
    rosidl_generator_traits::value_to_yaml(msg.assigned_robot, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AssignTask_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: assigned_robot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "assigned_robot: ";
    rosidl_generator_traits::value_to_yaml(msg.assigned_robot, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AssignTask_Response & msg, bool use_flow_style = false)
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

}  // namespace warehouse_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use warehouse_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const warehouse_interfaces::srv::AssignTask_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  warehouse_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use warehouse_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const warehouse_interfaces::srv::AssignTask_Response & msg)
{
  return warehouse_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<warehouse_interfaces::srv::AssignTask_Response>()
{
  return "warehouse_interfaces::srv::AssignTask_Response";
}

template<>
inline const char * name<warehouse_interfaces::srv::AssignTask_Response>()
{
  return "warehouse_interfaces/srv/AssignTask_Response";
}

template<>
struct has_fixed_size<warehouse_interfaces::srv::AssignTask_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<warehouse_interfaces::srv::AssignTask_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<warehouse_interfaces::srv::AssignTask_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<warehouse_interfaces::srv::AssignTask>()
{
  return "warehouse_interfaces::srv::AssignTask";
}

template<>
inline const char * name<warehouse_interfaces::srv::AssignTask>()
{
  return "warehouse_interfaces/srv/AssignTask";
}

template<>
struct has_fixed_size<warehouse_interfaces::srv::AssignTask>
  : std::integral_constant<
    bool,
    has_fixed_size<warehouse_interfaces::srv::AssignTask_Request>::value &&
    has_fixed_size<warehouse_interfaces::srv::AssignTask_Response>::value
  >
{
};

template<>
struct has_bounded_size<warehouse_interfaces::srv::AssignTask>
  : std::integral_constant<
    bool,
    has_bounded_size<warehouse_interfaces::srv::AssignTask_Request>::value &&
    has_bounded_size<warehouse_interfaces::srv::AssignTask_Response>::value
  >
{
};

template<>
struct is_service<warehouse_interfaces::srv::AssignTask>
  : std::true_type
{
};

template<>
struct is_service_request<warehouse_interfaces::srv::AssignTask_Request>
  : std::true_type
{
};

template<>
struct is_service_response<warehouse_interfaces::srv::AssignTask_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // WAREHOUSE_INTERFACES__SRV__DETAIL__ASSIGN_TASK__TRAITS_HPP_
