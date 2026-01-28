#include "staunch/physics.h"
#include "staunch/units.h"

f64 f_circle_mass_d(const f64 radius, const f64 density)
{
    return S_PI_64 * radius * radius * density;
}

f32 f_circle_mass_f(const f32 radius, const f32 density)
{
    return (float)S_PI_32 * radius * radius * density;
}
