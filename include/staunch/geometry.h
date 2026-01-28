#ifndef _STAUNCH_GEOMETRY_
#define _STAUNCH_GEOMETRY_

#include "point.h"
#include "types.h"

#include <stdbool.h>

// test if two point_d based circles intersect
extern bool f_circle_intersect_d(const Point_d *p1, const f64 r1, const Point_d *p2,
                                 const f64 r2);
// test if a point_d is in a circle (double)
extern bool f_point_d_in_circle_d(const Point_d *point, const Point_d *c, const double r);

#endif // _STAUNCH_GEOMETRY_
