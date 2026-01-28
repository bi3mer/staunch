#include "staunch/point.h"
#include "staunch/exam.h"
#include "staunch/general_math.h"
#include "staunch/random.h"

#include <math.h>
#include <stdio.h>

void f_point_d_clone(const Point64 *p, Point64 *out)
{
    out->x = p->x;
    out->y = p->y;
}

bool f_point_d_equals(const Point64 *a, const Point64 *b, const double range)
{
    e_assert(a != NULL);
    e_assert(b != NULL);
    return f_approximately_d(a->x, b->x, range) && f_approximately_d(a->y, b->y, range);
}

Point64 f_point_d_zero(void)
{
    Point64 out;
    out.x = 0;
    out.y = 0;

    return out;
}

bool f_point_d_is_zero(const Point64 *p)
{
    // TODO: make absolute and < 1e-9 or something like that?
    e_assert(p != NULL);
    return (p->x == 0) && (p->y == 0);
}

void f_point_d_zero_out(Point64 *p)
{
    e_assert(p != NULL);

    p->x = 0;
    p->y = 0;
}

Point64 f_point_d_random(const double min, const double max)
{
    Point64 out;
    out.x = f_rand_f64(min, max);
    out.y = f_rand_f64(min, max);

    return out;
}

void f_point_d_random_in(const double min, const double max, Point64 *out)
{
    e_assert(out != NULL);

    out->x = f_rand_f64(min, max);
    out->y = f_rand_f64(min, max);
}

double f_point_d_magnitude(const Point64 *p)
{
    e_assert(p != NULL);

    return f_sqrt_d(p->x * p->x + p->y * p->y);
}

double s_point64_magnitude_squared(const Point64 *p)
{
    e_assert(p != NULL);
    return p->x * p->x + p->y * p->y;
}

Point64 f_point_d_normalize(const Point64 *p)
{
    e_assert(p != NULL);

    const double d = f_point_d_magnitude(p);
    e_assert(d != 0.0);

    Point64 out;
    out.x = p->x / d;
    out.y = p->y / d;

    return out;
}

void f_point_d_normalize_in(Point64 *p)
{
    e_assert(p != NULL);

    const double d = f_point_d_magnitude(p);
    e_assert(d != 0.0);

    p->x /= d;
    p->y /= d;
}

Point64 f_point_d_scale(const Point64 *p, const double scale_factor)
{
    e_assert(p != NULL);

    Point64 out;
    out.x = p->x * scale_factor;
    out.y = p->y * scale_factor;

    return out;
}

void s_point_d_scale_in(Point64 *p, const double scale_factor)
{
    e_assert(p != NULL);

    p->x *= scale_factor;
    p->y *= scale_factor;
}

Point64 f_point_d_divide(const Point64 *p, const double divisor)
{
    e_assert(p != NULL);

    Point64 out;
    out.x = p->x / divisor;
    out.y = p->y / divisor;

    return out;
}

void f_point_d_divide_in(const Point64 *p, const double divisor, Point64 *out)
{
    e_assert(p != NULL);
    e_assert(out != NULL);
    e_assert(fabs(divisor) > 1e-9);

    out->x = p->x / divisor;
    out->y = p->y / divisor;
}

Point64 f_point_d_multiply(const Point64 *p, const double scale)
{
    e_assert(p != NULL);

    Point64 out;
    out.x = p->x * scale;
    out.y = p->y * scale;

    return out;
}

void f_point_d_multiply_in(const Point64 *p, const double scale, Point64 *out)
{
    e_assert(p != NULL);
    e_assert(out != NULL);

    out->x = p->x * scale;
    out->y = p->y * scale;
}

Point64 f_point_d_add(const Point64 *a, const Point64 *b)
{
    e_assert(a != NULL);
    e_assert(b != NULL);

    Point64 p;
    p.x = a->x + b->x;
    p.y = a->y + b->y;

    return p;
}

void f_point_d_add_in(Point64 *p_modified, const Point64 *p_added)
{
    e_assert(p_modified != NULL);
    e_assert(p_added != NULL);

    p_modified->x += p_added->x;
    p_modified->y += p_added->y;
}

void f_point_d_add_with_scale_in(Point64 *p_modified, const Point64 *p_added,
                                 const double scale)
{
    e_assert(p_modified != NULL);
    e_assert(p_added != NULL);

    p_modified->x += p_added->x * scale;
    p_modified->y += p_added->y * scale;
}

Point64 f_point_d_subtract(const Point64 *a, const Point64 *b)
{
    e_assert(a != NULL);
    e_assert(b != NULL);

    Point64 p;
    p.x = a->x - b->x;
    p.y = a->y - b->y;

    return p;
}

void f_point_d_subtract_in(Point64 *p1, const Point64 *p2)
{
    e_assert(p1 != NULL);
    e_assert(p2 != NULL);

    p1->x = p1->x - p2->x;
    p1->y = p1->y - p2->y;
}

void f_point_d_subtract_with_scale_in(Point64 *p1, const Point64 *p2, const double scale)
{
    e_assert(p1 != NULL);
    e_assert(p2 != NULL);

    p1->x = (p1->x - p2->x) * scale;
    p1->y = (p1->y - p2->y) * scale;
}
