#pragma once

#ifndef _FOUNDATION_
#define _FOUNDATION_

///////////////////////////////////////////////////////////////////////////////
/// General Math
// Computes square root of a 32 bit float
extern float f_sqrt_f(const float);
// Computes square root of a 64 bit double
extern double f_sqrt_d(const double);

///////////////////////////////////////////////////////////////////////////////
/// Linear Algebra
// Computes length of 2d vector with 32 bit float
extern float f_vec2f_length(const float vec[2]);
// Computes length of 2d vector with 64 bit double
extern double f_vec2d_length(const double vec[2]);
// Computes length of 3d vector with 32 bit float
extern float f_vec3f_length(const float vec[3]);
// Computes length of 3d vector with 64 bit double
extern double f_vec3d_length(const double vec[3]);

// Computes dot product of 2d vector with 32 bit float
extern float f_vec2f_dot(const float vec[2]);
// Computes dot product of 2d vector with 64 bit double
extern double f_vec2d_dot(const double vec[2]);
// Computes dot product of 3d vector with 32 bit float
extern float f_vec3f_dot(const float vec[3]);
// Computes dot product of 3d vector with 64 bit double
extern double f_vec3d_dot(const double vec[3]);

#endif