#include "staunch/exam.h"
#include "staunch/random.h"

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
