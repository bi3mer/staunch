// ----------------------------------------------------------------------------
// The API I have below is not great, because the result will be something that
// is not platform independent. Meaning, the user will have to write a
// different version if they are on windows. There should be something in the
// middle where its like, g_set_color(GLOW_RED), and that will work regardless
// of whether the user is on windows, mac, or unix. I guess that you would want
// the color to be hex or RGB that way the user can also specify custom colors.
// ----------------------------------------------------------------------------

#if defined(_WIN32) || defined(WIN32)
#include "windows.h"

extern void glow_set_color(const char* ansii_escape);
extern void glow_reset();

#else

#define GLOW_RESET        "\033[0m"
#define GLOW_BLACK        "\033[30m"
#define GLOW_RED          "\033[31m"
#define GLOW_GREEN        "\033[32m"
#define GLOW_YELLOW       "\033[33m"
#define GLOW_BLUE         "\033[34m"
#define GLOW_MAGENTA      "\033[35m"
#define GLOW_CYAN         "\033[36m"
#define GLOW_WHITE        "\033[37m"
#define GLOW_BOLD_BLACK   "\033[1m\033[30m"
#define GLOW_BOLD_RED     "\033[1m\033[31m"
#define GLOW_BOLD_GREEN   "\033[1m\033[32m"
#define GLOW_BOLD_YELLOW  "\033[1m\033[33m"
#define GLOW_BOLD_BLUE    "\033[1m\033[34m"
#define GLOW_BOLD_MAGENTA "\033[1m\033[35m"
#define GLOW_BOLD_CYAN    "\033[1m\033[36m"
#define GLOW_BOLD_WHITE   "\033[1m\033[37m"

extern void glow_set_color(const char* ansii_escape);
extern void glow_reset();

#endif