#include "stdio.h"
#include <math.h>
#include <stdio.h>
#include <sys/syslimits.h>

#include "exam.h"
#include "foundation.h"

int main(void)
{
    {
        e_begin("Purposeful Fail");
        e_assert(false);
        e_end();
    }

    e_log_summary();
    return 0;
}