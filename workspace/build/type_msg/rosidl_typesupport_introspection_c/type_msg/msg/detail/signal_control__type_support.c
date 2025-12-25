// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from type_msg:msg/SignalControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "type_msg/msg/detail/signal_control__rosidl_typesupport_introspection_c.h"
#include "type_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "type_msg/msg/detail/signal_control__functions.h"
#include "type_msg/msg/detail/signal_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  type_msg__msg__SignalControl__init(message_memory);
}

void type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_fini_function(void * message_memory)
{
  type_msg__msg__SignalControl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_message_member_array[2] = {
  {
    "n_l",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(type_msg__msg__SignalControl, n_l),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "n_r",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(type_msg__msg__SignalControl, n_r),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_message_members = {
  "type_msg__msg",  // message namespace
  "SignalControl",  // message name
  2,  // number of fields
  sizeof(type_msg__msg__SignalControl),
  type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_message_member_array,  // message members
  type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_init_function,  // function to initialize message memory (memory has to be allocated)
  type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_message_type_support_handle = {
  0,
  &type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_type_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, type_msg, msg, SignalControl)() {
  if (!type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_message_type_support_handle.typesupport_identifier) {
    type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &type_msg__msg__SignalControl__rosidl_typesupport_introspection_c__SignalControl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
