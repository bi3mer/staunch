#include "foundation.h"

bool f_circle_intersect_d(const Point_d *p1, const double r1, const Point_d *p2,
                          const double r2)
{
    const double dx = p2->p.x - p1->p.x;
    const double dy = p2->p.y - p1->p.y;

    const double d = dx * dx + dy * dy;
    const double r_sum = r1 + r2;

    return d <= r_sum * r_sum;
}
