// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from type_msg:msg/OffsetAngle.idl
// generated code does not contain a copyright notice

#ifndef TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__FUNCTIONS_H_
#define TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "type_msg/msg/rosidl_generator_c__visibility_control.h"

#include "type_msg/msg/detail/offset_angle__struct.h"

/// Initialize msg/OffsetAngle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * type_msg__msg__OffsetAngle
 * )) before or use
 * type_msg__msg__OffsetAngle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__OffsetAngle__init(type_msg__msg__OffsetAngle * msg);

/// Finalize msg/OffsetAngle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
void
type_msg__msg__OffsetAngle__fini(type_msg__msg__OffsetAngle * msg);

/// Create msg/OffsetAngle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * type_msg__msg__OffsetAngle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
type_msg__msg__OffsetAngle *
type_msg__msg__OffsetAngle__create();

/// Destroy msg/OffsetAngle message.
/**
 * It calls
 * type_msg__msg__OffsetAngle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
void
type_msg__msg__OffsetAngle__destroy(type_msg__msg__OffsetAngle * msg);

/// Check for msg/OffsetAngle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__OffsetAngle__are_equal(const type_msg__msg__OffsetAngle * lhs, const type_msg__msg__OffsetAngle * rhs);

/// Copy a msg/OffsetAngle message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__OffsetAngle__copy(
  const type_msg__msg__OffsetAngle * input,
  type_msg__msg__OffsetAngle * output);

/// Initialize array of msg/OffsetAngle messages.
/**
 * It allocates the memory for the number of elements and calls
 * type_msg__msg__OffsetAngle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__OffsetAngle__Sequence__init(type_msg__msg__OffsetAngle__Sequence * array, size_t size);

/// Finalize array of msg/OffsetAngle messages.
/**
 * It calls
 * type_msg__msg__OffsetAngle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
void
type_msg__msg__OffsetAngle__Sequence__fini(type_msg__msg__OffsetAngle__Sequence * array);

/// Create array of msg/OffsetAngle messages.
/**
 * It allocates the memory for the array and calls
 * type_msg__msg__OffsetAngle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
type_msg__msg__OffsetAngle__Sequence *
type_msg__msg__OffsetAngle__Sequence__create(size_t size);

/// Destroy array of msg/OffsetAngle messages.
/**
 * It calls
 * type_msg__msg__OffsetAngle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
void
type_msg__msg__OffsetAngle__Sequence__destroy(type_msg__msg__OffsetAngle__Sequence * array);

/// Check for msg/OffsetAngle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__OffsetAngle__Sequence__are_equal(const type_msg__msg__OffsetAngle__Sequence * lhs, const type_msg__msg__OffsetAngle__Sequence * rhs);

/// Copy an array of msg/OffsetAngle messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__OffsetAngle__Sequence__copy(
  const type_msg__msg__OffsetAngle__Sequence * input,
  type_msg__msg__OffsetAngle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TYPE_MSG__MSG__DETAIL__OFFSET_ANGLE__FUNCTIONS_H_
