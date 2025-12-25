// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from type_msg:msg/OffsetAngle.idl
// generated code does not contain a copyright notice

#ifndef TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__STRUCT_H_
#define TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/OffsetAngle in the package type_msg.
typedef struct type_msg__msg__OffsetAngle
{
  double offset;
  double angle;
} type_msg__msg__OffsetAngle;

// Struct for a sequence of type_msg__msg__OffsetAngle.
typedef struct type_msg__msg__OffsetAngle__Sequence
{
  type_msg__msg__OffsetAngle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} type_msg__msg__OffsetAngle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__STRUCT_H_
