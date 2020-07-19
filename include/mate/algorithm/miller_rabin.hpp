
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
    inline bool miller_rabin(dmn d, dmn input)
    {
        // Compute a^d % input where a is random in [2, input - 2].
        auto x = pow(PRNG::get(std::make_pair<dmn, dmn>(2, input - 2)), d, input);
        if (x == 1 || x == input - 1)
        {
            return true;
        }

        // Keep squaring x while one of the following doesn't
        // happen
        // (i)   d does not reach input-1
        // (ii)  (x^2) % input is not 1
        // (iii) (x^2) % input is not input-1
        while (d != input - 1)
        {
            x = multiply(x, x, input);
            d *= 2;

            if (x == 1) { return false; }
            if (x == input - 1) { return true; }
        }
        return false;
    }
}