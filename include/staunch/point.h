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
    struct
    {
        f32 x, y;
    };

    f32 arr[2];
} Point32;

extern void s_point64_clone(const Point64 *p, Point64 *out);
extern bool s_point64_equals(const Point64 *a, const Point64 *b, const f64 range);

extern Point64 s_point64_zero(void);
extern bool s_point64_is_zero(const Point64 *p);
extern void s_point64_zero_out(Point64 *p);

extern Point64 s_point64_random(const f64 min, const f64 max);
extern void s_point64_random_out(const f64 min, const f64 max, Point64 *out);

extern f64 s_point64_magnitude(const Point64 *p);
extern f64 s_point64_magnitude_squared(const Point64 *p);

extern Point64 s_point64_normalize(const Point64 *p);
extern void s_point64_normalize_in(Point64 *p);

extern Point64 s_point64_divide(const Point64 *p, const f64 divisor);
extern void s_point64_divide_in(Point64 *p, const f64 divisor);

extern Point64 s_point64_multiply(const Point64 *p, const f64 scale);
extern void s_point64_multiply_in(Point64 *p, const f64 scale);

extern Point64 s_point64_add(const Point64 *a, const Point64 *b);
extern void s_point64_add_in(Point64 *p_modified, const Point64 *p_added);
extern void s_point64_add_scaled_in(Point64 *p_modified, const Point64 *p_added,
                                    const f64 scale);

extern Point64 s_point64_subtract(const Point64 *p1, const Point64 *p2);
extern void s_point64_subtract_in(Point64 *p1, const Point64 *p2);
extern void s_point64_subtract_scaled_in(Point64 *p1, const Point64 *p2, const f64 scale);

#endif // _STAUNCH_POINT_
