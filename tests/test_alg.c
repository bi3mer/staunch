#include "alg.h"
#include "exam.h"

int main(void)
{
    ///////////////////////////////////////////////////////////////////////////
    // s_alg_has_non_zero_d
    {
        e_begin("s_alg_has_non_zero_d");

        // empty array
        {
            double arr[] = {};
            e_assert(!s_alg_has_non_zero_d(arr, 0));
        }

        // single element
        {
            double zero[] = {0.0};
            double positive[] = {5.0};
            double negative[] = {-3.14};
            e_assert(!s_alg_has_non_zero_d(zero, 1));
            e_assert(s_alg_has_non_zero_d(positive, 1));
            e_assert(s_alg_has_non_zero_d(negative, 1));
        }

        // all zeros
        {
            double arr[] = {0.0, 0.0, 0.0, 0.0, 0.0};
            e_assert(!s_alg_has_non_zero_d(arr, 5));
        }

        // all non-zero
        {
            double arr[] = {1.0, 2.5, -3.7, 4.2, 5.9};
            e_assert(s_alg_has_non_zero_d(arr, 5));
        }

        // position tests
        {
            double at_start[] = {1.5, 0.0, 0.0, 0.0};
            double at_end[] = {0.0, 0.0, 0.0, 2.7};
            double in_middle[] = {0.0, 0.0, 3.3, 0.0, 0.0};
            e_assert(s_alg_has_non_zero_d(at_start, 4));
            e_assert(s_alg_has_non_zero_d(at_end, 4));
            e_assert(s_alg_has_non_zero_d(in_middle, 5));
        }

        // very small values
        {
            double small_positive[] = {0.0, 1e-10, 0.0};
            double small_negative[] = {0.0, -1e-10, 0.0};
            e_assert(s_alg_has_non_zero_d(small_positive, 3));
            e_assert(s_alg_has_non_zero_d(small_negative, 3));
        }

        // mixed values
        {
            double arr[] = {-5.5, 0.0, 3.2, 0.0, -1.1, 0.0, 7.8};
            e_assert(s_alg_has_non_zero_d(arr, 7));
        }

        // negative zero
        {
            double arr[] = {-0.0, 0.0, -0.0};
            e_assert(!s_alg_has_non_zero_d(arr, 3));
        }

        // large arrays
        {
            double all_zeros[10000] = {0.0};
            double one_non_zero[10000] = {0.0};
            one_non_zero[50] = 1.0;
            e_assert(!s_alg_has_non_zero_d(all_zeros, 10000));
            e_assert(s_alg_has_non_zero_d(one_non_zero, 10000));
        }

        e_end();
    }

    return 0;
}
