#include "staunch/random.h"
#include "staunch/exam.h"

static u64 s_state = 1;

static inline void xorshift64(void)
{
    s_state ^= s_state << 13;
    s_state ^= s_state >> 7;
    s_state ^= s_state << 17;
}

void s_rand_init(u32 seed)
{
    s_state = seed;
    if (s_state == 0)
        s_state = 1;
}

bool s_rand_bool(void)
{
    xorshift64();
    return s_state & 1;
}

//
// intengers
//
i8 s_rand_i8(const i8 min, const i8 max)
{
    s_assert(max >= min);
    xorshift64();
    return min + (s_state % ((u8)(max - min) + 1));
}

i16 s_rand_i16(const i16 min, const i16 max)
{
    s_assert(max >= min);
    xorshift64();
    return min + (s_state % ((u16)(max - min) + 1));
}

i32 s_rand_i32(const i32 min, const i32 max)
{
    s_assert(max >= min);
    xorshift64();
    return min + (s_state % ((u32)(max - min) + 1));
}

i64 s_rand_i64(const i64 min, const i64 max)
{
    s_assert(max >= min);
    xorshift64();
    return min + (s_state % ((u64)(max - min) + 1));
}

//
// unisgned integers
//
u8 s_rand_u8(const u8 min, const u8 max)
{
    s_assert(max >= min);
    xorshift64();
    return min + (s_state % (max - min + 1));
}

u16 s_rand_u16(const u16 min, const u16 max)
{
    s_assert(max >= min);
    xorshift64();
    return min + (s_state % (max - min + 1));
}

u32 s_rand_u32(const u32 min, const u32 max)
{
    s_assert(max >= min);
    xorshift64();
    return min + (s_state % (max - min + 1));
}

u64 s_rand_u64(const u64 min, const u64 max)
{
    s_assert(max >= min);
    xorshift64();
    return min + (s_state % (max - min + 1));
}

//
// f32 and f64
//
f32 s_rand_f32(const f32 min, const f32 max)
{
    s_assert(max >= min);
    const u32 bits = s_rand_u32(0, UINT32_MAX);
    return min + ((f32)bits / (f32)UINT32_MAX) * (max - min);
}

f64 s_rand_f64(const f64 min, const f64 max)
{
    s_assert(max >= min);
    const u64 bits = s_rand_u64(0, UINT64_MAX);
    return min + ((f64)bits / (f64)UINT64_MAX) * (max - min);
}