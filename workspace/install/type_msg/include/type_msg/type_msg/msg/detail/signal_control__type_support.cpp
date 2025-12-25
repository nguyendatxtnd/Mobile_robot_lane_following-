// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from type_msg:msg/SignalControl.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "type_msg/msg/detail/signal_control__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace type_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SignalControl_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) type_msg::msg::SignalControl(_init);
}

void SignalControl_fini_function(void * message_memory)
{
  auto typed_message = static_cast<type_msg::msg::SignalControl *>(message_memory);
  typed_message->~SignalControl();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SignalControl_message_member_array[2] = {
  {
    "n_l",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(type_msg::msg::SignalControl, n_l),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "n_r",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(type_msg::msg::SignalControl, n_r),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SignalControl_message_members = {
  "type_msg::msg",  // message namespace
  "SignalControl",  // message name
  2,  // number of fields
  sizeof(type_msg::msg::SignalControl),
  SignalControl_message_member_array,  // message members
  SignalControl_init_function,  // function to initialize message memory (memory has to be allocated)
  SignalControl_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SignalControl_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SignalControl_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace type_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<type_msg::msg::SignalControl>()
{
  return &::type_msg::msg::rosidl_typesupport_introspection_cpp::SignalControl_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, type_msg, msg, SignalControl)() {
  return &::type_msg::msg::rosidl_typesupport_introspection_cpp::SignalControl_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
