#include "staunch/exam.h"
#include "staunch/general_math.h"
#include "staunch/linear_algebra.h"

#define EPSILON_F32 1e-6f
#define EPSILON_F64 1e-12

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_length_f32
    S_EXAM("s_vec2_length_f32")
    {
        // Unit vectors
        f32 v[2] = {1.0f, 0.0f};
        s_assert(s_approximately_f32(s_vec2_length_f32(v), 1.0f, EPSILON_F32));

        v[0] = 0.0f;
        v[1] = 1.0f;
        s_assert(s_approximately_f32(s_vec2_length_f32(v), 1.0f, EPSILON_F32));

        // Zero vector
        v[0] = 0.0f;
        v[1] = 0.0f;
        s_assert(s_approximately_f32(s_vec2_length_f32(v), 0.0f, EPSILON_F32));

        // 3-4-5 triangle
        v[0] = 3.0f;
        v[1] = 4.0f;
        s_assert(s_approximately_f32(s_vec2_length_f32(v), 5.0f, EPSILON_F32));

        // Negative components
        v[0] = -3.0f;
        v[1] = -4.0f;
        s_assert(s_approximately_f32(s_vec2_length_f32(v), 5.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_length_f64
    S_EXAM("s_vec2_length_f64")
    {
        // Unit vectors
        f64 v[2] = {1.0, 0.0};
        s_assert(s_approximately_f64(s_vec2_length_f64(v), 1.0, EPSILON_F64));

        v[0] = 0.0;
        v[1] = 1.0;
        s_assert(s_approximately_f64(s_vec2_length_f64(v), 1.0, EPSILON_F64));

        // Zero vector
        v[0] = 0.0;
        v[1] = 0.0;
        s_assert(s_approximately_f64(s_vec2_length_f64(v), 0.0, EPSILON_F64));

        // 3-4-5 triangle
        v[0] = 3.0;
        v[1] = 4.0;
        s_assert(s_approximately_f64(s_vec2_length_f64(v), 5.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_length_f32
    S_EXAM("s_vec3_length_f32")
    {
        // Unit vectors
        f32 v[3] = {1.0f, 0.0f, 0.0f};
        s_assert(s_approximately_f32(s_vec3_length_f32(v), 1.0f, EPSILON_F32));

        v[0] = 0.0f;
        v[1] = 1.0f;
        v[2] = 0.0f;
        s_assert(s_approximately_f32(s_vec3_length_f32(v), 1.0f, EPSILON_F32));

        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 1.0f;
        s_assert(s_approximately_f32(s_vec3_length_f32(v), 1.0f, EPSILON_F32));

        // Zero vector
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        s_assert(s_approximately_f32(s_vec3_length_f32(v), 0.0f, EPSILON_F32));

        // Known length: sqrt(1 + 4 + 9) = sqrt(14)
        v[0] = 1.0f;
        v[1] = 2.0f;
        v[2] = 3.0f;
        s_assert(s_approximately_f32(s_vec3_length_f32(v), 3.7416573f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_length_f64
    S_EXAM("s_vec3_length_f64")
    {
        // Unit vectors
        f64 v[3] = {1.0, 0.0, 0.0};
        s_assert(s_approximately_f64(s_vec3_length_f64(v), 1.0, EPSILON_F64));

        // Zero vector
        v[0] = 0.0;
        v[1] = 0.0;
        v[2] = 0.0;
        s_assert(s_approximately_f64(s_vec3_length_f64(v), 0.0, EPSILON_F64));

        // Known length: sqrt(14)
        v[0] = 1.0;
        v[1] = 2.0;
        v[2] = 3.0;
        s_assert(
            s_approximately_f64(s_vec3_length_f64(v), 3.74165738677394, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_length_squared_f32
    S_EXAM("s_vec2_length_squared_f32")
    {
        // Unit vector
        f32 v[2] = {1.0f, 0.0f};
        s_assert(s_approximately_f32(s_vec2_length_squared_f32(v), 1.0f, EPSILON_F32));

        // Zero vector
        v[0] = 0.0f;
        v[1] = 0.0f;
        s_assert(s_approximately_f32(s_vec2_length_squared_f32(v), 0.0f, EPSILON_F32));

        // 3-4-5: squared = 25
        v[0] = 3.0f;
        v[1] = 4.0f;
        s_assert(s_approximately_f32(s_vec2_length_squared_f32(v), 25.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_length_squared_f64
    S_EXAM("s_vec2_length_squared_f64")
    {
        // 3-4-5: squared = 25
        f64 v[2] = {3.0, 4.0};
        s_assert(s_approximately_f64(s_vec2_length_squared_f64(v), 25.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_length_squared_f32
    S_EXAM("s_vec3_length_squared_f32")
    {
        // 1^2 + 2^2 + 3^2 = 14
        f32 v[3] = {1.0f, 2.0f, 3.0f};
        s_assert(s_approximately_f32(s_vec3_length_squared_f32(v), 14.0f, EPSILON_F32));

        // Zero vector
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        s_assert(s_approximately_f32(s_vec3_length_squared_f32(v), 0.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_length_squared_f64
    S_EXAM("s_vec3_length_squared_f64")
    {
        // 1^2 + 2^2 + 3^2 = 14
        f64 v[3] = {1.0, 2.0, 3.0};
        s_assert(s_approximately_f64(s_vec3_length_squared_f64(v), 14.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_dot_f32
    S_EXAM("s_vec2_dot_f32")
    {
        f32 v1[2], v2[2];

        // Orthogonal vectors
        v1[0] = 1.0f;
        v1[1] = 0.0f;
        v2[0] = 0.0f;
        v2[1] = 1.0f;
        s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v2), 0.0f, EPSILON_F32));

        // Parallel vectors (same direction)
        v1[0] = 1.0f;
        v1[1] = 0.0f;
        v2[0] = 2.0f;
        v2[1] = 0.0f;
        s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v2), 2.0f, EPSILON_F32));

        // Opposite direction
        v1[0] = 1.0f;
        v1[1] = 0.0f;
        v2[0] = -1.0f;
        v2[1] = 0.0f;
        s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v2), -1.0f, EPSILON_F32));

        // General case
        v1[0] = 3.0f;
        v1[1] = 4.0f;
        v2[0] = 2.0f;
        v2[1] = 5.0f;
        s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v2), 26.0f, EPSILON_F32));

        // Self dot = length squared
        v1[0] = 3.0f;
        v1[1] = 4.0f;
        s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v1), 25.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_dot_f64
    S_EXAM("s_vec2_dot_f64")
    {
        f64 v1[2], v2[2];

        // Orthogonal
        v1[0] = 1.0;
        v1[1] = 0.0;
        v2[0] = 0.0;
        v2[1] = 1.0;
        s_assert(s_approximately_f64(s_vec2_dot_f64(v1, v2), 0.0, EPSILON_F64));

        // General case
        v1[0] = 3.0;
        v1[1] = 4.0;
        v2[0] = 2.0;
        v2[1] = 5.0;
        s_assert(s_approximately_f64(s_vec2_dot_f64(v1, v2), 26.0, EPSILON_F64));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_dot_f32
    S_EXAM("s_vec3_dot_f32")
    {
        f32 v1[3], v2[3];

        // Orthogonal
        v1[0] = 1.0f;
        v1[1] = 0.0f;
        v1[2] = 0.0f;
        v2[0] = 0.0f;
        v2[1] = 1.0f;
        v2[2] = 0.0f;
        s_assert(s_approximately_f32(s_vec3_dot_f32(v1, v2), 0.0f, EPSILON_F32));

        // General case: 1*4 + 2*5 + 3*6 = 32
        v1[0] = 1.0f;
        v1[1] = 2.0f;
        v1[2] = 3.0f;
        v2[0] = 4.0f;
        v2[1] = 5.0f;
        v2[2] = 6.0f;
        s_assert(s_approximately_f32(s_vec3_dot_f32(v1, v2), 32.0f, EPSILON_F32));

        // Self dot = length squared
        v1[0] = 1.0f;
        v1[1] = 2.0f;
        v1[2] = 3.0f;
        s_assert(s_approximately_f32(s_vec3_dot_f32(v1, v1), 14.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_dot_f64
    S_EXAM("s_vec3_dot_f64")
    {
        f64 v1[3], v2[3];

        // Orthogonal
        v1[0] = 1.0;
        v1[1] = 0.0;
        v1[2] = 0.0;
        v2[0] = 0.0;
        v2[1] = 1.0;
        v2[2] = 0.0;
        s_assert(s_approximately_f64(s_vec3_dot_f64(v1, v2), 0.0, EPSILON_F64));

        // General case: 1*4 + 2*5 + 3*6 = 32
        v1[0] = 1.0;
        v1[1] = 2.0;
        v1[2] = 3.0;
        v2[0] = 4.0;
        v2[1] = 5.0;
        v2[2] = 6.0;
        s_assert(s_approximately_f64(s_vec3_dot_f64(v1, v2), 32.0, EPSILON_F64));
    }

    s_exam_log_summary();
    return 0;
}