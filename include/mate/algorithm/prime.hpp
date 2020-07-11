
#pragma once

#include "miller_rabin.hpp"

#include <range/v3/view/indices.hpp>

namespace mate
{
    template <Domain dmn>
    constexpr bool is_prime(dmn input, dmn iterations = 3)
    {
        if (input <= 1 || input == 4) { return false; }
        if (input <= 3) { return true; }

        dmn d = input - 1;
        while (mod(d, static_cast<dmn>(2)) == static_cast<dmn>(0)) { d /= 2; }

        for ([[maybe_unused]] const auto idx : ranges::views::indices(iterations))
        {
            if (!miller_rabin(d, input)) { return false; }
        }
        return true;
    }
}