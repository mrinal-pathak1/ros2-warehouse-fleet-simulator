#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to warehouse_interfaces__srv__AssignTask_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignTask_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pickup_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pickup_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub task_id: std::string::String,

}



impl Default for AssignTask_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AssignTask_Request::default())
  }
}

impl rosidl_runtime_rs::Message for AssignTask_Request {
  type RmwMsg = super::srv::rmw::AssignTask_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pickup_x: msg.pickup_x,
        pickup_y: msg.pickup_y,
        target_x: msg.target_x,
        target_y: msg.target_y,
        task_id: msg.task_id.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      pickup_x: msg.pickup_x,
      pickup_y: msg.pickup_y,
      target_x: msg.target_x,
      target_y: msg.target_y,
        task_id: msg.task_id.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pickup_x: msg.pickup_x,
      pickup_y: msg.pickup_y,
      target_x: msg.target_x,
      target_y: msg.target_y,
      task_id: msg.task_id.to_string(),
    }
  }
}


// Corresponds to warehouse_interfaces__srv__AssignTask_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignTask_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub assigned_robot: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for AssignTask_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AssignTask_Response::default())
  }
}

impl rosidl_runtime_rs::Message for AssignTask_Response {
  type RmwMsg = super::srv::rmw::AssignTask_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        assigned_robot: msg.assigned_robot.as_str().into(),
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        assigned_robot: msg.assigned_robot.as_str().into(),
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      assigned_robot: msg.assigned_robot.to_string(),
      message: msg.message.to_string(),
    }
  }
}






#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__AssignTask() -> *const std::ffi::c_void;
}

// Corresponds to warehouse_interfaces__srv__AssignTask
#[allow(missing_docs, non_camel_case_types)]
pub struct AssignTask;

impl rosidl_runtime_rs::Service for AssignTask {
    type Request = AssignTask_Request;
    type Response = AssignTask_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__warehouse_interfaces__srv__AssignTask() }
    }
}


