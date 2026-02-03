#include "staunch/exam.h"
#include <stdlib.h>

int main(void)
{
    S_EXAM("Test NULL pointer safety")
    {
        int *ptr = NULL;
        s_assert(ptr != NULL); // This fails and jumps out
        *ptr = 5;              // This NEVER executes - we've jumped to s_exam_end()
        s_assert(false);       // Also never executes
    }

    S_EXAM("Test normal case")
    {
        int x = 5;
        s_assert(x == 5); // Passes
        s_assert(x > 0);  // Passes
    }

    s_exam_log_summary();

    return 0;
}
