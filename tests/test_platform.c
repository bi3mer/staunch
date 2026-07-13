#ifndef _WIN32
#define _POSIX_C_SOURCE 200112L
#endif

#include "staunch/exam.h"
#include "staunch/platform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

// Helper to remove directory
void cleanup_test_dir(const char *path)
{
#ifdef _WIN32
    RemoveDirectoryA(path);
#else
    rmdir(path);
#endif
}

// Helper to remove nested directories (reverse order)
void cleanup_nested_dirs(const char *base_path)
{
    char path[512];

    // Remove deepest first
    snprintf(path, 512, "%s/TestGame/Nested/Deep", base_path);
    cleanup_test_dir(path);

    snprintf(path, 512, "%s/TestGame/Nested", base_path);
    cleanup_test_dir(path);

    snprintf(path, 512, "%s/TestGame", base_path);
    cleanup_test_dir(path);
}

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_save_directory
    S_EXAM("s_save_directory")
    {
        // basic functionality
        {
            char save_path[512] = {0};
            bool ok = s_save_directory("TestGame", save_path, 512);
            s_assert(ok == true);
            s_assert(strlen(save_path) > 0);
            s_assert(strstr(save_path, "TestGame") != NULL);
        }

        // platform-specific paths
        {
            char save_path[512] = {0};
            bool ok = s_save_directory("MyGame", save_path, 512);
            s_assert(ok == true);
#ifdef _WIN32
            s_assert(strstr(save_path, "AppData") != NULL);
            s_assert(strstr(save_path, "\\") != NULL);
#elif __APPLE__
            s_assert(strstr(save_path, "Library/Application Support") != NULL);
#else // Linux
            s_assert(strstr(save_path, ".local/share") != NULL);
#endif
        }

        // different game names
        {
            char path1[512] = {0};
            char path2[512] = {0};
            bool ok1 = s_save_directory("Game1", path1, 512);
            bool ok2 = s_save_directory("Game2", path2, 512);
            s_assert(ok1 == true);
            s_assert(ok2 == true);
            s_assert(strcmp(path1, path2) != 0);
        }

        // buffer size respected
        {
            char small_buf[20] = {0};
            bool ok =
                s_save_directory("VeryLongGameNameThatExceedsBuffer", small_buf, 20);
            s_assert(ok == true);
            s_assert(strlen(small_buf) < 20); // snprintf should truncate
        }

        // missing home/config env var returns false and clears save_path
        {
            char save_path[512] = {'X', '\0'};
#ifdef _WIN32
            char old_appdata[512] = {0};
            DWORD old_len =
                GetEnvironmentVariableA("APPDATA", old_appdata, sizeof(old_appdata));
            SetEnvironmentVariableA("APPDATA", NULL);

            bool ok = s_save_directory("MissingEnvGame", save_path, 512);

            if (old_len > 0)
            {
                SetEnvironmentVariableA("APPDATA", old_appdata);
            }
#else
            const char *old_home_ptr = getenv("HOME");
            bool had_home = old_home_ptr != NULL;
            char old_home[512] = {0};
            if (had_home)
            {
                snprintf(old_home, sizeof(old_home), "%s", old_home_ptr);
            }
            unsetenv("HOME");

            bool ok = s_save_directory("MissingEnvGame", save_path, 512);

            if (had_home)
            {
                setenv("HOME", old_home, 1);
            }
#endif
            s_assert(ok == false);
            s_assert(save_path[0] == '\0');
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_make_dir_recursively
    S_EXAM("s_make_dir_recursively")
    {
        char base_dir[512];
#ifdef _WIN32
        char *appdata = getenv("APPDATA");
        snprintf(base_dir, 512, "%s", appdata);
#elif __APPLE__
        const char *home = getenv("HOME");
        snprintf(base_dir, 512, "%s/Library/Application Support", home);
#else
        const char *home = getenv("HOME");
        snprintf(base_dir, 512, "%s/.local/share", home);
#endif

        // create simple directory
        {
            char save_path[512];
            s_save_directory("TestGameSimple", save_path, 512);
            bool result = s_make_dir_recursively(save_path);
            s_assert(result == true);

            cleanup_test_dir(save_path);
        }
        // create already existing directory
        {
            char save_path[512];
            s_save_directory("TestGameExisting", save_path, 512);
            s_make_dir_recursively(save_path);
            bool result = s_make_dir_recursively(save_path); // second call
            s_assert(result == true); // should succeed even if exists

            cleanup_test_dir(save_path);
        }
        // create nested directories
        {
            char save_path[512];
            s_save_directory("TestGame/Nested/Deep", save_path, 512);
            bool result = s_make_dir_recursively(save_path);
            s_assert(result == true);

            cleanup_nested_dirs(base_dir);
        }
    }

    s_exam_log_summary();
    return 0;
}
