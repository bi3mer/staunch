#include <stdio.h>
#include <stdlib.h>

#include "staunch/exam.h"
#include "staunch/glow.h"

#if BUILD_MODE == 1 // Unit Test
#include "time.h"

///////////////////////////////////////////////////////////////////////////
/// hidden globals
bool _e_expect_assert = false;
char *_e_name;

unsigned int _e_passed = 0;
unsigned int _e_total = 0;

unsigned int _e_all_passed = 0;
unsigned int _e_all_total = 0;

clock_t _e_begin_time;

///////////////////////////////////////////////////////////////////////////
/// Function implementations
void e_begin(char *name)
{
    _e_name = name;
    _e_passed = 0;
    _e_total = 0;
    _e_begin_time = clock();

    printf("\t%s:\n", name);
}

void e_expect_assert_fail()
{
    _e_expect_assert = true;
}

void __e_assert(bool passed, const char *file, int line)
{
    if (_e_expect_assert)
    {
        _e_expect_assert = false;
        passed = !passed;
    }

    ++_e_total;
    if (passed)
    {
        ++_e_passed;
    }
    else
    {
        printf("\t\t%s::%u failed\n", file, line);
    }
}

void e_end()
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

void e_log_summary()
{
    s_glow_set_color(_e_all_passed == _e_all_total ? GLOW_BOLD_GREEN : GLOW_BOLD_RED);
    printf("\t%u/%u test cases pass.\n", _e_all_passed, _e_all_total);
    s_glow_reset();
}

#else // debug
void __e_assert(const bool condition, const char *file, const int line)
{
    if (!condition)
    {
        printf("%s::%i failed assertion\n", file, line);
        exit(1);
    }
}
#endif
