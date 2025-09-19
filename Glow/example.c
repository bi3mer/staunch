#include "glow.h"
#include <stdio.h>

int main()
{
    glow_set_color(GLOW_RED);
    printf("Error\n");
    glow_reset();
    printf("Fine\n");

    return 1;
}