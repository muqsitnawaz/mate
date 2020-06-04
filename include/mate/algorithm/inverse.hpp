
#pragma once

#include "../domain.hpp"
#include "../operation.hpp"

namespace mate
{
    template <SignedInteger signed_integer, Operation operation>
    signed_integer get_inverse(signed_integer value) noexcept
    {
        if constexpr (std::is_same_v<operation, Addition>)
        {
            return -value;
        }
        else
        {
            throw std::runtime_error("Multiplicative inverse is undefined over integers.");
        }
    }
}