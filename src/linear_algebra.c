#include "staunch/linear_algebra.h"
#include "staunch/general_math.h"

///////////////////////////////////////////////////////////////////////////////
// Length
f32 s_vec2_length_f32(const f32 vec[2])
{
    return s_sqrt_f32(vec[0] * vec[0] + vec[1] * vec[1]);
}
f64 s_vec2_length_f64(const f64 vec[2])
{
    return s_sqrt_f64(vec[0] * vec[0] + vec[1] * vec[1]);
}
f32 s_vec3_length_f32(const f32 vec[3])
{
    return s_sqrt_f32(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}
f64 s_vec3_length_f64(const f64 vec[3])
{
    return s_sqrt_f64(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

///////////////////////////////////////////////////////////////////////////////
// Length squared of a vector
f32 s_vec2_length_squared_f32(const f32 vec[2])
{
    return vec[0] * vec[0] + vec[1] * vec[1];
}
f64 s_vec2_length_squared_f64(const f64 vec[2])
{
    return vec[0] * vec[0] + vec[1] * vec[1];
}
f32 s_vec3_length_squared_f32(const f32 vec[3])
{
    return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
}
f64 s_vec3_length_squared_f64(const f64 vec[3])
{
    return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
}

///////////////////////////////////////////////////////////////////////////////
// Dot product
f32 s_vec2_dot_f32(const f32 vec1[2], const f32 vec2[2])
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1];
}
f64 s_vec2_dot_f64(const f64 vec1[2], const f64 vec2[2])
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1];
}
f32 s_vec3_dot_f32(const f32 vec1[3], const f32 vec2[3])
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}
f64 s_vec3_dot_f64(const f64 vec1[3], const f64 vec2[3])
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}
