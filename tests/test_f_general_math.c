#include "stdio.h"
#include <math.h>
#include <stdio.h>
#include <sys/syslimits.h>

#include "foundation.h"
#include "exam.h"

int main()
{
    {
        e_begin("f_approximately_2f");
        e_assert(f_approximately_f(2.f, 1.999991f, 0.01f));
        e_assert(f_approximately_f(2.f, 1.999991f, 0.001f));
        e_assert(f_approximately_f(2.f, 1.999991f, 0.0001f));
        e_assert(f_approximately_f(2.f, 1.999991f, 0.00001f));
        e_assert(!f_approximately_f(2.f, 1.999991f, 0.000001f));
        e_end();
    }
    {
        e_begin("f_approximately_2d");
        e_assert(f_approximately_d(2.0, 1.999991, 0.01));
        e_assert(f_approximately_d(2.0, 1.999991, 0.001));
        e_assert(f_approximately_d(2.0, 1.999991, 0.0001));
        e_assert(f_approximately_d(2.0, 1.999991, 0.00001));
        e_assert(!f_approximately_d(2.0, 1.999991, 0.000001));
        e_end();
    }
    {
        e_begin("f_min_i8");
        e_assert(f_min_i8(-3, 127) == -3);
        e_assert(f_min_i8(127, -127) == -127);
        e_assert(f_min_i8(0, 0) == 0);

        e_end();
    }

    e_log_summary();
    return 0;
}