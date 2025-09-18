#include "stdio.h"
#include <math.h>
#include <stdio.h>
#include <sys/syslimits.h>

#include "foundation.h"
#include "exam.h"

int main()
{
    {
        float vec[2];
        e_begin("f_vec2f_length");

        vec[0] = 0;
        vec[1] = 0;
        e_assert(f_vec2f_length(vec) == 0);

        vec[0] = 1;
        vec[1] = 1;
        e_assert(
            f_approximately_f(
                f_vec2f_length(vec),
                sqrtf(f_vec2f_length_squared(vec)),
                0.0000001
            )
        );

        vec[0] = -10;
        vec[1] = 100;
        e_assert(f_approximately_f(f_vec2f_length(vec), sqrtf(10100), 0.0000001));
        e_end();
    }

    e_log_summary();
    return 0;
}