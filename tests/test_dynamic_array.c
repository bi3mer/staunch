#include "staunch/dynamic_array.h"
#include "staunch/exam.h"
#include <string.h>

// Helper comparison function for priority insert tests
static int compare_int(const void *item, const float priority)
{
    int value = *(const int *)item;
    if (value < (int)priority)
        return -1;
    if (value > (int)priority)
        return 1;
    return 0;
}

static int compare_float(const void *item, const float priority)
{
    float value = *(const float *)item;
    if (value < priority)
        return -1;
    if (value > priority)
        return 1;
    return 0;
}

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_da_init
    {
        e_begin("s_da_init");

        // Initialize with integers
        {
            int *da = s_da_init(sizeof(int), 10);
            e_assert(da != NULL);
            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        // Initialize with floats
        {
            float *da = s_da_init(sizeof(float), 5);
            e_assert(da != NULL);
            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        // Initialize with structs
        {
            typedef struct
            {
                int x;
                int y;
            } Point;
            Point *da = s_da_init(sizeof(Point), 20);
            e_assert(da != NULL);
            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        // Initialize with capacity 1
        {
            int *da = s_da_init(sizeof(int), 1);
            e_assert(da != NULL);
            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_da_length
    {
        e_begin("s_da_length");

        // Length of NULL is 0
        {
            e_assert(s_da_length(NULL) == 0);
        }

        // Length starts at 0
        {
            int *da = s_da_init(sizeof(int), 10);
            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_da_append
    {
        e_begin("s_da_append");

        // Append single element
        {
            int *da = s_da_init(sizeof(int), 10);
            int *elem = s_da_append((void **)&da);
            e_assert(elem != NULL);
            *elem = 42;
            e_assert(s_da_length(da) == 1);
            e_assert(da[0] == 42);
            s_da_cleanup(da);
        }

        // Append multiple elements
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 5; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i * 10;
            }
            e_assert(s_da_length(da) == 5);
            e_assert(da[0] == 0);
            e_assert(da[1] == 10);
            e_assert(da[2] == 20);
            e_assert(da[3] == 30);
            e_assert(da[4] == 40);
            s_da_cleanup(da);
        }

        // Append with struct
        {
            typedef struct
            {
                float x;
                float y;
            } Vec2;
            Vec2 *da = s_da_init(sizeof(Vec2), 5);
            Vec2 *v1 = s_da_append((void **)&da);
            v1->x = 1.5f;
            v1->y = 2.5f;
            Vec2 *v2 = s_da_append((void **)&da);
            v2->x = 3.5f;
            v2->y = 4.5f;
            e_assert(s_da_length(da) == 2);
            e_assert(da[0].x == 1.5f && da[0].y == 2.5f);
            e_assert(da[1].x == 3.5f && da[1].y == 4.5f);
            s_da_cleanup(da);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_da_ensure_capacity (implicit through append)
    {
        e_begin("s_da_ensure_capacity");

        // Grow beyond initial capacity
        {
            int *da = s_da_init(sizeof(int), 2);
            for (int i = 0; i < 10; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i;
            }

            e_assert(s_da_length(da) == 10);
            for (int i = 0; i < 10; i++)
            {
                e_assert(da[i] == i);
            }

            s_da_cleanup(da);
        }

        // Grow from capacity 1
        {
            int *da = s_da_init(sizeof(int), 1);
            for (int i = 0; i < 100; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i * 2;
            }

            e_assert(s_da_length(da) == 100);
            e_assert(da[0] == 0);
            e_assert(da[50] == 100);
            e_assert(da[99] == 198);

            s_da_cleanup(da);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_da_pop_end
    {
        e_begin("s_da_pop_end");

        // Pop from array with elements
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 5; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i;
            }

            e_assert(s_da_length(da) == 5);
            s_da_pop_end(da);
            e_assert(s_da_length(da) == 4);
            e_assert(da[3] == 3);

            s_da_cleanup(da);
        }

        // Pop all elements
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 3; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i;
            }

            s_da_pop_end(da);
            s_da_pop_end(da);
            s_da_pop_end(da);

            e_assert(s_da_length(da) == 0);

            s_da_cleanup(da);
        }

        // Pop from empty array
        {
            int *da = s_da_init(sizeof(int), 10);
            s_da_pop_end(da);
            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        // Pop NULL
        {
            s_da_pop_end(NULL); // Should not crash
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_da_pop_start
    {
        e_begin("s_da_pop_start");

        // Pop from array with elements
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 5; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i * 10;
            }

            e_assert(s_da_length(da) == 5);
            e_assert(da[0] == 0);

            s_da_pop_start(da);
            e_assert(s_da_length(da) == 4);
            e_assert(da[0] == 10);
            e_assert(da[1] == 20);
            e_assert(da[2] == 30);
            e_assert(da[3] == 40);

            s_da_cleanup(da);
        }

        // Pop multiple from start
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 5; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i;
            }

            s_da_pop_start(da);
            s_da_pop_start(da);

            e_assert(s_da_length(da) == 3);
            e_assert(da[0] == 2);
            e_assert(da[1] == 3);
            e_assert(da[2] == 4);

            s_da_cleanup(da);
        }

        // Pop from single element
        {
            int *da = s_da_init(sizeof(int), 10);
            int *elem = s_da_append((void **)&da);
            *elem = 99;
            s_da_pop_start(da);
            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        // Pop from empty array
        {
            int *da = s_da_init(sizeof(int), 10);
            s_da_pop_start(da);
            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        // Pop NULL
        {
            s_da_pop_start(NULL); // Should not crash
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_da_reverse
    {
        e_begin("s_da_reverse");

        // Reverse odd number of elements
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 5; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i;
            }

            s_da_reverse(da);

            e_assert(s_da_length(da) == 5);
            e_assert(da[0] == 4);
            e_assert(da[1] == 3);
            e_assert(da[2] == 2);
            e_assert(da[3] == 1);
            e_assert(da[4] == 0);
            s_da_cleanup(da);
        }

        // Reverse even number of elements
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 4; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i * 10;
            }

            s_da_reverse(da);

            e_assert(s_da_length(da) == 4);
            e_assert(da[0] == 30);
            e_assert(da[1] == 20);
            e_assert(da[2] == 10);
            e_assert(da[3] == 0);
            s_da_cleanup(da);
        }

        // Reverse single element
        {
            int *da = s_da_init(sizeof(int), 10);
            int *elem = s_da_append((void **)&da);
            *elem = 42;

            s_da_reverse(da);

            e_assert(s_da_length(da) == 1);
            e_assert(da[0] == 42);
            s_da_cleanup(da);
        }

        // Reverse empty array
        {
            int *da = s_da_init(sizeof(int), 10);
            s_da_reverse(da);

            e_assert(s_da_length(da) == 0);
            s_da_cleanup(da);
        }

        // Reverse NULL
        {
            s_da_reverse(NULL); // Should not crash
        }

        // Double reverse returns to original
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 6; i++)
            {
                int *elem = s_da_append((void **)&da);
                *elem = i;
            }

            s_da_reverse(da);
            s_da_reverse(da);

            for (int i = 0; i < 6; i++)
            {
                e_assert(da[i] == i);
            }

            s_da_cleanup(da);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_da_priority_insert
    {
        e_begin("s_da_priority_insert");

        // Insert into empty array
        {
            int *da = s_da_init(sizeof(int), 10);
            int *elem = s_da_priority_insert((void **)&da, 5.0f, compare_int);
            *elem = 5;
            e_assert(s_da_length(da) == 1);
            e_assert(da[0] == 5);
            s_da_cleanup(da);
        }

        // Insert in sorted order (ascending)
        {
            int *da = s_da_init(sizeof(int), 10);
            int *e1 = s_da_priority_insert((void **)&da, 10.0f, compare_int);
            *e1 = 10;
            int *e2 = s_da_priority_insert((void **)&da, 20.0f, compare_int);
            *e2 = 20;
            int *e3 = s_da_priority_insert((void **)&da, 5.0f, compare_int);
            *e3 = 5;
            int *e4 = s_da_priority_insert((void **)&da, 15.0f, compare_int);
            *e4 = 15;

            e_assert(s_da_length(da) == 4);
            e_assert(da[0] == 5);
            e_assert(da[1] == 10);
            e_assert(da[2] == 15);
            e_assert(da[3] == 20);
            s_da_cleanup(da);
        }

        // Insert duplicates
        {
            int *da = s_da_init(sizeof(int), 10);
            int *e1 = s_da_priority_insert((void **)&da, 10.0f, compare_int);
            *e1 = 10;
            int *e2 = s_da_priority_insert((void **)&da, 10.0f, compare_int);
            *e2 = 10;
            int *e3 = s_da_priority_insert((void **)&da, 10.0f, compare_int);
            *e3 = 10;

            e_assert(s_da_length(da) == 3);
            e_assert(da[0] == 10);
            e_assert(da[1] == 10);
            e_assert(da[2] == 10);
            s_da_cleanup(da);
        }

        // Insert at beginning
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 10; i <= 50; i += 10)
            {
                int *e = s_da_priority_insert((void **)&da, (float)i, compare_int);
                *e = i;
            }
            int *e_new = s_da_priority_insert((void **)&da, 1.0f, compare_int);
            *e_new = 1;

            e_assert(s_da_length(da) == 6);
            e_assert(da[0] == 1);
            e_assert(da[1] == 10);
            s_da_cleanup(da);
        }

        // Insert at end
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 10; i <= 50; i += 10)
            {
                int *e = s_da_priority_insert((void **)&da, (float)i, compare_int);
                *e = i;
            }
            int *e_new = s_da_priority_insert((void **)&da, 100.0f, compare_int);
            *e_new = 100;

            e_assert(s_da_length(da) == 6);
            e_assert(da[5] == 100);
            s_da_cleanup(da);
        }

        // Insert with floats
        {
            float *da = s_da_init(sizeof(float), 10);
            float *e1 = s_da_priority_insert((void **)&da, 2.5f, compare_float);
            *e1 = 2.5f;
            float *e2 = s_da_priority_insert((void **)&da, 1.5f, compare_float);
            *e2 = 1.5f;
            float *e3 = s_da_priority_insert((void **)&da, 3.5f, compare_float);
            *e3 = 3.5f;

            e_assert(s_da_length(da) == 3);
            e_assert(da[0] == 1.5f);
            e_assert(da[1] == 2.5f);
            e_assert(da[2] == 3.5f);
            s_da_cleanup(da);
        }

        // Trigger capacity growth during priority insert
        {
            int *da = s_da_init(sizeof(int), 2);
            for (int i = 0; i < 10; i++)
            {
                int *e = s_da_priority_insert((void **)&da, (float)i, compare_int);
                *e = i;
            }
            e_assert(s_da_length(da) == 10);
            for (int i = 0; i < 10; i++)
            {
                e_assert(da[i] == i);
            }
            s_da_cleanup(da);
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_da_increment_length
    {
        e_begin("s_da_increment_length");

        // Increment from 0
        {
            int *da = s_da_init(sizeof(int), 10);
            e_assert(s_da_length(da) == 0);
            s_da_increment_length(da);
            e_assert(s_da_length(da) == 1);
            s_da_increment_length(da);
            e_assert(s_da_length(da) == 2);
            s_da_cleanup(da);
        }

        // Increment after appends
        {
            int *da = s_da_init(sizeof(int), 10);
            int *e = s_da_append((void **)&da);
            *e = 42;
            e_assert(s_da_length(da) == 1);
            s_da_increment_length(da);
            e_assert(s_da_length(da) == 2);
            s_da_cleanup(da);
        }

        // Increment NULL
        {
            s_da_increment_length(NULL); // Should not crash
        }

        e_end();
    }

    ///////////////////////////////////////////////////////////////////////////
    // Complex workflow tests
    {
        e_begin("complex workflow");

        // Append, reverse, pop
        {
            int *da = s_da_init(sizeof(int), 10);
            for (int i = 0; i < 5; i++)
            {
                int *e = s_da_append((void **)&da);
                *e = i;
            }
            s_da_reverse(da);
            s_da_pop_end(da);
            s_da_pop_start(da);

            e_assert(s_da_length(da) == 3);
            e_assert(da[0] == 3);
            e_assert(da[1] == 2);
            e_assert(da[2] == 1);
            s_da_cleanup(da);
        }

        // Mix priority inserts and pops
        {
            int *da = s_da_init(sizeof(int), 10);
            int *e1 = s_da_priority_insert((void **)&da, 5.0f, compare_int);
            *e1 = 5;
            int *e2 = s_da_priority_insert((void **)&da, 3.0f, compare_int);
            *e2 = 3;
            int *e3 = s_da_priority_insert((void **)&da, 7.0f, compare_int);
            *e3 = 7;

            s_da_pop_start(da); // Remove 3
            e_assert(s_da_length(da) == 2);
            e_assert(da[0] == 5);
            e_assert(da[1] == 7);

            s_da_cleanup(da);
        }

        e_end();
    }

    return 0;
}
