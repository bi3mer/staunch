#ifndef _STAUNCH_UNITS_
#define _STAUNCH_UNITS_

#include "staunch/types.h"

#define S_PI_32 3.141592653589793f
#define S_2PI_32 S_PI_32 * 2.f

#define S_PI_64 3.141592653589793115997963468544185161590576171875
#define S_2PI_64 S_PI_64 * 2.0

#define S_MAX_DEGREE_64 360.0
#define S_HALF_DEGREE_64 180.0

#define S_MAX_DEGREE_32 360.f
#define S_HALF_DEGREE_32 180.0f

typedef struct
{
    f32 value;
} Radian32;

typedef struct
{
    f64 value;
} Radian64;

typedef struct
{
    f32 value;
} Degree32;

typedef struct
{
    f64 value;
} Degree64;

extern Degree32 s_random_degree32(void);
extern Degree64 s_random_degree64(void);

extern Radian32 s_random_radian32(void);
extern Radian64 s_random_radian64(void);

extern Degree32 s_radian_to_degree32(Radian32 rad);
extern Radian32 s_degree_to_radian32(Degree32 deg);

extern Degree64 s_radian_to_degree64(Radian64 rad);
extern Radian64 s_degree_to_radian64(Degree64 deg);

#endif // _STAUNCH_UNITS_
