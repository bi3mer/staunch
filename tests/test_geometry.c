#include "staunch/exam.h"
#include "staunch/geometry.h"

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_circle_intersect_f64
    {
        s_exam_begin("s_circle_intersect_f64");

        // Circles clearly overlapping
        {
            Point64 p1 = {0.0, 0.0};
            Point64 p2 = {3.0, 0.0};
            s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 2.0) == true);
        }

        // Circles just touching (edge case, <= means true)
        {
            Point64 p1 = {0.0, 0.0};
            Point64 p2 = {5.0, 0.0};
            s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 3.0) == true);
        }

        // Circles not intersecting
        {
            Point64 p1 = {0.0, 0.0};
            Point64 p2 = {10.0, 0.0};
            s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 2.0) == false);
        }

        // One circle fully inside another
        {
            Point64 p1 = {0.0, 0.0};
            Point64 p2 = {1.0, 0.0};
            s_assert(s_circle_intersect_f64(&p1, 10.0, &p2, 2.0) == true);
        }

        // Same circle
        {
            Point64 p1 = {5.0, 5.0};
            Point64 p2 = {5.0, 5.0};
            s_assert(s_circle_intersect_f64(&p1, 3.0, &p2, 3.0) == true);
        }

        // Concentric circles, different radii
        {
            Point64 p1 = {0.0, 0.0};
            Point64 p2 = {0.0, 0.0};
            s_assert(s_circle_intersect_f64(&p1, 5.0, &p2, 2.0) == true);
        }

        // Zero radius circles (points) at same location
        {
            Point64 p1 = {3.0, 4.0};
            Point64 p2 = {3.0, 4.0};
            s_assert(s_circle_intersect_f64(&p1, 0.0, &p2, 0.0) == true);
        }

        // Zero radius circles (points) at different locations
        {
            Point64 p1 = {0.0, 0.0};
            Point64 p2 = {1.0, 0.0};
            s_assert(s_circle_intersect_f64(&p1, 0.0, &p2, 0.0) == false);
        }

        // Diagonal separation
        {
            Point64 p1 = {0.0, 0.0};
            Point64 p2 = {3.0, 4.0}; // distance = 5
            s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 2.0) == false);
            s_assert(s_circle_intersect_f64(&p1, 3.0, &p2, 2.0) == true);
        }

        // Negative coordinates
        {
            Point64 p1 = {-5.0, -5.0};
            Point64 p2 = {-3.0, -5.0};
            s_assert(s_circle_intersect_f64(&p1, 2.0, &p2, 2.0) == true);
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_d_in_circle_f64
    {
        s_exam_begin("s_point_d_in_circle_f64");

        // Point clearly inside
        {
            Point64 point = {1.0, 1.0};
            Point64 center = {0.0, 0.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 5.0) == true);
        }

        // Point clearly outside
        {
            Point64 point = {10.0, 10.0};
            Point64 center = {0.0, 0.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 5.0) == false);
        }

        // Point exactly on boundary (< means false)
        {
            Point64 point = {3.0, 4.0}; // distance = 5
            Point64 center = {0.0, 0.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 5.0) == false);
        }

        // Point at center
        {
            Point64 point = {5.0, 5.0};
            Point64 center = {5.0, 5.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 1.0) == true);
        }

        // Point at center with zero radius
        {
            Point64 point = {0.0, 0.0};
            Point64 center = {0.0, 0.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 0.0) == false);
        }

        // Zero radius circle, point not at center
        {
            Point64 point = {1.0, 0.0};
            Point64 center = {0.0, 0.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 0.0) == false);
        }

        // Negative coordinates
        {
            Point64 point = {-2.0, -2.0};
            Point64 center = {-3.0, -3.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 5.0) == true);
        }

        // Point just inside boundary
        {
            Point64 point = {2.9, 0.0};
            Point64 center = {0.0, 0.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 3.0) == true);
        }

        // Point just outside boundary
        {
            Point64 point = {3.1, 0.0};
            Point64 center = {0.0, 0.0};
            s_assert(s_point64_in_circle_f64(&point, &center, 3.0) == false);
        }

        s_exam_end();
    }

    return 0;
}
