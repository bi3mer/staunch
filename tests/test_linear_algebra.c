#include "staunch/exam.h"
#include "staunch/general_math.h"
#include "staunch/linear_algebra.h"

#define EPSILON_F32 1e-6f
#define EPSILON_F64 1e-12

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_length_f32
    {
        s_exam_begin("s_vec2_length_f32");

        // Unit vectors
        {
            f32 v1[2] = {1.0f, 0.0f};
            s_assert(s_approximately_f32(s_vec2_length_f32(v1), 1.0f, EPSILON_F32));

            f32 v2[2] = {0.0f, 1.0f};
            s_assert(s_approximately_f32(s_vec2_length_f32(v2), 1.0f, EPSILON_F32));
        }

        // Zero vector
        {
            f32 v[2] = {0.0f, 0.0f};
            s_assert(s_approximately_f32(s_vec2_length_f32(v), 0.0f, EPSILON_F32));
        }

        // 3-4-5 triangle
        {
            f32 v[2] = {3.0f, 4.0f};
            s_assert(s_approximately_f32(s_vec2_length_f32(v), 5.0f, EPSILON_F32));
        }

        // Negative components
        {
            f32 v[2] = {-3.0f, -4.0f};
            s_assert(s_approximately_f32(s_vec2_length_f32(v), 5.0f, EPSILON_F32));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_length_f64
    {
        s_exam_begin("s_vec2_length_f64");

        // Unit vectors
        {
            f64 v1[2] = {1.0, 0.0};
            s_assert(s_approximately_f64(s_vec2_length_f64(v1), 1.0, EPSILON_F64));

            f64 v2[2] = {0.0, 1.0};
            s_assert(s_approximately_f64(s_vec2_length_f64(v2), 1.0, EPSILON_F64));
        }

        // Zero vector
        {
            f64 v[2] = {0.0, 0.0};
            s_assert(s_approximately_f64(s_vec2_length_f64(v), 0.0, EPSILON_F64));
        }

        // 3-4-5 triangle
        {
            f64 v[2] = {3.0, 4.0};
            s_assert(s_approximately_f64(s_vec2_length_f64(v), 5.0, EPSILON_F64));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_length_f32
    {
        s_exam_begin("s_vec3_length_f32");

        // Unit vectors
        {
            f32 vx[3] = {1.0f, 0.0f, 0.0f};
            s_assert(s_approximately_f32(s_vec3_length_f32(vx), 1.0f, EPSILON_F32));

            f32 vy[3] = {0.0f, 1.0f, 0.0f};
            s_assert(s_approximately_f32(s_vec3_length_f32(vy), 1.0f, EPSILON_F32));

            f32 vz[3] = {0.0f, 0.0f, 1.0f};
            s_assert(s_approximately_f32(s_vec3_length_f32(vz), 1.0f, EPSILON_F32));
        }

        // Zero vector
        {
            f32 v[3] = {0.0f, 0.0f, 0.0f};
            s_assert(s_approximately_f32(s_vec3_length_f32(v), 0.0f, EPSILON_F32));
        }

        // Known length: sqrt(1 + 4 + 9) = sqrt(14)
        {
            f32 v[3] = {1.0f, 2.0f, 3.0f};
            s_assert(s_approximately_f32(s_vec3_length_f32(v), 3.7416573f, EPSILON_F32));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_length_f64
    {
        s_exam_begin("s_vec3_length_f64");

        // Unit vectors
        {
            f64 vx[3] = {1.0, 0.0, 0.0};
            s_assert(s_approximately_f64(s_vec3_length_f64(vx), 1.0, EPSILON_F64));
        }

        // Zero vector
        {
            f64 v[3] = {0.0, 0.0, 0.0};
            s_assert(s_approximately_f64(s_vec3_length_f64(v), 0.0, EPSILON_F64));
        }

        // Known length: sqrt(14)
        {
            f64 v[3] = {1.0, 2.0, 3.0};
            s_assert(
                s_approximately_f64(s_vec3_length_f64(v), 3.74165738677394, EPSILON_F64));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_length_squared_f32
    {
        s_exam_begin("s_vec2_length_squared_f32");

        // Unit vector
        {
            f32 v[2] = {1.0f, 0.0f};
            s_assert(
                s_approximately_f32(s_vec2_length_squared_f32(v), 1.0f, EPSILON_F32));
        }

        // Zero vector
        {
            f32 v[2] = {0.0f, 0.0f};
            s_assert(
                s_approximately_f32(s_vec2_length_squared_f32(v), 0.0f, EPSILON_F32));
        }

        // 3-4-5: squared = 25
        {
            f32 v[2] = {3.0f, 4.0f};
            s_assert(
                s_approximately_f32(s_vec2_length_squared_f32(v), 25.0f, EPSILON_F32));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_length_squared_f64
    {
        s_exam_begin("s_vec2_length_squared_f64");

        // 3-4-5: squared = 25
        {
            f64 v[2] = {3.0, 4.0};
            s_assert(
                s_approximately_f64(s_vec2_length_squared_f64(v), 25.0, EPSILON_F64));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_length_squared_f32
    {
        s_exam_begin("s_vec3_length_squared_f32");

        // 1^2 + 2^2 + 3^2 = 14
        {
            f32 v[3] = {1.0f, 2.0f, 3.0f};
            s_assert(
                s_approximately_f32(s_vec3_length_squared_f32(v), 14.0f, EPSILON_F32));
        }

        // Zero vector
        {
            f32 v[3] = {0.0f, 0.0f, 0.0f};
            s_assert(
                s_approximately_f32(s_vec3_length_squared_f32(v), 0.0f, EPSILON_F32));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_length_squared_f64
    {
        s_exam_begin("s_vec3_length_squared_f64");

        // 1^2 + 2^2 + 3^2 = 14
        {
            f64 v[3] = {1.0, 2.0, 3.0};
            s_assert(
                s_approximately_f64(s_vec3_length_squared_f64(v), 14.0, EPSILON_F64));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_dot_f32
    {
        s_exam_begin("s_vec2_dot_f32");

        // Orthogonal vectors
        {
            f32 v1[2] = {1.0f, 0.0f};
            f32 v2[2] = {0.0f, 1.0f};
            s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v2), 0.0f, EPSILON_F32));
        }

        // Parallel vectors (same direction)
        {
            f32 v1[2] = {1.0f, 0.0f};
            f32 v2[2] = {2.0f, 0.0f};
            s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v2), 2.0f, EPSILON_F32));
        }

        // Opposite direction
        {
            f32 v1[2] = {1.0f, 0.0f};
            f32 v2[2] = {-1.0f, 0.0f};
            s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v2), -1.0f, EPSILON_F32));
        }

        // General case
        {
            f32 v1[2] = {3.0f, 4.0f};
            f32 v2[2] = {2.0f, 5.0f};
            s_assert(s_approximately_f32(s_vec2_dot_f32(v1, v2), 26.0f, EPSILON_F32));
        }

        // Self dot = length squared
        {
            f32 v[2] = {3.0f, 4.0f};
            s_assert(s_approximately_f32(s_vec2_dot_f32(v, v), 25.0f, EPSILON_F32));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec2_dot_f64
    {
        s_exam_begin("s_vec2_dot_f64");

        // Orthogonal
        {
            f64 v1[2] = {1.0, 0.0};
            f64 v2[2] = {0.0, 1.0};
            s_assert(s_approximately_f64(s_vec2_dot_f64(v1, v2), 0.0, EPSILON_F64));
        }

        // General case
        {
            f64 v1[2] = {3.0, 4.0};
            f64 v2[2] = {2.0, 5.0};
            s_assert(s_approximately_f64(s_vec2_dot_f64(v1, v2), 26.0, EPSILON_F64));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_dot_f32
    {
        s_exam_begin("s_vec3_dot_f32");

        // Orthogonal
        {
            f32 v1[3] = {1.0f, 0.0f, 0.0f};
            f32 v2[3] = {0.0f, 1.0f, 0.0f};
            s_assert(s_approximately_f32(s_vec3_dot_f32(v1, v2), 0.0f, EPSILON_F32));
        }

        // General case: 1*4 + 2*5 + 3*6 = 32
        {
            f32 v1[3] = {1.0f, 2.0f, 3.0f};
            f32 v2[3] = {4.0f, 5.0f, 6.0f};
            s_assert(s_approximately_f32(s_vec3_dot_f32(v1, v2), 32.0f, EPSILON_F32));
        }

        // Self dot = length squared
        {
            f32 v[3] = {1.0f, 2.0f, 3.0f};
            s_assert(s_approximately_f32(s_vec3_dot_f32(v, v), 14.0f, EPSILON_F32));
        }

        s_exam_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_vec3_dot_f64
    {
        s_exam_begin("s_vec3_dot_f64");

        // Orthogonal
        {
            f64 v1[3] = {1.0, 0.0, 0.0};
            f64 v2[3] = {0.0, 1.0, 0.0};
            s_assert(s_approximately_f64(s_vec3_dot_f64(v1, v2), 0.0, EPSILON_F64));
        }

        // General case: 1*4 + 2*5 + 3*6 = 32
        {
            f64 v1[3] = {1.0, 2.0, 3.0};
            f64 v2[3] = {4.0, 5.0, 6.0};
            s_assert(s_approximately_f64(s_vec3_dot_f64(v1, v2), 32.0, EPSILON_F64));
        }

        s_exam_end();
    }

    return 0;
}
