#ifndef _STAUNCH_MEMORY_
#define _STAUNCH_MEMORY_

#include "staunch/types.h"

// Swap two pointers
extern void s_swap_ptr(void **a, void **b);
// Swap bytes of memory
extern void s_swap_bytes(void *a, void *b, st element_size);

#endif // _STAUNCH_MEMORY_
