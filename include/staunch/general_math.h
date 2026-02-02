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
// Return square root of a 32 bit f32
#define s_sqrt_f32(n) sqrtf(n)
// Return square root of a 64 bit f64
#define s_sqrt_f64(n) sqrt(n)

/// Minimum
// Get minimum of a or b for 8 bit integer
extern i8 s_min_i8(const i8 a, const i8 b);
// Get minimum of a or b for 16 bit integer
extern i16 s_min_i16(const i16 a, const i16 b);
// Get minimum of a or b for 32 bit integer
extern i32 s_min_i32(const i32 a, const i32 b);
// Get minimum of a or b for 64 bit integer
extern i64 s_min_i64(const i64 a, const i64 b);

// Get minimum of a or b for 8 bit integer
extern u8 s_min_u8(const u8 a, const u8 b);
// Get uinimum of a or b for 16 bit integer
extern u16 s_min_u16(const u16 a, const u16 b);
// Get uinimum of a or b for 32 bit integer
extern u32 s_min_u32(const u32 a, const u32 b);
// Get minimum of a or b for 64 bit integer
extern u64 s_min_u64(const u64 a, const u64 b);

// get minimum of a or b for f32
extern f32 s_min_f32(const f32 a, const f32 b);
// get minimum of a or b for f64
extern f64 s_min_f64(const f64 a, const f64 b);

/// Maximum
// Get minimum of a or b for 8 bit integer
extern i8 s_max_i8(const i8 a, const i8 b);
// Get minimum of a or b for 16 bit integer
extern i16 s_max_i16(const i16 a, const i16 b);
// Get minimum of a or b for 32 bit integer
extern i32 s_max_i32(const i32 a, const i32 b);
// Get minimum of a or b for 64 bit integer
extern i64 s_max_i64(const i64 a, const i64 b);

// Get minimum of a or b for 8 bit integer
extern u8 s_max_u8(const u8 a, const u8 b);
// Get uinimum of a or b for 16 bit integer
extern u16 s_max_u16(const u16 a, const u16 b);
// Get uinimum of a or b for 32 bit integer
extern u32 s_max_u32(const u32 a, const u32 b);
// Get minimum of a or b for 64 bit integer
extern u64 s_max_u64(const u64 a, const u64 b);

// get minimum of a or b for f32
extern f32 s_max_f32(const f32 a, const f32 b);
// get minimum of a or b for f64
extern f64 s_max_f64(const f64 a, const f64 b);

/// Clamp
// clamp val between min and max for i8
extern i8 s_clamp_i8(const i8 min, const i8 val, const i8 max);
// clamp val between min and max for i16
extern i16 s_clamp_i16(const i16 min, const i16 val, const i16 max);
// clamp val between min and max for i32
extern i32 s_clamp_i32(const i32 min, const i32 val, const i32 max);
// clamp val between min and max for i64
extern i64 s_clamp_i64(const i64 min, const i64 val, const i64 max);

// clamp val between min and max for u8
extern u8 s_clamp_u8(const u8 min, const u8 val, const u8 max);
// clamp val between min and max for u16
extern u16 s_clamp_u16(const u16 min, const u16 val, const u16 max);
// clamp val between min and max for u32
extern u32 s_clamp_u32(const u32 min, const u32 val, const u32 max);
// clamp val between min and max for u64
extern u64 s_clamp_u64(const u64 min, const u64 val, const u64 max);

// clamp val between min and max for f32
extern f32 s_clamp_32(const f32 min, const f32 val, const f32 max);
// clamp val between min and max for f64
extern f64 s_clamp_f64(const f64 min, const f64 val, const f64 max);

/// approximately
// Returns true if values are approximately similar, based on range for 32 bit f32
extern bool s_approximately_f32(const f32 a, const f32 b, const f32 range);
// Returns true if values are approximately similar, based on range for 32 bit f64
extern bool s_approximately_f64(const f64 a, const f64 b, const f64 range);

/// in_between
// Checks if a i8 is in between two others (inclusive, inclusive)
extern bool s_in_between_i8(i16 min, i16 middle, i16 max);
// Checks if a i16 is in between two others (inclusive, inclusive)
extern bool s_in_between_i16(i16 min, i16 middle, i16 max);
// Checks if a i32 is in between two others (inclusive, inclusive)
extern bool s_in_between_i32(i32 min, i32 middle, i32 max);
// Checks if a i64 is in between two others (inclusive, inclusive)
extern bool s_in_between_i64(i64 min, i64 middle, i64 max);

// Checks if a u8 is in between two others (inclusive, inclusive)
extern bool s_in_between_u8(u8 min, u8 middle, u8 max);
// Checks if a u16 is in between two others (inclusive, inclusive)
extern bool s_in_between_u16(u16 min, u16 middle, u16 max);
// Checks if a u32 is in between two others (inclusive, inclusive)
extern bool s_in_between_u32(u32 min, u32 middle, u32 max);
// Checks if a u64 is in between two others (inclusive, inclusive)
extern bool s_in_between_u64(u64 min, u64 middle, u64 max);

/// modulus
// mathematically correct modulus that can handle negative values for i8
extern i8 s_modulus_i8(i8 number, i8 divisor);
// mathematically correct modulus that can handle negative values for i16
extern i16 s_modulus_i16(i16 number, i16 divisor);
// mathematically correct modulus that can handle negative values for i32
extern i32 s_modulus_i32(i32 number, i32 divisor);
// mathematically correct modulus that can handle negative values for i64
extern i64 s_modulus_i64(i64 number, i64 divisor);

#endif // _STAUNCH_GENERAL_MATH_
