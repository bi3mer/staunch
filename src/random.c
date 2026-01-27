#include "staunch/random.h"
#include "staunch/exam.h"

#include <stdlib.h>

void f_rand_init(u32 seed)
{
    srand(seed);
}

bool f_rand_bool(void)
{
    return rand() % 2;
}

// TODO: look into the modulo bias
u8 f_rand_u8(const u8 min, const u8 max)
{
    e_assert(max >= min);
    return min + (rand() % (max - min + 1));
}

u16 f_rand_u16(const u16 min, const u16 max)
{
    e_assert(max >= min);
    return min + (rand() % (max - min + 1));
}

u32 f_rand_u32(const u32 min, const u32 max)
{
    e_assert(max >= min);
    return min + (rand() % (max - min + 1));
}

u64 f_rand_u64(const u64 min, const u64 max)
{
    e_assert(max >= min);
    return min + (rand() % (max - min + 1));
}

double f_rand_d(const double min, const double max)
{
    e_assert(max >= min);
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
