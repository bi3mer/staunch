#ifndef _STAUNCH_TYPES_
#define _STAUNCH_TYPES_

#include <stddef.h>
#include <stdint.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef size_t st;

#define MAX_U8 255

#define POINT64_ZERO_EPSILON 1e-9
#define POINT32_ZERO_EPSILON 1e-6f

#endif // _STAUNCH_TYPES_
