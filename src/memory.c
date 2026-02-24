#include "staunch/memory.h"

#include <stddef.h>
#include <string.h>

void s_swap_ptr(void **a, void **b)
{
    void *temp = *a;
    *a = *b;
    *b = temp;
}

void s_swap_bytes(void *a, void *b, st element_size)
{
    char *ca = (char *)a;
    char *cb = (char *)b;
    char tmp[256];

    while (element_size > 0)
    {
        const st chunk = element_size < sizeof(tmp) ? element_size : sizeof(tmp);

        memcpy(tmp, ca, chunk);
        memcpy(ca, cb, chunk);
        memcpy(cb, tmp, chunk);

        ca += chunk;
        cb += chunk;

        element_size -= chunk;
    }
}
