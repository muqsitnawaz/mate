
#pragma once

#include <range/v3/algorithm/for_each.hpp>

#include "mate/modular/mod.hpp"
#include "../modulus.hpp"

namespace mate
{
    template <Domain dmn, typename Set>
    inline constexpr std::decay_t<Set> mod(Set&& set, Modulus<dmn> modulus)
    {
        using Set_t = std::decay_t<Set>;
        static_assert(std::is_same_v<typename Set_t::value_type, dmn>);

        Set_t result;
        auto fn_reduce = [&result, m = modulus.get()](const auto elem)
        {
            result.insert(mod(elem, m));
        };
        ranges::for_each(set, fn_reduce);
        return result;
    }
}