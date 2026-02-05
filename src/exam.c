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
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#endif

void __s_assert(const bool condition, const char *file, const int line)
{
    if (!condition)
    {
        fprintf(stderr, "%s::%i failed assertion\n", file, line);
#ifdef __linux__
        void *buffer[100];
        int nptrs = backtrace(buffer, 100);
        fprintf(stderr, "Stack trace:\n");

        char **strings = backtrace_symbols(buffer, nptrs);
        if (strings == NULL)
        {
            fprintf(stderr, "Failed to get backtrace symbols\n");
        }
        else
        {
            char exe_path[1024];
            ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
            if (len != -1)
            {
                exe_path[len] = '\0';
            }

            // Get base address from /proc/self/maps
            unsigned long base_addr = 0;
            FILE *maps = fopen("/proc/self/maps", "r");
            if (maps)
            {
                char line_buf[512];
                if (fgets(line_buf, sizeof(line_buf), maps))
                {
                    sscanf(line_buf, "%lx", &base_addr);
                }
                fclose(maps);
            }

            for (int i = 0; i < nptrs; i++)
            {
                fprintf(stderr, "%s\n", strings[i]);

                // Extract address from [0xaddr]
                char *addr_start = strchr(strings[i], '[');
                char *addr_end = strchr(strings[i], ']');

                if (addr_start != NULL && addr_end != NULL && len != -1 && base_addr != 0)
                {
                    addr_start++; // Skip '['
                    unsigned long runtime_addr;
                    sscanf(addr_start, "%lx", &runtime_addr);

                    // Calculate offset from base
                    unsigned long offset = runtime_addr - base_addr;

                    char cmd[2048];
                    snprintf(cmd, sizeof(cmd),
                             "addr2line -e %s -f -p -i 0x%lx 2>/dev/null", exe_path,
                             offset);
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
