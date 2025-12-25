// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from type_msg:msg/OffsetAngle.idl
// generated code does not contain a copyright notice
#include "type_msg/msg/detail/offset_angle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
type_msg__msg__OffsetAngle__init(type_msg__msg__OffsetAngle * msg)
{
  if (!msg) {
    return false;
  }
  // offset
  // angle
  return true;
}

void
type_msg__msg__OffsetAngle__fini(type_msg__msg__OffsetAngle * msg)
{
  if (!msg) {
    return;
  }
  // offset
  // angle
}

bool
type_msg__msg__OffsetAngle__are_equal(const type_msg__msg__OffsetAngle * lhs, const type_msg__msg__OffsetAngle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // offset
  if (lhs->offset != rhs->offset) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  return true;
}

bool
type_msg__msg__OffsetAngle__copy(
  const type_msg__msg__OffsetAngle * input,
  type_msg__msg__OffsetAngle * output)
{
  if (!input || !output) {
    return false;
  }
  // offset
  output->offset = input->offset;
  // angle
  output->angle = input->angle;
  return true;
}

type_msg__msg__OffsetAngle *
type_msg__msg__OffsetAngle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  type_msg__msg__OffsetAngle * msg = (type_msg__msg__OffsetAngle *)allocator.allocate(sizeof(type_msg__msg__OffsetAngle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(type_msg__msg__OffsetAngle));
  bool success = type_msg__msg__OffsetAngle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
type_msg__msg__OffsetAngle__destroy(type_msg__msg__OffsetAngle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    type_msg__msg__OffsetAngle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
type_msg__msg__OffsetAngle__Sequence__init(type_msg__msg__OffsetAngle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  type_msg__msg__OffsetAngle * data = NULL;

  if (size) {
    data = (type_msg__msg__OffsetAngle *)allocator.zero_allocate(size, sizeof(type_msg__msg__OffsetAngle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = type_msg__msg__OffsetAngle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        type_msg__msg__OffsetAngle__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
type_msg__msg__OffsetAngle__Sequence__fini(type_msg__msg__OffsetAngle__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      type_msg__msg__OffsetAngle__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

type_msg__msg__OffsetAngle__Sequence *
type_msg__msg__OffsetAngle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  type_msg__msg__OffsetAngle__Sequence * array = (type_msg__msg__OffsetAngle__Sequence *)allocator.allocate(sizeof(type_msg__msg__OffsetAngle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = type_msg__msg__OffsetAngle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
type_msg__msg__OffsetAngle__Sequence__destroy(type_msg__msg__OffsetAngle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    type_msg__msg__OffsetAngle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
type_msg__msg__OffsetAngle__Sequence__are_equal(const type_msg__msg__OffsetAngle__Sequence * lhs, const type_msg__msg__OffsetAngle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!type_msg__msg__OffsetAngle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
type_msg__msg__OffsetAngle__Sequence__copy(
  const type_msg__msg__OffsetAngle__Sequence * input,
  type_msg__msg__OffsetAngle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(type_msg__msg__OffsetAngle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    type_msg__msg__OffsetAngle * data =
      (type_msg__msg__OffsetAngle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!type_msg__msg__OffsetAngle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          type_msg__msg__OffsetAngle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!type_msg__msg__OffsetAngle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
