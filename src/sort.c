#include "staunch/sort.h"

#include "staunch/memory.h"
#include "staunch/types.h"

#include "staunch/sort.h"
#include "staunch/types.h"
#include <math.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
// Compare functions
int s_sort_compare_i8(const void *a, const void *b)
{
    i8 ia = *(i8 *)a;
    i8 ib = *(i8 *)b;
    return (ia > ib) - (ia < ib);
}

int s_sort_compare_i16(const void *a, const void *b)
{
    i16 ia = *(i16 *)a;
    i16 ib = *(i16 *)b;
    return (ia > ib) - (ia < ib);
}

int s_sort_compare_i32(const void *a, const void *b)
{
    i32 ia = *(i32 *)a;
    i32 ib = *(i32 *)b;
    return (ia > ib) - (ia < ib);
}

int s_sort_compare_i64(const void *a, const void *b)
{
    i64 ia = *(i64 *)a;
    i64 ib = *(i64 *)b;
    return (ia > ib) - (ia < ib);
}

int s_sort_compare_u8(const void *a, const void *b)
{
    u8 ua = *(u8 *)a;
    u8 ub = *(u8 *)b;
    return (ua > ub) - (ua < ub);
}

int s_sort_compare_u16(const void *a, const void *b)
{
    u16 ua = *(u16 *)a;
    u16 ub = *(u16 *)b;
    return (ua > ub) - (ua < ub);
}

int s_sort_compare_u32(const void *a, const void *b)
{
    u32 ua = *(u32 *)a;
    u32 ub = *(u32 *)b;
    return (ua > ub) - (ua < ub);
}

int s_sort_compare_u64(const void *a, const void *b)
{
    u64 ua = *(u64 *)a;
    u64 ub = *(u64 *)b;
    return (ua > ub) - (ua < ub);
}

int s_sort_compare_st(const void *a, const void *b)
{
    st ua = *(st *)a;
    st ub = *(st *)b;
    return (ua > ub) - (ua < ub);
}

int s_sort_compare_f32(const void *a, const void *b)
{
    // Two NaNs are considered equal; NaN < any non-NaN
    f32 fa = *(f32 *)a;
    f32 fb = *(f32 *)b;
    int an = isnan(fa);
    int bn = isnan(fb);
    if (an || bn)
        return bn - an;
    return (fa > fb) - (fa < fb);
}

int s_sort_compare_f64(const void *a, const void *b)
{
    f64 fa = *(f64 *)a;
    f64 fb = *(f64 *)b;
    int an = isnan(fa);
    int bn = isnan(fb);
    if (an || bn)
        return bn - an;

    return (fa > fb) - (fa < fb);
}

