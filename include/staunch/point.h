#ifndef _STAUNCH_POINT_
#define _STAUNCH_POINT_
#include "staunch/types.h"
#include <stdbool.h>

typedef struct
{
    union
    {
        struct
        {
            f64 x, y;
        };
        f64 arr[2];
    };
} Point64;

typedef struct
{
    union
    {
        struct
        {
            f32 x, y;
        };
        f32 arr[2];
    };
} Point32;

// Point64 functions

// Copies the values of p into out
extern void s_point64_clone(const Point64 *p, Point64 *out);

// Returns true if a and b are within range of each other for both components
extern bool s_point64_equals(const Point64 *a, const Point64 *b, const f64 range);

// Returns a point with x=0 and y=0
extern Point64 s_point64_zero(void);

// Returns true if both x and y are within POINT64_ZERO_EPSILON of 0
extern bool s_point64_is_zero(const Point64 *p);

// Sets both x and y of p to 0
extern void s_point64_zero_out(Point64 *p);

// Returns a point with random x and y values between min and max
extern Point64 s_point64_random(const f64 min, const f64 max);

// Sets out to a point with random x and y values between min and max
extern void s_point64_random_out(const f64 min, const f64 max, Point64 *out);

// Returns the length of the vector: sqrt(x*x + y*y)
extern f64 s_point64_magnitude(const Point64 *p);

// Returns the squared length of the vector: x*x + y*y
extern f64 s_point64_magnitude_squared(const Point64 *p);

// Returns a unit vector in the same direction as p
extern Point64 s_point64_normalize(const Point64 *p);

// Normalizes p in place to a unit vector
extern void s_point64_normalize_in(Point64 *p);

// Returns p divided by divisor
extern Point64 s_point64_divide(const Point64 *p, const f64 divisor);

// Divides p by divisor in place
extern void s_point64_divide_in(Point64 *p, const f64 divisor);

// Returns p multiplied by scale
extern Point64 s_point64_scale(const Point64 *p, const f64 scale);

// Multiplies p by scale in place
extern void s_point64_scale_in(Point64 *p, const f64 scale);

// Returns the sum of a and b
extern Point64 s_point64_add(const Point64 *a, const Point64 *b);

// Adds p_added to p_modified in place
extern void s_point64_add_in(Point64 *p_modified, const Point64 *p_added);

// Adds (p_added * scale) to p_modified in place
extern void s_point64_add_scaled_in(Point64 *p_modified, const Point64 *p_added,
                                    const f64 scale);

// Returns p1 minus p2
extern Point64 s_point64_subtract(const Point64 *p1, const Point64 *p2);

// Subtracts p2 from p1 in place
extern void s_point64_subtract_in(Point64 *p1, const Point64 *p2);

// Subtracts p2 from p1, then scales the result, storing in p1
extern void s_point64_subtract_scaled_in(Point64 *p1, const Point64 *p2, const f64 scale);

// Point32 functions

// Copies the values of p into out
extern void s_point32_clone(const Point32 *p, Point32 *out);

// Returns true if a and b are within range of each other for both components
extern bool s_point32_equals(const Point32 *a, const Point32 *b, const f32 range);

// Returns a point with x=0 and y=0
extern Point32 s_point32_zero(void);

// Returns true if both x and y are within POINT32_ZERO_EPSILON of 0
extern bool s_point32_is_zero(const Point32 *p);

// Sets both x and y of p to 0
extern void s_point32_zero_out(Point32 *p);

// Returns a point with random x and y values between min and max
extern Point32 s_point32_random(const f32 min, const f32 max);

// Sets out to a point with random x and y values between min and max
extern void s_point32_random_out(const f32 min, const f32 max, Point32 *out);

// Returns the length of the vector: sqrtf(x*x + y*y)
extern f32 s_point32_magnitude(const Point32 *p);

// Returns the squared length of the vector: x*x + y*y
extern f32 s_point32_magnitude_squared(const Point32 *p);

// Returns a unit vector in the same direction as p
extern Point32 s_point32_normalize(const Point32 *p);

// Normalizes p in place to a unit vector
extern void s_point32_normalize_in(Point32 *p);

// Returns p divided by divisor
extern Point32 s_point32_divide(const Point32 *p, const f32 divisor);

// Divides p by divisor in place
extern void s_point32_divide_in(Point32 *p, const f32 divisor);

// Returns p multiplied by scale
extern Point32 s_point32_scale(const Point32 *p, const f32 scale);

// Multiplies p by scale in place
extern void s_point32_scale_in(Point32 *p, const f32 scale);

// Returns the sum of a and b
extern Point32 s_point32_add(const Point32 *a, const Point32 *b);

// Adds p_added to p_modified in place
extern void s_point32_add_in(Point32 *p_modified, const Point32 *p_added);

// Adds (p_added * scale) to p_modified in place
extern void s_point32_add_scaled_in(Point32 *p_modified, const Point32 *p_added,
                                    const f32 scale);

// Returns p1 minus p2
extern Point32 s_point32_subtract(const Point32 *p1, const Point32 *p2);

// Subtracts p2 from p1 in place
extern void s_point32_subtract_in(Point32 *p1, const Point32 *p2);

// Subtracts (p2 * scale) from p1 in place
extern void s_point32_subtract_scaled_in(Point32 *p1, const Point32 *p2, const f32 scale);

#endif // _STAUNCH_POINT_
