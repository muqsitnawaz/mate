
#pragma once

#include <exception>
#include <vector>

#include <range/v3/algorithm/transform.hpp>
#include <range/v3/algorithm/find_if.hpp>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/transform.hpp>

#include "domain.hpp"
#include "operation.hpp"
#include "set.hpp"

#include "algorithm/identity.hpp"
#include "algorithm/inverse.hpp"

#include "mate/arithmetic/compute.hpp"
#include "utility/name.hpp"

namespace mate
{
    template <Domain _dmn, Operation _opr, typename _Set>
    auto make_group(_Set&& set);

    template <Domain dmn, Operation opr>
    class Group
    {
    public:
        using dmn_type = dmn;
        using opr_type = opr;
        using set_type = Set<dmn>;

        inline void print()
        {
            for (auto elem : elements_)
            {
                fmt::print("{} ", elem);
            }
        }

    private:
        set_type elements_;

        Group() = default;

        template <Domain _dmn, Operation _opr, typename _Set>
        friend auto make_group(_Set&& elements);
    };

    template <Domain _dmn, Operation _opr, typename _Set>
    auto make_group(_Set&& set)
    {
        using Group_t = Group<_dmn, _opr>;

        namespace rg = ranges;
        using namespace rg::views;

        // Verify that set has identity element.
        if (!has_identity<_opr>(set))
        {
            auto msg = fmt::format("Set doesn't have an identity w.r.t {}.", name<_opr>());
            throw std::invalid_argument(msg);
        }

        // Verify that set contains inverses for each element.
        if constexpr (meta_::is_signed_integral_t<_dmn>())
        {
            // TODO: No need to compute inverse of each element -- early break (use find_if).
            auto fn_get_inverse = [](const auto elem) { return get_inverse<_dmn, _opr>(elem); };
            auto fn_inv_exists = [&set](const auto inverse)
            {
                return rg::find(set, inverse) != end(set);
            };
            auto inverses_exists = set | transform(fn_get_inverse) | transform(fn_inv_exists);
            auto all_inverses_exist = rg::accumulate(inverses_exists, true, std::multiplies<bool>());
            if (!all_inverses_exist)
            {
                throw std::invalid_argument("Set doesn't contain an inverse of each element.");
            }
        }
        else
        {
            throw std::invalid_argument("Set doesn't contain an inverse of each element.");
        }

        // Verify that set is closed under given operation.
        auto fn_make_pairs = [&set](const auto elem)
        {
            return set | transform([elem](const auto v) { return std::make_pair(elem, v); });
        };
        auto pairs = ranges::views::join(set | ranges::views::transform(fn_make_pairs));
        auto fn_not_exists = [&set](auto p)
        {
            return rg::find(set, compute<_dmn, _opr>(p.first, p.second)) == rg::end(set);
        };
        auto closed_under_op = ranges::find_if(pairs, fn_not_exists) == ranges::end(pairs);
        if (!closed_under_op)
        {
            throw std::invalid_argument(fmt::format("Set is not closed under {}.", name<_opr>()));
        }

        Group_t group;
        group.elements_ = std::forward<typename Group_t::set_type>(set);
        return group;
    }
}