#include "staunch/general_math.h"
#include "staunch/exam.h"

///////////////////////////////////////////////////////////////////////////////
// approximately
bool s_approximately_f32(const f32 a, const f32 b, const f32 range)
{
    return a <= b + range && a >= b - range;
}

bool s_approximately_f64(const f64 a, const f64 b, const f64 range)
{
    return a <= b + range && a >= b - range;
}

///////////////////////////////////////////////////////////////////////////////
// min
i8 s_min_i8(const i8 a, const i8 b)
{
    return a < b ? a : b;
}
i16 s_min_i16(const i16 a, const i16 b)
{
    return a < b ? a : b;
}
i32 s_min_i32(const i32 a, const i32 b)
{
    return a < b ? a : b;
}
i64 s_min_i64(const i64 a, const i64 b)
{
    return a < b ? a : b;
}

u8 s_min_u8(const u8 a, const u8 b)
{
    return a < b ? a : b;
}

u16 s_min_u16(const u16 a, const u16 b)
{
    return a < b ? a : b;
}

u32 s_min_u32(const u32 a, const u32 b)
{
    return a < b ? a : b;
}

u64 s_min_u64(const u64 a, const u64 b)
{
    return a < b ? a : b;
}

f32 s_min_f32(const f32 a, const f32 b)
{
    return a < b ? a : b;
}

f64 s_min_f64(const f64 a, const f64 b)
{
    return a < b ? a : b;
}

///////////////////////////////////////////////////////////////////////////////
// max
i8 s_max_i8(const i8 a, const i8 b)
{
    return a > b ? a : b;
}
i16 s_max_i16(const i16 a, const i16 b)
{
    return a > b ? a : b;
}
i32 s_max_i32(const i32 a, const i32 b)
{
    return a > b ? a : b;
}
i64 s_max_i64(const i64 a, const i64 b)
{
    return a > b ? a : b;
}

u8 s_max_u8(const u8 a, const u8 b)
{
    return a > b ? a : b;
}
u16 s_max_u16(const u16 a, const u16 b)
{
    return a > b ? a : b;
}
u32 s_max_u32(const u32 a, const u32 b)
{
    return a > b ? a : b;
}
u64 s_max_u64(const u64 a, const u64 b)
{
    return a > b ? a : b;
}

f32 s_max_f32(const f32 a, const f32 b)
{
    return a > b ? a : b;
}

f64 s_max_f64(const f64 a, const f64 b)
{
    return a > b ? a : b;
}

///////////////////////////////////////////////////////////////////////////////
// clamp
i8 s_clamp_i8(const i8 min, const i8 val, const i8 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

i16 s_clamp_i16(const i16 min, const i16 val, const i16 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

i32 s_clamp_i32(const i32 min, const i32 val, const i32 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

i64 s_clamp_i64(const i64 min, const i64 val, const i64 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

u8 s_clamp_u8(const u8 min, const u8 val, const u8 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

u16 s_clamp_u16(const u16 min, const u16 val, const u16 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

u32 s_clamp_u32(const u32 min, const u32 val, const u32 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

u64 s_clamp_u64(const u64 min, const u64 val, const u64 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

f32 s_clamp_32(const f32 min, const f32 val, const f32 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

f64 s_clamp_f64(const f64 min, const f64 val, const f64 max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

///////////////////////////////////////////////////////////////////////////////
// in between
bool s_in_between_i8(i16 min, i16 middle, i16 max)
{
    e_assert(min <= max);
    return min <= middle && middle <= max;
}

bool s_in_between_i16(i16 min, i16 middle, i16 max)
{
    e_assert(min <= max);
    return min <= middle && middle <= max;
}

bool s_in_between_i32(i32 min, i32 middle, i32 max)
{
    e_assert(min <= max);
    return min <= middle && middle <= max;
}

bool s_in_between_i64(i64 min, i64 middle, i64 max)
{
    e_assert(min <= max);
    return min <= middle && middle <= max;
}

bool s_in_between_u8(u8 min, u8 middle, u8 max)
{
    e_assert(min <= max);
    return min <= middle && middle <= max;
}

bool s_in_between_u16(u16 min, u16 middle, u16 max)
{
    e_assert(min <= max);
    return min <= middle && middle <= max;
}

bool s_in_between_u32(u32 min, u32 middle, u32 max)
{
    e_assert(min <= max);
    return min <= middle && middle <= max;
}

bool s_in_between_u64(u64 min, u64 middle, u64 max)
{
    e_assert(min <= max);
    return min <= middle && middle <= max;
}

///////////////////////////////////////////////////////////////////////////////
// modulus
i8 s_modulus_i8(i8 number, i8 divisor)
{
    e_assert(divisor > 0);
    i8 res = number % divisor;
    if (res < 0)
    {
        res += divisor;
    }
    return res;
}

i16 s_modulus_i16(i16 number, i16 divisor)
{
    e_assert(divisor > 0);
    i16 res = number % divisor;
    if (res < 0)
    {
        res += divisor;
    }
    return res;
}

i32 s_modulus_i32(i32 number, i32 divisor)
{
    e_assert(divisor > 0);
    i32 res = number % divisor;
    if (res < 0)
    {
        res += divisor;
    }
    return res;
}

i64 s_modulus_i64(i64 number, i64 divisor)
{
    e_assert(divisor > 0);
    i64 res = number % divisor;
    if (res < 0)
    {
        res += divisor;
    }
    return res;
}
