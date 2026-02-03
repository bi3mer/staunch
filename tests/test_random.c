#include "staunch/exam.h"
#include "staunch/random.h"

int main(void)
{
    {
        s_exam_begin("Purposeful Fail");
        s_assert(false);
        s_exam_end();
    }

    s_exam_log_summary();
    return 0;
}
