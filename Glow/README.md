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

Compile with `gcc -o glow-example -std=c11 -I glow.h glow.c main.c`. You mean need to update the paths to glow files, depending on where you made your `main.c` file. Then run the executable: `./glow-example`. It will print out:

```
$${\color{red}Error}$$
Fine
```

