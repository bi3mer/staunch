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

#ifdef __linux__
#include <execinfo.h>
#include <string.h>
#include <unistd.h>
#endif

void __s_assert(const bool condition, const char *file, const int line)
{
    if (!condition)
    {
        fprintf(stderr, "%s::%i failed assertion\n", file, line);
#ifdef __linux__
        // Print stack trace on Linux
        void *buffer[100];
        int nptrs = backtrace(buffer, 100);
        fprintf(stderr, "Stack trace:\n");

        char **strings = backtrace_symbols(buffer, nptrs);
        if (strings != NULL)
        {
            char exe_path[1024];
            ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
            if (len != -1)
            {
                exe_path[len] = '\0';
            }

            for (int i = 0; i < nptrs; i++)
            {
                fprintf(stderr, "%s\n", strings[i]);

                // Extract offset from strings[i] which looks like:
                // ./bin/billiards(function+0x123) [0xaddr]
                char *offset_start = strchr(strings[i], '+');
                char *offset_end = strchr(strings[i], ')');
                if (offset_start != NULL && offset_end != NULL && len != -1)
                {
                    // Extract just the hex offset (e.g., "0x123")
                    int offset_len = offset_end - offset_start - 1;
                    char offset[32];
                    strncpy(offset, offset_start + 1, offset_len);
                    offset[offset_len] = '\0';

                    char cmd[2048];
                    snprintf(cmd, sizeof(cmd), "addr2line -e %s -f -p -i %s 2>/dev/null",
                             exe_path, offset);
                    system(cmd);
                }
            }
            free(strings);
        }
#endif
        fflush(stderr);
        abort();
    }
}

#endif
