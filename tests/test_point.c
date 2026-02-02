#include "staunch/exam.h"
#include "staunch/general_math.h"
#include "staunch/point.h"

#include <math.h>

#define EPSILON 1e-9

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_point_clone_f64
    {
        e_begin("s_point_clone_f64");

        {
            Point64 p = {3.0, 4.0};
            Point64 out;
            s_point_clone_f64(&p, &out);
            e_assert(out.x == 3.0);
            e_assert(out.y == 4.0);
        }

        {
            Point64 p = {-1.5, 2.5};
            Point64 out;
            s_point_clone_f64(&p, &out);
            e_assert(out.x == -1.5);
            e_assert(out.y == 2.5);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_equals_f64
    {
        e_begin("s_point_equals_f64");

        // Equal points
        {
            Point64 a = {1.0, 2.0};
            Point64 b = {1.0, 2.0};
            e_assert(s_point_equals_f64(&a, &b, EPSILON) == true);
        }

        // Approximately equal
        {
            Point64 a = {1.0, 2.0};
            Point64 b = {1.0 + 1e-10, 2.0 - 1e-10};
            e_assert(s_point_equals_f64(&a, &b, EPSILON) == true);
        }

        // Not equal
        {
            Point64 a = {1.0, 2.0};
            Point64 b = {1.1, 2.0};
            e_assert(s_point_equals_f64(&a, &b, EPSILON) == false);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_zero_f64
    {
        e_begin("s_point_zero_f64");

        {
            Point64 p = s_point_zero_f64();
            e_assert(p.x == 0.0);
            e_assert(p.y == 0.0);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_is_zero_f64
    {
        e_begin("s_point_is_zero_f64");

        {
            Point64 p = {0.0, 0.0};
            e_assert(s_point_is_zero_f64(&p) == true);
        }

        {
            Point64 p = {1.0, 0.0};
            e_assert(s_point_is_zero_f64(&p) == false);
        }

        {
            Point64 p = {0.0, 1.0};
            e_assert(s_point_is_zero_f64(&p) == false);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_zero_out_f64
    {
        e_begin("s_point_zero_out_f64");

        {
            Point64 p = {5.0, 10.0};
            s_point_zero_out_f64(&p);
            e_assert(p.x == 0.0);
            e_assert(p.y == 0.0);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_magnitude_f64
    {
        e_begin("s_point_magnitude_f64");

        // 3-4-5 triangle
        {
            Point64 p = {3.0, 4.0};
            e_assert(s_approximately_f64(s_point_magnitude_f64(&p), 5.0, EPSILON));
        }

        // Unit vector
        {
            Point64 p = {1.0, 0.0};
            e_assert(s_approximately_f64(s_point_magnitude_f64(&p), 1.0, EPSILON));
        }

        // Zero vector
        {
            Point64 p = {0.0, 0.0};
            e_assert(s_approximately_f64(s_point_magnitude_f64(&p), 0.0, EPSILON));
        }

        // Negative components
        {
            Point64 p = {-3.0, -4.0};
            e_assert(s_approximately_f64(s_point_magnitude_f64(&p), 5.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_magnitude_squared_f64
    {
        e_begin("s_point_magnitude_squared_f64");

        // 3-4-5: squared = 25
        {
            Point64 p = {3.0, 4.0};
            e_assert(
                s_approximately_f64(s_point_magnitude_squared_f64(&p), 25.0, EPSILON));
        }

        // Zero
        {
            Point64 p = {0.0, 0.0};
            e_assert(
                s_approximately_f64(s_point_magnitude_squared_f64(&p), 0.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_normalize_f64
    {
        e_begin("s_point_normalize_f64");

        // 3-4-5
        {
            Point64 p = {3.0, 4.0};
            Point64 n = s_point_normalize_f64(&p);
            e_assert(s_approximately_f64(n.x, 0.6, EPSILON));
            e_assert(s_approximately_f64(n.y, 0.8, EPSILON));
            e_assert(s_approximately_f64(s_point_magnitude_f64(&n), 1.0, EPSILON));
        }

        // Unit vector stays unit
        {
            Point64 p = {1.0, 0.0};
            Point64 n = s_point_normalize_f64(&p);
            e_assert(s_approximately_f64(n.x, 1.0, EPSILON));
            e_assert(s_approximately_f64(n.y, 0.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_normalize_in_f64
    {
        e_begin("s_point_normalize_in_f64");

        {
            Point64 p = {3.0, 4.0};
            s_point_normalize_in_f64(&p);
            e_assert(s_approximately_f64(p.x, 0.6, EPSILON));
            e_assert(s_approximately_f64(p.y, 0.8, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_scale_f64
    {
        e_begin("s_point_scale_f64");

        {
            Point64 p = {2.0, 3.0};
            Point64 scaled = s_point_scale_f64(&p, 2.0);
            e_assert(s_approximately_f64(scaled.x, 4.0, EPSILON));
            e_assert(s_approximately_f64(scaled.y, 6.0, EPSILON));
        }

        // Scale by zero
        {
            Point64 p = {5.0, 10.0};
            Point64 scaled = s_point_scale_f64(&p, 0.0);
            e_assert(s_approximately_f64(scaled.x, 0.0, EPSILON));
            e_assert(s_approximately_f64(scaled.y, 0.0, EPSILON));
        }

        // Negative scale
        {
            Point64 p = {2.0, 3.0};
            Point64 scaled = s_point_scale_f64(&p, -1.0);
            e_assert(s_approximately_f64(scaled.x, -2.0, EPSILON));
            e_assert(s_approximately_f64(scaled.y, -3.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_scale_in_f64
    {
        e_begin("s_point_scale_in_f64");

        {
            Point64 p = {2.0, 3.0};
            s_point_scale_in_f64(&p, 3.0);
            e_assert(s_approximately_f64(p.x, 6.0, EPSILON));
            e_assert(s_approximately_f64(p.y, 9.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_divide_f64
    {
        e_begin("s_point_divide_f64");

        {
            Point64 p = {10.0, 20.0};
            Point64 divided = s_point_divide_f64(&p, 2.0);
            e_assert(s_approximately_f64(divided.x, 5.0, EPSILON));
            e_assert(s_approximately_f64(divided.y, 10.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_divide_in_f64
    {
        e_begin("s_point_divide_in_f64");

        {
            Point64 p = {10.0, 20.0};
            Point64 out;
            s_point_divide_in_f64(&p, 5.0, &out);
            e_assert(s_approximately_f64(out.x, 2.0, EPSILON));
            e_assert(s_approximately_f64(out.y, 4.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_multiply_f64
    {
        e_begin("s_point_multiply_f64");

        {
            Point64 p = {3.0, 4.0};
            Point64 result = s_point_multiply_f64(&p, 2.0);
            e_assert(s_approximately_f64(result.x, 6.0, EPSILON));
            e_assert(s_approximately_f64(result.y, 8.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_multiply_in_f64
    {
        e_begin("s_point_multiply_in_f64");

        {
            Point64 p = {3.0, 4.0};
            Point64 out;
            s_point_multiply_in_f64(&p, 2.0, &out);
            e_assert(s_approximately_f64(out.x, 6.0, EPSILON));
            e_assert(s_approximately_f64(out.y, 8.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_add_f64
    {
        e_begin("s_point_add_f64");

        {
            Point64 a = {1.0, 2.0};
            Point64 b = {3.0, 4.0};
            Point64 result = s_point_add_f64(&a, &b);
            e_assert(s_approximately_f64(result.x, 4.0, EPSILON));
            e_assert(s_approximately_f64(result.y, 6.0, EPSILON));
        }

        // Add zero
        {
            Point64 a = {5.0, 10.0};
            Point64 b = {0.0, 0.0};
            Point64 result = s_point_add_f64(&a, &b);
            e_assert(s_approximately_f64(result.x, 5.0, EPSILON));
            e_assert(s_approximately_f64(result.y, 10.0, EPSILON));
        }

        // Add negative
        {
            Point64 a = {5.0, 10.0};
            Point64 b = {-3.0, -4.0};
            Point64 result = s_point_add_f64(&a, &b);
            e_assert(s_approximately_f64(result.x, 2.0, EPSILON));
            e_assert(s_approximately_f64(result.y, 6.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_add_in_f64
    {
        e_begin("s_point_add_in_f64");

        {
            Point64 a = {1.0, 2.0};
            Point64 b = {3.0, 4.0};
            s_point_add_in_f64(&a, &b);
            e_assert(s_approximately_f64(a.x, 4.0, EPSILON));
            e_assert(s_approximately_f64(a.y, 6.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_add_scaled_in_f64
    {
        e_begin("s_point_add_scaled_in_f64");

        {
            Point64 a = {1.0, 2.0};
            Point64 b = {3.0, 4.0};
            s_point_add_scaled_in_f64(&a, &b, 2.0);
            e_assert(s_approximately_f64(a.x, 7.0, EPSILON));  // 1 + 3*2
            e_assert(s_approximately_f64(a.y, 10.0, EPSILON)); // 2 + 4*2
        }

        // Scale by zero
        {
            Point64 a = {1.0, 2.0};
            Point64 b = {3.0, 4.0};
            s_point_add_scaled_in_f64(&a, &b, 0.0);
            e_assert(s_approximately_f64(a.x, 1.0, EPSILON));
            e_assert(s_approximately_f64(a.y, 2.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_subtract_f64
    {
        e_begin("s_point_subtract_f64");

        {
            Point64 a = {5.0, 10.0};
            Point64 b = {2.0, 3.0};
            Point64 result = s_point_subtract_f64(&a, &b);
            e_assert(s_approximately_f64(result.x, 3.0, EPSILON));
            e_assert(s_approximately_f64(result.y, 7.0, EPSILON));
        }

        // Subtract self
        {
            Point64 a = {5.0, 10.0};
            Point64 result = s_point_subtract_f64(&a, &a);
            e_assert(s_approximately_f64(result.x, 0.0, EPSILON));
            e_assert(s_approximately_f64(result.y, 0.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_subtract_in_f64
    {
        e_begin("s_point_subtract_in_f64");

        {
            Point64 a = {5.0, 10.0};
            Point64 b = {2.0, 3.0};
            s_point_subtract_in_f64(&a, &b);
            e_assert(s_approximately_f64(a.x, 3.0, EPSILON));
            e_assert(s_approximately_f64(a.y, 7.0, EPSILON));
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point_subtract_scaled_in_f64
    {
        e_begin("s_point_subtract_scaled_in_f64");

        {
            Point64 a = {10.0, 20.0};
            Point64 b = {2.0, 4.0};
            s_point_subtract_scaled_in_f64(&a, &b, 2.0);
            // (10 - 2) * 2 = 16, (20 - 4) * 2 = 32
            e_assert(s_approximately_f64(a.x, 16.0, EPSILON));
            e_assert(s_approximately_f64(a.y, 32.0, EPSILON));
        }

        e_end();
    }

    return 0;
}
