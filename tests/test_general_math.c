#include "staunch/exam.h"
#include "staunch/general_math.h"
#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_approximately_f32
    S_EXAM("s_approximately_f32")
    {
        s_assert(s_approximately_f32(2.f, 1.999991f, 0.01f));
        s_assert(s_approximately_f32(2.f, 1.999991f, 0.001f));
        s_assert(s_approximately_f32(2.f, 1.999991f, 0.0001f));
        s_assert(s_approximately_f32(2.f, 1.999991f, 0.00001f));
        s_assert(!s_approximately_f32(2.f, 1.999991f, 0.000001f));
        // Exact match
        s_assert(s_approximately_f32(5.0f, 5.0f, 0.0001f));
        // Negative numbers
        s_assert(s_approximately_f32(-2.0f, -1.999f, 0.01f));
        s_assert(!s_approximately_f32(-2.0f, -1.9f, 0.01f));
        // Zero
        s_assert(s_approximately_f32(0.0f, 0.0001f, 0.001f));
        s_assert(!s_approximately_f32(0.0f, 0.01f, 0.001f));
        // Reverse order (b > a)
        s_assert(s_approximately_f32(1.999f, 2.0f, 0.01f));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_approximately_f64
    S_EXAM("s_approximately_f64")
    {
        s_assert(s_approximately_f64(2.0, 1.999991, 0.01));
        s_assert(s_approximately_f64(2.0, 1.999991, 0.001));
        s_assert(s_approximately_f64(2.0, 1.999991, 0.0001));
        s_assert(s_approximately_f64(2.0, 1.999991, 0.00001));
        s_assert(!s_approximately_f64(2.0, 1.999991, 0.000001));
        // High precision
        s_assert(
            s_approximately_f64(3.14159265358979, 3.14159265358978, 0.00000000000001));
        s_assert(
            !s_approximately_f64(3.14159265358979, 3.14159265358978, 0.000000000000001));
        // Negative numbers
        s_assert(s_approximately_f64(-100.5, -100.50001, 0.001));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_i8
    S_EXAM("s_min_i8")
    {
        s_assert(s_min_i8(-3, 127) == -3);
        s_assert(s_min_i8(127, -127) == -127);
        s_assert(s_min_i8(0, 0) == 0);
        s_assert(s_min_i8(-128, -127) == -128);
        s_assert(s_min_i8(5, 5) == 5);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_i16
    S_EXAM("s_min_i16")
    {
        s_assert(s_min_i16(-3, 32767) == -3);
        s_assert(s_min_i16(32767, -32767) == -32767);
        s_assert(s_min_i16(0, 0) == 0);
        s_assert(s_min_i16(-32768, 100) == -32768);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_i32
    S_EXAM("s_min_i32")
    {
        s_assert(s_min_i32(-3, 2147483647) == -3);
        s_assert(s_min_i32(2147483647, -2147483648) == -2147483648);
        s_assert(s_min_i32(0, 0) == 0);
        s_assert(s_min_i32(1000, 999) == 999);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_i64
    S_EXAM("s_min_i64")
    {
        s_assert(s_min_i64(-3LL, 9223372036854775807LL) == -3LL);
        s_assert(s_min_i64(100LL, 100LL) == 100LL);
        s_assert(s_min_i64(0LL, -1LL) == -1LL);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_u8
    S_EXAM("s_min_u8")
    {
        s_assert(s_min_u8(3, 255) == 3);
        s_assert(s_min_u8(0, 0) == 0);
        s_assert(s_min_u8(128, 127) == 127);
        s_assert(s_min_u8(255, 254) == 254);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_u16
    S_EXAM("s_min_u16")
    {
        s_assert(s_min_u16(3, 65535) == 3);
        s_assert(s_min_u16(0, 1) == 0);
        s_assert(s_min_u16(32768, 32767) == 32767);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_u32
    S_EXAM("s_min_u32")
    {
        s_assert(s_min_u32(3, 4294967295U) == 3);
        s_assert(s_min_u32(0, 0) == 0);
        s_assert(s_min_u32(1000000, 999999) == 999999);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_u64
    S_EXAM("s_min_u64")
    {
        s_assert(s_min_u64(3ULL, 18446744073709551615ULL) == 3ULL);
        s_assert(s_min_u64(100ULL, 100ULL) == 100ULL);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_f32
    S_EXAM("s_min_f32")
    {
        s_assert(s_min_f32(1.5f, 2.5f) == 1.5f);
        s_assert(s_min_f32(-1.5f, 1.5f) == -1.5f);
        s_assert(s_min_f32(0.0f, 0.0f) == 0.0f);
        s_assert(s_min_f32(-100.5f, -100.6f) == -100.6f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_f64
    S_EXAM("s_min_f64")
    {
        s_assert(s_min_f64(1.5, 2.5) == 1.5);
        s_assert(s_min_f64(-1.5, 1.5) == -1.5);
        s_assert(s_min_f64(0.0, 0.0) == 0.0);
        s_assert(s_min_f64(3.14159, 3.14160) == 3.14159);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_i8
    S_EXAM("s_max_i8")
    {
        s_assert(s_max_i8(-3, 127) == 127);
        s_assert(s_max_i8(127, -127) == 127);
        s_assert(s_max_i8(0, 0) == 0);
        s_assert(s_max_i8(-128, -127) == -127);
        s_assert(s_max_i8(5, 5) == 5);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_i16
    S_EXAM("s_max_i16")
    {
        s_assert(s_max_i16(-3, 32767) == 32767);
        s_assert(s_max_i16(32767, -32767) == 32767);
        s_assert(s_max_i16(0, 0) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_i32
    S_EXAM("s_max_i32")
    {
        s_assert(s_max_i32(-3, 2147483647) == 2147483647);
        s_assert(s_max_i32(2147483647, -2147483648) == 2147483647);
        s_assert(s_max_i32(1000, 999) == 1000);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_i64
    S_EXAM("s_max_i64")
    {
        s_assert(s_max_i64(-3LL, 9223372036854775807LL) == 9223372036854775807LL);
        s_assert(s_max_i64(100LL, 100LL) == 100LL);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_u8
    S_EXAM("s_max_u8")
    {
        s_assert(s_max_u8(3, 255) == 255);
        s_assert(s_max_u8(0, 0) == 0);
        s_assert(s_max_u8(128, 127) == 128);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_u16
    S_EXAM("s_max_u16")
    {
        s_assert(s_max_u16(3, 65535) == 65535);
        s_assert(s_max_u16(32768, 32767) == 32768);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_u32
    S_EXAM("s_max_u32")
    {
        s_assert(s_max_u32(3, 4294967295U) == 4294967295U);
        s_assert(s_max_u32(1000000, 999999) == 1000000);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_u64
    S_EXAM("s_max_u64")
    {
        s_assert(s_max_u64(3ULL, 18446744073709551615ULL) == 18446744073709551615ULL);
        s_assert(s_max_u64(100ULL, 100ULL) == 100ULL);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_f32
    S_EXAM("s_max_f32")
    {
        s_assert(s_max_f32(1.5f, 2.5f) == 2.5f);
        s_assert(s_max_f32(-1.5f, 1.5f) == 1.5f);
        s_assert(s_max_f32(0.0f, 0.0f) == 0.0f);
        s_assert(s_max_f32(-100.5f, -100.6f) == -100.5f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_f64
    S_EXAM("s_max_f64")
    {
        s_assert(s_max_f64(1.5, 2.5) == 2.5);
        s_assert(s_max_f64(-1.5, 1.5) == 1.5);
        s_assert(s_max_f64(3.14159, 3.14160) == 3.14160);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_i8
    S_EXAM("s_clamp_i8")
    {
        // Invalid range (should assert)
        s_exam_expect_fail(s_clamp_i8(10, 0, -10));

        // Valid clamps
        s_assert(s_clamp_i8(-10, -15, 10) == -10);     // Below min
        s_assert(s_clamp_i8(-10, 15, 10) == 10);       // Above max
        s_assert(s_clamp_i8(-10, 0, 10) == 0);         // Within range
        s_assert(s_clamp_i8(0, 0, 100) == 0);          // At min
        s_assert(s_clamp_i8(0, 100, 100) == 100);      // At max
        s_assert(s_clamp_i8(-127, -127, 127) == -127); // Extreme low
        s_assert(s_clamp_i8(-128, 127, 127) == 127);   // Extreme high
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_i16
    S_EXAM("s_clamp_i16")
    {
        s_assert(s_clamp_i16(-100, -150, 100) == -100);
        s_assert(s_clamp_i16(-100, 150, 100) == 100);
        s_assert(s_clamp_i16(-100, 50, 100) == 50);
        s_assert(s_clamp_i16(0, -1, 0) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_i32
    S_EXAM("s_clamp_i32")
    {
        s_assert(s_clamp_i32(-1000, -2000, 1000) == -1000);
        s_assert(s_clamp_i32(-1000, 2000, 1000) == 1000);
        s_assert(s_clamp_i32(-1000, 0, 1000) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_i64
    S_EXAM("s_clamp_i64")
    {
        s_assert(s_clamp_i64(-1000LL, -2000LL, 1000LL) == -1000LL);
        s_assert(s_clamp_i64(-1000LL, 2000LL, 1000LL) == 1000LL);
        s_assert(s_clamp_i64(-1000LL, 500LL, 1000LL) == 500LL);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_u8
    S_EXAM("s_clamp_u8")
    {
        s_assert(s_clamp_u8(10, 5, 100) == 10);    // Below min
        s_assert(s_clamp_u8(10, 150, 100) == 100); // Above max
        s_assert(s_clamp_u8(10, 50, 100) == 50);   // Within range
        s_assert(s_clamp_u8(0, 0, 255) == 0);      // At min
        s_assert(s_clamp_u8(0, 255, 255) == 255);  // At max
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_u16
    S_EXAM("s_clamp_u16")
    {
        s_assert(s_clamp_u16(100, 50, 1000) == 100);
        s_assert(s_clamp_u16(100, 2000, 1000) == 1000);
        s_assert(s_clamp_u16(100, 500, 1000) == 500);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_u32
    S_EXAM("s_clamp_u32")
    {
        s_assert(s_clamp_u32(1000, 500, 10000) == 1000);
        s_assert(s_clamp_u32(1000, 20000, 10000) == 10000);
        s_assert(s_clamp_u32(1000, 5000, 10000) == 5000);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_u64
    S_EXAM("s_clamp_u64")
    {
        s_assert(s_clamp_u64(1000ULL, 500ULL, 10000ULL) == 1000ULL);
        s_assert(s_clamp_u64(1000ULL, 20000ULL, 10000ULL) == 10000ULL);
        s_assert(s_clamp_u64(1000ULL, 5000ULL, 10000ULL) == 5000ULL);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_32 (f32)
    S_EXAM("s_clamp_f32")
    {
        s_assert(s_clamp_f32(-1.0f, -2.0f, 1.0f) == -1.0f);
        s_assert(s_clamp_f32(-1.0f, 2.0f, 1.0f) == 1.0f);
        s_assert(s_clamp_f32(-1.0f, 0.5f, 1.0f) == 0.5f);
        s_assert(s_clamp_f32(0.0f, -0.1f, 1.0f) == 0.0f);
        s_assert(s_clamp_f32(0.0f, 1.1f, 1.0f) == 1.0f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_f64
    S_EXAM("s_clamp_f64")
    {
        s_assert(s_clamp_f64(-1.0, -2.0, 1.0) == -1.0);
        s_assert(s_clamp_f64(-1.0, 2.0, 1.0) == 1.0);
        s_assert(s_clamp_f64(-1.0, 0.5, 1.0) == 0.5);
        s_assert(s_clamp_f64(-3.14159, -5.0, 3.14159) == -3.14159);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_i8
    S_EXAM("s_in_between_i8")
    {
        // Invalid range (should assert)
        s_exam_expect_fail(s_in_between_i8(10, 5, -10));

        // Valid checks
        s_assert(s_in_between_i8(-10, -10, 10));  // At min (inclusive)
        s_assert(s_in_between_i8(-10, 10, 10));   // At max (inclusive)
        s_assert(s_in_between_i8(-10, 0, 10));    // In middle
        s_assert(!s_in_between_i8(-10, -11, 10)); // Below min
        s_assert(!s_in_between_i8(-10, 11, 10));  // Above max
        s_assert(s_in_between_i8(0, 0, 0));       // Single value
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_i16
    S_EXAM("s_in_between_i16")
    {
        s_assert(s_in_between_i16(-100, -100, 100));
        s_assert(s_in_between_i16(-100, 100, 100));
        s_assert(s_in_between_i16(-100, 0, 100));
        s_assert(!s_in_between_i16(-100, -101, 100));
        s_assert(!s_in_between_i16(-100, 101, 100));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_i32
    S_EXAM("s_in_between_i32")
    {
        s_assert(s_in_between_i32(-1000, -1000, 1000));
        s_assert(s_in_between_i32(-1000, 1000, 1000));
        s_assert(s_in_between_i32(-1000, 0, 1000));
        s_assert(!s_in_between_i32(-1000, -1001, 1000));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_i64
    S_EXAM("s_in_between_i64")
    {
        s_assert(s_in_between_i64(-1000LL, -1000LL, 1000LL));
        s_assert(s_in_between_i64(-1000LL, 1000LL, 1000LL));
        s_assert(s_in_between_i64(-1000LL, 0LL, 1000LL));
        s_assert(!s_in_between_i64(-1000LL, 1001LL, 1000LL));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_u8
    S_EXAM("s_in_between_u8")
    {
        s_assert(s_in_between_u8(10, 10, 100));
        s_assert(s_in_between_u8(10, 100, 100));
        s_assert(s_in_between_u8(10, 50, 100));
        s_assert(!s_in_between_u8(10, 9, 100));
        s_assert(!s_in_between_u8(10, 101, 100));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_u16
    S_EXAM("s_in_between_u16")
    {
        s_assert(s_in_between_u16(100, 100, 1000));
        s_assert(s_in_between_u16(100, 1000, 1000));
        s_assert(s_in_between_u16(100, 500, 1000));
        s_assert(!s_in_between_u16(100, 99, 1000));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_u32
    S_EXAM("s_in_between_u32")
    {
        s_assert(s_in_between_u32(1000, 1000, 10000));
        s_assert(s_in_between_u32(1000, 10000, 10000));
        s_assert(s_in_between_u32(1000, 5000, 10000));
        s_assert(!s_in_between_u32(1000, 10001, 10000));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_u64
    S_EXAM("s_in_between_u64")
    {
        s_assert(s_in_between_u64(1000ULL, 1000ULL, 10000ULL));
        s_assert(s_in_between_u64(1000ULL, 10000ULL, 10000ULL));
        s_assert(s_in_between_u64(1000ULL, 5000ULL, 10000ULL));
        s_assert(!s_in_between_u64(1000ULL, 999ULL, 10000ULL));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_modulus_i8
    S_EXAM("s_modulus_i8")
    {
        // Invalid divisor (should assert)
        s_exam_expect_fail(s_modulus_i8(5, 0));
        s_exam_expect_fail(s_modulus_i8(5, -3));

        // Positive number
        s_assert(s_modulus_i8(10, 3) == 1);
        s_assert(s_modulus_i8(15, 4) == 3);

        // Negative number (mathematically correct modulus)
        s_assert(s_modulus_i8(-10, 3) == 2); // -10 % 3 = -1, then -1 + 3 = 2
        s_assert(s_modulus_i8(-15, 4) == 1); // -15 % 4 = -3, then -3 + 4 = 1
        s_assert(s_modulus_i8(-1, 5) == 4);  // -1 % 5 = -1, then -1 + 5 = 4

        // Exact division
        s_assert(s_modulus_i8(10, 5) == 0);
        s_assert(s_modulus_i8(-10, 5) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_modulus_i16
    S_EXAM("s_modulus_i16")
    {
        // Invalid divisor (should assert)
        s_exam_expect_fail(s_modulus_i16(5, 0));
        s_exam_expect_fail(s_modulus_i16(5, -3));

        // valid tests
        s_assert(s_modulus_i16(100, 7) == 2);
        s_assert(s_modulus_i16(-100, 7) == 5); // -100 % 7 = -2, then -2 + 7 = 5
        s_assert(s_modulus_i16(50, 10) == 0);
        s_assert(s_modulus_i16(-50, 10) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_modulus_i32
    S_EXAM("s_modulus_i32")
    {
        // Invalid divisor (should assert)
        s_exam_expect_fail(s_modulus_i32(5, 0));
        s_exam_expect_fail(s_modulus_i32(5, -3));

        // valid tests
        s_assert(s_modulus_i32(1000, 13) == 12);
        s_assert(s_modulus_i32(-1000, 13) == 1); // -1000 % 13 = -12, then -12 + 13 = 1
        s_assert(s_modulus_i32(360, 360) == 0);
        s_assert(s_modulus_i32(-360, 360) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_modulus_i64
    S_EXAM("s_modulus_i64")
    {
        // Invalid divisor (should assert)
        s_exam_expect_fail(s_modulus_i64(5, 0));
        s_exam_expect_fail(s_modulus_i64(5, -3));

        // valid tests
        s_assert(s_modulus_i64(10000LL, 17LL) == 4LL);
        s_assert(s_modulus_i64(-10000LL, 17LL) == 13LL);
        s_assert(s_modulus_i64(1000000LL, 1000LL) == 0LL);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_lerp_f32
    S_EXAM("s_lerp_f32")
    {
        s_exam_expect_fail(s_lerp_f32(-100.f, 12.f, -0.0001f));
        s_exam_expect_fail(s_lerp_f32(-100.f, 12.f, 1.0001f));

        s_assert(s_lerp_f32(-10.f, 10.f, 0.0f) == -10.0f);
        s_assert(s_lerp_f32(-10.f, 10.f, 0.5f) == 0.0f);
        s_assert(s_lerp_f32(-10.f, 10.f, 1.0f) == 10.0f);

        s_assert(s_lerp_f32(0.f, 100.f, 0.25f) == 25.0f);
        s_assert(s_lerp_f32(0.f, 100.f, 0.75f) == 75.0f);

        s_assert(s_lerp_f32(10.f, -10.f, 0.0f) == 10.0f);
        s_assert(s_lerp_f32(10.f, -10.f, 0.5f) == 0.0f);
        s_assert(s_lerp_f32(10.f, -10.f, 1.0f) == -10.0f);

        s_assert(s_lerp_f32(5.f, 5.f, 0.0f) == 5.0f);
        s_assert(s_lerp_f32(5.f, 5.f, 0.5f) == 5.0f);
        s_assert(s_lerp_f32(5.f, 5.f, 1.0f) == 5.0f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_lerp_f64
    S_EXAM("s_lerp_f64")
    {
        s_exam_expect_fail(s_lerp_f64(-100.0, 12.0, -0.0001));
        s_exam_expect_fail(s_lerp_f64(-100.0, 12.0, 1.0001));

        s_assert(s_lerp_f64(-10.0, 10.0, 0.00) == -10.0);
        s_assert(s_lerp_f64(-10.0, 10.0, 0.50) == 0.0);
        s_assert(s_lerp_f64(-10.0, 10.0, 1.00) == 10.0);

        s_assert(s_lerp_f64(0.0, 100.0, 0.25) == 25.0);
        s_assert(s_lerp_f64(0.0, 100.0, 0.75) == 75.0);

        s_assert(s_lerp_f64(10.0, -10.0, 0.00) == 10.0);
        s_assert(s_lerp_f64(10.0, -10.0, 0.50) == 0.0);
        s_assert(s_lerp_f64(10.0, -10.0, 1.00) == -10.0);

        s_assert(s_lerp_f64(5.0, 5.0, 0.00) == 5.0);
        s_assert(s_lerp_f64(5.0, 5.0, 0.50) == 5.0);
        s_assert(s_lerp_f64(5.0, 5.0, 1.00) == 5.0);
    }

    s_exam_log_summary();
    return 0;
}
