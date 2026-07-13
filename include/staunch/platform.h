#include "staunch/types.h"
#include <stdbool.h>

// get save directory for a directory
// returns false (and sets save_path to "") if the platform's home/config
// env var is unset
extern bool s_save_directory(const char *dir_name, char *save_path, u32 size);
// make a directory recursively
extern bool s_make_dir_recursively(const char *path);
