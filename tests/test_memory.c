#include "staunch/exam.h"
#include "staunch/memory.h"
#include <stddef.h> // NULL
#include <stdlib.h>

typedef struct
{
    i64 x;
    i64 y;
} Point;

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_swap_ptr
    S_EXAM("s_swap_ptr")
    {
        // Swap two int pointers
        {
            i16 x = 10;
            i16 y = 20;

            void *a = &x;
            void *b = &y;

            s_swap_ptr(&a, &b);

            s_assert(a == &y);
            s_assert(b == &x);
            s_assert(*(i16 *)a == 20);
            s_assert(*(i16 *)b == 10);
        }

        // Swap pointer and NULL
        {
            int x = 42;
            void *a = &x;
            void *b = NULL;

            s_swap_ptr(&a, &b);

            s_assert(a == NULL);
            s_assert(b == &x);
            s_assert(*(int *)b == 42);
        }

        // Swap two NULLs
        {
            void *a = NULL;
            void *b = NULL;

            s_swap_ptr(&a, &b);

            s_assert(a == NULL);
            s_assert(b == NULL);
        }

        // Swap same pointer values
        {
            i32 x = 99;
            void *a = &x;
            void *b = &x;

            s_swap_ptr(&a, &b);

            s_assert(a == &x);
            s_assert(b == &x);
        }

        // Swap struct pointers
        {
            Point p1 = {1, 2};
            Point p2 = {3, 4};

            void *a = &p1;
            void *b = &p2;

            s_swap_ptr(&a, &b);

            s_assert(a == &p2);
            s_assert(b == &p1);

            s_assert(((Point *)a)->x == 3);
            s_assert(((Point *)b)->x == 1);
        }

        // Double swap returns to original
        {
            f32 f1 = 1.5f;
            f32 f2 = 2.5f;

            void *a = &f1;
            void *b = &f2;
            s_swap_ptr(&a, &b);
            s_swap_ptr(&a, &b);
            s_assert(a == &f1);
            s_assert(b == &f2);
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_swap_bytes
    S_EXAM("s_swap_bytes")
    {
        // Swap two ints
        {
            i64 x = 10;
            i64 y = 20;
            s_swap_bytes(&x, &y, sizeof(int));
            s_assert(x == 20);
            s_assert(y == 10);
        }

        // Swap two floats
        {
            f32 f1 = 1.5f;
            f32 f2 = 2.5f;

            s_swap_bytes(&f1, &f2, sizeof(float));

            s_assert(f1 == 2.5f);
            s_assert(f2 == 1.5f);
        }

        // Swap two doubles
        {
            f64 f1 = 10.0;
            f64 f2 = -10.0;

            s_swap_bytes(&f1, &f2, sizeof(double));

            s_assert(f1 == -10.0);
            s_assert(f2 == 10.0);
        }

        // Swap two structs
        {
            Point p1 = {1, 2};
            Point p2 = {3, 4};

            s_swap_bytes(&p1, &p2, sizeof(Point));

            s_assert(p1.x == 3);
            s_assert(p1.y == 4);
            s_assert(p2.x == 1);
            s_assert(p2.y == 2);
        }

        // Swap with itself (aliasing — values should be unchanged)
        {
            i32 x = 42;
            s_swap_bytes(&x, &x, sizeof(int));
            s_assert(x == 42);
        }

        // Double swap returns to original
        {
            u64 x = 10;
            u64 y = 20;

            s_swap_bytes(&x, &y, sizeof(int));
            s_swap_bytes(&x, &y, sizeof(int));

            s_assert(x == 10);
            s_assert(y == 20);
        }

        // Swap large struct (forces the 256-byte chunk loop)
        {
            typedef struct
            {
                char data[512];
            } BigStruct;

            BigStruct big1, big2;
            memset(big1.data, 0xAA, sizeof(big1.data));
            memset(big2.data, 0xBB, sizeof(big2.data));

            s_swap_bytes(&big1, &big2, sizeof(BigStruct));

            s_assert(big1.data[0] == (char)0xBB);
            s_assert(big2.data[0] == (char)0xAA);
            s_assert(big1.data[511] == (char)0xBB);
            s_assert(big2.data[511] == (char)0xAA);
        }

        // Swap single byte
        {
            char c1 = 'A';
            char c2 = 'Z';

            s_swap_bytes(&c1, &c2, sizeof(char));

            s_assert(c1 == 'Z');
            s_assert(c2 == 'A');
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // S_FREE_MALLOC
    S_EXAM("S_FREE_MALLOC")
    {
        // Free a malloc'd int and ensure pointer is NULL
        {
            i32 *ptr = malloc(sizeof(i32));
            s_assert(ptr != NULL);
            S_FREE_MALLOC(ptr);
            s_assert(ptr == NULL);
        }

        // Free a malloc'd struct and ensure pointer is NULL
        {
            Point *ptr = malloc(sizeof(Point));
            s_assert(ptr != NULL);
            ptr->x = 1;
            ptr->y = 2;
            S_FREE_MALLOC(ptr);
            s_assert(ptr == NULL);
        }

        // Free a malloc'd array and ensure pointer is NULL
        {
            i64 *ptr = malloc(sizeof(i64) * 64);
            s_assert(ptr != NULL);
            S_FREE_MALLOC(ptr);
            s_assert(ptr == NULL);
        }

        // Double free is safe (ptr is NULL after first free)
        {
            i32 *ptr = malloc(sizeof(i32));
            s_assert(ptr != NULL);
            S_FREE_MALLOC(ptr);
            s_assert(ptr == NULL);
            S_FREE_MALLOC(ptr); // free(NULL) is a no-op, ptr stays NULL
            s_assert(ptr == NULL);
        }

        // Free a NULL pointer (no-op, no crash)
        {
            i32 *ptr = NULL;
            S_FREE_MALLOC(ptr);
            s_assert(ptr == NULL);
        }
    }

    s_exam_log_summary();
    return 0;
}
