// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from type_msg:msg/SignalControl.idl
// generated code does not contain a copyright notice

#ifndef TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__STRUCT_HPP_
#define TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__type_msg__msg__SignalControl __attribute__((deprecated))
#else
# define DEPRECATED__type_msg__msg__SignalControl __declspec(deprecated)
#endif

namespace type_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SignalControl_
{
  using Type = SignalControl_<ContainerAllocator>;

  explicit SignalControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->n_l = 0.0;
      this->n_r = 0.0;
    }
  }

  explicit SignalControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->n_l = 0.0;
      this->n_r = 0.0;
    }
  }

  // field types and members
  using _n_l_type =
    double;
  _n_l_type n_l;
  using _n_r_type =
    double;
  _n_r_type n_r;

  // setters for named parameter idiom
  Type & set__n_l(
    const double & _arg)
  {
    this->n_l = _arg;
    return *this;
  }
  Type & set__n_r(
    const double & _arg)
  {
    this->n_r = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    type_msg::msg::SignalControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const type_msg::msg::SignalControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<type_msg::msg::SignalControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<type_msg::msg::SignalControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      type_msg::msg::SignalControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<type_msg::msg::SignalControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      type_msg::msg::SignalControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<type_msg::msg::SignalControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<type_msg::msg::SignalControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<type_msg::msg::SignalControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__type_msg__msg__SignalControl
    std::shared_ptr<type_msg::msg::SignalControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__type_msg__msg__SignalControl
    std::shared_ptr<type_msg::msg::SignalControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SignalControl_ & other) const
  {
    if (this->n_l != other.n_l) {
      return false;
    }
    if (this->n_r != other.n_r) {
      return false;
    }
    return true;
  }
  bool operator!=(const SignalControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SignalControl_

// alias to use template instance with default allocator
using SignalControl =
  type_msg::msg::SignalControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace type_msg

#endif  // TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__STRUCT_HPP_
