#include "staunch/types.h"

// compare two i8 values
extern int s_sort_compare_i8(const void *a, const void *b);
// compare two i16 values
extern int s_sort_compare_i16(const void *a, const void *b);
// compare two i32 values
extern int s_sort_compare_i32(const void *a, const void *b);
// compare two i64 values
extern int s_sort_compare_i64(const void *a, const void *b);
// compare two u8 values
extern int s_sort_compare_u8(const void *a, const void *b);
// compare two u16 values
extern int s_sort_compare_u16(const void *a, const void *b);
// compare two u32 values
extern int s_sort_compare_u32(const void *a, const void *b);
// compare two u64 values
extern int s_sort_compare_u64(const void *a, const void *b);
// compare two st values
extern int s_sort_compare_st(const void *a, const void *b);
// compare two f32 values, NaNs sort first
extern int s_sort_compare_f32(const void *a, const void *b);
// compare two f64 values, NaNs sort first
extern int s_sort_compare_f64(const void *a, const void *b);
// compare two c strings (expects const char **)
extern int s_sort_compare_str(const void *a, const void *b);

// sort an array in-place with insertion sort
extern void s_insertion_sort(void *array, st element_count, st element_size,
                             int (*compare)(const void *, const void *));
// sort two arrays in-place with insertion sort
extern void s_insertion_sort2(void *key_array, void *val_array, st element_count,
                              st key_size, st val_size,
                              int (*compare)(const void *, const void *));

// sort an array in-place with quicksort
extern void s_quicksort(void *array, st element_count, st element_size,
                        int (*compare)(const void *, const void *));

// sort two arrays in-place with quicksort
extern void s_quicksort2(void *key_array, void *val_array, st element_count, st key_size,
                         st val_size, int (*compare)(const void *, const void *));