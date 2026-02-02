#include "staunch/geometry.h"

bool s_circle_intersect_f64(const Point64 *p1, const f64 r1, const Point64 *p2,
                            const f64 r2)
{
    const f64 dx = p2->x - p1->x;
    const f64 dy = p2->y - p1->y;

    const f64 d = dx * dx + dy * dy;
    const f64 r_sum = r1 + r2;

    return d <= r_sum * r_sum;
}

bool s_point64_in_circle_f64(const Point64 *point, const Point64 *c, const f64 r)
{
    const Point64 p = {
        .x = point->x - c->x,
        .y = point->y - c->y,
    };

    return p.x * p.x + p.y * p.y < r * r;
}
