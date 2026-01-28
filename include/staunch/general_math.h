#ifndef _STAUNCH_GENERAL_MATH_
#define _STAUNCH_GENERAL_MATH_

#include "types.h"

#include <math.h>
#include <stdbool.h>

/// square root
// ----------------------------------------------------------------------------
// @NOTE: There is a good chance I end up replacing sqrt, which is why I have
//        added a wrapper
// ----------------------------------------------------------------------------
// Return square root of a 32 bit float
#define f_sqrt_f(n) sqrtf(n)
// Return square root of a 64 bit double
#define f_sqrt_d(n) sqrt(n)

/// Minimum
// Get minimum of a or b for 8 bit integer
extern i8 f_min_i8(const i8 a, const i8 b);
// Get minimum of a or b for 16 bit integer
extern i16 f_min_i16(const i16 a, const i16 b);
// Get minimum of a or b for 32 bit integer
extern i32 f_min_i32(const i32 a, const i32 b);
// Get minimum of a or b for 64 bit integer
extern i64 f_min_i64(const i64 a, const i64 b);

// Get minimum of a or b for 8 bit integer
extern u8 f_min_u8(const u8 a, const u8 b);
// Get uinimum of a or b for 16 bit integer
extern u16 f_min_u16(const u16 a, const u16 b);
// Get uinimum of a or b for 32 bit integer
extern u32 f_min_u32(const u32 a, const u32 b);
// Get minimum of a or b for 64 bit integer
extern u64 f_min_u64(const u64 a, const u64 b);

// get minimum of a or b for float
extern float f_min_f(const float a, const float b);
// get minimum of a or b for double
extern double f_min_d(const double a, const double b);

/// Maximum
// Get minimum of a or b for 8 bit integer
extern i8 f_max_i8(const i8 a, const i8 b);
// Get minimum of a or b for 16 bit integer
extern i16 f_max_i16(const i16 a, const i16 b);
// Get minimum of a or b for 32 bit integer
extern i32 f_max_i32(const i32 a, const i32 b);
// Get minimum of a or b for 64 bit integer
extern i64 f_max_i64(const i64 a, const i64 b);

// Get minimum of a or b for 8 bit integer
extern u8 f_max_u8(const u8 a, const u8 b);
// Get uinimum of a or b for 16 bit integer
extern u16 f_max_u16(const u16 a, const u16 b);
// Get uinimum of a or b for 32 bit integer
extern u32 f_max_u32(const u32 a, const u32 b);
// Get minimum of a or b for 64 bit integer
extern u64 f_max_u64(const u64 a, const u64 b);

// get minimum of a or b for float
extern float f_max_f(const float a, const float b);
// get minimum of a or b for double
extern double f_max_d(const double a, const double b);

/// Clamp
// clamp val between min and max for i8
extern i8 f_clamp_i8(const i8 min, const i8 val, const i8 max);
// clamp val between min and max for i16
extern i16 f_clamp_i16(const i16 min, const i16 val, const i16 max);
// clamp val between min and max for i32
extern i32 f_clamp_i32(const i32 min, const i32 val, const i32 max);
// clamp val between min and max for i64
extern i64 f_clamp_i64(const i64 min, const i64 val, const i64 max);

// clamp val between min and max for u8
extern u8 f_clamp_u8(const u8 min, const u8 val, const u8 max);
// clamp val between min and max for u16
extern u16 f_clamp_u16(const u16 min, const u16 val, const u16 max);
// clamp val between min and max for u32
extern u32 f_clamp_u32(const u32 min, const u32 val, const u32 max);
// clamp val between min and max for u64
extern u64 f_clamp_u64(const u64 min, const u64 val, const u64 max);

// clamp val between min and max for float
extern float f_clamp_f(const float min, const float val, const float max);
// clamp val between min and max for double
extern double s_clamp_f64(const double min, const double val, const double max);

/// approximately
// Returns true if values are approximately similar, based on range for 32 bit float
extern bool f_approximately_f(const float a, const float b, const float range);
// Returns true if values are approximately similar, based on range for 32 bit double
extern bool f_approximately_d(const double a, const double b, const double range);

/// in_between
// Checks if a i8 is in between two others (inclusive, inclusive)
extern bool f_in_between_i8(i16 min, i16 middle, i16 max);
// Checks if a i16 is in between two others (inclusive, inclusive)
extern bool f_in_between_i16(i16 min, i16 middle, i16 max);
// Checks if a i32 is in between two others (inclusive, inclusive)
extern bool f_in_between_i32(i32 min, i32 middle, i32 max);
// Checks if a i64 is in between two others (inclusive, inclusive)
extern bool f_in_between_i64(i64 min, i64 middle, i64 max);

// Checks if a u8 is in between two others (inclusive, inclusive)
extern bool f_in_between_u8(u8 min, u8 middle, u8 max);
// Checks if a u16 is in between two others (inclusive, inclusive)
extern bool f_in_between_u16(u16 min, u16 middle, u16 max);
// Checks if a u32 is in between two others (inclusive, inclusive)
extern bool f_in_between_u32(u32 min, u32 middle, u32 max);
// Checks if a u64 is in between two others (inclusive, inclusive)
extern bool f_in_between_u64(u64 min, u64 middle, u64 max);

/// modulus
// mathematically correct modulus that can handle negative values for i8
extern i8 f_modulus_i8(i8 number, i8 divisor);
// mathematically correct modulus that can handle negative values for i16
extern i16 f_modulus_i16(i16 number, i16 divisor);
// mathematically correct modulus that can handle negative values for i32
extern i32 f_modulus_i32(i32 number, i32 divisor);
// mathematically correct modulus that can handle negative values for i64
extern i64 f_modulus_i64(i64 number, i64 divisor);

#endif // _STAUNCH_GENERAL_MATH_
