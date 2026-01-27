#ifndef _STAUNCH_LINEAR_ALGEBRA_
#define _STAUNCH_LINEAR_ALGEBRA_

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

#endif // _STAUNCH_LINEAR_ALGEBRA_
