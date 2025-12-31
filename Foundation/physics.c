#include "foundation.h"

double f_circle_mass_d(const double radius, const double density)
{
    return F_PI * radius * radius * density;
}

float f_circle_mass_f(const float radius, const float density)
{
    return (float)F_PI * radius * radius * density;
}
