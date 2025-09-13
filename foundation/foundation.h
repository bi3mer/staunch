#pragma once

#ifndef _FOUNDATION_
#define _FOUNDATION_

///////////////////////////////////////////////////////////////////////////////
/// Structs
typedef struct Vec2i {
    int x,y;
} Vec2i;

typedef struct Vec2f {
    float x,y;
} Vec2f;

typedef struct Vec2d {
    double x,y;
} Vec2d;

///////////////////////////////////////////////////////////////////////////////
/// General Math
extern float f_sqrt_f(const float);
extern double d_sqrt_d(const double);

/// Linear Algebra
extern float f_vec_length_2f(const float*);

#endif