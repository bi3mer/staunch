#include "staunch/point.h"
#include "staunch/exam.h"
#include "staunch/general_math.h"
#include "staunch/random.h"

#include <math.h>
#include <stdio.h>

void s_point64_clone(const Point64 *p, Point64 *out)
{
    out->x = p->x;
    out->y = p->y;
}

bool s_point64_equals(const Point64 *a, const Point64 *b, const f64 range)
{
    s_assert(a != NULL);
    s_assert(b != NULL);
    return s_approximately_f64(a->x, b->x, range) &&
           s_approximately_f64(a->y, b->y, range);
}

Point64 s_point64_zero(void)
{
    Point64 out;
    out.x = 0;
    out.y = 0;

    return out;
}

bool s_point64_is_zero(const Point64 *p)
{
    // TODO: make absolute and < 1e-9 or something like that?
    s_assert(p != NULL);
    return (p->x == 0) && (p->y == 0);
}

void s_point64_zero_out(Point64 *p)
{
    s_assert(p != NULL);

    p->x = 0;
    p->y = 0;
}

Point64 s_point64_random(const f64 min, const f64 max)
{
    Point64 out;
    out.x = s_rand_f64(min, max);
    out.y = s_rand_f64(min, max);

    return out;
}

void s_point64_random_out(const f64 min, const f64 max, Point64 *out)
{
    s_assert(out != NULL);

    out->x = s_rand_f64(min, max);
    out->y = s_rand_f64(min, max);
}

f64 s_point64_magnitude(const Point64 *p)
{
    s_assert(p != NULL);

    return s_sqrt_f64(p->x * p->x + p->y * p->y);
}

f64 s_point64_magnitude_squared(const Point64 *p)
{
    s_assert(p != NULL);
    return p->x * p->x + p->y * p->y;
}

Point64 s_point64_normalize(const Point64 *p)
{
    s_assert(p != NULL);

    const f64 d = s_point64_magnitude(p);
    s_assert(d != 0.0);

    Point64 out;
    out.x = p->x / d;
    out.y = p->y / d;

    return out;
}

void s_point64_normalize_in(Point64 *p)
{
    s_assert(p != NULL);

    const f64 d = s_point64_magnitude(p);
    s_assert(d != 0.0);

    p->x /= d;
    p->y /= d;
}

Point64 s_point64_divide(const Point64 *p, const f64 divisor)
{
    s_assert(p != NULL);

    Point64 out;
    out.x = p->x / divisor;
    out.y = p->y / divisor;

    return out;
}

void s_point64_divide_in(Point64 *p, const f64 divisor)
{
    s_assert(p != NULL);
    s_assert(fabs(divisor) > 1e-9);

    p->x /= divisor;
    p->y /= divisor;
}

Point64 s_point64_multiply(const Point64 *p, const f64 multiplier)
{
    s_assert(p != NULL);

    Point64 out;
    out.x = p->x * multiplier;
    out.y = p->y * multiplier;

    return out;
}

void s_point64_multiply_in(Point64 *p, const f64 multiplier)
{
    s_assert(p != NULL);

    p->x *= multiplier;
    p->y *= multiplier;
}

Point64 s_point64_add(const Point64 *a, const Point64 *b)
{
    s_assert(a != NULL);
    s_assert(b != NULL);

    Point64 p;
    p.x = a->x + b->x;
    p.y = a->y + b->y;

    return p;
}

void s_point64_add_in(Point64 *p_modified, const Point64 *p_added)
{
    s_assert(p_modified != NULL);
    s_assert(p_added != NULL);

    p_modified->x += p_added->x;
    p_modified->y += p_added->y;
}

void s_point64_add_scaled_in(Point64 *p_modified, const Point64 *p_added, const f64 scale)
{
    s_assert(p_modified != NULL);
    s_assert(p_added != NULL);

    p_modified->x += p_added->x * scale;
    p_modified->y += p_added->y * scale;
}

Point64 s_point64_subtract(const Point64 *a, const Point64 *b)
{
    s_assert(a != NULL);
    s_assert(b != NULL);

    Point64 p;
    p.x = a->x - b->x;
    p.y = a->y - b->y;

    return p;
}

void s_point64_subtract_in(Point64 *p1, const Point64 *p2)
{
    s_assert(p1 != NULL);
    s_assert(p2 != NULL);

    p1->x = p1->x - p2->x;
    p1->y = p1->y - p2->y;
}

void s_point64_subtract_scaled_in(Point64 *p1, const Point64 *p2, const f64 scale)
{
    s_assert(p1 != NULL);
    s_assert(p2 != NULL);

    p1->x = (p1->x - p2->x) * scale;
    p1->y = (p1->y - p2->y) * scale;
}
