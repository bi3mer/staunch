#include "staunch/alg.h"
#include "staunch/types.h"

bool s_alg_has_non_zero_d(const double *arr, size_t len)
{
    const u64 *words = (const u64 *)arr;
    size_t word_count = (len * sizeof(double)) / sizeof(uint64_t);
    size_t i = 0;

    // Mask to clear the sign bit
    const u64 mask = 0x7FFFFFFFFFFFFFFFULL;

    for (; i + 4 <= word_count; i += 4)
    {
        if ((words[i] & mask) | (words[i + 1] & mask) | (words[i + 2] & mask) |
            (words[i + 3] & mask))
            return true;
    }
    for (; i < word_count; i++)
    {
        if (words[i] & mask)
            return true;
    }
    return false;
}
