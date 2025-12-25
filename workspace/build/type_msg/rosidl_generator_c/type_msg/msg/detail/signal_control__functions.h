// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from type_msg:msg/SignalControl.idl
// generated code does not contain a copyright notice

#ifndef TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__FUNCTIONS_H_
#define TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "type_msg/msg/rosidl_generator_c__visibility_control.h"

#include "type_msg/msg/detail/signal_control__struct.h"

/// Initialize msg/SignalControl message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * type_msg__msg__SignalControl
 * )) before or use
 * type_msg__msg__SignalControl__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__SignalControl__init(type_msg__msg__SignalControl * msg);

/// Finalize msg/SignalControl message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
void
type_msg__msg__SignalControl__fini(type_msg__msg__SignalControl * msg);

/// Create msg/SignalControl message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * type_msg__msg__SignalControl__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
type_msg__msg__SignalControl *
type_msg__msg__SignalControl__create();

/// Destroy msg/SignalControl message.
/**
 * It calls
 * type_msg__msg__SignalControl__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
void
type_msg__msg__SignalControl__destroy(type_msg__msg__SignalControl * msg);

/// Check for msg/SignalControl message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__SignalControl__are_equal(const type_msg__msg__SignalControl * lhs, const type_msg__msg__SignalControl * rhs);

/// Copy a msg/SignalControl message.
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
type_msg__msg__SignalControl__copy(
  const type_msg__msg__SignalControl * input,
  type_msg__msg__SignalControl * output);

/// Initialize array of msg/SignalControl messages.
/**
 * It allocates the memory for the number of elements and calls
 * type_msg__msg__SignalControl__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__SignalControl__Sequence__init(type_msg__msg__SignalControl__Sequence * array, size_t size);

/// Finalize array of msg/SignalControl messages.
/**
 * It calls
 * type_msg__msg__SignalControl__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
void
type_msg__msg__SignalControl__Sequence__fini(type_msg__msg__SignalControl__Sequence * array);

/// Create array of msg/SignalControl messages.
/**
 * It allocates the memory for the array and calls
 * type_msg__msg__SignalControl__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
type_msg__msg__SignalControl__Sequence *
type_msg__msg__SignalControl__Sequence__create(size_t size);

/// Destroy array of msg/SignalControl messages.
/**
 * It calls
 * type_msg__msg__SignalControl__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
void
type_msg__msg__SignalControl__Sequence__destroy(type_msg__msg__SignalControl__Sequence * array);

/// Check for msg/SignalControl message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_type_msg
bool
type_msg__msg__SignalControl__Sequence__are_equal(const type_msg__msg__SignalControl__Sequence * lhs, const type_msg__msg__SignalControl__Sequence * rhs);

/// Copy an array of msg/SignalControl messages.
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
type_msg__msg__SignalControl__Sequence__copy(
  const type_msg__msg__SignalControl__Sequence * input,
  type_msg__msg__SignalControl__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TYPE_MSG__MSG__DETAIL__SIGNAL_CONTROL__FUNCTIONS_H_
