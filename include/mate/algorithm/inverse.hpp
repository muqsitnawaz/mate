
#pragma once

#include <range/v3/algorithm/find.hpp>
#include <range/v3/algorithm/transform.hpp>
#include <range/v3/numeric.hpp>

#include "mate/arithmetic/inverse.hpp"
#include "mate/modular/inverse.hpp"

namespace mate
{
    template <Operation opr, Set Set_>
    inline constexpr bool has_inverses(Set_&& set) noexcept
    {
        using dmn = Domain_type<Set_>;
        using namespace ranges::views;

        auto fn_get_inverse = [](const auto elem) { return inverse<dmn, opr>(elem); };
        auto fn_inv_exists = [&set](const auto inverse)
        {
            return ranges::find(set, inverse) != end(set);
        };
        const auto inverses_exists = set | transform(fn_get_inverse) | transform(fn_inv_exists);
        return ranges::accumulate(inverses_exists, true, std::multiplies<bool>());
    }

    template <Operation opr, Set Set_>
    inline constexpr bool has_inverses(Set_&& set, Modulus<Domain_type<Set_>> modulus) noexcept
    {
        using dmn = Domain_type<Set_>;
        using namespace ranges::views;

        auto fn_get_inverse = [modulus](const auto elem)
        {
            return inverse<dmn, opr>(elem, modulus);
        };
        auto fn_inv_exists = [&set](const auto inverse)
        {
            return ranges::find(set, inverse) != end(set);
        };
        const auto inverses_exists = set | transform(fn_get_inverse) | transform(fn_inv_exists);
        return ranges::accumulate(inverses_exists, true, std::multiplies<bool>());
    }
}