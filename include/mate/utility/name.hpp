
#pragma once

#include "../operation.hpp"

namespace mate
{
    template <Operation operation>
    inline std::string name() noexcept
    {
        if constexpr (meta_::is_add_t<operation>())
        {
            return "Addition";
        }
        else
        {
            return "Multiplication";
        }
    }
}