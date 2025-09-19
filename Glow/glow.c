#include <stdio.h>
#include "glow.h"

#if defined(_WIN32) || defined(WIN32)

void glow_set_color(const char* ansii_escape)
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("Windows not currently supported, fully... sorry.");
}

void glow_reset()
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

#else

void glow_set_color(const char* ansii_escape)
{
    printf("%s", ansii_escape);
}

void glow_reset()
{
    printf("%s", GLOW_RESET);
}

#endif