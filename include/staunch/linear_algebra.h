#ifndef _STAUNCH_LINEAR_ALGEBRA_
#define _STAUNCH_LINEAR_ALGEBRA_

#include "staunch/types.h"

// Computes length of 2d vector with 32 bit f32
extern f32 s_vec2_length_f32(const f32 vec[2]);
// Computes length of 2d vector with 64 bit f64
extern f64 s_vec2_length_f64(const f64 vec[2]);
// Computes length of 3d vector with 32 bit f32
extern f32 s_vec3_length_f32(const f32 vec[3]);
// Computes length of 3d vector with 64 bit f64
extern f64 s_vec3_length_f64(const f64 vec[3]);

// Computes squared length of 2d vector with 32 bit f32
extern f32 s_vec2_length_squared_f32(const f32 vec[2]);
// Computes squared length of 2d vector with 64 bit f64
extern f64 s_vec2_length_squared_f64(const f64 vec[2]);
// Computes squared length of 3d vector with 32 bit f32
extern f32 s_vec3_length_squared_f32(const f32 vec[3]);
// Computes squared length of 3d vector with 64 bit f64
extern f64 s_vec3_length_squared_f64(const f64 vec[3]);

// Computes the dot product of 2d vector with 32 bit f32
extern f32 s_vec2_dot_f32(const f32 vec1[2], const f32 vec2[2]);
// Computes the dot product of 2d vector with 64 bit f64
extern f64 s_vec2_dot_f64(const f64 vec1[2], const f64 vec2[2]);
// Computes the dot product of 3d vector with 32 bit f32
extern f32 s_vec3_dot_f32(const f32 vec1[3], const f32 vec2[3]);
// Computes the dot product of 3d vector with 64 bit f64
extern f64 s_vec3_dot_f64(const f64 vec1[3], const f64 vec2[3]);

#endif // _STAUNCH_LINEAR_ALGEBRA_
