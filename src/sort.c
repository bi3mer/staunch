#include "staunch/sort.h"

#include "staunch/memory.h"
#include "staunch/types.h"

static void qs(char *array, st element_count, st element_size,
               int (*compare)(const void *, const void *))
{
    if (element_count < 2)
        return;

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

        do
        {
            j -= element_size;
        } while (j > array && compare(j, pivot) > 0);

        if (i >= j)
        {
            break;
        }

        s_swap_bytes(i, j, element_size);
    }

    // Restore pivot
    s_swap_bytes(i, pivot, element_size);

    size_t left = (i - array) / element_size;
    size_t right = element_count - left - 1;

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

void s_sort(void *array, st element_count, st element_size,
            int (*compare)(const void *, const void *))
{
    if (array && element_count > 1 && element_size > 0 && compare)
    {
        qs((char *)array, element_count, element_size, compare);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
// Quick Sort 2
static void qs2(char *key_array, char *val_array, st element_count, st key_size,
                st val_size, int (*compare)(const void *, const void *))
{
    if (element_count < 2)
        return;

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

        do
        {
            j -= key_size;
        } while (j > key_array && compare(j, pivot) > 0);

        if (i >= j)
        {
            break;
        }

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

void s_sort2(void *key_array, void *val_array, st element_count, st key_size, st val_size,
             int (*compare)(const void *, const void *))
{
    if (key_array && val_array && element_count > 1 && key_size > 0 && val_size > 0 &&
        compare)
    {
        qs2((char *)key_array, (char *)val_array, element_count, key_size, val_size,
            compare);
    }
}
