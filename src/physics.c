#include "staunch/physics.h"
#include "staunch/constants.h"

f64 f_circle_mass_d(const f64 radius, const f64 density)
{
    return F_PI * radius * radius * density;
}

f32 f_circle_mass_f(const f32 radius, const f32 density)
{
    return (float)F_PI * radius * radius * density;
}
