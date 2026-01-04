#include "foundation.h"

bool f_circle_intersect_d(const Point_d *p1, const double r1, const Point_d *p2,
                          const double r2)
{
    const double dx = p2->x - p1->x;
    const double dy = p2->y - p1->y;

    const double d = dx * dx + dy * dy;
    const double r_sum = r1 + r2;

    return d <= r_sum * r_sum;
}

bool f_point_d_in_circle_d(const Point_d *point, const Point_d *c, const double r)
{
    const Point_d p = {
        .x = point->x - c->x,
        .y = point->y - c->y,
    };

    return p.x * p.x + p.y * p.y < r * r;
}
