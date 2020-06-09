
#pragma once

#include <range/v3/algorithm/find.hpp>
#include <range/v3/algorithm/transform.hpp>
#include <range/v3/numeric.hpp>

#include "../alias.hpp"
#include "../domain.hpp"
#include "../modulus.hpp"
#include "../operation.hpp"
#include "mod.hpp"

namespace mate
{
    template <SignedInteger dmn, Operation opr>
    inline constexpr dmn inverse(dmn value) noexcept
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

    template <UnsignedInteger dmn, Operation opr>
    inline constexpr dmn inverse(dmn value, dmn modulus) noexcept
    {
        if constexpr (meta_::is_add_t<opr>())
        {
            return mod(modulus - mod(value, modulus), modulus);
        }
        else
        {
            throw std::runtime_error("Multiplicative inverse is not defined over integers.");
        }
    }

    // TODO: Validate that the type Set is defined over valid domain.

    template <Operation opr, typename Set>
    inline constexpr bool has_inverses(Set&& set) noexcept
    {
        using namespace ranges::views;
        using dmn = Domain_type<Set>;

        auto fn_get_inverse = [](const auto elem) { return inverse<dmn, opr>(elem); };
        auto fn_inv_exists = [&set](const auto inverse)
        {
            return ranges::find(set, inverse) != end(set);
        };
        const auto inverses_exists = set | transform(fn_get_inverse) | transform(fn_inv_exists);
        return ranges::accumulate(inverses_exists, true, std::multiplies<bool>());
    }

    template <Domain dmn, Operation opr, typename Set>
    inline constexpr bool has_inverses(Set&& set, Modulus<dmn> modulus) noexcept
    {
        using namespace ranges::views;

        // Verify that modulus and set domain is the same.
        static_assert(std::is_same_v<Domain_type<Set>, dmn>);

        auto fn_get_inverse = [mod = *modulus](const auto elem)
        {
            return inverse<dmn, opr>(elem, mod);
        };
        auto fn_inv_exists = [&set](const auto inverse)
        {
            return ranges::find(set, inverse) != end(set);
        };
        const auto inverses_exists = set | transform(fn_get_inverse) | transform(fn_inv_exists);
        return ranges::accumulate(inverses_exists, true, std::multiplies<bool>());
    }
}