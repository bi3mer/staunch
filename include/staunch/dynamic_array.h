#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__

#include <stddef.h>

typedef struct
{
    size_t length;
    size_t capacity;
    size_t item_size;
} __DA_Header;

extern void *s_da_init(const size_t item_size, const size_t capacity);
extern void s_da_cleanup(void *da);

extern void s_da_ensure_capacity(void **da, const size_t capacity_increase);
extern void *s_da_append(void **da);

extern void *s_da_priority_insert(void **da, const float priority,
                                  int (*compare)(const void *, const float));

extern void s_da_pop_start(void *da);
extern void s_da_pop_end(void *da);

extern void s_da_reverse(void *da);

extern size_t s_da_length(const void *da);
extern void s_da_increment_length(void *da);

#endif
