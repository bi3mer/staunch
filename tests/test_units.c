#include "staunch/exam.h"
#include "staunch/units.h"
#include <math.h>

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_radian_to_degree32
    S_EXAM("s_radian_to_degree32")
    {
        Radian32 rad;
        Degree32 deg;

        // zero
        rad = (Radian32){0.0f};
        deg = s_radian_to_degree32(rad);
        s_assert(deg.value == 0.0f);

        // pi radians = 180 degrees
        rad = (Radian32){S_PI_32};
        deg = s_radian_to_degree32(rad);
        s_assert(fabsf(deg.value - S_HALF_DEGREE_32) < 0.001f);

        // pi/2 radians = 90 degrees
        rad = (Radian32){S_PI_32 / 2.0f};
        deg = s_radian_to_degree32(rad);
        s_assert(fabsf(deg.value - 90.0f) < 0.001f);

        // 2*pi radians = 360 degrees
        rad = (Radian32){2.0f * S_PI_32};
        deg = s_radian_to_degree32(rad);
        s_assert(fabsf(deg.value - S_MAX_DEGREE_32) < 0.001f);

        // negative angles
        rad = (Radian32){-S_PI_32};
        deg = s_radian_to_degree32(rad);
        s_assert(fabsf(deg.value - (-S_HALF_DEGREE_32)) < 0.001f);

        // small angles
        rad = (Radian32){0.01f};
        deg = s_radian_to_degree32(rad);
        s_assert(fabsf(deg.value - 0.5729578f) < 0.001f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_degree_to_radian32
    S_EXAM("s_degree_to_radian32")
    {
        Degree32 deg;
        Radian32 rad;

        // zero
        deg = (Degree32){0.0f};
        rad = s_degree_to_radian32(deg);
        s_assert(rad.value == 0.0f);

        // 180 degrees = pi radians
        deg = (Degree32){S_HALF_DEGREE_32};
        rad = s_degree_to_radian32(deg);
        s_assert(fabsf(rad.value - S_PI_32) < 0.001f);

        // 90 degrees = pi/2 radians
        deg = (Degree32){90.0f};
        rad = s_degree_to_radian32(deg);
        s_assert(fabsf(rad.value - (S_PI_32 / 2.0f)) < 0.001f);

        // 360 degrees = 2*pi radians
        deg = (Degree32){S_MAX_DEGREE_32};
        rad = s_degree_to_radian32(deg);
        s_assert(fabsf(rad.value - (2.0f * S_PI_32)) < 0.001f);

        // negative angles
        deg = (Degree32){-S_HALF_DEGREE_32};
        rad = s_degree_to_radian32(deg);
        s_assert(fabsf(rad.value - (-S_PI_32)) < 0.001f);

        // 45 degrees
        deg = (Degree32){45.0f};
        rad = s_degree_to_radian32(deg);
        s_assert(fabsf(rad.value - (S_PI_32 / 4.0f)) < 0.001f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_radian_to_degree64
    S_EXAM("s_radian_to_degree64")
    {
        Radian64 rad;
        Degree64 deg;

        // zero
        rad = (Radian64){0.0};
        deg = s_radian_to_degree64(rad);
        s_assert(deg.value == 0.0);

        // pi radians = 180 degrees
        rad = (Radian64){S_PI_64};
        deg = s_radian_to_degree64(rad);
        s_assert(fabs(deg.value - S_HALF_DEGREE_64) < 0.000001);

        // pi/2 radians = 90 degrees
        rad = (Radian64){S_PI_64 / 2.0};
        deg = s_radian_to_degree64(rad);
        s_assert(fabs(deg.value - 90.0) < 0.000001);

        // 2*pi radians = 360 degrees
        rad = (Radian64){2.0 * S_PI_64};
        deg = s_radian_to_degree64(rad);
        s_assert(fabs(deg.value - S_MAX_DEGREE_64) < 0.000001);

        // negative angles
        rad = (Radian64){-S_PI_64};
        deg = s_radian_to_degree64(rad);
        s_assert(fabs(deg.value - (-S_HALF_DEGREE_64)) < 0.000001);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_degree_to_radian64
    S_EXAM("s_degree_to_radian64")
    {
        Degree64 deg;
        Radian64 rad;

        // zero
        deg = (Degree64){0.0};
        rad = s_degree_to_radian64(deg);
        s_assert(rad.value == 0.0);

        // 180 degrees = pi radians
        deg = (Degree64){S_HALF_DEGREE_64};
        rad = s_degree_to_radian64(deg);
        s_assert(fabs(rad.value - S_PI_64) < 0.000001);

        // 90 degrees = pi/2 radians
        deg = (Degree64){90.0};
        rad = s_degree_to_radian64(deg);
        s_assert(fabs(rad.value - (S_PI_64 / 2.0)) < 0.000001);

        // 360 degrees = 2*pi radians
        deg = (Degree64){S_MAX_DEGREE_64};
        rad = s_degree_to_radian64(deg);
        s_assert(fabs(rad.value - (2.0 * S_PI_64)) < 0.000001);

        // negative angles
        deg = (Degree64){-S_HALF_DEGREE_64};
        rad = s_degree_to_radian64(deg);
        s_assert(fabs(rad.value - (-S_PI_64)) < 0.000001);
    }

    ///////////////////////////////////////////////////////////////////////////
    // round-trip conversions 32
    S_EXAM("round-trip conversions 32")
    {
        // rad -> deg -> rad
        Radian32 orig_rad = {1.5f};
        Degree32 deg = s_radian_to_degree32(orig_rad);
        Radian32 result_rad = s_degree_to_radian32(deg);
        s_assert(fabsf(result_rad.value - orig_rad.value) < 0.001f);

        // deg -> rad -> deg
        Degree32 orig_deg = {123.456f};
        Radian32 rad = s_degree_to_radian32(orig_deg);
        Degree32 result_deg = s_radian_to_degree32(rad);
        s_assert(fabsf(result_deg.value - orig_deg.value) < 0.001f);
    }

    ///////////////////////////////////////////////////////////////////////////
    // round-trip conversions 64
    S_EXAM("round-trip conversions 64")
    {
        // rad -> deg -> rad
        Radian64 orig_rad = {1.5};
        Degree64 deg = s_radian_to_degree64(orig_rad);
        Radian64 result_rad = s_degree_to_radian64(deg);
        s_assert(fabs(result_rad.value - orig_rad.value) < 0.000001);

        // deg -> rad -> deg
        Degree64 orig_deg = {123.456789};
        Radian64 rad = s_degree_to_radian64(orig_deg);
        Degree64 result_deg = s_radian_to_degree64(rad);
        s_assert(fabs(result_deg.value - orig_deg.value) < 0.000001);
    }

    s_exam_log_summary();
    return 0;
}
