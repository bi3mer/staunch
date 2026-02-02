#include "staunch/point.h"
#include "staunch/exam.h"
#include "staunch/general_math.h"
#include "staunch/random.h"

#include <math.h>
#include <stdio.h>

void s_point_clone_f64(const Point64 *p, Point64 *out)
{
    out->x = p->x;
    out->y = p->y;
}

bool s_point_equals_f64(const Point64 *a, const Point64 *b, const f64 range)
{
    e_assert(a != NULL);
    e_assert(b != NULL);
    return s_approximately_f64(a->x, b->x, range) &&
           s_approximately_f64(a->y, b->y, range);
}

Point64 s_point_zero_f64(void)
{
    Point64 out;
    out.x = 0;
    out.y = 0;

    return out;
}

bool s_point_is_zero_f64(const Point64 *p)
{
    // TODO: make absolute and < 1e-9 or something like that?
    e_assert(p != NULL);
    return (p->x == 0) && (p->y == 0);
}

void s_point_zero_out_f64(Point64 *p)
{
    e_assert(p != NULL);

    p->x = 0;
    p->y = 0;
}

Point64 s_point_random_f64(const f64 min, const f64 max)
{
    Point64 out;
    out.x = f_rand_f64(min, max);
    out.y = f_rand_f64(min, max);

    return out;
}

void s_point_random_in_f64(const f64 min, const f64 max, Point64 *out)
{
    e_assert(out != NULL);

    out->x = f_rand_f64(min, max);
    out->y = f_rand_f64(min, max);
}

f64 s_point_magnitude_f64(const Point64 *p)
{
    e_assert(p != NULL);

    return s_sqrt_f64(p->x * p->x + p->y * p->y);
}

f64 s_point_magnitude_squared_f64(const Point64 *p)
{
    e_assert(p != NULL);
    return p->x * p->x + p->y * p->y;
}

Point64 s_point_normalize_f64(const Point64 *p)
{
    e_assert(p != NULL);

    const f64 d = s_point_magnitude_f64(p);
    e_assert(d != 0.0);

    Point64 out;
    out.x = p->x / d;
    out.y = p->y / d;

    return out;
}

void s_point_normalize_in_f64(Point64 *p)
{
    e_assert(p != NULL);

    const f64 d = s_point_magnitude_f64(p);
    e_assert(d != 0.0);

    p->x /= d;
    p->y /= d;
}

Point64 s_point_scale_f64(const Point64 *p, const f64 scale_factor)
{
    e_assert(p != NULL);

    Point64 out;
    out.x = p->x * scale_factor;
    out.y = p->y * scale_factor;

    return out;
}

void s_point_scale_in_f64(Point64 *p, const f64 scale_factor)
{
    e_assert(p != NULL);

    p->x *= scale_factor;
    p->y *= scale_factor;
}

Point64 s_point_divide_f64(const Point64 *p, const f64 divisor)
{
    e_assert(p != NULL);

    Point64 out;
    out.x = p->x / divisor;
    out.y = p->y / divisor;

    return out;
}

void s_point_divide_in_f64(const Point64 *p, const f64 divisor, Point64 *out)
{
    e_assert(p != NULL);
    e_assert(out != NULL);
    e_assert(fabs(divisor) > 1e-9);

    out->x = p->x / divisor;
    out->y = p->y / divisor;
}

Point64 s_point_multiply_f64(const Point64 *p, const f64 scale)
{
    e_assert(p != NULL);

    Point64 out;
    out.x = p->x * scale;
    out.y = p->y * scale;

    return out;
}

void s_point_multiply_in_f64(const Point64 *p, const f64 scale, Point64 *out)
{
    e_assert(p != NULL);
    e_assert(out != NULL);

    out->x = p->x * scale;
    out->y = p->y * scale;
}

Point64 s_point_add_f64(const Point64 *a, const Point64 *b)
{
    e_assert(a != NULL);
    e_assert(b != NULL);

    Point64 p;
    p.x = a->x + b->x;
    p.y = a->y + b->y;

    return p;
}

void s_point_add_in_f64(Point64 *p_modified, const Point64 *p_added)
{
    e_assert(p_modified != NULL);
    e_assert(p_added != NULL);

    p_modified->x += p_added->x;
    p_modified->y += p_added->y;
}

void s_point_add_scaled_in_f64(Point64 *p_modified, const Point64 *p_added,
                               const f64 scale)
{
    e_assert(p_modified != NULL);
    e_assert(p_added != NULL);

    p_modified->x += p_added->x * scale;
    p_modified->y += p_added->y * scale;
}

Point64 s_point_subtract_f64(const Point64 *a, const Point64 *b)
{
    e_assert(a != NULL);
    e_assert(b != NULL);

    Point64 p;
    p.x = a->x - b->x;
    p.y = a->y - b->y;

    return p;
}

void s_point_subtract_in_f64(Point64 *p1, const Point64 *p2)
{
    e_assert(p1 != NULL);
    e_assert(p2 != NULL);

    p1->x = p1->x - p2->x;
    p1->y = p1->y - p2->y;
}

void s_point_subtract_scaled_in_f64(Point64 *p1, const Point64 *p2, const f64 scale)
{
    e_assert(p1 != NULL);
    e_assert(p2 != NULL);

    p1->x = (p1->x - p2->x) * scale;
    p1->y = (p1->y - p2->y) * scale;
}
