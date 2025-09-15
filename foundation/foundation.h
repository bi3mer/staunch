#pragma once

#ifndef _FOUNDATION_
#define _FOUNDATION_

#include <stdint.h>
#include <float.h>
#include "stdbool.h"

///////////////////////////////////////////////////////////////////////////////
//// types
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

///////////////////////////////////////////////////////////////////////////////
//// General Math
// Get minimum of a or b
#define f_min(a,b) (((a) < (b)) ? (a) : (b))
// Get maximum of a or b
#define f_max(a,b) (((a) < (b)) ? (a) : (b))
// Clamp value between min and max
#define f_clamp(min, value, max) \
    (((value) < (min)) ? (min) : \
     ((max) < (value)) ? (max) : \
     (value))

//-----------------------------------------------------------------------------
// I can't decide, but I feel like these macros are the wrong call, and I
// should, instead, implement each one for better type safety.
//-----------------------------------------------------------------------------

// Returns true if values are approximately similar, based on range for 32 bit float
extern bool f_approximately_f(const float a, const float b, const float range);
// Returns true if values are approximately similar, based on range for 32 bit double
extern bool f_approximately_d(const double a, const double b, const double range);

///////////////////////////////////////////////////////////////////////////////
//// linear_algebra.c
// Computes length of 2d vector with 32 bit float
extern float f_vec2f_length(const float vec[2]);
// Computes length of 2d vector with 64 bit double
extern double f_vec2d_length(const double vec[2]);
// Computes length of 3d vector with 32 bit float
extern float f_vec3f_length(const float vec[3]);
// Computes length of 3d vector with 64 bit double
extern double f_vec3d_length(const double vec[3]);


// Computes squared length of 2d vector with 32 bit float
extern float f_vec2f_length_squared(const float vec[2]);
// Computes squared length of 2d vector with 64 bit double
extern double f_vec2d_length_squared(const double vec[2]);
// Computes squared length of 3d vector with 32 bit float
extern float f_vec3f_length_squared(const float vec[3]);
// Computes squared length of 3d vector with 64 bit double
extern double f_vec3d_length_squared(const double vec[3]);

// Computes the dot product of 2d vector with 32 bit float
extern float f_vec2f_dot(const float vec1[2], const float vec2[2]);
// Computes the dot product of 2d vector with 64 bit double
extern double f_vec2d_dot(const double vec1[2], const double vec2[2]);
// Computes the dot product of 3d vector with 32 bit float
extern float f_vec3f_dot(const float vec1[3], const float vec2[3]);
// Computes the dot product of 3d vector with 64 bit double
extern double f_vec3d_dot(const double vec1[3], const float vec2[3]);

///////////////////////////////////////////////////////////////////////////////
//// random.c
//-----------------------------------------------------------------------------
// For this API, I'm trying to figure out whether I should do something global
// like you see with rand() or if I should make a struct like you see with more
// modern approaches. I'm leaning towards the more modern approach, which would
// mean that r_rand_seed() returns a struct. However, I find that approach very
// inconvenient when I'm programming. So... I can't make up my mind. Otherwise,
// the basic API for different number types is reasonable, I think.
//-----------------------------------------------------------------------------
// Seed random number generation
extern void f_rand_seed();

// generate random i8 between a minimum and maximum
extern i8 f_rand_i8(const i8 min, const i8 max);
// generate random i16 between a minimum and maximum
extern i16 f_rand_i16(const i16 min, const i16 max);
// generate random i32 between a minimum and maximum
extern i32 f_rand_i32(const i32 min, const i32 max);
// generate random i64 between a minimum and maximum
extern i64 f_rand_i64(const i64 min, const i64 max);

// generate random u8 between a minimum and maximum
extern u8 f_rand_u8(const u8 min, const u8 max);
// generate random u16 between a minimum and maximum
extern u16 f_rand_u16(const u16 min, const u16 max);
// generate random u32 between a minimum and maximum
extern u32 f_rand_u32(const u32 min, const u32 max);
// generate random u64 between a minimum and maximum
extern u64 f_rand_u64(const u64 min, const u64 max);

// generate random float between a minimum and maximum
extern float f_rand_f(const float min, const float max);
// generate random float between a 0 and 1
#define f_rand_f_01() f_rand_f(0.f, 1.f);
// generate random float between the minimum and maximum values of floats
#define f_rand_f_max() f_rand_f(-FLT_MAX, FLT_MAX)

// generate random double between a minimum and maximum
extern double f_rand_d(const double min, const double max);
// generate double float between a 0 and 1
#define f_rand_d_01() f_rand_f(0.0, 1.0);
// generate double float between the minimum and maximum values of floats
#define f_rand_d_max() f_rand_f(-DBL_MAX, DBL_MAX)

#endif