#include "foundation.h"

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

double d_sqrt_d(const double number)
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