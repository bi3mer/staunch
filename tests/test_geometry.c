#include "staunch/exam.h"
#include "staunch/geometry.h"

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_circle_intersect_f64
    S_EXAM("s_circle_intersect_f64")
    {
        // Circles clearly overlapping
        Point64 p1 = {0.0, 0.0};
        Point64 p2 = {3.0, 0.0};
        s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 2.0) == true);

        // Circles just touching (edge case, <= means true)
        p1 = (Point64){0.0, 0.0};
        p2 = (Point64){5.0, 0.0};
        s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 3.0) == true);

        // Circles not intersecting
        p1 = (Point64){0.0, 0.0};
        p2 = (Point64){10.0, 0.0};
        s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 2.0) == false);

        // One circle fully inside another
        p1 = (Point64){0.0, 0.0};
        p2 = (Point64){1.0, 0.0};
        s_assert(s_circle_intersect_f64(&p1, 10.0, &p2, 2.0) == true);

        // Same circle
        p1 = (Point64){5.0, 5.0};
        p2 = (Point64){5.0, 5.0};
        s_assert(s_circle_intersect_f64(&p1, 3.0, &p2, 3.0) == true);

        // Concentric circles, different radii
        p1 = (Point64){0.0, 0.0};
        p2 = (Point64){0.0, 0.0};
        s_assert(s_circle_intersect_f64(&p1, 5.0, &p2, 2.0) == true);

        // Zero radius circles (points) at same location
        p1 = (Point64){3.0, 4.0};
        p2 = (Point64){3.0, 4.0};
        s_assert(s_circle_intersect_f64(&p1, 0.0, &p2, 0.0) == true);

        // Zero radius circles (points) at different locations
        p1 = (Point64){0.0, 0.0};
        p2 = (Point64){1.0, 0.0};
        s_assert(s_circle_intersect_f64(&p1, 0.0, &p2, 0.0) == false);

        // Diagonal separation
        p1 = (Point64){0.0, 0.0};
        p2 = (Point64){3.0, 4.0}; // distance = 5
        s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 2.0) == false);
        s_assert(s_circle_intersect_f64(&p1, 3.0, &p2, 2.0) == true);

        // Negative coordinates
        p1 = (Point64){-5.0, -5.0};
        p2 = (Point64){-3.0, -5.0};
        s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 2.0) == true);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_d_in_circle_f64
    S_EXAM("s_point64_in_circle_f64")
    {
        Point64 point, center;

        // Point clearly inside
        point = (Point64){1.0, 1.0};
        center = (Point64){0.0, 0.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 5.0) == true);

        // Point clearly outside
        point = (Point64){10.0, 10.0};
        center = (Point64){0.0, 0.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 5.0) == false);

        // Point exactly on boundary (< means false)
        point = (Point64){3.0, 4.0}; // distance = 5
        center = (Point64){0.0, 0.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 5.0) == false);

        // Point at center
        point = (Point64){5.0, 5.0};
        center = (Point64){5.0, 5.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 1.0) == true);

        // Point at center with zero radius
        point = (Point64){0.0, 0.0};
        center = (Point64){0.0, 0.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 0.0) == false);

        // Zero radius circle, point not at center
        point = (Point64){1.0, 0.0};
        center = (Point64){0.0, 0.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 0.0) == false);

        // Negative coordinates
        point = (Point64){-2.0, -2.0};
        center = (Point64){-3.0, -3.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 5.0) == true);

        // Point just inside boundary
        point = (Point64){2.9, 0.0};
        center = (Point64){0.0, 0.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 3.0) == true);

        // Point just outside boundary
        point = (Point64){3.1, 0.0};
        center = (Point64){0.0, 0.0};
        s_assert(s_point64_in_circle_f64(&point, &center, 3.0) == false);
    }

    s_exam_log_summary();
    return 0;
}