#include "foundation.h"

bool f_approximately_f(const float a, const float b, const float range)
{
    return a <= b + range && a >= b - range;
}

bool f_approximately_d(const double a, const double b, const double range)
{
    return a <= b + range && a >= b - range;
}

float f_sqrt_f(const float number)
{
    int i;
    float x, y;

    x = number * 0.5;
    y  = number;
    i  = * (int * ) &y;
    i  = 0x5f3759df - (i >> 1);
    y  = * ( float * ) &i;
    y  = y * (1.5 - (x * y * y));
    y  = y * (1.5 - (x * y * y));

    return number * y;
}

double f_sqrt_d(const double number)
{
    int i;
    double x, y;

    x = number * 0.5;
    y  = number;
    i  = * (int * ) &y;
    i  = 0x5f3759df - (i >> 1);
    y  = * ( double * ) &i;
    y  = y * (1.5 - (x * y * y));
    y  = y * (1.5 - (x * y * y));

    return number * y;
}