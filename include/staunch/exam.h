#ifndef _EXAM_
#define _EXAM_

#include "stdbool.h"

//--------------------------------------- exam.h ----------------------------------------
// Since `e_assert` can and should be used in parts of your codebase not related to unit
// testing, its behavior is different depending on the compile mode which can be set with
// a flag:
//
// ```
// -DMODE_PRODUCTION
// -DMODE_UNIT_TEST
// -DMODE_DEBUG
// ```

// - If compiled with `-DMODE_PRODUCTION`, then all `e_assert` calls will not be included
// in the final executable.
// - If compiled with `-DMODE_UNIT_TEST`, then `e_assert` calls will be treated as unit
// tests, meaning a failed assert will not end program execution.
// - If compiled with `-DMODE_DEBUG` or none of the flags above, then `e_assert` will
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
#define e_assert(expr) ((void)0)
#elif BUILD_MODE == 1
// Unit test mode. Not only do we have asserts, but other functions that can
// be used
extern void e_begin(char *name);
extern void e_expect_assert_fail();
extern void __e_assert(bool condition, const char *file, int line);
extern void e_end();
extern void e_log_summary();

#define e_assert(b) __e_assert(b, __FILE__, __LINE__)
#else
// Debug mode. Assert behaves similar to assert.h
extern void __e_assert(const bool condition, const char *file, const int line);
#define e_assert(b) __e_assert(b, __FILE__, __LINE__)
#endif

#endif
