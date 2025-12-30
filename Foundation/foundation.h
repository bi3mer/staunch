#pragma once

#include <stdlib.h>
#ifndef _FOUNDATION_
#define _FOUNDATION_

#include <float.h>
#include <math.h> // sqrt and sqrt_f
#include <stdbool.h>
#include <stdint.h>

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

#define F_PI 3.14159265359

typedef struct
{
    struct
    {
        double x, y;
    } p;

    double arr[2];
} Point_d;

// typedef struct
// {
//     struct
//     {
//         float x, y;
//     } p;

//     float arr[2];
// } Point_f;

///////////////////////////////////////////////////////////////////////////////
//// General Math
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
extern double f_clamp_d(const double min, const double val, const double max);

/// approximately
// Returns true if values are approximately similar, based on range for 32 bit float
extern bool f_approximately_f(const float a, const float b, const float range);
// Returns true if values are approximately similar, based on range for 32 bit double
extern bool f_approximately_d(const double a, const double b, const double range);

/// in_between
// Checks if a i8 is in between two othes
extern bool f_in_between_i8(i16 min, i16 middle, i16 max);
// Checks if a i16 is in between two othes
extern bool f_in_between_i16(i16 min, i16 middle, i16 max);
// Checks if a i32 is in between two othes
extern bool f_in_between_i32(i32 min, i32 middle, i32 max);
// Checks if a i64 is in between two othes
extern bool f_in_between_i64(i64 min, i64 middle, i64 max);

// Checks if a u8 is in between two othes
extern bool f_in_between_u8(u16 min, u16 middle, u16 max);
// Checks if a u16 is in between two othes
extern bool f_in_between_u16(u16 min, u16 middle, u16 max);
// Checks if a u32 is in between two othes
extern bool f_in_between_u32(u32 min, u32 middle, u32 max);
// Checks if a u64 is in between two othes
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

///////////////////////////////////////////////////////////////////////////////
//// geometry.c
extern bool f_circle_intersect_d(const Point_d p1, const double r1, const Point_d p2,
                                 const double r2);

///////////////////////////////////////////////////////////////////////////////
//// linear_algebra.c
/// @TODO: use point_f and point_d
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
extern void f_rand_init(i64 seed);

// generate random bool (true or false)
extern bool f_rand_bool(void);

// generate random i8 between a minimum and maximum
extern i8 f_rand_i8(const i8 min, const i8 max);
// generate random i16 between a minimum and maximum
extern i16 f_rand_i16(const i16 min, const i16 max);
// generate random i32 between a minimum and maximum
extern i32 f_rand_i32(const i32 min, const i32 max);
// generate random i64 between a minimum and maximum
extern i64 f_rand_i64(const i64 min, const i64 max);

// generate random u8 between a minimum (inclusive) and maximum (exclusive)
extern u8 f_rand_u8(const u8 min, const u8 max);
// generate random u16 between a minimum (inclusive) and maximum (exclusive)
extern u16 f_rand_u16(const u16 min, const u16 max);
// generate random 32 between a minimum (inclusive) and maximum (exclusive)
extern u32 f_rand_u32(const u32 min, const u32 max);
// generate random u64 between a minimum (inclusive) and maximum (exclusive)
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
#define f_rand_d_01() f_rand_d(0.0, 1.0);
// generate double float between the minimum and maximum values of floats
#define f_rand_d_max() f_rand_f(-DBL_MAX, DBL_MAX)

///////////////////////////////////////////////////////////////////////////////
//// point.c
//-----------------------------------------------------------------------------
// This contains different point types but all with the same API
//-----------------------------------------------------------------------------
extern void point_d_clone(const Point_d *p, Point_d *out);
extern bool point_d_equals(const Point_d *a, const Point_d *b, const double range);

extern Point_d point_d_random(const double min, const double max);
extern void point_d_random_in(const double min, const double max, Point_d *out);

extern double point_d_magnitude(const Point_d *p);

extern Point_d point_d_divide(const Point_d *p, const double divisor);
extern void point_d_divide_in(const Point_d *p, const double divisor, Point_d *out);

extern Point_d point_d_multiply(const Point_d *p, const double scale);
extern void point_d_multiply_in(const Point_d *p, const double scale, Point_d *out);

extern Point_d point_d_add(const Point_d *a, const Point_d *b);
extern void point_d_add_in(Point_d *p_modified, const Point_d *p_added);
extern void point_d_add_with_scale_in(Point_d *p_modified, const Point_d *p_added,
                                      const double scale);

extern Point_d point_d_subtract(const Point_d *p1, const Point_d *p2);
extern void point_d_subtract_in(Point_d *p_modified, const Point_d *p_added);
extern void point_d_subtract_with_scale_in(Point_d *p_modified, const Point_d *p_added,
                                           const double scale);

#endif
