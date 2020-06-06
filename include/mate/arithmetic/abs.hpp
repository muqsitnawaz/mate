
#pragma once

#include "mate/domain.hpp"

namespace mate
{
    template <Domain dmn>
    inline constexpr dmn abs(dmn elem) noexcept
    {
        if constexpr (meta_::is_signed_integral_t<dmn>())
        {
            elem = elem < 0 ? -elem : elem;
        }
        return elem;
    }
}