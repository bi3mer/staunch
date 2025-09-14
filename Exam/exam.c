#include "exam.h"
#include <stdio.h>
#include <sys/types.h>

char* _e_name;
uint _e_passed = 0;
uint _e_total = 0;

void e_begin(char* name)
{
    _e_name = name;
    _e_passed = 0;
    _e_total = 0;

    printf("%s:\n", name);
}

void _e_assert(bool passed, const char* file, int line)
{
    if (passed)
    {
        ++_e_passed;
    }
    else
    {
        printf("\t%s::%u failed\n", file, line);
    }
    ++_e_total;
}

void e_end()
{
    if (_e_passed == _e_total)
    {
        printf("\tPassed: %u / %u\n",_e_passed, _e_total);
    }
    else
    {
        printf("\tFailed: %u / %u\n", _e_passed, _e_total);
    }
}