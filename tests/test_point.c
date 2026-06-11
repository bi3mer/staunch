#include "staunch/exam.h"
#include "staunch/general_math.h"
#include "staunch/point.h"

#include <math.h>

#define EPSILON_F64 1e-9
#define EPSILON_F32 1e-6f

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    //                              POINT64 TESTS
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_clone
    S_EXAM("s_point64_clone")
    {
        Point64 p = {3.0, 4.0};
        Point64 out;
        s_point64_clone(&p, &out);
        s_assert(out.x == 3.0);
        s_assert(out.y == 4.0);

        p = (Point64){-1.5, 2.5};
        s_point64_clone(&p, &out);
        s_assert(out.x == -1.5);
        s_assert(out.y == 2.5);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_equals
    S_EXAM("s_point64_equals")
    {
        Point64 a, b;

        // Equal points
        a = (Point64){1.0, 2.0};
        b = (Point64){1.0, 2.0};
        s_assert(s_point64_equals(&a, &b, EPSILON_F64) == true);

        // Approximately equal
        a = (Point64){1.0, 2.0};
        b = (Point64){1.0 + 1e-10, 2.0 - 1e-10};
        s_assert(s_point64_equals(&a, &b, EPSILON_F64) == true);

        // Not equal
        a = (Point64){1.0, 2.0};
        b = (Point64){1.1, 2.0};
        s_assert(s_point64_equals(&a, &b, EPSILON_F64) == false);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_zero
    S_EXAM("s_point64_zero")
    {
        Point64 p = s_point64_zero();
        s_assert(p.x == 0.0);
        s_assert(p.y == 0.0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_is_zero
    S_EXAM("s_point64_is_zero")
    {
        Point64 p = {0.0, 0.0};
        s_assert(s_point64_is_zero(&p) == true);

        p = (Point64){1.0, 0.0};
        s_assert(s_point64_is_zero(&p) == false);

        p = (Point64){0.0, 1.0};
        s_assert(s_point64_is_zero(&p) == false);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_zero_out
    S_EXAM("s_point64_zero_out")
    {
        Point64 p = {5.0, 10.0};
        s_point64_zero_out(&p);
        s_assert(p.x == 0.0);
        s_assert(p.y == 0.0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_magnitude
    S_EXAM("s_point64_magnitude")
    {
        // 3-4-5 triangle
        Point64 p = {3.0, 4.0};
        s_assert(s_approximately_f64(s_point64_magnitude(&p), 5.0, EPSILON_F64));

        // Unit vector
        p = (Point64){1.0, 0.0};
        s_assert(s_approximately_f64(s_point64_magnitude(&p), 1.0, EPSILON_F64));

        // Zero vector
        p = (Point64){0.0, 0.0};
        s_assert(s_approximately_f64(s_point64_magnitude(&p), 0.0, EPSILON_F64));

        // Negative components
        p = (Point64){-3.0, -4.0};
        s_assert(s_approximately_f64(s_point64_magnitude(&p), 5.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_magnitude_squared
    S_EXAM("s_point64_magnitude_squared")
    {
        // 3-4-5: squared = 25
        Point64 p = {3.0, 4.0};
        s_assert(s_approximately_f64(s_point64_magnitude_squared(&p), 25.0, EPSILON_F64));

        // Zero
        p = (Point64){0.0, 0.0};
        s_assert(s_approximately_f64(s_point64_magnitude_squared(&p), 0.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_normalize
    S_EXAM("s_point64_normalize")
    {
        // 3-4-5
        Point64 p = {3.0, 4.0};
        Point64 n = s_point64_normalize(&p);
        s_assert(s_approximately_f64(n.x, 0.6, EPSILON_F64));
        s_assert(s_approximately_f64(n.y, 0.8, EPSILON_F64));
        s_assert(s_approximately_f64(s_point64_magnitude(&n), 1.0, EPSILON_F64));

        // Unit vector stays unit
        p = (Point64){1.0, 0.0};
        n = s_point64_normalize(&p);
        s_assert(s_approximately_f64(n.x, 1.0, EPSILON_F64));
        s_assert(s_approximately_f64(n.y, 0.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_normalize_in
    S_EXAM("s_point64_normalize_in")
    {
        Point64 p = {3.0, 4.0};
        s_point64_normalize_in(&p);
        s_assert(s_approximately_f64(p.x, 0.6, EPSILON_F64));
        s_assert(s_approximately_f64(p.y, 0.8, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_divide
    S_EXAM("s_point64_divide")
    {
        Point64 p = {10.0, 20.0};
        Point64 divided = s_point64_divide(&p, 2.0);
        s_assert(s_approximately_f64(divided.x, 5.0, EPSILON_F64));
        s_assert(s_approximately_f64(divided.y, 10.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_divide_in
    S_EXAM("s_point64_divide_in")
    {
        Point64 p = {10.0, 20.0};
        s_point64_divide_in(&p, 5.0);
        s_assert(s_approximately_f64(p.x, 2.0, EPSILON_F64));
        s_assert(s_approximately_f64(p.y, 4.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_multiply
    S_EXAM("s_point64_multiply")
    {
        Point64 p = {3.0, 4.0};
        Point64 result = s_point64_scale(&p, 2.0);
        s_assert(s_approximately_f64(result.x, 6.0, EPSILON_F64));
        s_assert(s_approximately_f64(result.y, 8.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_multiply_in
    S_EXAM("s_point64_multiply_in")
    {
        Point64 p = {3.0, 4.0};
        s_point64_scale_in(&p, 2.0);
        s_assert(s_approximately_f64(p.x, 6.0, EPSILON_F64));
        s_assert(s_approximately_f64(p.y, 8.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_add
    S_EXAM("s_point64_add")
    {
        Point64 a = {1.0, 2.0};
        Point64 b = {3.0, 4.0};
        Point64 result = s_point64_add(&a, &b);
        s_assert(s_approximately_f64(result.x, 4.0, EPSILON_F64));
        s_assert(s_approximately_f64(result.y, 6.0, EPSILON_F64));

        // Add zero
        a = (Point64){5.0, 10.0};
        b = (Point64){0.0, 0.0};
        result = s_point64_add(&a, &b);
        s_assert(s_approximately_f64(result.x, 5.0, EPSILON_F64));
        s_assert(s_approximately_f64(result.y, 10.0, EPSILON_F64));

        // Add negative
        a = (Point64){5.0, 10.0};
        b = (Point64){-3.0, -4.0};
        result = s_point64_add(&a, &b);
        s_assert(s_approximately_f64(result.x, 2.0, EPSILON_F64));
        s_assert(s_approximately_f64(result.y, 6.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_add_in
    S_EXAM("s_point64_add_in")
    {
        Point64 a = {1.0, 2.0};
        Point64 b = {3.0, 4.0};
        s_point64_add_in(&a, &b);
        s_assert(s_approximately_f64(a.x, 4.0, EPSILON_F64));
        s_assert(s_approximately_f64(a.y, 6.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_add_scaled_in
    S_EXAM("s_point64_add_scaled_in")
    {
        Point64 a = {1.0, 2.0};
        Point64 b = {3.0, 4.0};
        s_point64_add_scaled_in(&a, &b, 2.0);
        s_assert(s_approximately_f64(a.x, 7.0, EPSILON_F64));  // 1 + 3*2
        s_assert(s_approximately_f64(a.y, 10.0, EPSILON_F64)); // 2 + 4*2

        // Scale by zero
        a = (Point64){1.0, 2.0};
        b = (Point64){3.0, 4.0};
        s_point64_add_scaled_in(&a, &b, 0.0);
        s_assert(s_approximately_f64(a.x, 1.0, EPSILON_F64));
        s_assert(s_approximately_f64(a.y, 2.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_subtract
    S_EXAM("s_point64_subtract")
    {
        Point64 a = {5.0, 10.0};
        Point64 b = {2.0, 3.0};
        Point64 result = s_point64_subtract(&a, &b);
        s_assert(s_approximately_f64(result.x, 3.0, EPSILON_F64));
        s_assert(s_approximately_f64(result.y, 7.0, EPSILON_F64));

        // Subtract self
        a = (Point64){5.0, 10.0};
        result = s_point64_subtract(&a, &a);
        s_assert(s_approximately_f64(result.x, 0.0, EPSILON_F64));
        s_assert(s_approximately_f64(result.y, 0.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_subtract_in
    S_EXAM("s_point64_subtract_in")
    {
        Point64 a = {5.0, 10.0};
        Point64 b = {2.0, 3.0};
        s_point64_subtract_in(&a, &b);
        s_assert(s_approximately_f64(a.x, 3.0, EPSILON_F64));
        s_assert(s_approximately_f64(a.y, 7.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point64_subtract_scaled_in
    S_EXAM("s_point64_subtract_scaled_in")
    {
        Point64 a = {10.0, 20.0};
        Point64 b = {2.0, 4.0};
        s_point64_subtract_scaled_in(&a, &b, 2.0);
        // 10 - 2*2 = 6, 20 - 4*2 = 12
        s_assert(s_approximately_f64(a.x, 6.0, EPSILON_F64));
        s_assert(s_approximately_f64(a.y, 12.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    //                              POINT32 TESTS
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_clone
    S_EXAM("s_point32_clone")
    {
        Point32 p = {3.0f, 4.0f};
        Point32 out;
        s_point32_clone(&p, &out);
        s_assert(out.x == 3.0f);
        s_assert(out.y == 4.0f);

        p = (Point32){-1.5f, 2.5f};
        s_point32_clone(&p, &out);
        s_assert(out.x == -1.5f);
        s_assert(out.y == 2.5f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_equals
    S_EXAM("s_point32_equals")
    {
        Point32 a, b;

        // Equal points
        a = (Point32){1.0f, 2.0f};
        b = (Point32){1.0f, 2.0f};
        s_assert(s_point32_equals(&a, &b, EPSILON_F32) == true);

        // Approximately equal
        a = (Point32){1.0f, 2.0f};
        b = (Point32){1.0f + 1e-7f, 2.0f - 1e-7f};
        s_assert(s_point32_equals(&a, &b, EPSILON_F32) == true);

        // Not equal
        a = (Point32){1.0f, 2.0f};
        b = (Point32){1.1f, 2.0f};
        s_assert(s_point32_equals(&a, &b, EPSILON_F32) == false);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_zero
    S_EXAM("s_point32_zero")
    {
        Point32 p = s_point32_zero();
        s_assert(p.x == 0.0f);
        s_assert(p.y == 0.0f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_is_zero
    S_EXAM("s_point32_is_zero")
    {
        Point32 p = {0.0f, 0.0f};
        s_assert(s_point32_is_zero(&p) == true);

        p = (Point32){1.0f, 0.0f};
        s_assert(s_point32_is_zero(&p) == false);

        p = (Point32){0.0f, 1.0f};
        s_assert(s_point32_is_zero(&p) == false);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_zero_out
    S_EXAM("s_point32_zero_out")
    {
        Point32 p = {5.0f, 10.0f};
        s_point32_zero_out(&p);
        s_assert(p.x == 0.0f);
        s_assert(p.y == 0.0f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_magnitude
    S_EXAM("s_point32_magnitude")
    {
        // 3-4-5 triangle
        Point32 p = {3.0f, 4.0f};
        s_assert(s_approximately_f32(s_point32_magnitude(&p), 5.0f, EPSILON_F32));

        // Unit vector
        p = (Point32){1.0f, 0.0f};
        s_assert(s_approximately_f32(s_point32_magnitude(&p), 1.0f, EPSILON_F32));

        // Zero vector
        p = (Point32){0.0f, 0.0f};
        s_assert(s_approximately_f32(s_point32_magnitude(&p), 0.0f, EPSILON_F32));

        // Negative components
        p = (Point32){-3.0f, -4.0f};
        s_assert(s_approximately_f32(s_point32_magnitude(&p), 5.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_magnitude_squared
    S_EXAM("s_point32_magnitude_squared")
    {
        // 3-4-5: squared = 25
        Point32 p = {3.0f, 4.0f};
        s_assert(
            s_approximately_f32(s_point32_magnitude_squared(&p), 25.0f, EPSILON_F32));

        // Zero
        p = (Point32){0.0f, 0.0f};
        s_assert(s_approximately_f32(s_point32_magnitude_squared(&p), 0.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_normalize
    S_EXAM("s_point32_normalize")
    {
        // 3-4-5
        Point32 p = {3.0f, 4.0f};
        Point32 n = s_point32_normalize(&p);
        s_assert(s_approximately_f32(n.x, 0.6f, EPSILON_F32));
        s_assert(s_approximately_f32(n.y, 0.8f, EPSILON_F32));
        s_assert(s_approximately_f32(s_point32_magnitude(&n), 1.0f, EPSILON_F32));

        // Unit vector stays unit
        p = (Point32){1.0f, 0.0f};
        n = s_point32_normalize(&p);
        s_assert(s_approximately_f32(n.x, 1.0f, EPSILON_F32));
        s_assert(s_approximately_f32(n.y, 0.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_normalize_in
    S_EXAM("s_point32_normalize_in")
    {
        Point32 p = {3.0f, 4.0f};
        s_point32_normalize_in(&p);
        s_assert(s_approximately_f32(p.x, 0.6f, EPSILON_F32));
        s_assert(s_approximately_f32(p.y, 0.8f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_divide
    S_EXAM("s_point32_divide")
    {
        Point32 p = {10.0f, 20.0f};
        Point32 divided = s_point32_divide(&p, 2.0f);
        s_assert(s_approximately_f32(divided.x, 5.0f, EPSILON_F32));
        s_assert(s_approximately_f32(divided.y, 10.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_divide_in
    S_EXAM("s_point32_divide_in")
    {
        Point32 p = {10.0f, 20.0f};
        s_point32_divide_in(&p, 5.0f);
        s_assert(s_approximately_f32(p.x, 2.0f, EPSILON_F32));
        s_assert(s_approximately_f32(p.y, 4.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_multiply
    S_EXAM("s_point32_multiply")
    {
        Point32 p = {3.0f, 4.0f};
        Point32 result = s_point32_scale(&p, 2.0f);
        s_assert(s_approximately_f32(result.x, 6.0f, EPSILON_F32));
        s_assert(s_approximately_f32(result.y, 8.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_multiply_in
    S_EXAM("s_point32_multiply_in")
    {
        Point32 p = {3.0f, 4.0f};
        s_point32_scale_in(&p, 2.0f);
        s_assert(s_approximately_f32(p.x, 6.0f, EPSILON_F32));
        s_assert(s_approximately_f32(p.y, 8.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_add
    S_EXAM("s_point32_add")
    {
        Point32 a = {1.0f, 2.0f};
        Point32 b = {3.0f, 4.0f};
        Point32 result = s_point32_add(&a, &b);
        s_assert(s_approximately_f32(result.x, 4.0f, EPSILON_F32));
        s_assert(s_approximately_f32(result.y, 6.0f, EPSILON_F32));

        // Add zero
        a = (Point32){5.0f, 10.0f};
        b = (Point32){0.0f, 0.0f};
        result = s_point32_add(&a, &b);
        s_assert(s_approximately_f32(result.x, 5.0f, EPSILON_F32));
        s_assert(s_approximately_f32(result.y, 10.0f, EPSILON_F32));

        // Add negative
        a = (Point32){5.0f, 10.0f};
        b = (Point32){-3.0f, -4.0f};
        result = s_point32_add(&a, &b);
        s_assert(s_approximately_f32(result.x, 2.0f, EPSILON_F32));
        s_assert(s_approximately_f32(result.y, 6.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_add_in
    S_EXAM("s_point32_add_in")
    {
        Point32 a = {1.0f, 2.0f};
        Point32 b = {3.0f, 4.0f};
        s_point32_add_in(&a, &b);
        s_assert(s_approximately_f32(a.x, 4.0f, EPSILON_F32));
        s_assert(s_approximately_f32(a.y, 6.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_add_scaled_in
    S_EXAM("s_point32_add_scaled_in")
    {
        Point32 a = {1.0f, 2.0f};
        Point32 b = {3.0f, 4.0f};
        s_point32_add_scaled_in(&a, &b, 2.0f);
        s_assert(s_approximately_f32(a.x, 7.0f, EPSILON_F32));  // 1 + 3*2
        s_assert(s_approximately_f32(a.y, 10.0f, EPSILON_F32)); // 2 + 4*2

        // Scale by zero
        a = (Point32){1.0f, 2.0f};
        b = (Point32){3.0f, 4.0f};
        s_point32_add_scaled_in(&a, &b, 0.0f);
        s_assert(s_approximately_f32(a.x, 1.0f, EPSILON_F32));
        s_assert(s_approximately_f32(a.y, 2.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_subtract
    S_EXAM("s_point32_subtract")
    {
        Point32 a = {5.0f, 10.0f};
        Point32 b = {2.0f, 3.0f};
        Point32 result = s_point32_subtract(&a, &b);
        s_assert(s_approximately_f32(result.x, 3.0f, EPSILON_F32));
        s_assert(s_approximately_f32(result.y, 7.0f, EPSILON_F32));

        // Subtract self
        a = (Point32){5.0f, 10.0f};
        result = s_point32_subtract(&a, &a);
        s_assert(s_approximately_f32(result.x, 0.0f, EPSILON_F32));
        s_assert(s_approximately_f32(result.y, 0.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_subtract_in
    S_EXAM("s_point32_subtract_in")
    {
        Point32 a = {5.0f, 10.0f};
        Point32 b = {2.0f, 3.0f};
        s_point32_subtract_in(&a, &b);
        s_assert(s_approximately_f32(a.x, 3.0f, EPSILON_F32));
        s_assert(s_approximately_f32(a.y, 7.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_point32_subtract_scaled_in
    S_EXAM("s_point32_subtract_scaled_in")
    {
        Point32 a = {10.0f, 20.0f};
        Point32 b = {2.0f, 4.0f};
        s_point32_subtract_scaled_in(&a, &b, 2.0f);
        // 10 - 2*2 = 6, 20 - 4*2 = 12
        s_assert(s_approximately_f32(a.x, 6.0f, EPSILON_F32));
        s_assert(s_approximately_f32(a.y, 12.0f, EPSILON_F32));
    }

    s_exam_log_summary();
    return 0;
}
