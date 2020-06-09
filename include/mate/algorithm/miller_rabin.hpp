
#pragma once

#include <random>

#include "../modular/pow.hpp"

namespace mate
{
    /**
     * Performs miller-rabin test for probable primes.
     */
    template <Domain dmn>
    inline bool miller_rabin(dmn d, dmn n)
    {
        // Pick a random number in [2..n-2]
        // Corner cases make sure that n > 4
        dmn a = 2 + rand() % (n - 4);

        // Compute a^d % n
        auto x = pow(a, d, n);
        if (x == 1 || x == n - 1)
        {
            return true;
        }

        // Keep squaring x while one of the following doesn't
        // happen
        // (i)   d does not reach n-1
        // (ii)  (x^2) % n is not 1
        // (iii) (x^2) % n is not n-1
        while (d != n - 1)
        {
            x = multiply(x, x, n);
            d *= 2;

            if (x == 1)
            { return false; }
            if (x == n - 1)
            { return true; }
        }

        return false;
    }
}