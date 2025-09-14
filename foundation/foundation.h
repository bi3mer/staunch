#pragma once

#ifndef _FOUNDATION_
#define _FOUNDATION_

#include "stdbool.h"

///////////////////////////////////////////////////////////////////////////////
// types
#if defined _WIN32
typedef unsigned int uint;
#else
#include <sys/types.h>
#endif

///////////////////////////////////////////////////////////////////////////////
/// General Math
// Returns true if values are approximately similar, based on range for 32 bit float
extern bool f_approximately_f(const float a, const float b, const float range);
// Returns true if values are approximately similar, based on range for 32 bit double
extern bool f_approximately_d(const double a, const double b, const double range);
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

// Computes the dot product of 2d vector with 32 bit float
extern float f_vec2f_dot(const float vec1[2], const float vec2[2]);
// Computes the dot product of 2d vector with 64 bit double
extern double f_vec2d_dot(const double vec1[2], const double vec2[2]);
// Computes the dot product of 3d vector with 32 bit float
extern float f_vec3f_dot(const float vec1[3], const float vec2[3]);
// Computes the dot product of 3d vector with 64 bit double
extern double f_vec3d_dot(const double vec1[3], const float vec2[3]);

#endif