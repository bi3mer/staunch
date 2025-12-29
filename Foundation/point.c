#include "foundation.h"

void point_d_clone(const Point_d *p, Point_d *out)
{
    out->p.x = p->p.x;
    out->p.y = p->p.y;
}

void point_d_add(Point_d *p_modified, const Point_d *p_added)
{
    p_modified->p.x += p_added->p.x;
    p_modified->p.y += p_added->p.y;
}

void point_d_add_with_scale(Point_d *p_modified, const Point_d *p_added,
                            const double scale)
{
    p_modified->p.x += p_added->p.x * scale;
    p_modified->p.y += p_added->p.y * scale;
}
