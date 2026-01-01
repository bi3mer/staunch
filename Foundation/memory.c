#include "foundation.h"

void f_swap_ptr(void **a, void **b)
{
    void *temp = *a;
    *a = *b;
    *b = temp;
}
