
#pragma once

#include <exception>
#include <vector>

#include <range/v3/algorithm/transform.hpp>
#include <range/v3/numeric/accumulate.hpp>

#include "mate/algorithm/closed.hpp"
#include "mate/algorithm/identity.hpp"
#include "mate/algorithm/inverse.hpp"
#include "mate/core/domain.hpp"
#include "mate/core/operation.hpp"
#include "mate/core/set.hpp"
#include "mate/utility/name.hpp"

namespace mate
{
    template <Domain dmn_, Operation opr_, Set Set_>
    auto make_group(Set_&& set);

    template <Domain dmn, Operation opr>
    class Group
    {
    public:
        using dmn_type = dmn;
        using opr_type = opr;
        using set_type = Set_type<dmn>;

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

        template <Domain dmn_, Operation opr_, Set Set_>
        friend auto make_group(Set_&& elements);
    };

    template <Domain dmn_, Operation opr_, Set Set_>
    auto make_group(Set_&& set)
    {
        static_assert(std::is_same_v<Domain_type<Set_>, dmn_>, "Set must be over the same domain.");

        if (!has_identity<opr_>(set))
        {
            throw std::invalid_argument(fmt::format("Set doesn't have an identity w.r.t {}.", name<opr_>()));
        }
        if (!has_inverses<opr_>(set))
        {
            throw std::invalid_argument("Set doesn't contain an inverse of each element.");
        }
        if (!is_closed<opr_>(set))
        {
            throw std::invalid_argument(fmt::format("Set is not closed under {}.", name<opr_>()));
        }

        using Group_t = Group<dmn_, opr_>;

        Group_t group;
        group.elements_ = std::forward<typename Group_t::set_type>(set);
        return group;
    }
}