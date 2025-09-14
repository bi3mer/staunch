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
        e_assert(f_approximately_2f(2.f, 1.999991f, 0.01f));
        e_assert(f_approximately_2f(2.f, 1.999991f, 0.001f));
        e_assert(f_approximately_2f(2.f, 1.999991f, 0.0001f));
        e_assert(f_approximately_2f(2.f, 1.999991f, 0.00001f));
        e_assert(!f_approximately_2f(2.f, 1.999991f, 0.000001f));
        e_end();
    }
    {
        e_begin("f_approximately_2d");
        e_assert(f_approximately_2d(2.0, 1.999991, 0.01));
        e_assert(f_approximately_2d(2.0, 1.999991, 0.001));
        e_assert(f_approximately_2d(2.0, 1.999991, 0.0001));
        e_assert(f_approximately_2d(2.0, 1.999991, 0.00001));
        e_assert(!f_approximately_2d(2.0, 1.999991, 0.000001));
        e_end();
    }
    {
        e_begin("f_sqrt_f");
        e_assert(f_approximately_2f(f_sqrt_f(4.f), 2.f, 0.00000001f));
        e_assert(f_approximately_2f(f_sqrt_f(4.f), 2.f, 0.00000001f));
        e_assert(f_approximately_2f(f_sqrt_f(4.f), 2.f, 0.0001f));
        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // Linear Algebra

    return 0;
}