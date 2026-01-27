#ifndef _STAUNCH_RANDOM_
#define _STAUNCH_RANDOM_

//-----------------------------------------------------------------------------
// For this API, I'm trying to figure out whether I should do something global
// like you see with rand() or if I should make a struct like you see with more
// modern approaches. I'm leaning towards the more modern approach, which would
// mean that r_rand_seed() returns a struct. However, I find that approach very
// inconvenient when I'm programming. So... I can't make up my mind. Otherwise,
// the basic API for different number types is reasonable, I think.
//-----------------------------------------------------------------------------
// Seed random number generation
#include "types.h"
#include <stdbool.h>

extern void f_rand_init(u32 seed);

// generate random bool (true or false)
extern bool f_rand_bool(void);

// generate random i8 between a minimum and maximum
extern i8 f_rand_i8(const i8 min, const i8 max);
// generate random i16 between a minimum and maximum
extern i16 f_rand_i16(const i16 min, const i16 max);
// generate random i32 between a minimum and maximum
extern i32 f_rand_i32(const i32 min, const i32 max);
// generate random i64 between a minimum and maximum
extern i64 f_rand_i64(const i64 min, const i64 max);

// generate random u8 between a minimum (inclusive) and maximum (inclusive)
extern u8 f_rand_u8(const u8 min, const u8 max);
// generate random u16 between a minimum (inclusive) and maximum (inclusive)
extern u16 f_rand_u16(const u16 min, const u16 max);
// generate random 32 between a minimum (inclusive) and maximum (inclusive)
extern u32 f_rand_u32(const u32 min, const u32 max);
// generate random u64 between a minimum (inclusive) and maximum (inclusive)
extern u64 f_rand_u64(const u64 min, const u64 max);

// generate random float between a minimum and maximum
extern float f_rand_f(const float min, const float max);
// generate random float between a 0 and 1
#define f_rand_f_01() f_rand_f(0.f, 1.f);
// generate random float between the minimum and maximum values of floats
#define f_rand_f_max() f_rand_f(-FLT_MAX, FLT_MAX)

// generate random double between a minimum and maximum
extern double f_rand_d(const double min, const double max);
// generate double float between a 0 and 1
#define f_rand_d_01() f_rand_d(0.0, 1.0);
// generate double float between the minimum and maximum values of floats
#define f_rand_d_max() f_rand_f(-DBL_MAX, DBL_MAX)

#endif // _STAUNCH_RANDOM_
