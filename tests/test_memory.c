#include "staunch/exam.h"
#include "staunch/memory.h"
#include <string.h> // NULL

typedef struct
{
    int x;
    int y;
} Point;

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_swap_ptr
    S_EXAM("s_swap_ptr")
    {
        // Swap two int pointers
        int x = 10;
        int y = 20;
        void *a = &x;
        void *b = &y;
        s_swap_ptr(&a, &b);
        s_assert(a == &y);
        s_assert(b == &x);
        s_assert(*(int *)a == 20);
        s_assert(*(int *)b == 10);

        // Swap pointer and NULL
        x = 42;
        a = &x;
        b = NULL;
        s_swap_ptr(&a, &b);
        s_assert(a == NULL);
        s_assert(b == &x);
        s_assert(*(int *)b == 42);

        // Swap two NULLs
        a = NULL;
        b = NULL;
        s_swap_ptr(&a, &b);
        s_assert(a == NULL);
        s_assert(b == NULL);

        // Swap same pointer values
        x = 99;
        a = &x;
        b = &x;
        s_swap_ptr(&a, &b);
        s_assert(a == &x);
        s_assert(b == &x);

        // Swap struct pointers
        Point p1 = {1, 2};
        Point p2 = {3, 4};
        a = &p1;
        b = &p2;
        s_swap_ptr(&a, &b);
        s_assert(a == &p2);
        s_assert(b == &p1);
        s_assert(((Point *)a)->x == 3);
        s_assert(((Point *)b)->x == 1);

        // Double swap returns to original
        float f1 = 1.5f;
        float f2 = 2.5f;
        a = &f1;
        b = &f2;
        s_swap_ptr(&a, &b);
        s_swap_ptr(&a, &b);
        s_assert(a == &f1);
        s_assert(b == &f2);
    }

    s_exam_log_summary();
    return 0;
}