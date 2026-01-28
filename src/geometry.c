#include "staunch/geometry.h"

bool f_circle_intersect_d(const Point64 *p1, const double r1, const Point64 *p2,
                          const double r2)
{
    const double dx = p2->x - p1->x;
    const double dy = p2->y - p1->y;

    const double d = dx * dx + dy * dy;
    const double r_sum = r1 + r2;

    return d <= r_sum * r_sum;
}

bool f_point_d_in_circle_d(const Point64 *point, const Point64 *c, const double r)
{
    const Point64 p = {
        .x = point->x - c->x,
        .y = point->y - c->y,
    };

    return p.x * p.x + p.y * p.y < r * r;
}
