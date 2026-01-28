#include "staunch/exam.h"
#include "staunch/units.h"
#include <math.h>

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_radian_to_degree32
    {
        e_begin("s_radian_to_degree32");
        // zero
        {
            Radian32 rad = {0.0f};
            Degree32 deg = s_radian_to_degree32(rad);
            e_assert(deg.value == 0.0f);
        }
        // pi radians = 180 degrees
        {
            Radian32 rad = {S_PI_32};
            Degree32 deg = s_radian_to_degree32(rad);
            e_assert(fabsf(deg.value - S_HALF_DEGREE_32) < 0.001f);
        }
        // pi/2 radians = 90 degrees
        {
            Radian32 rad = {S_PI_32 / 2.0f};
            Degree32 deg = s_radian_to_degree32(rad);
            e_assert(fabsf(deg.value - 90.0f) < 0.001f);
        }
        // 2*pi radians = 360 degrees
        {
            Radian32 rad = {2.0f * S_PI_32};
            Degree32 deg = s_radian_to_degree32(rad);
            e_assert(fabsf(deg.value - S_MAX_DEGREE_32) < 0.001f);
        }
        // negative angles
        {
            Radian32 rad = {-S_PI_32};
            Degree32 deg = s_radian_to_degree32(rad);
            e_assert(fabsf(deg.value - (-S_HALF_DEGREE_32)) < 0.001f);
        }
        // small angles
        {
            Radian32 rad = {0.01f};
            Degree32 deg = s_radian_to_degree32(rad);
            e_assert(fabsf(deg.value - 0.5729578f) < 0.001f);
        }
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_degree_to_radian32
    {
        e_begin("s_degree_to_radian32");
        // zero
        {
            Degree32 deg = {0.0f};
            Radian32 rad = s_degree_to_radian32(deg);
            e_assert(rad.value == 0.0f);
        }
        // 180 degrees = pi radians
        {
            Degree32 deg = {S_HALF_DEGREE_32};
            Radian32 rad = s_degree_to_radian32(deg);
            e_assert(fabsf(rad.value - S_PI_32) < 0.001f);
        }
        // 90 degrees = pi/2 radians
        {
            Degree32 deg = {90.0f};
            Radian32 rad = s_degree_to_radian32(deg);
            e_assert(fabsf(rad.value - (S_PI_32 / 2.0f)) < 0.001f);
        }
        // 360 degrees = 2*pi radians
        {
            Degree32 deg = {S_MAX_DEGREE_32};
            Radian32 rad = s_degree_to_radian32(deg);
            e_assert(fabsf(rad.value - (2.0f * S_PI_32)) < 0.001f);
        }
        // negative angles
        {
            Degree32 deg = {-S_HALF_DEGREE_32};
            Radian32 rad = s_degree_to_radian32(deg);
            e_assert(fabsf(rad.value - (-S_PI_32)) < 0.001f);
        }
        // 45 degrees
        {
            Degree32 deg = {45.0f};
            Radian32 rad = s_degree_to_radian32(deg);
            e_assert(fabsf(rad.value - (S_PI_32 / 4.0f)) < 0.001f);
        }
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_radian_to_degree64
    {
        e_begin("s_radian_to_degree64");
        // zero
        {
            Radian64 rad = {0.0};
            Degree64 deg = s_radian_to_degree64(rad);
            e_assert(deg.value == 0.0);
        }
        // pi radians = 180 degrees
        {
            Radian64 rad = {S_PI_64};
            Degree64 deg = s_radian_to_degree64(rad);
            e_assert(fabs(deg.value - S_HALF_DEGREE_64) < 0.000001);
        }
        // pi/2 radians = 90 degrees
        {
            Radian64 rad = {S_PI_64 / 2.0};
            Degree64 deg = s_radian_to_degree64(rad);
            e_assert(fabs(deg.value - 90.0) < 0.000001);
        }
        // 2*pi radians = 360 degrees
        {
            Radian64 rad = {2.0 * S_PI_64};
            Degree64 deg = s_radian_to_degree64(rad);
            e_assert(fabs(deg.value - S_MAX_DEGREE_64) < 0.000001);
        }
        // negative angles
        {
            Radian64 rad = {-S_PI_64};
            Degree64 deg = s_radian_to_degree64(rad);
            e_assert(fabs(deg.value - (-S_HALF_DEGREE_64)) < 0.000001);
        }
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_degree_to_radian64
    {
        e_begin("s_degree_to_radian64");
        // zero
        {
            Degree64 deg = {0.0};
            Radian64 rad = s_degree_to_radian64(deg);
            e_assert(rad.value == 0.0);
        }
        // 180 degrees = pi radians
        {
            Degree64 deg = {S_HALF_DEGREE_64};
            Radian64 rad = s_degree_to_radian64(deg);
            e_assert(fabs(rad.value - S_PI_64) < 0.000001);
        }
        // 90 degrees = pi/2 radians
        {
            Degree64 deg = {90.0};
            Radian64 rad = s_degree_to_radian64(deg);
            e_assert(fabs(rad.value - (S_PI_64 / 2.0)) < 0.000001);
        }
        // 360 degrees = 2*pi radians
        {
            Degree64 deg = {S_MAX_DEGREE_64};
            Radian64 rad = s_degree_to_radian64(deg);
            e_assert(fabs(rad.value - (2.0 * S_PI_64)) < 0.000001);
        }
        // negative angles
        {
            Degree64 deg = {-S_HALF_DEGREE_64};
            Radian64 rad = s_degree_to_radian64(deg);
            e_assert(fabs(rad.value - (-S_PI_64)) < 0.000001);
        }
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // round-trip conversions 32
    {
        e_begin("round-trip conversions 32");
        // rad -> deg -> rad
        {
            Radian32 original = {1.5f};
            Degree32 deg = s_radian_to_degree32(original);
            Radian32 result = s_degree_to_radian32(deg);
            e_assert(fabsf(result.value - original.value) < 0.001f);
        }
        // deg -> rad -> deg
        {
            Degree32 original = {123.456f};
            Radian32 rad = s_degree_to_radian32(original);
            Degree32 result = s_radian_to_degree32(rad);
            e_assert(fabsf(result.value - original.value) < 0.001f);
        }
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // round-trip conversions 64
    {
        e_begin("round-trip conversions 64");
        // rad -> deg -> rad
        {
            Radian64 original = {1.5};
            Degree64 deg = s_radian_to_degree64(original);
            Radian64 result = s_degree_to_radian64(deg);
            e_assert(fabs(result.value - original.value) < 0.000001);
        }
        // deg -> rad -> deg
        {
            Degree64 original = {123.456789};
            Radian64 rad = s_degree_to_radian64(original);
            Degree64 result = s_radian_to_degree64(rad);
            e_assert(fabs(result.value - original.value) < 0.000001);
        }
        e_end();
    }

    return 0;
}
