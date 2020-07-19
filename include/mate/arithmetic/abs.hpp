
#pragma once

#include "mate/core/domain.hpp"

namespace mate
{
    template <Domain dmn>
    inline constexpr dmn abs(dmn elem) noexcept
    {
        if constexpr (meta_::is_signed_integer_v<dmn>)
        {
            elem = elem < 0 ? -elem : elem;
        }
        return elem;
    }
}