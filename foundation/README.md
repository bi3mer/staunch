# Foundation

What is Foundation? ____

## Compiling Notes

Foundation.h files do include `assert` calls from `assert.h`. If you do not want these to run in your final build, make sure to include the flag `-DNDEBUG` when you compile.

## Tests

All tests are in [test.c](./test.c), which uses [Exam](../Exam). To run:

```bash
make test
```