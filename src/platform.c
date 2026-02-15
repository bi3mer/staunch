#include "staunch/platform.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <direct.h> // for _mkdir
#include <windows.h>
#else
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

void s_save_directory(const char *dir_name, char *save_path, u32 size)
{
#ifdef _WIN32
    char *appdata = getenv("APPDATA");
    if (appdata)
    {
        snprintf(save_path, size, "%s\\%s", appdata, dir_name);
    }
#elif __APPLE__
    const char *home = getenv("HOME");
    if (home)
    {
        snprintf(save_path, size, "%s/Library/Application Support/%s", home, dir_name);
    }
#else // Linux
    const char *home = getenv("HOME");
    if (home)
    {
        snprintf(save_path, size, "%s/.local/share/%s", home, dir_name);
    }
#endif
}

bool s_make_dir_recursively(const char *path)
{
    char tmp[512];
    snprintf(tmp, sizeof(tmp), "%s", path);

    for (char *p = tmp + 1; *p; p++)
    {
#ifdef _WIN32
        if (*p == '\\' || *p == '/')
        {
#else
        if (*p == '/')
        {
#endif
            *p = '\0';
#ifdef _WIN32
            _mkdir(tmp);
#else
            mkdir(tmp, 0755);
#endif
            *p = '/';
        }
    }

#ifdef _WIN32
    return _mkdir(tmp) == 0 || errno == EEXIST;
#else
    return mkdir(tmp, 0755) == 0 || errno == EEXIST;
#endif
}
