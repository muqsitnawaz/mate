
#pragma once

#include "mate/core/operation.hpp"

namespace mate
{
    template <Operation operation>
    inline std::string name() noexcept
    {
        if constexpr (meta_::is_add_v<operation>)
        {
            return "Addition";
        }
        else
        {
            return "Multiplication";
        }
    }
}