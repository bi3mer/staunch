#include "staunch/random.h"
#include "staunch/exam.h"

#include <stdlib.h>

void s_rand_init(u32 seed)
{
    srand(seed);
}

bool s_rand_bool(void)
{
    return rand() % 2;
}

// TODO: look into the modulo bias
u8 s_rand_u8(const u8 min, const u8 max)
{
    s_assert(max >= min);
    return min + (rand() % (max - min + 1));
}

u16 s_rand_u16(const u16 min, const u16 max)
{
    s_assert(max >= min);
    return min + (rand() % (max - min + 1));
}

u32 s_rand_u32(const u32 min, const u32 max)
{
    s_assert(max >= min);
    return min + (rand() % (max - min + 1));
}

u64 s_rand_u64(const u64 min, const u64 max)
{
    s_assert(max >= min);
    return min + (rand() % (max - min + 1));
}

f32 s_rand_f32(const f32 min, const f32 max)
{
    s_assert(max >= min);
    return min + ((f32)rand() / RAND_MAX) * (max - min);
}

f64 s_rand_f64(const f64 min, const f64 max)
{
    s_assert(max >= min);
    return min + ((f64)rand() / RAND_MAX) * (max - min);
}
