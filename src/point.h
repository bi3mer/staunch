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
} Point_d;

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

extern void f_point_d_clone(const Point_d *p, Point_d *out);
extern bool f_point_d_equals(const Point_d *a, const Point_d *b, const double range);

extern Point_d f_point_d_zero(void);
extern bool f_point_d_is_zero(const Point_d *p);
extern void f_point_d_zero_out(Point_d *p);

extern Point_d f_point_d_random(const double min, const double max);
extern void f_point_d_random_in(const double min, const double max, Point_d *out);

extern double f_point_d_magnitude(const Point_d *p);
extern double f_point_d_magnitude_squared(const Point_d *p);

extern Point_d f_point_d_normalize(const Point_d *p);
extern void f_point_d_normalize_in(Point_d *p);

extern Point_d f_point_d_scale(const Point_d *p, const double scale_factor);
extern void f_point_d_scale_in(Point_d *p, const double scale_factor);

extern Point_d f_point_d_divide(const Point_d *p, const double divisor);
extern void f_point_d_divide_in(const Point_d *p, const double divisor, Point_d *out);

extern Point_d f_point_d_multiply(const Point_d *p, const double scale);
extern void f_point_d_multiply_in(const Point_d *p, const double scale, Point_d *out);

extern Point_d f_point_d_add(const Point_d *a, const Point_d *b);
extern void f_point_d_add_in(Point_d *p_modified, const Point_d *p_added);
extern void f_point_d_add_with_scale_in(Point_d *p_modified, const Point_d *p_added,
                                        const double scale);

extern Point_d f_point_d_subtract(const Point_d *p1, const Point_d *p2);
extern void f_point_d_subtract_in(Point_d *p1, const Point_d *p2);
extern void f_point_d_subtract_with_scale_in(Point_d *p1, const Point_d *p2,
                                             const double scale);

#endif // _STAUNCH_POINT_
