#include <stdio.h>

#include "staunch/exam.h"
#include "staunch/random.h"

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_rand_init determinism
    S_EXAM("s_rand_init determinism")
    {
        s_rand_init(12345);
        u32 a1 = s_rand_u32(0, 1000);
        u32 a2 = s_rand_u32(0, 1000);
        u32 a3 = s_rand_u32(0, 1000);

        s_rand_init(12345);
        u32 b1 = s_rand_u32(0, 1000);
        u32 b2 = s_rand_u32(0, 1000);
        u32 b3 = s_rand_u32(0, 1000);

        s_assert(a1 == b1);
        s_assert(a2 == b2);
        s_assert(a3 == b3);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_bool
    S_EXAM("s_rand_bool")
    {
        s_rand_init(42);
        int trues = 0;
        int falses = 0;

        for (int i = 0; i < 1000; ++i)
        {
            if (s_rand_bool())
                ++trues;
            else
                ++falses;
        }

        // should have some of each
        s_assert(trues > 0);
        s_assert(falses > 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_u8
    S_EXAM("s_rand_u8")
    {
        s_rand_init(42);

        // range check
        for (int i = 0; i < 1000; ++i)
        {
            u8 val = s_rand_u8(10, 20);
            s_assert(val >= 10 && val <= 20);
        }

        // min == max
        u8 fixed = s_rand_u8(50, 50);
        s_assert(fixed == 50);

        // full range
        u8 full = s_rand_u8(0, 255);
        s_assert(full <= 255);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_u8 invalid range
    S_EXAM("s_rand_u8 invalid range")
    {
        s_rand_init(42);
        s_exam_expect_fail(s_rand_u8(20, 10));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_u16
    S_EXAM("s_rand_u16")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            u16 val = s_rand_u16(100, 500);
            s_assert(val >= 100 && val <= 500);
        }

        u16 fixed = s_rand_u16(1000, 1000);
        s_assert(fixed == 1000);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_u32
    S_EXAM("s_rand_u32")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            u32 val = s_rand_u32(1000, 2000);
            s_assert(val >= 1000 && val <= 2000);
        }

        u32 fixed = s_rand_u32(999999, 999999);
        s_assert(fixed == 999999);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_u64
    S_EXAM("s_rand_u64")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            u64 val = s_rand_u64(10000, 20000);
            s_assert(val >= 10000 && val <= 20000);
        }

        u64 fixed = s_rand_u64(123456789, 123456789);
        s_assert(fixed == 123456789);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_i8
    S_EXAM("s_rand_i8")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            i8 val = s_rand_i8(-50, 50);
            s_assert(val >= -50 && val <= 50);
        }

        // negative range
        for (int i = 0; i < 1000; ++i)
        {
            i8 val = s_rand_i8(-100, -10);
            s_assert(val >= -100 && val <= -10);
        }

        i8 fixed = s_rand_i8(-5, -5);
        s_assert(fixed == -5);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_i8 invalid range
    S_EXAM("s_rand_i8 invalid range")
    {
        s_rand_init(42);
        s_exam_expect_fail(s_rand_i8(10, -10));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_i16
    S_EXAM("s_rand_i16")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            i16 val = s_rand_i16(-1000, 1000);
            s_assert(val >= -1000 && val <= 1000);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_i32
    S_EXAM("s_rand_i32")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            i32 val = s_rand_i32(-100000, 100000);
            s_assert(val >= -100000 && val <= 100000);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_i64
    S_EXAM("s_rand_i64")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            i64 val = s_rand_i64(-1000000, 1000000);
            s_assert(val >= -1000000 && val <= 1000000);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_f32
    S_EXAM("s_rand_f32")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            f32 val = s_rand_f32(-10.0f, 10.0f);
            s_assert(val >= -10.0f && val <= 10.0f);
        }

        // min == max
        f32 fixed = s_rand_f32(5.5f, 5.5f);
        s_assert(fixed == 5.5f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_f32 invalid range
    S_EXAM("s_rand_f32 invalid range")
    {
        s_rand_init(42);
        s_exam_expect_fail(s_rand_f32(10.0f, -10.0f));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_f32_01
    S_EXAM("s_rand_f32_01")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            f32 val = s_rand_f32_01();
            s_assert(val >= 0.0f && val <= 1.0f);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_f64
    S_EXAM("s_rand_f64")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            f64 val = s_rand_f64(-100.0, 100.0);
            s_assert(val >= -100.0 && val <= 100.0);
        }

        f64 fixed = s_rand_f64(3.14, 3.14);
        s_assert(fixed == 3.14);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_f64_01
    S_EXAM("s_rand_f64_01")
    {
        s_rand_init(42);

        for (int i = 0; i < 1000; ++i)
        {
            f64 val = s_rand_f64_01();
            s_assert(val >= 0.0 && val <= 1.0);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_choice
    S_EXAM("s_rand_choice")
    {
        s_rand_init(42);

        int arr[] = {10, 20, 30, 40, 50};
        int len = 5;

        for (int i = 0; i < 1000; ++i)
        {
            int val = s_rand_choice(arr, len);
            s_assert(val == 10 || val == 20 || val == 30 || val == 40 || val == 50);
        }

        // single element
        int single[] = {999};
        int val = s_rand_choice(single, 1);
        s_assert(val == 999);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_rand_choice empty array
    S_EXAM("s_rand_choice empty array")
    {
        s_rand_init(42);
        int arr[] = {1};
        s_exam_expect_fail((void)s_rand_choice(arr, 0));
    }

    s_exam_log_summary();
    return 0;
}