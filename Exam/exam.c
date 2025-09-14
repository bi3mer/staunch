#include "exam.h"
#include <stdio.h>
#include <sys/types.h>

char* _e_name;

uint _e_passed = 0;
uint _e_total  = 0;

uint _e_all_passed = 0;
uint _e_all_total = 0;

void e_begin(char* name)
{
    _e_name = name;
    _e_passed = 0;
    _e_total = 0;

    printf("%s:\n", name);
}

void _e_assert(bool passed, const char* file, int line)
{
    ++_e_total;
    if (passed)
    {
        ++_e_passed;
    }
    else
    {
        printf("\t%s::%u failed\n", file, line);
    }
}

void e_end()
{
    ++_e_all_total;
    if (_e_passed == _e_total)
    {
        ++_e_all_passed;
        printf("\x1b[1F"); // Move to beginning of previous line
        printf("\x1b[2K"); // Clear entire line
        printf("%s Passed: %u / %u\n", _e_name, _e_passed, _e_total);
    }
    else
    {
        printf("\tFailed: %u / %u\n", _e_passed, _e_total);
    }
}

void e_log_summary()
{
    printf("\n%u/%u test cases pass.\n", _e_all_passed, _e_all_total);
}