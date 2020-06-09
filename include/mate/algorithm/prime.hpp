
#pragma once

#include "miller_rabin.hpp"

namespace mate
{
    template <Domain dmn>
    constexpr bool is_prime(dmn input, dmn iterations = 3)
    {
        if (input <= 1 || input == 4)
        { return false; }
        if (input <= 3)
        { return true; }

        // Find r such that input = 2^d * r + 1 for some r >= 1
        dmn d = input - 1;
        while (mod(d, static_cast<dmn>(2)) == 0)
        {
            d /= 2;
        }

        for (dmn i = 0; i < iterations; ++i)
        {
            if (!miller_rabin(d, input))
            {
                return false;
            }
        }

        return true;
    }
}