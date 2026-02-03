#include <stdio.h>
#include <stdlib.h>

#include "staunch/exam.h"
#include "staunch/glow.h"

#if BUILD_MODE == 1

///////////////////////////////////////////////////////////////////////////
bool _e_expect_assert = false;
char *_e_name;

u32 _e_passed = 0;
u32 _e_total = 0;

u32 _e_all_passed = 0;
u32 _e_all_total = 0;

clock_t _e_begin_time;
jmp_buf _e_test_env;

///////////////////////////////////////////////////////////////////////////
/// Function implementations
void __s_exam_begin(char *name)
{
    _e_name = name;
    _e_passed = 0;
    _e_total = 0;
    _e_begin_time = clock();
    printf("\t%s:\n", name);
}

void __s_assert(bool passed, const char *file, int line)
{
    // If expecting a failure and this assertion failed - that's success
    if (_e_expect_assert && !passed)
    {
        _e_expect_assert = false;
        ++_e_total;
        ++_e_passed;
        longjmp(_e_test_env, 1);
    }

    // Normal assertion handling
    ++_e_total;
    if (passed)
    {
        ++_e_passed;
    }
    else
    {
        printf("\t\t%s::%u failed\n", file, line);
        longjmp(_e_test_env, 1);
    }
}

void __s_exam_end(void)
{
    clock_t end_time = clock();
    ++_e_all_total;
    if (_e_passed == _e_total)
    {
        ++_e_all_passed;
        printf("\x1b[1F"); // Move to beginning of previous line
        printf("\x1b[2K"); // Clear entire line
        s_glow_set_color(GLOW_GREEN);
        printf("\t%s Passed: %u / %u (%f s)\n", _e_name, _e_passed, _e_total,
               (double)(end_time - _e_begin_time) / CLOCKS_PER_SEC);
        s_glow_reset();
    }
    else
    {
        s_glow_set_color(GLOW_RED);
        printf("\t\tFailed: %u / %u (%f s)\n", _e_passed, _e_total,
               (double)(end_time - _e_begin_time) / CLOCKS_PER_SEC);
        s_glow_reset();
    }
}

void s_exam_log_summary(void)
{
    s_glow_set_color(_e_all_passed == _e_all_total ? GLOW_BOLD_GREEN : GLOW_BOLD_RED);
    printf("\t%u/%u test cases pass.\n", _e_all_passed, _e_all_total);
    s_glow_reset();
}

#else // debug
void __s_assert(const bool condition, const char *file, const int line)
{
    if (!condition)
    {
        printf("%s::%i failed assertion\n", file, line);
        exit(1);
    }
}
#endif
