#ifndef _EXAM_
    #define _EXAM_

    #include "stdbool.h"

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
        extern void e_begin(char* name);
        extern void e_expect_assert_fail();
        extern void __e_assert(bool condition, const char* file, int line);
        extern void e_end();
        extern void e_log_summary();

        #define e_assert(b) __e_assert(b, __FILE__, __LINE__)
    #else
        // Debug mode. Assert behaves similar to assert.h
        extern void __e_assert(const bool condition, const char* file, const int line);
        #define e_assert(b, __FILE, __LINE)
    #endif

#endif