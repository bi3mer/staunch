# Staunch

A set of libararies I've built for developing in `C99`.

## TODO:

- Custom Memory Management:
  - [ ] [RAD arena approach](https://github.com/EpicGamesExt/raddebugger/blob/master/src/base/base_arena.h)
- Profiler:
  - [ ] [Rad profiler approach](https://github.com/EpicGamesExt/raddebugger/blob/08642d2745da516387fa0f43639b7a8776a154b0/src/base/base_profile.h#L35)
- Thread Pool:
  - [ ] https://www.rfleury.com/p/multi-threading-and-mutation
  - [ ] https://nachtimwald.com/2019/04/12/thread-pool-in-c/
  - [ ] https://github.com/EpicGamesExt/raddebugger/blob/master/src/linker/thread_pool/thread_pool.h
  - [ ] https://github.com/EpicGamesExt/raddebugger/blob/master/src/linker/thread_pool/thread_pool.c

## Foundation

What is Foundation? \_\_\_\_

### Compiling Notes

Foundation.h files do include `e_assert` calls from [Exam](../Exam)---see the [README](../README.md) for info on production versus debug builds.

### Tests

All tests are in [test.c](./test.c), which uses [Exam](../Exam). To run:

```bash
make test
```

## Exam

`Exam` is a very simple library for unit testing. The basic format for unit tests is the following:

```c
#include "exam.h"

int main()
{
    {
        e_begin("add");
        e_assert(1+1 == 2);
        e_end();
    }
    {
        e_begin("subtract");
        e_assert(1-1 == 0);
        e_assert(1-2 == -1);
        e_end();
    }

    e_log_summary();

    return 0;
}
```

Which will output:

```
  add Passed: 1 / 1
  subtract Passed: 2 / 2
  2/2 test cases pass.
```

The idea, though, is that you should also be able to use it in your code, and outside of a file for unit tests.

```c
#include "exam.h"

int clamp(int min, int val, int max)
{
    e_assert(min <= max);
    return val < min ? min : (val > max ? max : val);
}

int main()
{
    {
        e_begin("clamp");
        e_assert(clamp(10, 30, 15) == 15);
        e_expect_assert_fail();
        e_assert(clamp(10,0,-10));
        e_end();
    }

    e_log_summary();
    return 0;
}
```

Which outputs:

```
  clamp Passed: 4 / 4
  1/1 test cases pass.
```

Since `e_assert` can and should be used in parts of your codebase not related to unit testing, its behavior is different depending on the compile mode which can be set with a flag:

```
-DMODE_PRODUCTION
-DMODE_UNIT_TEST
-DMODE_DEBUG
```

- If compiled with `-DMODE_PRODUCTION`, then all `e_assert` calls will not be included in the final executable.
- If compiled with `-DMODE_UNIT_TEST`, then `e_assert` calls will be treated as unit tests, meaning a failed assert will not end program execution.
- If compiled with `-DMODE_DEBUG` or none of the flags above, then `e_assert` will behave similarly to `assert`.

See [../tests/Makefile](../tests/Makefile) for an example of building in unit test mode.

# Glow

Glow is a simple library for printing colored text to the console. It is incomplete and I haven't tested thoroughly for any platform, but the biggest gap right now is testing on Windows. I also want to support RGB or hex, and I currently support neither.

## Example

Make a main.c file and fill it with:

```c
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
```

Compile with:

```bash
gcc -o glow-example -std=c11 -I glow.h glow.c main.c`
```

You mean need to update the paths to glow files, depending on where you made your `main.c` file. Then run the executable: `./glow-example`. It will print out:

![](media/example-screenshot.png)
