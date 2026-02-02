#include "staunch/physics.h"
#include "staunch/units.h"

f32 s_circle_mass_f32(const f32 radius, const f32 density)
{
    return S_PI_32 * radius * radius * density;
}

f64 s_circle_mass_f64(const f64 radius, const f64 density)
{
    return S_PI_64 * radius * radius * density;
}
