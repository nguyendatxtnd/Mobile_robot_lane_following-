// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from type_msg:msg/OffsetAngle.idl
// generated code does not contain a copyright notice

#ifndef TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__STRUCT_HPP_
#define TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__type_msg__msg__OffsetAngle __attribute__((deprecated))
#else
# define DEPRECATED__type_msg__msg__OffsetAngle __declspec(deprecated)
#endif

namespace type_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OffsetAngle_
{
  using Type = OffsetAngle_<ContainerAllocator>;

  explicit OffsetAngle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->offset = 0.0;
      this->angle = 0.0;
    }
  }

  explicit OffsetAngle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->offset = 0.0;
      this->angle = 0.0;
    }
  }

  // field types and members
  using _offset_type =
    double;
  _offset_type offset;
  using _angle_type =
    double;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__offset(
    const double & _arg)
  {
    this->offset = _arg;
    return *this;
  }
  Type & set__angle(
    const double & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    type_msg::msg::OffsetAngle_<ContainerAllocator> *;
  using ConstRawPtr =
    const type_msg::msg::OffsetAngle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<type_msg::msg::OffsetAngle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<type_msg::msg::OffsetAngle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      type_msg::msg::OffsetAngle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<type_msg::msg::OffsetAngle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      type_msg::msg::OffsetAngle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<type_msg::msg::OffsetAngle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<type_msg::msg::OffsetAngle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<type_msg::msg::OffsetAngle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__type_msg__msg__OffsetAngle
    std::shared_ptr<type_msg::msg::OffsetAngle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__type_msg__msg__OffsetAngle
    std::shared_ptr<type_msg::msg::OffsetAngle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OffsetAngle_ & other) const
  {
    if (this->offset != other.offset) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const OffsetAngle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OffsetAngle_

// alias to use template instance with default allocator
using OffsetAngle =
  type_msg::msg::OffsetAngle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace type_msg

#endif  // TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__STRUCT_HPP_
