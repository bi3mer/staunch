#include "staunch/exam.h"
#include "staunch/point.h"
#include "staunch/sort.h"
#include <math.h>
#include <string.h>

// compare_point32_x is the only local comparator needed — all scalar and
// string comparators are provided by staunch/sort.h as s_sort_compare_*
static int compare_point32_x(const void *a, const void *b)
{
    f32 fa = ((Point32 *)a)->x;
    f32 fb = ((Point32 *)b)->x;
    if (fa < fb)
        return -1;
    if (fa > fb)
        return 1;
    return 0;
}

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_i8
    S_EXAM("s_sort_compare_i8")
    {
        i8 lo = -100, hi = 100, eq = -100;
        s_assert(s_sort_compare_i8(&lo, &hi) < 0);
        s_assert(s_sort_compare_i8(&hi, &lo) > 0);
        s_assert(s_sort_compare_i8(&lo, &eq) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_i16
    S_EXAM("s_sort_compare_i16")
    {
        i16 lo = -1000, hi = 1000, eq = -1000;
        s_assert(s_sort_compare_i16(&lo, &hi) < 0);
        s_assert(s_sort_compare_i16(&hi, &lo) > 0);
        s_assert(s_sort_compare_i16(&lo, &eq) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_i32
    S_EXAM("s_sort_compare_i32")
    {
        // normal values
        {
            i32 lo = -1, hi = 1, eq = -1;
            s_assert(s_sort_compare_i32(&lo, &hi) < 0);
            s_assert(s_sort_compare_i32(&hi, &lo) > 0);
            s_assert(s_sort_compare_i32(&lo, &eq) == 0);
        }
        // extreme values that would overflow with subtraction trick
        {
            i32 lo = INT32_MIN, hi = INT32_MAX;
            s_assert(s_sort_compare_i32(&lo, &hi) < 0);
            s_assert(s_sort_compare_i32(&hi, &lo) > 0);
            s_assert(s_sort_compare_i32(&lo, &lo) == 0);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_i64
    S_EXAM("s_sort_compare_i64")
    {
        // normal values
        {
            i64 lo = -1, hi = 1, eq = -1;
            s_assert(s_sort_compare_i64(&lo, &hi) < 0);
            s_assert(s_sort_compare_i64(&hi, &lo) > 0);
            s_assert(s_sort_compare_i64(&lo, &eq) == 0);
        }
        // extreme values
        {
            i64 lo = INT64_MIN, hi = INT64_MAX;
            s_assert(s_sort_compare_i64(&lo, &hi) < 0);
            s_assert(s_sort_compare_i64(&hi, &lo) > 0);
            s_assert(s_sort_compare_i64(&lo, &lo) == 0);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_u8
    S_EXAM("s_sort_compare_u8")
    {
        u8 lo = 0, hi = 255, eq = 0;
        s_assert(s_sort_compare_u8(&lo, &hi) < 0);
        s_assert(s_sort_compare_u8(&hi, &lo) > 0);
        s_assert(s_sort_compare_u8(&lo, &eq) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_u16
    S_EXAM("s_sort_compare_u16")
    {
        u16 lo = 0, hi = 65535, eq = 0;
        s_assert(s_sort_compare_u16(&lo, &hi) < 0);
        s_assert(s_sort_compare_u16(&hi, &lo) > 0);
        s_assert(s_sort_compare_u16(&lo, &eq) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_u32
    S_EXAM("s_sort_compare_u32")
    {
        u32 lo = 0, hi = UINT32_MAX, eq = 0;
        s_assert(s_sort_compare_u32(&lo, &hi) < 0);
        s_assert(s_sort_compare_u32(&hi, &lo) > 0);
        s_assert(s_sort_compare_u32(&lo, &eq) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_u64
    S_EXAM("s_sort_compare_u64")
    {
        u64 lo = 0, hi = UINT64_MAX, eq = 0;
        s_assert(s_sort_compare_u64(&lo, &hi) < 0);
        s_assert(s_sort_compare_u64(&hi, &lo) > 0);
        s_assert(s_sort_compare_u64(&lo, &eq) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_st
    S_EXAM("s_sort_compare_st")
    {
        st lo = 0, hi = SIZE_MAX, eq = 0;
        s_assert(s_sort_compare_st(&lo, &hi) < 0);
        s_assert(s_sort_compare_st(&hi, &lo) > 0);
        s_assert(s_sort_compare_st(&lo, &eq) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_f32
    S_EXAM("s_sort_compare_f32")
    {
        // normal values
        {
            f32 lo = -1.5f, hi = 1.5f, eq = -1.5f;
            s_assert(s_sort_compare_f32(&lo, &hi) < 0);
            s_assert(s_sort_compare_f32(&hi, &lo) > 0);
            s_assert(s_sort_compare_f32(&lo, &eq) == 0);
        }
        // NaN sorts before any normal value, including most negative f32
        {
            f32 nan = 0.0f / 0.0f, val = -1e38f;
            s_assert(s_sort_compare_f32(&nan, &val) < 0);
            s_assert(s_sort_compare_f32(&val, &nan) > 0);
            s_assert(s_sort_compare_f32(&nan, &nan) == 0);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_f64
    S_EXAM("s_sort_compare_f64")
    {
        // normal values
        {
            f64 lo = -1.5, hi = 1.5, eq = -1.5;
            s_assert(s_sort_compare_f64(&lo, &hi) < 0);
            s_assert(s_sort_compare_f64(&hi, &lo) > 0);
            s_assert(s_sort_compare_f64(&lo, &eq) == 0);
        }
        // NaN sorts before any normal value, including most negative f64
        {
            f64 nan = 0.0 / 0.0, val = -1e308;
            s_assert(s_sort_compare_f64(&nan, &val) < 0);
            s_assert(s_sort_compare_f64(&val, &nan) > 0);
            s_assert(s_sort_compare_f64(&nan, &nan) == 0);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort_compare_str
    S_EXAM("s_sort_compare_str")
    {
        // expects const char **
        const char *lo = "apple", *hi = "banana", *eq = "apple";
        s_assert(s_sort_compare_str(&lo, &hi) < 0);
        s_assert(s_sort_compare_str(&hi, &lo) > 0);
        s_assert(s_sort_compare_str(&lo, &eq) == 0);
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_quicksort
    S_EXAM("s_quicksort")
    {
        // Already sorted i32
        {
            i32 arr[] = {1, 2, 3, 4, 5};
            s_quicksort(arr, 5, sizeof(i32), s_sort_compare_i32);
            s_assert(arr[0] == 1);
            s_assert(arr[1] == 2);
            s_assert(arr[2] == 3);
            s_assert(arr[3] == 4);
            s_assert(arr[4] == 5);
        }
        // Reverse sorted i32
        {
            i32 arr[] = {5, 4, 3, 2, 1};
            s_quicksort(arr, 5, sizeof(i32), s_sort_compare_i32);
            s_assert(arr[0] == 1);
            s_assert(arr[1] == 2);
            s_assert(arr[2] == 3);
            s_assert(arr[3] == 4);
            s_assert(arr[4] == 5);
        }
        // Random order i32
        {
            i32 arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
            s_quicksort(arr, 8, sizeof(i32), s_sort_compare_i32);
            s_assert(arr[0] == 1);
            s_assert(arr[1] == 1);
            s_assert(arr[2] == 2);
            s_assert(arr[3] == 3);
            s_assert(arr[4] == 4);
            s_assert(arr[5] == 5);
            s_assert(arr[6] == 6);
            s_assert(arr[7] == 9);
        }
        // All duplicates i32
        {
            i32 arr[] = {7, 7, 7, 7};
            s_quicksort(arr, 4, sizeof(i32), s_sort_compare_i32);
            s_assert(arr[0] == 7);
            s_assert(arr[1] == 7);
            s_assert(arr[2] == 7);
            s_assert(arr[3] == 7);
        }
        // Single element i32
        {
            i32 arr[] = {42};
            s_quicksort(arr, 1, sizeof(i32), s_sort_compare_i32);
            s_assert(arr[0] == 42);
        }
        // Two elements unsorted i32
        {
            i32 arr[] = {2, 1};
            s_quicksort(arr, 2, sizeof(i32), s_sort_compare_i32);
            s_assert(arr[0] == 1);
            s_assert(arr[1] == 2);
        }
        // Negative numbers i32
        {
            i32 arr[] = {-3, -1, -4, -1, -5};
            s_quicksort(arr, 5, sizeof(i32), s_sort_compare_i32);
            s_assert(arr[0] == -5);
            s_assert(arr[1] == -4);
            s_assert(arr[2] == -3);
            s_assert(arr[3] == -1);
            s_assert(arr[4] == -1);
        }
        // Mixed negative and positive i32
        {
            i32 arr[] = {3, -2, 0, -5, 1};
            s_quicksort(arr, 5, sizeof(i32), s_sort_compare_i32);
            s_assert(arr[0] == -5);
            s_assert(arr[1] == -2);
            s_assert(arr[2] == 0);
            s_assert(arr[3] == 1);
            s_assert(arr[4] == 3);
        }
        // Random order f64
        {
            f64 arr[] = {3.14, 1.0, -2.5, 0.0, 2.71};
            s_quicksort(arr, 5, sizeof(f64), s_sort_compare_f64);
            s_assert(arr[0] == -2.5);
            s_assert(arr[1] == 0.0);
            s_assert(arr[2] == 1.0);
            s_assert(arr[3] == 2.71);
            s_assert(arr[4] == 3.14);
        }
        // All same value f64
        {
            f64 arr[] = {1.5, 1.5, 1.5};
            s_quicksort(arr, 3, sizeof(f64), s_sort_compare_f64);
            s_assert(arr[0] == 1.5);
            s_assert(arr[1] == 1.5);
            s_assert(arr[2] == 1.5);
        }
        // Two elements unsorted f64
        {
            f64 arr[] = {9.9, -9.9};
            s_quicksort(arr, 2, sizeof(f64), s_sort_compare_f64);
            s_assert(arr[0] == -9.9);
            s_assert(arr[1] == 9.9);
        }
        // Alphabetical strings
        {
            const char *arr[] = {"banana", "apple", "cherry", "date"};
            s_quicksort(arr, 4, sizeof(char *), s_sort_compare_str);
            s_assert(strcmp(arr[0], "apple") == 0);
            s_assert(strcmp(arr[1], "banana") == 0);
            s_assert(strcmp(arr[2], "cherry") == 0);
            s_assert(strcmp(arr[3], "date") == 0);
        }
        // Already sorted strings
        {
            const char *arr[] = {"ant", "bee", "cat"};
            s_quicksort(arr, 3, sizeof(char *), s_sort_compare_str);
            s_assert(strcmp(arr[0], "ant") == 0);
            s_assert(strcmp(arr[1], "bee") == 0);
            s_assert(strcmp(arr[2], "cat") == 0);
        }
        // Reverse sorted strings
        {
            const char *arr[] = {"zebra", "monkey", "ant"};
            s_quicksort(arr, 3, sizeof(char *), s_sort_compare_str);
            s_assert(strcmp(arr[0], "ant") == 0);
            s_assert(strcmp(arr[1], "monkey") == 0);
            s_assert(strcmp(arr[2], "zebra") == 0);
        }
        // Duplicate strings
        {
            const char *arr[] = {"cat", "ant", "cat", "bee"};
            s_quicksort(arr, 4, sizeof(char *), s_sort_compare_str);
            s_assert(strcmp(arr[0], "ant") == 0);
            s_assert(strcmp(arr[1], "bee") == 0);
            s_assert(strcmp(arr[2], "cat") == 0);
            s_assert(strcmp(arr[3], "cat") == 0);
        }
        // Single string
        {
            const char *arr[] = {"only"};
            s_quicksort(arr, 1, sizeof(char *), s_sort_compare_str);
            s_assert(strcmp(arr[0], "only") == 0);
        }
        // Sort Point32 by x ascending
        {
            Point32 arr[] = {{3.0f, 0.0f}, {1.0f, 0.0f}, {2.0f, 0.0f}};
            s_quicksort(arr, 3, sizeof(Point32), compare_point32_x);
            s_assert(arr[0].x == 1.0f);
            s_assert(arr[1].x == 2.0f);
            s_assert(arr[2].x == 3.0f);
        }
        // Already sorted Point32
        {
            Point32 arr[] = {{1.0f, 9.0f}, {2.0f, 8.0f}, {3.0f, 7.0f}};
            s_quicksort(arr, 3, sizeof(Point32), compare_point32_x);
            s_assert(arr[0].x == 1.0f);
            s_assert(arr[1].x == 2.0f);
            s_assert(arr[2].x == 3.0f);
        }
        // Duplicate x values Point32 — y must follow its point
        {
            Point32 arr[] = {{2.0f, 1.0f}, {1.0f, 5.0f}, {2.0f, 3.0f}};
            s_quicksort(arr, 3, sizeof(Point32), compare_point32_x);
            s_assert(arr[0].x == 1.0f && arr[0].y == 5.0f);
            s_assert(arr[1].x == 2.0f);
            s_assert(arr[2].x == 2.0f);
            s_assert((arr[1].y == 1.0f && arr[2].y == 3.0f) ||
                     (arr[1].y == 3.0f && arr[2].y == 1.0f));
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_quicksort2
    S_EXAM("s_quicksort2")
    {
        // Sort i32 keys with i32 values
        {
            i32 keys[] = {3, 1, 4, 1, 5};
            i32 vals[] = {30, 10, 40, 10, 50};
            s_quicksort2(keys, vals, 5, sizeof(i32), sizeof(i32), s_sort_compare_i32);
            s_assert(keys[0] == 1);
            s_assert(vals[0] == 10);
            s_assert(keys[1] == 1);
            s_assert(vals[1] == 10);
            s_assert(keys[2] == 3);
            s_assert(vals[2] == 30);
            s_assert(keys[3] == 4);
            s_assert(vals[3] == 40);
            s_assert(keys[4] == 5);
            s_assert(vals[4] == 50);
        }
        // Sort i32 keys with f64 values
        {
            i32 keys[] = {4, 2, 3, 1};
            f64 vals[] = {4.4, 2.2, 3.3, 1.1};
            s_quicksort2(keys, vals, 4, sizeof(i32), sizeof(f64), s_sort_compare_i32);
            s_assert(keys[0] == 1);
            s_assert(vals[0] == 1.1);
            s_assert(keys[1] == 2);
            s_assert(vals[1] == 2.2);
            s_assert(keys[2] == 3);
            s_assert(vals[2] == 3.3);
            s_assert(keys[3] == 4);
            s_assert(vals[3] == 4.4);
        }
        // Sort i32 keys with string values
        {
            i32 keys[] = {3, 1, 2};
            const char *vals[] = {"three", "one", "two"};
            s_quicksort2(keys, vals, 3, sizeof(i32), sizeof(char *), s_sort_compare_i32);
            s_assert(keys[0] == 1);
            s_assert(strcmp(vals[0], "one") == 0);
            s_assert(keys[1] == 2);
            s_assert(strcmp(vals[1], "two") == 0);
            s_assert(keys[2] == 3);
            s_assert(strcmp(vals[2], "three") == 0);
        }
        // Sort i32 keys with Point32 values
        {
            i32 keys[] = {3, 1, 2};
            Point32 vals[] = {{30.0f, 30.0f}, {10.0f, 10.0f}, {20.0f, 20.0f}};
            s_quicksort2(keys, vals, 3, sizeof(i32), sizeof(Point32), s_sort_compare_i32);
            s_assert(keys[0] == 1);
            s_assert(vals[0].x == 10.0f && vals[0].y == 10.0f);
            s_assert(keys[1] == 2);
            s_assert(vals[1].x == 20.0f && vals[1].y == 20.0f);
            s_assert(keys[2] == 3);
            s_assert(vals[2].x == 30.0f && vals[2].y == 30.0f);
        }
        // Already sorted
        {
            i32 keys[] = {1, 2, 3, 4, 5};
            i32 vals[] = {10, 20, 30, 40, 50};
            s_quicksort2(keys, vals, 5, sizeof(i32), sizeof(i32), s_sort_compare_i32);
            s_assert(keys[0] == 1);
            s_assert(vals[0] == 10);
            s_assert(keys[1] == 2);
            s_assert(vals[1] == 20);
            s_assert(keys[2] == 3);
            s_assert(vals[2] == 30);
            s_assert(keys[3] == 4);
            s_assert(vals[3] == 40);
            s_assert(keys[4] == 5);
            s_assert(vals[4] == 50);
        }
        // Reverse sorted
        {
            i32 keys[] = {5, 4, 3, 2, 1};
            i32 vals[] = {50, 40, 30, 20, 10};
            s_quicksort2(keys, vals, 5, sizeof(i32), sizeof(i32), s_sort_compare_i32);
            s_assert(keys[0] == 1);
            s_assert(vals[0] == 10);
            s_assert(keys[1] == 2);
            s_assert(vals[1] == 20);
            s_assert(keys[2] == 3);
            s_assert(vals[2] == 30);
            s_assert(keys[3] == 4);
            s_assert(vals[3] == 40);
            s_assert(keys[4] == 5);
            s_assert(vals[4] == 50);
        }
        // Duplicate keys — values follow their key
        {
            i32 keys[] = {2, 1, 2, 1};
            i32 vals[] = {20, 10, 21, 11};
            s_quicksort2(keys, vals, 4, sizeof(i32), sizeof(i32), s_sort_compare_i32);
            s_assert(keys[0] == 1);
            s_assert(keys[1] == 1);
            s_assert(keys[2] == 2);
            s_assert(keys[3] == 2);
            s_assert((vals[0] == 10 && vals[1] == 11) ||
                     (vals[0] == 11 && vals[1] == 10));
            s_assert((vals[2] == 20 && vals[3] == 21) ||
                     (vals[2] == 21 && vals[3] == 20));
        }
        // Single element
        {
            i32 keys[] = {42};
            i32 vals[] = {99};
            s_quicksort2(keys, vals, 1, sizeof(i32), sizeof(i32), s_sort_compare_i32);
            s_assert(keys[0] == 42);
            s_assert(vals[0] == 99);
        }
        // Two elements unsorted
        {
            i32 keys[] = {2, 1};
            i32 vals[] = {20, 10};
            s_quicksort2(keys, vals, 2, sizeof(i32), sizeof(i32), s_sort_compare_i32);
            s_assert(keys[0] == 1);
            s_assert(vals[0] == 10);
            s_assert(keys[1] == 2);
            s_assert(vals[1] == 20);
        }
        // Negative keys
        {
            i32 keys[] = {-1, -3, -2};
            i32 vals[] = {-10, -30, -20};
            s_quicksort2(keys, vals, 3, sizeof(i32), sizeof(i32), s_sort_compare_i32);
            s_assert(keys[0] == -3);
            s_assert(vals[0] == -30);
            s_assert(keys[1] == -2);
            s_assert(vals[1] == -20);
            s_assert(keys[2] == -1);
            s_assert(vals[2] == -10);
        }
        // Sort f64 keys with i32 values
        {
            f64 keys[] = {3.14, 1.0, 2.71};
            i32 vals[] = {3, 1, 2};
            s_quicksort2(keys, vals, 3, sizeof(f64), sizeof(i32), s_sort_compare_f64);
            s_assert(keys[0] == 1.0);
            s_assert(vals[0] == 1);
            s_assert(keys[1] == 2.71);
            s_assert(vals[1] == 2);
            s_assert(keys[2] == 3.14);
            s_assert(vals[2] == 3);
        }
        // Sort string keys with i32 values
        {
            const char *keys[] = {"banana", "apple", "cherry"};
            i32 vals[] = {2, 1, 3};
            s_quicksort2(keys, vals, 3, sizeof(char *), sizeof(i32), s_sort_compare_str);
            s_assert(strcmp(keys[0], "apple") == 0);
            s_assert(vals[0] == 1);
            s_assert(strcmp(keys[1], "banana") == 0);
            s_assert(vals[1] == 2);
            s_assert(strcmp(keys[2], "cherry") == 0);
            s_assert(vals[2] == 3);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_insertion_sort — large arrays
    // Arrays use (i * 37) % 100 — coprime with 100, so visits every value
    // 0..99 exactly once, giving a well-spread permutation without literals.
    S_EXAM("s_insertion_sort large")
    {
        // 100 i32 — permuted order
        {
            i32 arr[100];
            for (st i = 0; i < 100; i++)
                arr[i] = (i32)((i * 37) % 100);
            s_insertion_sort(arr, 100, sizeof(i32), s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
                s_assert(arr[i] == (i32)i);
        }
        // 100 i32 — reverse sorted
        {
            i32 arr[100];
            for (st i = 0; i < 100; i++)
                arr[i] = (i32)(99 - i);
            s_insertion_sort(arr, 100, sizeof(i32), s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
                s_assert(arr[i] == (i32)i);
        }
        // 100 i32 — all duplicates
        {
            i32 arr[100];
            for (st i = 0; i < 100; i++)
                arr[i] = 5;
            s_insertion_sort(arr, 100, sizeof(i32), s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
                s_assert(arr[i] == 5);
        }
        // 100 f64 — permuted order
        {
            f64 arr[100];
            for (st i = 0; i < 100; i++)
                arr[i] = (f64)((i * 37) % 100);
            s_insertion_sort(arr, 100, sizeof(f64), s_sort_compare_f64);
            for (st i = 0; i < 100; i++)
                s_assert(arr[i] == (f64)i);
        }
        // 100 f64 — NaNs sort first
        {
            f64 arr[100];
            for (st i = 0; i < 90; i++)
                arr[i] = (f64)i;
            for (st i = 90; i < 100; i++)
                arr[i] = 0.0 / 0.0; // NaN
            s_insertion_sort(arr, 100, sizeof(f64), s_sort_compare_f64);
            for (st i = 0; i < 10; i++)
                s_assert(isnan(arr[i]));
            for (st i = 10; i < 100; i++)
                s_assert(arr[i] == (f64)(i - 10));
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_insertion_sort2 — large arrays
    S_EXAM("s_insertion_sort2 large")
    {
        // 100 i32 keys with i32 values — permuted order
        {
            i32 keys[100], vals[100];
            for (st i = 0; i < 100; i++)
                keys[i] = vals[i] = (i32)((i * 37) % 100);
            s_insertion_sort2(keys, vals, 100, sizeof(i32), sizeof(i32),
                              s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
            {
                s_assert(keys[i] == (i32)i);
                s_assert(vals[i] == (i32)i);
            }
        }
        // 100 i32 keys with f64 values — reverse sorted
        {
            i32 keys[100];
            f64 vals[100];
            for (st i = 0; i < 100; i++)
            {
                keys[i] = (i32)(99 - i);
                vals[i] = (f64)(99 - i);
            }
            s_insertion_sort2(keys, vals, 100, sizeof(i32), sizeof(f64),
                              s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
            {
                s_assert(keys[i] == (i32)i);
                s_assert(vals[i] == (f64)i);
            }
        }
        // 100 i32 keys with Point32 values — permuted order
        {
            i32 keys[100];
            Point32 vals[100];
            for (st i = 0; i < 100; i++)
            {
                keys[i] = (i32)((i * 37) % 100);
                vals[i].x = (f32)((i * 37) % 100);
                vals[i].y = (f32)((i * 37) % 100);
            }
            s_insertion_sort2(keys, vals, 100, sizeof(i32), sizeof(Point32),
                              s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
            {
                s_assert(keys[i] == (i32)i);
                s_assert(vals[i].x == (f32)i);
                s_assert(vals[i].y == (f32)i);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_quicksort — large arrays (exercises partition and recursion)
    S_EXAM("s_quicksort large")
    {
        // 100 i32 — permuted order
        {
            i32 arr[100];
            for (st i = 0; i < 100; i++)
                arr[i] = (i32)((i * 37) % 100);
            s_quicksort(arr, 100, sizeof(i32), s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
                s_assert(arr[i] == (i32)i);
        }
        // 100 i32 — reverse sorted
        {
            i32 arr[100];
            for (st i = 0; i < 100; i++)
                arr[i] = (i32)(99 - i);
            s_quicksort(arr, 100, sizeof(i32), s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
                s_assert(arr[i] == (i32)i);
        }
        // 100 i32 — all duplicates
        {
            i32 arr[100];
            for (st i = 0; i < 100; i++)
                arr[i] = 5;
            s_quicksort(arr, 100, sizeof(i32), s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
                s_assert(arr[i] == 5);
        }
        // 100 f64 — permuted order
        {
            f64 arr[100];
            for (st i = 0; i < 100; i++)
                arr[i] = (f64)((i * 37) % 100);
            s_quicksort(arr, 100, sizeof(f64), s_sort_compare_f64);
            for (st i = 0; i < 100; i++)
                s_assert(arr[i] == (f64)i);
        }
        // 100 f64 — NaNs sort first
        {
            f64 arr[100];
            for (st i = 0; i < 90; i++)
                arr[i] = (f64)i;
            for (st i = 90; i < 100; i++)
                arr[i] = 0.0 / 0.0; // NaN
            s_quicksort(arr, 100, sizeof(f64), s_sort_compare_f64);
            for (st i = 0; i < 10; i++)
                s_assert(isnan(arr[i]));
            for (st i = 10; i < 100; i++)
                s_assert(arr[i] == (f64)(i - 10));
        }
        // 100 Point32 — permuted order by x, y must follow
        {
            Point32 arr[100];
            for (st i = 0; i < 100; i++)
            {
                arr[i].x = (f32)((i * 37) % 100);
                arr[i].y = arr[i].x;
            }
            s_quicksort(arr, 100, sizeof(Point32), compare_point32_x);
            for (st i = 0; i < 100; i++)
            {
                s_assert(arr[i].x == (f32)i);
                s_assert(arr[i].y == (f32)i);
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_quicksort2 — large arrays (exercises partition and recursion)
    S_EXAM("s_quicksort2 large")
    {
        // 100 i32 keys with i32 values — permuted order
        {
            i32 keys[100], vals[100];
            for (st i = 0; i < 100; i++)
                keys[i] = vals[i] = (i32)((i * 37) % 100);
            s_quicksort2(keys, vals, 100, sizeof(i32), sizeof(i32), s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
            {
                s_assert(keys[i] == (i32)i);
                s_assert(vals[i] == (i32)i);
            }
        }
        // 100 i32 keys with f64 values — reverse sorted
        {
            i32 keys[100];
            f64 vals[100];
            for (st i = 0; i < 100; i++)
            {
                keys[i] = (i32)(99 - i);
                vals[i] = (f64)(99 - i);
            }
            s_quicksort2(keys, vals, 100, sizeof(i32), sizeof(f64), s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
            {
                s_assert(keys[i] == (i32)i);
                s_assert(vals[i] == (f64)i);
            }
        }
        // 100 i32 keys with Point32 values — permuted order
        {
            i32 keys[100];
            Point32 vals[100];
            for (st i = 0; i < 100; i++)
            {
                keys[i] = (i32)((i * 37) % 100);
                vals[i].x = (f32)((i * 37) % 100);
                vals[i].y = (f32)((i * 37) % 100);
            }
            s_quicksort2(keys, vals, 100, sizeof(i32), sizeof(Point32),
                         s_sort_compare_i32);
            for (st i = 0; i < 100; i++)
            {
                s_assert(keys[i] == (i32)i);
                s_assert(vals[i].x == (f32)i);
                s_assert(vals[i].y == (f32)i);
            }
        }
        // 100 f64 keys with i32 values — all duplicates
        {
            f64 keys[100];
            i32 vals[100];
            for (st i = 0; i < 100; i++)
                keys[i] = 1.5, vals[i] = (i32)i;
            s_quicksort2(keys, vals, 100, sizeof(f64), sizeof(i32), s_sort_compare_f64);
            for (st i = 0; i < 100; i++)
                s_assert(keys[i] == 1.5);
        }
        // 100 f64 keys with i32 values — NaN keys sort first
        {
            f64 keys[100];
            i32 vals[100];
            for (st i = 0; i < 90; i++)
                keys[i] = (f64)i, vals[i] = (i32)i;
            for (st i = 90; i < 100; i++)
                keys[i] = 0.0 / 0.0, vals[i] = -1; // NaN keys
            s_quicksort2(keys, vals, 100, sizeof(f64), sizeof(i32), s_sort_compare_f64);
            for (st i = 0; i < 10; i++)
                s_assert(isnan(keys[i]) && vals[i] == -1);
            for (st i = 10; i < 100; i++)
                s_assert(keys[i] == (f64)(i - 10) && vals[i] == (i32)(i - 10));
        }
    }

    s_exam_log_summary();
    return 0;
}
