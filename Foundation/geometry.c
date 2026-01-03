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
