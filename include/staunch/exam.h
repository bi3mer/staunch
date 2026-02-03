#ifndef _EXAM_
#define _EXAM_

#include "stdbool.h"

//--------------------------------------- exam.h ----------------------------------------
// Since `s_assert` can and should be used in parts of your codebase not related to unit
// testing, its behavior is different depending on the compile mode which can be set with
// a flag:
//
// ```
// -DMODE_PRODUCTION
// -DMODE_UNIT_TEST
// -DMODE_DEBUG
// ```

// - If compiled with `-DMODE_PRODUCTION`, then all `s_assert` calls will not be included
// in the final executable.
// - If compiled with `-DMODE_UNIT_TEST`, then `s_assert` calls will be treated as unit
// tests, meaning a failed assert will not end program execution.
// - If compiled with `-DMODE_DEBUG` or none of the flags above, then `s_assert` will
// behave similarly to `assert`.
//
// See [../tests/Makefile](../tests/Makefile) for an example of building in unit test
// mode.
//---------------------------------------------------------------------------------------

#if defined(MODE_PRODUCTION)
#define BUILD_MODE 0
#elif defined(MODE_UNIT_TEST)
#define BUILD_MODE 1
#else
#define BUILD_MODE 2 // MODE_DEBUG
#endif

#if BUILD_MODE == 0

// Production mode. Asserts compile down to nothing
#define s_assert(expr) ((void)0)
#elif BUILD_MODE == 1
// Unit test mode. Not only do we have asserts, but other functions that can
// be used
#include <setjmp.h>
#include <string.h> //memcpy
#include <time.h>

#include "staunch/types.h"

///////////////////////////////////////////////////////////////////////////
extern bool _e_expect_assert;
extern char *_e_name;

extern u32 _e_passed;
extern u32 _e_total;

extern u32 _e_all_passed;
extern u32 _e_all_total;

extern clock_t _e_begin_time;
extern jmp_buf _e_test_env;

extern void __s_exam_begin(char *name);
extern void __s_assert(bool condition, const char *file, int line);
extern void __s_exam_end(void);

// extern void s_exam_expect_assert_fail(void);
extern void s_exam_log_summary(void);

#define s_exam_expect_fail(code)                                                         \
    do                                                                                   \
    {                                                                                    \
        jmp_buf _e_saved_env;                                                            \
        memcpy(_e_saved_env, _e_test_env, sizeof(jmp_buf));                              \
        _e_expect_assert = true;                                                         \
        if (setjmp(_e_test_env) == 0)                                                    \
        {                                                                                \
            code;                                                                        \
            _e_expect_assert = false;                                                    \
            ++_e_total;                                                                  \
            printf("\t\t%s::%d expected assertion failure did not occur\n", __FILE__,    \
                   __LINE__);                                                            \
        }                                                                                \
        memcpy(_e_test_env, _e_saved_env, sizeof(jmp_buf));                              \
    } while (0)

#define S_EXAM(name)                                                                     \
    __s_exam_begin(name);                                                                \
    for (int _e_jmp = setjmp(_e_test_env), _e_run = 1; _e_run;                           \
         _e_run = 0, __s_exam_end())                                                     \
        if (_e_jmp == 0)

#define s_assert(b) __s_assert(b, __FILE__, __LINE__)
#else
// Debug mode. Assert behaves similar to assert.h
extern void __s_assert(const bool condition, const char *file, const int line);
#define s_assert(b) __s_assert(b, __FILE__, __LINE__)
#endif

#endif