// Strings — expects const char **
int s_sort_compare_str(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

///////////////////////////////////////////////////////////////////////////////
// Insertion Sort
void s_insertion_sort(void *array, st element_count, st element_size,
                      int (*compare)(const void *, const void *))
{
    char *arr = (char *)array;
    for (st i = 1; i < element_count; i++)
    {
        for (st j = i;
             j > 0 && compare(arr + (j - 1) * element_size, arr + j * element_size) > 0;
             j--)
        {
            s_swap_bytes(arr + (j - 1) * element_size, arr + j * element_size,
                         element_size);
        }
    }
}

void s_insertion_sort2(void *key_array, void *val_array, st element_count, st key_size,
                       st val_size, int (*compare)(const void *, const void *))
{
    char *keys = (char *)key_array;
    char *vals = (char *)val_array;

    for (st i = 1; i < element_count; i++)
    {
        for (st j = i;
             j > 0 && compare(keys + (j - 1) * key_size, keys + j * key_size) > 0; j--)
        {
            s_swap_bytes(keys + (j - 1) * key_size, keys + j * key_size, key_size);
            s_swap_bytes(vals + (j - 1) * val_size, vals + j * val_size, val_size);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
// Quicksort
#define INSERTION_SORT_THRESHOLD 16

static void qs(char *array, st element_count, st element_size,
               int (*compare)(const void *, const void *))
{
    if (element_count < 2)
        return;

    if (element_count <= INSERTION_SORT_THRESHOLD)
    {
        s_insertion_sort(array, element_count, element_size, compare);
        return;
    }

    // Median-of-three pivot selection
    const st mid = (element_count / 2) * element_size;
    const st end = (element_count - 1) * element_size;

    if (compare(array, array + mid) > 0)
        s_swap_bytes(array, array + mid, element_size);
    if (compare(array, array + end) > 0)
        s_swap_bytes(array, array + end, element_size);
    if (compare(array + mid, array + end) > 0)
        s_swap_bytes(array + mid, array + end, element_size);

    // Place pivot at end
    s_swap_bytes(array + mid, array + end, element_size);
    char *pivot = array + end;

    // Partition
    char *i = array - element_size;
    char *j = pivot;

    for (;;)
    {
        do
        {
            i += element_size;
        } while (compare(i, pivot) < 0);

        // Median-of-three guarantees array[0] <= pivot, so j will naturally
        // stop. The j > array guard is kept as a safety net against misuse.
        do
        {
            j -= element_size;
        } while (j > array && compare(j, pivot) > 0);

        if (i >= j)
            break;

        s_swap_bytes(i, j, element_size);
    }

    // Restore pivot
    s_swap_bytes(i, pivot, element_size);

    st left = (i - array) / element_size;
    st right = element_count - left - 1;

    // Recurse on smaller partition first to bound stack depth
    if (left < right)
    {
        qs(array, left, element_size, compare);
        qs(i + element_size, right, element_size, compare);
    }
    else
    {
        qs(i + element_size, right, element_size, compare);
        qs(array, left, element_size, compare);
    }
}

static void qs2(char *key_array, char *val_array, st element_count, st key_size,
                st val_size, int (*compare)(const void *, const void *))
{
    if (element_count < 2)
        return;

    if (element_count <= INSERTION_SORT_THRESHOLD)
    {
        s_insertion_sort2(key_array, val_array, element_count, key_size, val_size,
                          compare);
        return;
    }

    // Median-of-three pivot selection
    const st mid = (element_count / 2) * key_size;
    const st end = (element_count - 1) * key_size;

    if (compare(key_array, key_array + mid) > 0)
    {
        s_swap_bytes(key_array, key_array + mid, key_size);
        s_swap_bytes(val_array, val_array + (element_count / 2) * val_size, val_size);
    }

    if (compare(key_array, key_array + end) > 0)
    {
        s_swap_bytes(key_array, key_array + end, key_size);
        s_swap_bytes(val_array, val_array + (element_count - 1) * val_size, val_size);
    }

    if (compare(key_array + mid, key_array + end) > 0)
    {
        s_swap_bytes(key_array + mid, key_array + end, key_size);
        s_swap_bytes(val_array + (element_count / 2) * val_size,
                     val_array + (element_count - 1) * val_size, val_size);
    }

    // Place pivot at end
    s_swap_bytes(key_array + mid, key_array + end, key_size);
    s_swap_bytes(val_array + (element_count / 2) * val_size,
                 val_array + (element_count - 1) * val_size, val_size);

    char *pivot = key_array + end;

    // Partition
    char *i = key_array - key_size;
    char *j = pivot;

    for (;;)
    {
        do
        {
            i += key_size;
        } while (compare(i, pivot) < 0);

        // Median-of-three guarantees key_array[0] <= pivot, so j will naturally
        // stop. The j > key_array guard is kept as a safety net against misuse.
        do
        {
            j -= key_size;
        } while (j > key_array && compare(j, pivot) > 0);

        if (i >= j)
            break;

        st i_index = (i - key_array) / key_size;
        st j_index = (j - key_array) / key_size;

        s_swap_bytes(i, j, key_size);
        s_swap_bytes(val_array + i_index * val_size, val_array + j_index * val_size,
                     val_size);
    }

    // Restore pivot
    st i_index = (i - key_array) / key_size;
    s_swap_bytes(i, pivot, key_size);
    s_swap_bytes(val_array + i_index * val_size,
                 val_array + (element_count - 1) * val_size, val_size);

    st left = (i - key_array) / key_size;
    st right = element_count - left - 1;

    // Recurse on smaller partition first to bound stack depth
    if (left < right)
    {
        qs2(key_array, val_array, left, key_size, val_size, compare);
        qs2(i + key_size, val_array + (left + 1) * val_size, right, key_size, val_size,
            compare);
    }
    else
    {
        qs2(i + key_size, val_array + (left + 1) * val_size, right, key_size, val_size,
            compare);
        qs2(key_array, val_array, left, key_size, val_size, compare);
    }
}

void s_quicksort(void *array, st element_count, st element_size,
                 int (*compare)(const void *, const void *))
{
    if (array && element_count > 1 && element_size > 0 && compare)
        qs((char *)array, element_count, element_size, compare);
}

void s_quicksort2(void *key_array, void *val_array, st element_count, st key_size,
                  st val_size, int (*compare)(const void *, const void *))
{
    if (key_array && val_array && element_count > 1 && key_size > 0 && val_size > 0 &&
        compare)
    {
        qs2((char *)key_array, (char *)val_array, element_count, key_size, val_size,
            compare);
    }
}
