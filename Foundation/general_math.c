#include "foundation.h"
#include <assert.h>

///////////////////////////////////////////////////////////////////////////////
// approximately
bool f_approximately_f(const float a, const float b, const float range)
{
    return a <= b + range && a >= b - range;
}

bool f_approximately_d(const double a, const double b, const double range)
{
    return a <= b + range && a >= b - range;
}

///////////////////////////////////////////////////////////////////////////////
// min
i8 f_min_i8(const i8 a, const i8 b)     { return a < b ? a : b; }
i16 f_min_i16(const i16 a, const i16 b) { return a < b ? a : b; }
i32 f_min_i32(const i32 a, const i32 b) { return a < b ? a : b; }
i64 f_min_i64(const i64 a, const i64 b) { return a < b ? a : b; }

u8 f_min_u8(const u8 a, const u8 b)     { return a < b ? a : b; }
u16 f_min_u16(const u16 a, const u16 b) { return a < b ? a : b; }
u32 f_min_u32(const u32 a, const u32 b) { return a < b ? a : b; }
u64 f_min_u64(const u64 a, const u64 b) { return a < b ? a : b; }

float f_min_f(const float a, const float b)    { return a < b ? a : b; }
double f_min_d(const double a, const double b) { return a < b ? a : b; }

///////////////////////////////////////////////////////////////////////////////
// max
i8 f_max_i8(const i8 a, const i8 b)     { return a > b ? a : b; }
i16 f_max_i16(const i16 a, const i16 b) { return a > b ? a : b; }
i32 f_max_i32(const i32 a, const i32 b) { return a > b ? a : b; }
i64 f_max_i64(const i64 a, const i64 b) { return a > b ? a : b; }

u8 f_max_u8(const u8 a, const u8 b)     { return a > b ? a : b; }
u16 f_max_u16(const u16 a, const u16 b) { return a > b ? a : b; }
u32 f_max_u32(const u32 a, const u32 b) { return a > b ? a : b; }
u64 f_max_u64(const u64 a, const u64 b) { return a > b ? a : b; }

float f_max_f(const float a, const float b)    { return a > b ? a : b; }
double f_max_d(const double a, const double b) { return a > b ? a : b; }

///////////////////////////////////////////////////////////////////////////////
// clamp
i8 f_clamp_i8(const i8 min, const i8 val, const i8 max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

i16 f_clamp_i16(const i16 min, const i16 val, const i16 max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

i32 f_clamp_i32(const i32 min, const i32 val, const i32 max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

i64 f_clamp_i64(const i64 min, const i64 val, const i64 max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}


u8 f_clamp_u8(const u8 min, const u8 val, const u8 max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

u16 f_clamp_u16(const u16 min, const u16 val, const u16 max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

u32 f_clamp_u32(const u32 min, const u32 val, const u32 max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

u64 f_clamp_u64(const u64 min, const u64 val, const u64 max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}


float f_clamp_f(const float min, const float val, const float max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

double f_clamp_d(const double min, const double val, const double max)
{
    assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}
