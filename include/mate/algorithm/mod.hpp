
#pragma once

#include <range/v3/algorithm/for_each.hpp>

#include "mate/core/modulus.hpp"
#include "mate/modular/mod.hpp"
#include "mate/modular/multiply.hpp"

namespace mate
{
    template <Set Set_>
    inline constexpr auto mod(Set_&& set, Domain_type<Set_> modulus)
    {
        using Set_t = std::decay_t<Set_>;

        Set_t result;
        auto fn_reduce = [&result, modulus](const auto elem)
        {
            result.insert(mod(elem, modulus));
        };
        ranges::for_each(set, fn_reduce);
        return result;
    }
}