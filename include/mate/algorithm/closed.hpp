
#pragma once

#include <fmt/format.h>

#include <range/v3/algorithm/find.hpp>
#include <range/v3/algorithm/find_if.hpp>
#include <range/v3/algorithm/transform.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/transform.hpp>

#include "../alias.hpp"
#include "../domain.hpp"
#include "../modulus.hpp"
#include "../operation.hpp"

#include "../arithmetic/compute.hpp"
#include "../modular/compute.hpp"

namespace mate
{
    template <Operation opr, typename Set>
    inline constexpr bool is_closed(Set&& set) noexcept
    {
        namespace rg = ranges;

        auto fn_make_pairs = [&set](const auto elem)
        {
            return set | rg::views::transform([elem](const auto v) { return std::make_pair(elem, v); });
        };
        auto pairs = ranges::views::join(set | ranges::views::transform(fn_make_pairs));
        auto fn_not_exists = [&set](const auto p)
        {
            return rg::find(set, compute<Domain_type<Set>, opr>(p.first, p.second)) == rg::end(set);
        };
        return ranges::find_if(pairs, fn_not_exists) == ranges::end(pairs);
    }

    template <Domain dmn, Operation opr, typename Set>
    inline constexpr bool is_closed(Set&& set, Modulus<dmn> modulus) noexcept
    {
        namespace rg = ranges;

        // Verify that modulus and set domain is the same.
        static_assert(std::is_same_v<Domain_type<Set>, dmn>);

        auto fn_make_pairs = [&set](const auto elem)
        {
            return set | rg::views::transform([elem](const auto v) { return std::make_pair(elem, v); });
        };
        auto pairs = ranges::views::join(set | ranges::views::transform(fn_make_pairs));
        auto fn_not_exists = [&set, mod = static_cast<dmn>(modulus)](const auto p)
        {
            return rg::find(set, compute<dmn, opr>(p.first, p.second, mod)) == rg::end(set);
        };
        return ranges::find_if(pairs, fn_not_exists) == ranges::end(pairs);
    }
}