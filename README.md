# Staunch

Staunch is a C99 library filled with functions and tools that I find useful. It is not complete, and it will never be complete. When I need something for a project I am working on, I add it. A good example of this is [glow](src/glow.h). I have support for mac and linux but because I don't develop on Windows, I have no actual implementation of the functionality. I can add it, but I won't unless I need it.

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

## Tests

All tests are in [test.c](./test.c), which uses [Exam](src/exam.h). To run:

```bash
cd tests
make test
```
