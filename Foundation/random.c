#include "foundation.h"

#include "exam.h"

// TODO: look into the modulo bias
// TODO: so much more to implement for thi to work
u8 f_rand_u8(const u8 min, const u8 max)
{
    e_assert(max >= min);
    return min + (rand() % (max - min + 1));
}
