#include "staunch/glow.h"
#include <stdio.h>

#if defined(_WIN32) || defined(WIN32)

void glow_set_color(const char *ansii_escape)
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("Windows not currently supported, fully... sorry.");
}

void glow_reset(void)
{
    SetConsoleTextAttribute(hConsole,
                            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

#else

void s_glow_set_color(const char *ansii_escape)
{
    printf("%s", ansii_escape);
}

void s_glow_reset(void)
{
    printf("%s", GLOW_RESET);
}

#endif
