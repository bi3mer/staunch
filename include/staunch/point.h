#ifndef _STAUNCH_POINT_
#define _STAUNCH_POINT_

#include <stdbool.h>
typedef struct
{
    union
    {
        struct
        {
            double x, y;
        };
        double arr[2];
    };
} Point64;

typedef struct
{
    struct
    {
        float x, y;
    } p;

    float arr[2];
} Point_f;

//-----------------------------------------------------------------------------
// This contains different point types but all with the same API
//
// NOTE: _in suffix typically means in-place modification (f_point_d_scale in)
//       but i have other functions like f_point_divide_in which do not behave
//       similarly.
//
//       Resolve this.
//-----------------------------------------------------------------------------

extern void f_point_d_clone(const Point64 *p, Point64 *out);
extern bool f_point_d_equals(const Point64 *a, const Point64 *b, const double range);

extern Point64 f_point_d_zero(void);
extern bool f_point_d_is_zero(const Point64 *p);
extern void f_point_d_zero_out(Point64 *p);

extern Point64 f_point_d_random(const double min, const double max);
extern void f_point_d_random_in(const double min, const double max, Point64 *out);

extern double f_point_d_magnitude(const Point64 *p);
extern double f_point_d_magnitude_squared(const Point64 *p);

extern Point64 f_point_d_normalize(const Point64 *p);
extern void f_point_d_normalize_in(Point64 *p);

extern Point64 f_point_d_scale(const Point64 *p, const double scale_factor);
extern void f_point_d_scale_in(Point64 *p, const double scale_factor);

extern Point64 f_point_d_divide(const Point64 *p, const double divisor);
extern void f_point_d_divide_in(const Point64 *p, const double divisor, Point64 *out);

extern Point64 f_point_d_multiply(const Point64 *p, const double scale);
extern void f_point_d_multiply_in(const Point64 *p, const double scale, Point64 *out);

extern Point64 f_point_d_add(const Point64 *a, const Point64 *b);
extern void f_point_d_add_in(Point64 *p_modified, const Point64 *p_added);
extern void f_point_d_add_with_scale_in(Point64 *p_modified, const Point64 *p_added,
                                        const double scale);

extern Point64 f_point_d_subtract(const Point64 *p1, const Point64 *p2);
extern void f_point_d_subtract_in(Point64 *p1, const Point64 *p2);
extern void f_point_d_subtract_with_scale_in(Point64 *p1, const Point64 *p2,
                                             const double scale);

#endif // _STAUNCH_POINT_
