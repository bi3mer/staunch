#include "staunch/types.h"
#include <stdbool.h>

// get save directory for a directory
extern void s_save_directory(const char *dir_name, char *save_path, u32 size);
// make a directory recursively
bool s_make_dir_recursively(const char *path);
