# Exam

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

See [../tests/Makefile](../tests/Makefile) for an example of building unit test mode, and the behavior is exactly what you would expect. If compiled with `-DMODE_DEBUG` (this is also the DEFAULT mode), then the behavior will be similar to assert where a message is logged to `stdout` and then the program is exited. If in `-DMODE_PRODUCTION`, asserts are not compiled into the final build.
