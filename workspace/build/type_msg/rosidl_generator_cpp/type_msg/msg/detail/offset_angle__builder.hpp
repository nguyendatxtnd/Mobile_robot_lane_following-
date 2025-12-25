// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from type_msg:msg/OffsetAngle.idl
// generated code does not contain a copyright notice

#ifndef TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__BUILDER_HPP_
#define TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "type_msg/msg/detail/offset_angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace type_msg
{

namespace msg
{

namespace builder
{

class Init_OffsetAngle_angle
{
public:
  explicit Init_OffsetAngle_angle(::type_msg::msg::OffsetAngle & msg)
  : msg_(msg)
  {}
  ::type_msg::msg::OffsetAngle angle(::type_msg::msg::OffsetAngle::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::type_msg::msg::OffsetAngle msg_;
};

class Init_OffsetAngle_offset
{
public:
  Init_OffsetAngle_offset()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OffsetAngle_angle offset(::type_msg::msg::OffsetAngle::_offset_type arg)
  {
    msg_.offset = std::move(arg);
    return Init_OffsetAngle_angle(msg_);
  }

private:
  ::type_msg::msg::OffsetAngle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::type_msg::msg::OffsetAngle>()
{
  return type_msg::msg::builder::Init_OffsetAngle_offset();
}

}  // namespace type_msg

#endif  // TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__BUILDER_HPP_
