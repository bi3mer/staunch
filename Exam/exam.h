#ifndef _EXAM_
#define _EXAM_

#include "stdbool.h"

extern void e_begin(char* name);
extern void _e_assert(bool condition, const char* file, int line);
extern void e_end();

#define e_assert(b) _e_assert(b, __FILE__, __LINE__)

#endif