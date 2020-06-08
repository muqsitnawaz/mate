
#pragma once

#include <exception>
#include <vector>

#include <range/v3/algorithm/transform.hpp>

#include <range/v3/numeric/accumulate.hpp>

#include "domain.hpp"
#include "operation.hpp"
#include "set.hpp"

#include "algorithm/closed.hpp"
#include "algorithm/identity.hpp"
#include "algorithm/inverse.hpp"

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

        if (!has_identity<_opr>(set))
        {
            auto msg = fmt::format("Set doesn't have an identity w.r.t {}.", name<_opr>());
            throw std::invalid_argument(msg);
        }
        if (!has_inverses<_opr>(set))
        {
            throw std::invalid_argument("Set doesn't contain an inverse of each element.");
        }
        if (!is_closed<_opr>(set))
        {
            throw std::invalid_argument(fmt::format("Set is not closed under {}.", name<_opr>()));
        }

        Group_t group;
        group.elements_ = std::forward<typename Group_t::set_type>(set);
        return group;
    }
}