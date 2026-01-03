#include "foundation.h"

void f_point_d_clone(const Point_d *p, Point_d *out)
{
    out->p.x = p->p.x;
    out->p.y = p->p.y;
}

bool f_point_d_equals(const Point_d *a, const Point_d *b, const double range)
{
    return f_approximately_d(a->p.x, b->p.x, range) &&
           f_approximately_d(a->p.y, b->p.y, range);
}

bool f_point_d_is_zero(const Point_d *p)
{
    return (p->p.x == 0) && (p->p.y == 0);
}

Point_d f_point_d_random(const double min, const double max)
{
    Point_d out;
    out.p.x = f_rand_d(min, max);
    out.p.y = f_rand_d(min, max);

    return out;
}

void f_point_d_random_in(const double min, const double max, Point_d *out)
{
    out->p.x = f_rand_d(min, max);
    out->p.y = f_rand_d(min, max);
}

double f_point_d_magnitude(const Point_d *p)
{
    return f_sqrt_d(p->p.x * p->p.x + p->p.y * p->p.y);
}

double f_point_d_magnitude_squared(const Point_d *p)
{
    return p->p.x * p->p.x + p->p.y * p->p.y;
}

Point_d f_point_d_scale(const Point_d *p, const double scale_factor)
{
    Point_d out;
    out.p.x = p->p.x * scale_factor;
    out.p.y = p->p.y * scale_factor;

    return out;
}

void f_point_d_scale_in(Point_d *p, const double scale_factor)
{
    p->p.x *= scale_factor;
    p->p.y *= scale_factor;
}

Point_d f_point_d_divide(const Point_d *p, const double divisor)
{
    Point_d out = {.p.x = p->p.x / divisor, .p.y = p->p.y / divisor};
    return out;
}

void f_point_d_divide_in(const Point_d *p, const double divisor, Point_d *out)
{
    out->p.x = p->p.x / divisor;
    out->p.y = p->p.y / divisor;
}

Point_d f_point_d_multiply(const Point_d *p, const double scale)
{
    Point_d out = {.p.x = p->p.x * scale, .p.y = p->p.y * scale};
    return out;
}

void f_point_d_multiply_in(const Point_d *p, const double scale, Point_d *out)
{
    out->p.x = p->p.x * scale;
    out->p.y = p->p.y * scale;
}

Point_d f_point_d_add(const Point_d *a, const Point_d *b)
{
    Point_d p = {.p.x = a->p.x + b->p.x, .p.y = a->p.y + b->p.y};
    return p;
}

void f_point_d_add_in(Point_d *p_modified, const Point_d *p_added)
{
    p_modified->p.x += p_added->p.x;
    p_modified->p.y += p_added->p.y;
}

void f_point_d_add_with_scale_in(Point_d *p_modified, const Point_d *p_added,
                                 const double scale)
{
    p_modified->p.x += p_added->p.x * scale;
    p_modified->p.y += p_added->p.y * scale;
}

Point_d f_point_d_subtract(const Point_d *a, const Point_d *b)
{
    Point_d p = {.p.x = a->p.x - b->p.x, .p.y = a->p.y - b->p.y};
    return p;
}

void f_point_d_subtract_in(Point_d *p_modified, const Point_d *p_added)
{
    p_modified->p.x -= p_added->p.x;
    p_modified->p.y -= p_added->p.y;
}

void f_point_d_subtract_with_scale_in(Point_d *p_modified, const Point_d *p_added,
                                      const double scale)
{
    p_modified->p.x -= p_added->p.x * scale;
    p_modified->p.y -= p_added->p.y * scale;
}
