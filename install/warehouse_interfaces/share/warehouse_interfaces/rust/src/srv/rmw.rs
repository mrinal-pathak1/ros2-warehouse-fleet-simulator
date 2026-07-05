#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__AssignTask_Request() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__AssignTask_Request__init(msg: *mut AssignTask_Request) -> bool;
    fn warehouse_interfaces__srv__AssignTask_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AssignTask_Request>, size: usize) -> bool;
    fn warehouse_interfaces__srv__AssignTask_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AssignTask_Request>);
    fn warehouse_interfaces__srv__AssignTask_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AssignTask_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<AssignTask_Request>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__AssignTask_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    pub task_id: rosidl_runtime_rs::String,

}



impl Default for AssignTask_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__AssignTask_Request__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__AssignTask_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AssignTask_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignTask_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignTask_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignTask_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AssignTask_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AssignTask_Request where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/AssignTask_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__AssignTask_Request() }
  }
}


#[link(name = "warehouse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__AssignTask_Response() -> *const std::ffi::c_void;
}

#[link(name = "warehouse_interfaces__rosidl_generator_c")]
extern "C" {
    fn warehouse_interfaces__srv__AssignTask_Response__init(msg: *mut AssignTask_Response) -> bool;
    fn warehouse_interfaces__srv__AssignTask_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AssignTask_Response>, size: usize) -> bool;
    fn warehouse_interfaces__srv__AssignTask_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AssignTask_Response>);
    fn warehouse_interfaces__srv__AssignTask_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AssignTask_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<AssignTask_Response>) -> bool;
}

// Corresponds to warehouse_interfaces__srv__AssignTask_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignTask_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub assigned_robot: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for AssignTask_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !warehouse_interfaces__srv__AssignTask_Response__init(&mut msg as *mut _) {
        panic!("Call to warehouse_interfaces__srv__AssignTask_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AssignTask_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignTask_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignTask_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { warehouse_interfaces__srv__AssignTask_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AssignTask_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AssignTask_Response where Self: Sized {
  const TYPE_NAME: &'static str = "warehouse_interfaces/srv/AssignTask_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__warehouse_interfaces__srv__AssignTask_Response() }
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


