#include "staunch/exam.h"
#include "staunch/memory.h"
#include <string.h> // NULL

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_swap_ptr
    {
        e_begin("s_swap_ptr");

        // Swap two int pointers
        {
            int x = 10;
            int y = 20;
            void *a = &x;
            void *b = &y;

            s_swap_ptr(&a, &b);

            e_assert(a == &y);
            e_assert(b == &x);
            e_assert(*(int *)a == 20);
            e_assert(*(int *)b == 10);
        }

        // Swap pointer and NULL
        {
            int x = 42;
            void *a = &x;
            void *b = NULL;

            s_swap_ptr(&a, &b);

            e_assert(a == NULL);
            e_assert(b == &x);
            e_assert(*(int *)b == 42);
        }

        // Swap two NULLs
        {
            void *a = NULL;
            void *b = NULL;

            s_swap_ptr(&a, &b);

            e_assert(a == NULL);
            e_assert(b == NULL);
        }

        // Swap same pointer values
        {
            int x = 99;
            void *a = &x;
            void *b = &x;

            s_swap_ptr(&a, &b);

            e_assert(a == &x);
            e_assert(b == &x);
        }

        // Swap struct pointers
        {
            typedef struct
            {
                int x;
                int y;
            } Point;

            Point p1 = {1, 2};
            Point p2 = {3, 4};
            void *a = &p1;
            void *b = &p2;

            s_swap_ptr(&a, &b);

            e_assert(a == &p2);
            e_assert(b == &p1);
            e_assert(((Point *)a)->x == 3);
            e_assert(((Point *)b)->x == 1);
        }

        // Double swap returns to original
        {
            float f1 = 1.5f;
            float f2 = 2.5f;
            void *a = &f1;
            void *b = &f2;

            s_swap_ptr(&a, &b);
            s_swap_ptr(&a, &b);

            e_assert(a == &f1);
            e_assert(b == &f2);
        }

        e_end();
    }

    return 0;
}
