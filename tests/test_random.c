#include "staunch/exam.h"
#include "staunch/random.h"

int main(void)
{
    S_EXAM("FAIL OKAY")
    {
        s_assert(false);
    }

    s_exam_log_summary();
    return 0;
}
