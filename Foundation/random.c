#include "foundation.h"

#include "exam.h"

#include <stdlib.h>

void f_rand_init(i64 seed)
{
    srand(seed);
}

// TODO: look into the modulo bias
// TODO: so much more to implement for thi to work
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

double f_rand_d(const double min, const double max)
{
    e_assert(max >= min);
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
