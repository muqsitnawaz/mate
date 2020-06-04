
#pragma once

#include "../domain.hpp"
#include "../operation.hpp"

namespace mate
{
    template <SignedInteger sig_int, Operation opr>
    inline constexpr sig_int get_inverse(sig_int value) noexcept
    {
        if constexpr (is_add_t<opr>())
        {
            return -value;
        }
        else
        {
            throw std::runtime_error("Multiplicative inverse is undefined over integers.");
        }
    }
}