#include "foundation.h"

bool f_approximately_f(const float a, const float b, const float range)
{
    return a <= b + range && a >= b - range;
}

bool f_approximately_d(const double a, const double b, const double range)
{
    return a <= b + range && a >= b - range;
}
