#include "foundation.h"

///////////////////////////////////////////////////////////////////////////////
// Length
float f_vec2f_length(const float vec[2])
{
    return f_sqrt_f(vec[0]*vec[0] + vec[1]*vec[1]);
}

double f_vec2d_length(const double vec[2])
{
    return f_sqrt_d(vec[0]*vec[0] + vec[1]*vec[1]);
}

float f_vec3f_length(const float vec[3])
{
    return f_sqrt_f(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}

double f_vec3d_length(const double vec[3])
{
    return f_sqrt_d(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}

///////////////////////////////////////////////////////////////////////////////
// Dot product
float f_vec2f_dot(const float vec[2])
{
    return vec[0]*vec[0] + vec[1]*vec[1];
}

double f_vec2d_dot(const double vec[2])
{
    return vec[0]*vec[0] + vec[1]*vec[1];
}

float f_vec3f_dot(const float vec[3])
{
    return vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
}

double f_vec3d_dot(const double vec[3])
{
    return vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
}