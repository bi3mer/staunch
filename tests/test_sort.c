#include "staunch/exam.h"
#include "staunch/sort.h"
#include <string.h>

typedef struct
{
    i32 x;
    i32 y;
} Point;

static int compare_i32(const void *a, const void *b)
{
    return *(i32 *)a - *(i32 *)b;
}

static int compare_f64(const void *a, const void *b)
{
    f64 fa = *(f64 *)a;
    f64 fb = *(f64 *)b;
    if (fa < fb)
        return -1;
    if (fa > fb)
        return 1;
    return 0;
}

static int compare_str(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

static int compare_point_x(const void *a, const void *b)
{
    return ((Point *)a)->x - ((Point *)b)->x;
}

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_sort
    S_EXAM("s_sort")
    {
        // Already sorted i32
        {
            i32 arr[] = {1, 2, 3, 4, 5};
            s_sort(arr, 5, sizeof(i32), compare_i32);
            s_assert(arr[0] == 1);
            s_assert(arr[1] == 2);
            s_assert(arr[2] == 3);
            s_assert(arr[3] == 4);
            s_assert(arr[4] == 5);
        }
        // Reverse sorted i32
        {
            i32 arr[] = {5, 4, 3, 2, 1};
            s_sort(arr, 5, sizeof(i32), compare_i32);
            s_assert(arr[0] == 1);
            s_assert(arr[1] == 2);
            s_assert(arr[2] == 3);
            s_assert(arr[3] == 4);
            s_assert(arr[4] == 5);
        }
        // Random order i32
        {
            i32 arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
            s_sort(arr, 8, sizeof(i32), compare_i32);
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
            s_sort(arr, 4, sizeof(i32), compare_i32);
            s_assert(arr[0] == 7);
            s_assert(arr[1] == 7);
            s_assert(arr[2] == 7);
            s_assert(arr[3] == 7);
        }
        // Single element i32
        {
            i32 arr[] = {42};
            s_sort(arr, 1, sizeof(i32), compare_i32);
            s_assert(arr[0] == 42);
        }
        // Two elements unsorted i32
        {
            i32 arr[] = {2, 1};
            s_sort(arr, 2, sizeof(i32), compare_i32);
            s_assert(arr[0] == 1);
            s_assert(arr[1] == 2);
        }
        // Negative numbers i32
        {
            i32 arr[] = {-3, -1, -4, -1, -5};
            s_sort(arr, 5, sizeof(i32), compare_i32);
            s_assert(arr[0] == -5);
            s_assert(arr[1] == -4);
            s_assert(arr[2] == -3);
            s_assert(arr[3] == -1);
            s_assert(arr[4] == -1);
        }
        // Mixed negative and positive i32
        {
            i32 arr[] = {3, -2, 0, -5, 1};
            s_sort(arr, 5, sizeof(i32), compare_i32);
            s_assert(arr[0] == -5);
            s_assert(arr[1] == -2);
            s_assert(arr[2] == 0);
            s_assert(arr[3] == 1);
            s_assert(arr[4] == 3);
        }
        // Random order f64
        {
            f64 arr[] = {3.14, 1.0, -2.5, 0.0, 2.71};
            s_sort(arr, 5, sizeof(f64), compare_f64);
            s_assert(arr[0] == -2.5);
            s_assert(arr[1] == 0.0);
            s_assert(arr[2] == 1.0);
            s_assert(arr[3] == 2.71);
            s_assert(arr[4] == 3.14);
        }
        // All same value f64
        {
            f64 arr[] = {1.5, 1.5, 1.5};
            s_sort(arr, 3, sizeof(f64), compare_f64);
            s_assert(arr[0] == 1.5);
            s_assert(arr[1] == 1.5);
            s_assert(arr[2] == 1.5);
        }
        // Two elements unsorted f64
        {
            f64 arr[] = {9.9, -9.9};
            s_sort(arr, 2, sizeof(f64), compare_f64);
            s_assert(arr[0] == -9.9);
            s_assert(arr[1] == 9.9);
        }
        // Alphabetical strings
        {
            const char *arr[] = {"banana", "apple", "cherry", "date"};
            s_sort(arr, 4, sizeof(char *), compare_str);
            s_assert(strcmp(arr[0], "apple") == 0);
            s_assert(strcmp(arr[1], "banana") == 0);
            s_assert(strcmp(arr[2], "cherry") == 0);
            s_assert(strcmp(arr[3], "date") == 0);
        }
        // Already sorted strings
        {
            const char *arr[] = {"ant", "bee", "cat"};
            s_sort(arr, 3, sizeof(char *), compare_str);
            s_assert(strcmp(arr[0], "ant") == 0);
            s_assert(strcmp(arr[1], "bee") == 0);
            s_assert(strcmp(arr[2], "cat") == 0);
        }
        // Reverse sorted strings
        {
            const char *arr[] = {"zebra", "monkey", "ant"};
            s_sort(arr, 3, sizeof(char *), compare_str);
            s_assert(strcmp(arr[0], "ant") == 0);
            s_assert(strcmp(arr[1], "monkey") == 0);
            s_assert(strcmp(arr[2], "zebra") == 0);
        }
        // Duplicate strings
        {
            const char *arr[] = {"cat", "ant", "cat", "bee"};
            s_sort(arr, 4, sizeof(char *), compare_str);
            s_assert(strcmp(arr[0], "ant") == 0);
            s_assert(strcmp(arr[1], "bee") == 0);
            s_assert(strcmp(arr[2], "cat") == 0);
            s_assert(strcmp(arr[3], "cat") == 0);
        }
        // Single string
        {
            const char *arr[] = {"only"};
            s_sort(arr, 1, sizeof(char *), compare_str);
            s_assert(strcmp(arr[0], "only") == 0);
        }
        // Sort Point by x ascending
        {
            Point arr[] = {{3, 0}, {1, 0}, {2, 0}};
            s_sort(arr, 3, sizeof(Point), compare_point_x);
            s_assert(arr[0].x == 1);
            s_assert(arr[1].x == 2);
            s_assert(arr[2].x == 3);
        }
        // Already sorted Point
        {
            Point arr[] = {{1, 9}, {2, 8}, {3, 7}};
            s_sort(arr, 3, sizeof(Point), compare_point_x);
            s_assert(arr[0].x == 1);
            s_assert(arr[1].x == 2);
            s_assert(arr[2].x == 3);
        }
        // Duplicate x values Point
        {
            Point arr[] = {{2, 1}, {1, 5}, {2, 3}};
            s_sort(arr, 3, sizeof(Point), compare_point_x);
            s_assert(arr[0].x == 1);
            s_assert(arr[1].x == 2);
            s_assert(arr[2].x == 2);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_sort2
    S_EXAM("s_sort2")
    {
        // Sort i32 keys with i32 values
        {
            i32 keys[] = {3, 1, 4, 1, 5};
            i32 vals[] = {30, 10, 40, 10, 50};
            s_sort2(keys, vals, 5, sizeof(i32), sizeof(i32), compare_i32);
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
            s_sort2(keys, vals, 4, sizeof(i32), sizeof(f64), compare_i32);
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
            s_sort2(keys, vals, 3, sizeof(i32), sizeof(char *), compare_i32);
            s_assert(keys[0] == 1);
            s_assert(strcmp(vals[0], "one") == 0);
            s_assert(keys[1] == 2);
            s_assert(strcmp(vals[1], "two") == 0);
            s_assert(keys[2] == 3);
            s_assert(strcmp(vals[2], "three") == 0);
        }
        // Sort i32 keys with Point values
        {
            i32 keys[] = {3, 1, 2};
            Point vals[] = {{30, 30}, {10, 10}, {20, 20}};
            s_sort2(keys, vals, 3, sizeof(i32), sizeof(Point), compare_i32);
            s_assert(keys[0] == 1);
            s_assert(vals[0].x == 10 && vals[0].y == 10);
            s_assert(keys[1] == 2);
            s_assert(vals[1].x == 20 && vals[1].y == 20);
            s_assert(keys[2] == 3);
            s_assert(vals[2].x == 30 && vals[2].y == 30);
        }
        // Already sorted
        {
            i32 keys[] = {1, 2, 3, 4, 5};
            i32 vals[] = {10, 20, 30, 40, 50};
            s_sort2(keys, vals, 5, sizeof(i32), sizeof(i32), compare_i32);
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
            s_sort2(keys, vals, 5, sizeof(i32), sizeof(i32), compare_i32);
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
            s_sort2(keys, vals, 4, sizeof(i32), sizeof(i32), compare_i32);
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
            s_sort2(keys, vals, 1, sizeof(i32), sizeof(i32), compare_i32);
            s_assert(keys[0] == 42);
            s_assert(vals[0] == 99);
        }
        // Two elements unsorted
        {
            i32 keys[] = {2, 1};
            i32 vals[] = {20, 10};
            s_sort2(keys, vals, 2, sizeof(i32), sizeof(i32), compare_i32);
            s_assert(keys[0] == 1);
            s_assert(vals[0] == 10);
            s_assert(keys[1] == 2);
            s_assert(vals[1] == 20);
        }
        // Negative keys
        {
            i32 keys[] = {-1, -3, -2};
            i32 vals[] = {-10, -30, -20};
            s_sort2(keys, vals, 3, sizeof(i32), sizeof(i32), compare_i32);
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
            s_sort2(keys, vals, 3, sizeof(f64), sizeof(i32), compare_f64);
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
            s_sort2(keys, vals, 3, sizeof(char *), sizeof(i32), compare_str);
            s_assert(strcmp(keys[0], "apple") == 0);
            s_assert(vals[0] == 1);
            s_assert(strcmp(keys[1], "banana") == 0);
            s_assert(vals[1] == 2);
            s_assert(strcmp(keys[2], "cherry") == 0);
            s_assert(vals[2] == 3);
        }
    }

    s_exam_log_summary();
    return 0;
}
