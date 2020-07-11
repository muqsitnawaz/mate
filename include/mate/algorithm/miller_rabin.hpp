
#pragma once

#include <random>

#include "../modular/pow.hpp"
#include "../utility/prng.hpp"

namespace mate
{
    /**
     * Performs miller-rabin test for probable primes.
     */
    template <Domain dmn>
    inline bool miller_rabin(dmn d, dmn n)
    {
        // Compute a^d % n where a is random in [2, n - 2].
        auto x = pow(PRNG::get(std::make_pair<dmn, dmn>(2, n - 2)), d, n);
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

            if (x == 1) { return false; }
            if (x == n - 1) { return true; }
        }
        return false;
    }
}