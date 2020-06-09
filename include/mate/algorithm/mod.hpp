
#pragma once

#include <range/v3/algorithm/for_each.hpp>

#include "../modular/mod.hpp"
#include "../modular/multiply.hpp"
#include "../modulus.hpp"

namespace mate
{
    template <Domain dmn, typename S, typename = std::enable_if_t<is_set_v<std::decay_t<S>>()>>
    inline constexpr std::decay_t<S> mod(S&& set, dmn modulus)
    {
        using Set_t = std::decay_t<S>;
        static_assert(std::is_same_v<typename Set_t::value_type, dmn>);

        Set_t result;
        auto fn_reduce = [&result, modulus](const auto elem)
        {
            result.insert(mod(elem, modulus));
        };
        ranges::for_each(set, fn_reduce);
        return result;
    }
}