#include "staunch/units.h"
#include "staunch/random.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Random
Degree32 s_random_degree32(void)
{
    return (Degree32){f_rand_f32(0, S_MAX_DEGREE_32)};
}

Degree64 s_random_degree64(void)
{
    return (Degree64){f_rand_f64(0, S_MAX_DEGREE_64)};
}

Radian32 s_random_radian32(void)
{
    return (Radian32){f_rand_f32(0, S_2PI_32)};
}

Radian64 s_random_radian64(void)
{
    return (Radian64){f_rand_f64(0, S_2PI_64)};
}

/////////////////////////////////////////////////////////////////////////////////////////
// Conversion
Degree32 s_radian_to_degree32(Radian32 rad)
{
    return (Degree32){rad.value * (S_HALF_DEGREE_32 / S_PI_32)};
}

Radian32 s_degree_to_radian32(Degree32 deg)
{
    return (Radian32){deg.value * (S_PI_32 / S_HALF_DEGREE_32)};
}

Degree64 s_radian_to_degree64(Radian64 rad)
{
    return (Degree64){rad.value * (S_HALF_DEGREE_64 / S_PI_64)};
}

Radian64 s_degree_to_radian64(Degree64 deg)
{
    return (Radian64){deg.value * (S_PI_64 / S_HALF_DEGREE_64)};
}
