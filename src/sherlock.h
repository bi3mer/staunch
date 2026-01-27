#ifndef _SHERLOCK_
#define _SHERLOCK_

///////////////////////////////////////////////////////////////////////////////
#ifdef _SHERLOCK_DEBUG_

extern void s_debug_init()

// replace malloc, realloc, & free with debug version to log file and location
#define malloc(n) s_debug_malloc(n, __FILE__, __LINE__)
#define realloc(n, m) s_debug_realloc(n, __FILE__, __LINE__)
#define free(n) s_debug_free(n, __file__, __LINE__)

#endif

#endif