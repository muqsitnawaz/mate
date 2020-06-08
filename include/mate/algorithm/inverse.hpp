
#pragma once

#include <range/v3/algorithm/find.hpp>
#include <range/v3/algorithm/transform.hpp>
#include <range/v3/numeric.hpp>

#include "../alias.hpp"
#include "../domain.hpp"
#include "../operation.hpp"

namespace mate
{
    template <SignedInteger dmn, Operation opr>
    inline constexpr dmn get_inverse(dmn value) noexcept
    {
        if constexpr (meta_::is_add_t<opr>())
        {
            return -value;
        }
        else
        {
            throw std::runtime_error("Multiplicative inverse is not defined over integers.");
        }
    }

    template <Operation opr, typename Set>
    inline constexpr bool has_inverses(Set&& set) noexcept
    {
        using namespace ranges::views;
        using dmn = Domain_type<Set>;

        static_assert(meta_::is_signed_integral_t<dmn>());

        auto fn_get_inverse = [](const auto elem) { return get_inverse<dmn, opr>(elem); };
        auto fn_inv_exists = [&set](const auto inverse)
        {
            return ranges::find(set, inverse) != end(set);
        };
        auto inverses_exists = set | transform(fn_get_inverse) | transform(fn_inv_exists);
        return ranges::accumulate(inverses_exists, true, std::multiplies<bool>());
    }
}