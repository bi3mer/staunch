#include "staunch/memory.h"

void s_swap_ptr(void **a, void **b)
{
    void *temp = *a;
    *a = *b;
    *b = temp;
}
