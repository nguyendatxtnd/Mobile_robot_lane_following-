// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from type_msg:msg/SignalControl.idl
// generated code does not contain a copyright notice

#ifndef TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__TRAITS_HPP_
#define TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "type_msg/msg/detail/signal_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace type_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const SignalControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: n_l
  {
    out << "n_l: ";
    rosidl_generator_traits::value_to_yaml(msg.n_l, out);
    out << ", ";
  }

  // member: n_r
  {
    out << "n_r: ";
    rosidl_generator_traits::value_to_yaml(msg.n_r, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SignalControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: n_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "n_l: ";
    rosidl_generator_traits::value_to_yaml(msg.n_l, out);
    out << "\n";
  }

  // member: n_r
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "n_r: ";
    rosidl_generator_traits::value_to_yaml(msg.n_r, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SignalControl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace type_msg

namespace rosidl_generator_traits
{

[[deprecated("use type_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const type_msg::msg::SignalControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  type_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use type_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const type_msg::msg::SignalControl & msg)
{
  return type_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<type_msg::msg::SignalControl>()
{
  return "type_msg::msg::SignalControl";
}

template<>
inline const char * name<type_msg::msg::SignalControl>()
{
  return "type_msg/msg/SignalControl";
}

template<>
struct has_fixed_size<type_msg::msg::SignalControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<type_msg::msg::SignalControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<type_msg::msg::SignalControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__TRAITS_HPP_
