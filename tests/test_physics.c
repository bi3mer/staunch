#include "staunch/exam.h"
#include "staunch/general_math.h"
#include "staunch/physics.h"
#include "staunch/units.h"

#define EPSILON_F32 1e-6f
#define EPSILON_F64 1e-12

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_circle_mass_f32
    S_EXAM("s_circle_mass_f32")
    {
        f32 mass;

        // Unit circle, unit density: mass = π
        mass = s_circle_mass_f32(1.0f, 1.0f);
        s_assert(s_approximately_f32(mass, S_PI_32, EPSILON_F32));

        // Radius 2, density 1: mass = 4π
        mass = s_circle_mass_f32(2.0f, 1.0f);
        s_assert(s_approximately_f32(mass, 4.0f * S_PI_32, EPSILON_F32));

        // Radius 1, density 2: mass = 2π
        mass = s_circle_mass_f32(1.0f, 2.0f);
        s_assert(s_approximately_f32(mass, 2.0f * S_PI_32, EPSILON_F32));

        // Radius 3, density 5: mass = 45π
        mass = s_circle_mass_f32(3.0f, 5.0f);
        s_assert(s_approximately_f32(mass, 45.0f * S_PI_32, EPSILON_F32));

        // Zero radius
        mass = s_circle_mass_f32(0.0f, 10.0f);
        s_assert(s_approximately_f32(mass, 0.0f, EPSILON_F32));

        // Zero density
        mass = s_circle_mass_f32(5.0f, 0.0f);
        s_assert(s_approximately_f32(mass, 0.0f, EPSILON_F32));
    }

    ///////////////////////////////////////////////////////////////////////////
    // s_circle_mass_f64
    S_EXAM("s_circle_mass_f64")
    {
        f64 mass;

        // Unit circle, unit density: mass = π
        mass = s_circle_mass_f64(1.0, 1.0);
        s_assert(s_approximately_f64(mass, S_PI_64, EPSILON_F64));

        // Radius 2, density 1: mass = 4π
        mass = s_circle_mass_f64(2.0, 1.0);
        s_assert(s_approximately_f64(mass, 4.0 * S_PI_64, EPSILON_F64));

        // Radius 1, density 2: mass = 2π
        mass = s_circle_mass_f64(1.0, 2.0);
        s_assert(s_approximately_f64(mass, 2.0 * S_PI_64, EPSILON_F64));

        // Radius 3, density 5: mass = 45π
        mass = s_circle_mass_f64(3.0, 5.0);
        s_assert(s_approximately_f64(mass, 45.0 * S_PI_64, EPSILON_F64));

        // Zero radius
        mass = s_circle_mass_f64(0.0, 10.0);
        s_assert(s_approximately_f64(mass, 0.0, EPSILON_F64));

        // Zero density
        mass = s_circle_mass_f64(5.0, 0.0);
        s_assert(s_approximately_f64(mass, 0.0, EPSILON_F64));
    }

    s_exam_log_summary();
    return 0;
}
