#ifndef _STAUNCH_GEOMETRY_
#define _STAUNCH_GEOMETRY_

#include "point.h"
#include "types.h"

#include <stdbool.h>

// test if two point_d based circles intersect
extern bool s_circle_intersect_f64(const Point64 *p1, const f64 r1, const Point64 *p2,
                                   const f64 r2);
// test if a point_d is in a circle (double)
extern bool s_point64_in_circle_f64(const Point64 *point, const Point64 *c,
                                    const double r);

#endif // _STAUNCH_GEOMETRY_
