#include "stdio.h"
#include <stdio.h>

#include "foundation.h"
#include "exam.h"

int main()
{
    ///////////////////////////////////////////////////////////////////////////
    // General Math
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
        e_begin("f_sqrt_f");
        e_assert(f_approximately_f(f_sqrt_f(4.f), 2.f, 0.00001f));
        e_assert(!f_approximately_f(f_sqrt_f(4.f), 2.f, 0.000001f));
        e_end();
    }
    {
        e_begin("f_sqrt_d");
        e_assert(f_approximately_d(f_sqrt_d(4.0), 2.0,  0.000001));
        e_assert(!f_approximately_d(f_sqrt_d(4.0), 2.0, 0.0000001));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // Linear Algebra


    e_log_summary();
    return 0;
}