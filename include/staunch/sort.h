#include "staunch/types.h"

// sort an array in-place
extern void s_sort(void *array, st element_count, st element_size,
                   int (*compare)(const void *, const void *));

// sort two arrays in-place
extern void s_sort2(void *key_array, void *val_array, st element_count, st key_size,
                    st val_size, int (*compare)(const void *, const void *));
