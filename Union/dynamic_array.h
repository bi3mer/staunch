#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__

#include <stddef.h>

typedef struct
{
    size_t length;
    size_t capacity;
    size_t item_size;
} __DA_Header;

extern void *u_da_init(const size_t item_size, const size_t capacity);
extern void u_da_cleanup(void *da);

extern void u_da_ensure_capacity(void **da, const size_t capacity_increase);
extern void *u_da_append(void **da);

extern void *u_da_priority_insert(void **da, const float priority,
                                  int (*compare)(const void *, const float));

extern void u_da_pop_start(void *da);
extern void u_da_pop_end(void *da);

extern void u_da_reverse(void *da);

extern size_t u_da_length(const void *da);
extern void u_da_increment_length(void *da);

#endif
