
#pragma once

#include "mate/core/domain.hpp"

#include "mod.hpp"
#include "multiply.hpp"

namespace mate
{
    /**
     * Performs modular exponentiation.
     */
    template <Domain dmn>
    inline constexpr dmn pow(dmn x, dmn y, dmn modulus)
    {
        dmn res = 1;                // Initialize result
        x = mod(x, modulus);        // Update x if it is more than or equal to modulus.
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1) { res = multiply(res, x, modulus); }

            // y must be even now
            y = y >> 1;
            x = multiply(x, x, modulus);
        }
        return res;
    }
}