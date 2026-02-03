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

extern jmp_buf _e_test_env;

extern int __s_exam_begin(char *name);
extern void __s_assert(bool condition, const char *file, int line);
extern void __s_exam_end(void);

extern void s_exam_expect_assert_fail(void);
extern void s_exam_log_summary(void);

#define S_EXAM(name)                                                                     \
    __s_exam_begin(name);                                                                \
    for (int _e_once = (setjmp(_e_test_env) == 0); _e_once; _e_once = 0, __s_exam_end())

#define s_assert(b) __s_assert(b, __FILE__, __LINE__)
#else
// Debug mode. Assert behaves similar to assert.h
extern void __s_assert(const bool condition, const char *file, const int line);
// #define s_assert(b) __s_assert(b, __FILE__, __LINE__)
extern void s_assert(bool b);
#endif

#endif
