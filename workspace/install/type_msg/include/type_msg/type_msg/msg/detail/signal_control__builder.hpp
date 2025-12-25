// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from type_msg:msg/SignalControl.idl
// generated code does not contain a copyright notice

#ifndef TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__BUILDER_HPP_
#define TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "type_msg/msg/detail/signal_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace type_msg
{

namespace msg
{

namespace builder
{

class Init_SignalControl_n_r
{
public:
  explicit Init_SignalControl_n_r(::type_msg::msg::SignalControl & msg)
  : msg_(msg)
  {}
  ::type_msg::msg::SignalControl n_r(::type_msg::msg::SignalControl::_n_r_type arg)
  {
    msg_.n_r = std::move(arg);
    return std::move(msg_);
  }

private:
  ::type_msg::msg::SignalControl msg_;
};

class Init_SignalControl_n_l
{
public:
  Init_SignalControl_n_l()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SignalControl_n_r n_l(::type_msg::msg::SignalControl::_n_l_type arg)
  {
    msg_.n_l = std::move(arg);
    return Init_SignalControl_n_r(msg_);
  }

private:
  ::type_msg::msg::SignalControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::type_msg::msg::SignalControl>()
{
  return type_msg::msg::builder::Init_SignalControl_n_l();
}

}  // namespace type_msg

#endif  // TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__BUILDER_HPP_
