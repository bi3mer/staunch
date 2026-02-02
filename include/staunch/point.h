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
    } p;

    f32 arr[2];
} Point32;

//-----------------------------------------------------------------------------
// This contains different point types but all with the same API
//
// NOTE: _in suffix typically means in-place modification (f_point_d_scale in)
//       but i have other functions like f_point_divide_in which do not behave
//       similarly.
//
//       Resolve this.
//-----------------------------------------------------------------------------
extern void s_point_clone_f64(const Point64 *p, Point64 *out);
extern bool s_point_equals_f64(const Point64 *a, const Point64 *b, const f64 range);

extern Point64 s_point_zero_f64(void);
extern bool s_point_is_zero_f64(const Point64 *p);
extern void s_point_zero_out_f64(Point64 *p);

extern Point64 s_point_random_f64(const f64 min, const f64 max);
extern void s_point_random_in_f64(const f64 min, const f64 max, Point64 *out);

extern f64 s_point_magnitude_f64(const Point64 *p);
extern f64 s_point_magnitude_squared_f64(const Point64 *p);

extern Point64 s_point_normalize_f64(const Point64 *p);
extern void s_point_normalize_in_f64(Point64 *p);

extern Point64 s_point_scale_f64(const Point64 *p, const f64 scale_factor);
extern void s_point_scale_in_f64(Point64 *p, const f64 scale_factor);

extern Point64 s_point_divide_f64(const Point64 *p, const f64 divisor);
extern void s_point_divide_in_f64(const Point64 *p, const f64 divisor, Point64 *out);

extern Point64 s_point_multiply_f64(const Point64 *p, const f64 scale);
extern void s_point_multiply_in_f64(const Point64 *p, const f64 scale, Point64 *out);

extern Point64 s_point_add_f64(const Point64 *a, const Point64 *b);
extern void s_point_add_in_f64(Point64 *p_modified, const Point64 *p_added);
extern void s_point_add_scaled_in_f64(Point64 *p_modified, const Point64 *p_added,
                                      const f64 scale);

extern Point64 s_point_subtract_f64(const Point64 *p1, const Point64 *p2);
extern void s_point_subtract_in_f64(Point64 *p1, const Point64 *p2);
extern void s_point_subtract_scaled_in_f64(Point64 *p1, const Point64 *p2,
                                           const f64 scale);

#endif // _STAUNCH_POINT_
