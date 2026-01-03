#include "exam.h"
#include "foundation.h"

#include <math.h>
#include <stdio.h>

void f_point_d_clone(const Point_d *p, Point_d *out)
{
    out->x = p->x;
    out->y = p->y;
}

bool f_point_d_equals(const Point_d *a, const Point_d *b, const double range)
{
    e_assert(a != NULL);
    e_assert(b != NULL);
    return f_approximately_d(a->x, b->x, range) && f_approximately_d(a->y, b->y, range);
}

Point_d f_point_d_zero(void)
{
    Point_d out;
    out.x = 0;
    out.y = 0;

    return out;
}

bool f_point_d_is_zero(const Point_d *p)
{
    // TODO: make absolute and < 1e-9 or something like that?
    e_assert(p != NULL);
    return (p->x == 0) && (p->y == 0);
}

void f_point_d_zero_out(Point_d *p)
{
    e_assert(p != NULL);

    p->x = 0;
    p->y = 0;
}

Point_d f_point_d_random(const double min, const double max)
{
    Point_d out;
    out.x = f_rand_d(min, max);
    out.y = f_rand_d(min, max);

    return out;
}

void f_point_d_random_in(const double min, const double max, Point_d *out)
{
    e_assert(out != NULL);

    out->x = f_rand_d(min, max);
    out->y = f_rand_d(min, max);
}

double f_point_d_magnitude(const Point_d *p)
{
    e_assert(p != NULL);

    return f_sqrt_d(p->x * p->x + p->y * p->y);
}

double f_point_d_magnitude_squared(const Point_d *p)
{
    e_assert(p != NULL);
    return p->x * p->x + p->y * p->y;
}

Point_d f_point_d_scale(const Point_d *p, const double scale_factor)
{
    e_assert(p != NULL);

    Point_d out;
    out.x = p->x * scale_factor;
    out.y = p->y * scale_factor;

    return out;
}

void f_point_d_scale_in(Point_d *p, const double scale_factor)
{
    e_assert(p != NULL);

    p->x *= scale_factor;
    p->y *= scale_factor;
}

Point_d f_point_d_divide(const Point_d *p, const double divisor)
{
    e_assert(p != NULL);

    Point_d out;
    out.x = p->x / divisor;
    out.y = p->y / divisor;

    return out;
}

void f_point_d_divide_in(const Point_d *p, const double divisor, Point_d *out)
{
    e_assert(p != NULL);
    e_assert(out != NULL);
    e_assert(fabs(divisor) > 1e-9);

    out->x = p->x / divisor;
    out->y = p->y / divisor;
}

Point_d f_point_d_multiply(const Point_d *p, const double scale)
{
    e_assert(p != NULL);

    Point_d out;
    out.x = p->x * scale;
    out.y = p->y * scale;

    return out;
}

void f_point_d_multiply_in(const Point_d *p, const double scale, Point_d *out)
{
    e_assert(p != NULL);
    e_assert(out != NULL);

    out->x = p->x * scale;
    out->y = p->y * scale;
}

Point_d f_point_d_add(const Point_d *a, const Point_d *b)
{
    e_assert(a != NULL);
    e_assert(b != NULL);

    Point_d p;
    p.x = a->x + b->x;
    p.y = a->y + b->y;

    return p;
}

void f_point_d_add_in(Point_d *p_modified, const Point_d *p_added)
{
    e_assert(p_modified != NULL);
    e_assert(p_added != NULL);

    p_modified->x += p_added->x;
    p_modified->y += p_added->y;
}

void f_point_d_add_with_scale_in(Point_d *p_modified, const Point_d *p_added,
                                 const double scale)
{
    e_assert(p_modified != NULL);
    e_assert(p_added != NULL);

    p_modified->x += p_added->x * scale;
    p_modified->y += p_added->y * scale;
}

Point_d f_point_d_subtract(const Point_d *a, const Point_d *b)
{
    e_assert(a != NULL);
    e_assert(b != NULL);

    Point_d p;
    p.x = a->x - b->x;
    p.y = a->y - b->y;

    return p;
}

void f_point_d_subtract_in(Point_d *p_modified, const Point_d *p_added)
{
    e_assert(p_modified != NULL);
    e_assert(p_added != NULL);

    p_modified->x -= p_added->x;
    p_modified->y -= p_added->y;
}

void f_point_d_subtract_with_scale_in(Point_d *p_modified, const Point_d *p_added,
                                      const double scale)
{
    e_assert(p_modified != NULL);
    e_assert(p_added != NULL);

    p_modified->x -= p_added->x * scale;
    p_modified->y -= p_added->y * scale;
}
