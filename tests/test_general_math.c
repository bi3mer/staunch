#include "staunch/exam.h"
#include "staunch/general_math.h"
#include <float.h>
#include <limits.h>

int main()
{
    ///////////////////////////////////////////////////////////////////////////
    // s_approximately_f32
    {
        e_begin("s_approximately_f32");
        e_assert(s_approximately_f32(2.f, 1.999991f, 0.01f));
        e_assert(s_approximately_f32(2.f, 1.999991f, 0.001f));
        e_assert(s_approximately_f32(2.f, 1.999991f, 0.0001f));
        e_assert(s_approximately_f32(2.f, 1.999991f, 0.00001f));
        e_assert(!s_approximately_f32(2.f, 1.999991f, 0.000001f));

        // Exact match
        e_assert(s_approximately_f32(5.0f, 5.0f, 0.0001f));

        // Negative numbers
        e_assert(s_approximately_f32(-2.0f, -1.999f, 0.01f));
        e_assert(!s_approximately_f32(-2.0f, -1.9f, 0.01f));

        // Zero
        e_assert(s_approximately_f32(0.0f, 0.0001f, 0.001f));
        e_assert(!s_approximately_f32(0.0f, 0.01f, 0.001f));

        // Reverse order (b > a)
        e_assert(s_approximately_f32(1.999f, 2.0f, 0.01f));

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_approximately_f64
    {
        e_begin("s_approximately_f64");
        e_assert(s_approximately_f64(2.0, 1.999991, 0.01));
        e_assert(s_approximately_f64(2.0, 1.999991, 0.001));
        e_assert(s_approximately_f64(2.0, 1.999991, 0.0001));
        e_assert(s_approximately_f64(2.0, 1.999991, 0.00001));
        e_assert(!s_approximately_f64(2.0, 1.999991, 0.000001));

        // High precision
        e_assert(
            s_approximately_f64(3.14159265358979, 3.14159265358978, 0.00000000000001));
        e_assert(
            !s_approximately_f64(3.14159265358979, 3.14159265358978, 0.000000000000001));

        // Negative numbers
        e_assert(s_approximately_f64(-100.5, -100.50001, 0.001));

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_i8
    {
        e_begin("s_min_i8");
        e_assert(s_min_i8(-3, 127) == -3);
        e_assert(s_min_i8(127, -127) == -127);
        e_assert(s_min_i8(0, 0) == 0);
        e_assert(s_min_i8(-128, -127) == -128);
        e_assert(s_min_i8(5, 5) == 5);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_i16
    {
        e_begin("s_min_i16");
        e_assert(s_min_i16(-3, 32767) == -3);
        e_assert(s_min_i16(32767, -32767) == -32767);
        e_assert(s_min_i16(0, 0) == 0);
        e_assert(s_min_i16(-32768, 100) == -32768);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_i32
    {
        e_begin("s_min_i32");
        e_assert(s_min_i32(-3, 2147483647) == -3);
        e_assert(s_min_i32(2147483647, -2147483648) == -2147483648);
        e_assert(s_min_i32(0, 0) == 0);
        e_assert(s_min_i32(1000, 999) == 999);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_i64
    {
        e_begin("s_min_i64");
        e_assert(s_min_i64(-3LL, 9223372036854775807LL) == -3LL);
        e_assert(s_min_i64(100LL, 100LL) == 100LL);
        e_assert(s_min_i64(0LL, -1LL) == -1LL);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_u8
    {
        e_begin("s_min_u8");
        e_assert(s_min_u8(3, 255) == 3);
        e_assert(s_min_u8(0, 0) == 0);
        e_assert(s_min_u8(128, 127) == 127);
        e_assert(s_min_u8(255, 254) == 254);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_u16
    {
        e_begin("s_min_u16");
        e_assert(s_min_u16(3, 65535) == 3);
        e_assert(s_min_u16(0, 1) == 0);
        e_assert(s_min_u16(32768, 32767) == 32767);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_u32
    {
        e_begin("s_min_u32");
        e_assert(s_min_u32(3, 4294967295U) == 3);
        e_assert(s_min_u32(0, 0) == 0);
        e_assert(s_min_u32(1000000, 999999) == 999999);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_u64
    {
        e_begin("s_min_u64");
        e_assert(s_min_u64(3ULL, 18446744073709551615ULL) == 3ULL);
        e_assert(s_min_u64(100ULL, 100ULL) == 100ULL);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_f32
    {
        e_begin("s_min_f32");
        e_assert(s_min_f32(1.5f, 2.5f) == 1.5f);
        e_assert(s_min_f32(-1.5f, 1.5f) == -1.5f);
        e_assert(s_min_f32(0.0f, 0.0f) == 0.0f);
        e_assert(s_min_f32(-100.5f, -100.6f) == -100.6f);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_min_f64
    {
        e_begin("s_min_f64");
        e_assert(s_min_f64(1.5, 2.5) == 1.5);
        e_assert(s_min_f64(-1.5, 1.5) == -1.5);
        e_assert(s_min_f64(0.0, 0.0) == 0.0);
        e_assert(s_min_f64(3.14159, 3.14160) == 3.14159);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_i8
    {
        e_begin("s_max_i8");
        e_assert(s_max_i8(-3, 127) == 127);
        e_assert(s_max_i8(127, -127) == 127);
        e_assert(s_max_i8(0, 0) == 0);
        e_assert(s_max_i8(-128, -127) == -127);
        e_assert(s_max_i8(5, 5) == 5);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_i16
    {
        e_begin("s_max_i16");
        e_assert(s_max_i16(-3, 32767) == 32767);
        e_assert(s_max_i16(32767, -32767) == 32767);
        e_assert(s_max_i16(0, 0) == 0);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_i32
    {
        e_begin("s_max_i32");
        e_assert(s_max_i32(-3, 2147483647) == 2147483647);
        e_assert(s_max_i32(2147483647, -2147483648) == 2147483647);
        e_assert(s_max_i32(1000, 999) == 1000);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_i64
    {
        e_begin("s_max_i64");
        e_assert(s_max_i64(-3LL, 9223372036854775807LL) == 9223372036854775807LL);
        e_assert(s_max_i64(100LL, 100LL) == 100LL);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_u8
    {
        e_begin("s_max_u8");
        e_assert(s_max_u8(3, 255) == 255);
        e_assert(s_max_u8(0, 0) == 0);
        e_assert(s_max_u8(128, 127) == 128);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_u16
    {
        e_begin("s_max_u16");
        e_assert(s_max_u16(3, 65535) == 65535);
        e_assert(s_max_u16(32768, 32767) == 32768);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_u32
    {
        e_begin("s_max_u32");
        e_assert(s_max_u32(3, 4294967295U) == 4294967295U);
        e_assert(s_max_u32(1000000, 999999) == 1000000);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_u64
    {
        e_begin("s_max_u64");
        e_assert(s_max_u64(3ULL, 18446744073709551615ULL) == 18446744073709551615ULL);
        e_assert(s_max_u64(100ULL, 100ULL) == 100ULL);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_f32
    {
        e_begin("s_max_f32");
        e_assert(s_max_f32(1.5f, 2.5f) == 2.5f);
        e_assert(s_max_f32(-1.5f, 1.5f) == 1.5f);
        e_assert(s_max_f32(0.0f, 0.0f) == 0.0f);
        e_assert(s_max_f32(-100.5f, -100.6f) == -100.5f);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_max_f64
    {
        e_begin("s_max_f64");
        e_assert(s_max_f64(1.5, 2.5) == 2.5);
        e_assert(s_max_f64(-1.5, 1.5) == 1.5);
        e_assert(s_max_f64(3.14159, 3.14160) == 3.14160);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_i8
    {
        e_begin("s_clamp_i8");

        // Invalid range (should assert)
        e_expect_assert_fail();
        e_assert(s_clamp_i8(10, 0, -10));

        // Valid clamps
        e_assert(s_clamp_i8(-10, -15, 10) == -10);     // Below min
        e_assert(s_clamp_i8(-10, 15, 10) == 10);       // Above max
        e_assert(s_clamp_i8(-10, 0, 10) == 0);         // Within range
        e_assert(s_clamp_i8(0, 0, 100) == 0);          // At min
        e_assert(s_clamp_i8(0, 100, 100) == 100);      // At max
        e_assert(s_clamp_i8(-127, -127, 127) == -127); // Extreme low
        e_assert(s_clamp_i8(-128, 127, 127) == 127);   // Extreme high

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_i16
    {
        e_begin("s_clamp_i16");
        e_assert(s_clamp_i16(-100, -150, 100) == -100);
        e_assert(s_clamp_i16(-100, 150, 100) == 100);
        e_assert(s_clamp_i16(-100, 50, 100) == 50);
        e_assert(s_clamp_i16(0, -1, 0) == 0);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_i32
    {
        e_begin("s_clamp_i32");
        e_assert(s_clamp_i32(-1000, -2000, 1000) == -1000);
        e_assert(s_clamp_i32(-1000, 2000, 1000) == 1000);
        e_assert(s_clamp_i32(-1000, 0, 1000) == 0);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_i64
    {
        e_begin("s_clamp_i64");
        e_assert(s_clamp_i64(-1000LL, -2000LL, 1000LL) == -1000LL);
        e_assert(s_clamp_i64(-1000LL, 2000LL, 1000LL) == 1000LL);
        e_assert(s_clamp_i64(-1000LL, 500LL, 1000LL) == 500LL);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_u8
    {
        e_begin("s_clamp_u8");
        e_assert(s_clamp_u8(10, 5, 100) == 10);    // Below min
        e_assert(s_clamp_u8(10, 150, 100) == 100); // Above max
        e_assert(s_clamp_u8(10, 50, 100) == 50);   // Within range
        e_assert(s_clamp_u8(0, 0, 255) == 0);      // At min
        e_assert(s_clamp_u8(0, 255, 255) == 255);  // At max
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_u16
    {
        e_begin("s_clamp_u16");
        e_assert(s_clamp_u16(100, 50, 1000) == 100);
        e_assert(s_clamp_u16(100, 2000, 1000) == 1000);
        e_assert(s_clamp_u16(100, 500, 1000) == 500);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_u32
    {
        e_begin("s_clamp_u32");
        e_assert(s_clamp_u32(1000, 500, 10000) == 1000);
        e_assert(s_clamp_u32(1000, 20000, 10000) == 10000);
        e_assert(s_clamp_u32(1000, 5000, 10000) == 5000);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_u64
    {
        e_begin("s_clamp_u64");
        e_assert(s_clamp_u64(1000ULL, 500ULL, 10000ULL) == 1000ULL);
        e_assert(s_clamp_u64(1000ULL, 20000ULL, 10000ULL) == 10000ULL);
        e_assert(s_clamp_u64(1000ULL, 5000ULL, 10000ULL) == 5000ULL);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_32 (f32)
    {
        e_begin("s_clamp_32");
        e_assert(s_clamp_32(-1.0f, -2.0f, 1.0f) == -1.0f);
        e_assert(s_clamp_32(-1.0f, 2.0f, 1.0f) == 1.0f);
        e_assert(s_clamp_32(-1.0f, 0.5f, 1.0f) == 0.5f);
        e_assert(s_clamp_32(0.0f, -0.1f, 1.0f) == 0.0f);
        e_assert(s_clamp_32(0.0f, 1.1f, 1.0f) == 1.0f);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_clamp_f64
    {
        e_begin("s_clamp_f64");
        e_assert(s_clamp_f64(-1.0, -2.0, 1.0) == -1.0);
        e_assert(s_clamp_f64(-1.0, 2.0, 1.0) == 1.0);
        e_assert(s_clamp_f64(-1.0, 0.5, 1.0) == 0.5);
        e_assert(s_clamp_f64(-3.14159, -5.0, 3.14159) == -3.14159);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_i8
    {
        e_begin("s_in_between_i8");

        // Invalid range (should assert)
        e_expect_assert_fail();
        s_in_between_i8(10, 5, -10);

        // Valid checks
        e_assert(s_in_between_i8(-10, -10, 10));  // At min (inclusive)
        e_assert(s_in_between_i8(-10, 10, 10));   // At max (inclusive)
        e_assert(s_in_between_i8(-10, 0, 10));    // In middle
        e_assert(!s_in_between_i8(-10, -11, 10)); // Below min
        e_assert(!s_in_between_i8(-10, 11, 10));  // Above max
        e_assert(s_in_between_i8(0, 0, 0));       // Single value

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_i16
    {
        e_begin("s_in_between_i16");
        e_assert(s_in_between_i16(-100, -100, 100));
        e_assert(s_in_between_i16(-100, 100, 100));
        e_assert(s_in_between_i16(-100, 0, 100));
        e_assert(!s_in_between_i16(-100, -101, 100));
        e_assert(!s_in_between_i16(-100, 101, 100));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_i32
    {
        e_begin("s_in_between_i32");
        e_assert(s_in_between_i32(-1000, -1000, 1000));
        e_assert(s_in_between_i32(-1000, 1000, 1000));
        e_assert(s_in_between_i32(-1000, 0, 1000));
        e_assert(!s_in_between_i32(-1000, -1001, 1000));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_i64
    {
        e_begin("s_in_between_i64");
        e_assert(s_in_between_i64(-1000LL, -1000LL, 1000LL));
        e_assert(s_in_between_i64(-1000LL, 1000LL, 1000LL));
        e_assert(s_in_between_i64(-1000LL, 0LL, 1000LL));
        e_assert(!s_in_between_i64(-1000LL, 1001LL, 1000LL));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_u8
    {
        e_begin("s_in_between_u8");
        e_assert(s_in_between_u8(10, 10, 100));
        e_assert(s_in_between_u8(10, 100, 100));
        e_assert(s_in_between_u8(10, 50, 100));
        e_assert(!s_in_between_u8(10, 9, 100));
        e_assert(!s_in_between_u8(10, 101, 100));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_u16
    {
        e_begin("s_in_between_u16");
        e_assert(s_in_between_u16(100, 100, 1000));
        e_assert(s_in_between_u16(100, 1000, 1000));
        e_assert(s_in_between_u16(100, 500, 1000));
        e_assert(!s_in_between_u16(100, 99, 1000));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_u32
    {
        e_begin("s_in_between_u32");
        e_assert(s_in_between_u32(1000, 1000, 10000));
        e_assert(s_in_between_u32(1000, 10000, 10000));
        e_assert(s_in_between_u32(1000, 5000, 10000));
        e_assert(!s_in_between_u32(1000, 10001, 10000));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_in_between_u64
    {
        e_begin("s_in_between_u64");
        e_assert(s_in_between_u64(1000ULL, 1000ULL, 10000ULL));
        e_assert(s_in_between_u64(1000ULL, 10000ULL, 10000ULL));
        e_assert(s_in_between_u64(1000ULL, 5000ULL, 10000ULL));
        e_assert(!s_in_between_u64(1000ULL, 999ULL, 10000ULL));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_modulus_i8
    {
        e_begin("s_modulus_i8");

        // Invalid divisor (should assert)
        e_expect_assert_fail();
        s_modulus_i8(5, 0);

        e_expect_assert_fail();
        s_modulus_i8(5, -3);

        // Positive number
        e_assert(s_modulus_i8(10, 3) == 1);
        e_assert(s_modulus_i8(15, 4) == 3);

        // Negative number (mathematically correct modulus)
        e_assert(s_modulus_i8(-10, 3) == 2); // -10 % 3 = -1, then -1 + 3 = 2
        e_assert(s_modulus_i8(-15, 4) == 1); // -15 % 4 = -3, then -3 + 4 = 1
        e_assert(s_modulus_i8(-1, 5) == 4);  // -1 % 5 = -1, then -1 + 5 = 4

        // Exact division
        e_assert(s_modulus_i8(10, 5) == 0);
        e_assert(s_modulus_i8(-10, 5) == 0);

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_modulus_i16
    {
        e_begin("s_modulus_i16");
        e_assert(s_modulus_i16(100, 7) == 2);
        e_assert(s_modulus_i16(-100, 7) == 5); // -100 % 7 = -2, then -2 + 7 = 5
        e_assert(s_modulus_i16(50, 10) == 0);
        e_assert(s_modulus_i16(-50, 10) == 0);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_modulus_i32
    {
        e_begin("s_modulus_i32");
        e_assert(s_modulus_i32(1000, 13) == 12);
        e_assert(s_modulus_i32(-1000, 13) == 1); // -1000 % 13 = -12, then -12 + 13 = 1
        e_assert(s_modulus_i32(360, 360) == 0);
        e_assert(s_modulus_i32(-360, 360) == 0);
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_modulus_i64
    {
        e_begin("s_modulus_i64");
        e_assert(s_modulus_i64(10000LL, 17LL) == 7LL);
        e_assert(s_modulus_i64(-10000LL, 17LL) ==
                 10LL); // -10000 % 17 = -7, then -7 + 17 = 10
        e_assert(s_modulus_i64(1000000LL, 1000LL) == 0LL);
        e_end();
    }

    e_log_summary();
    return 0;
}
