
#pragma once

#include <range/v3/numeric/iota.hpp>

#include "mate/algorithm/is_closed.hpp"
#include "mate/algorithm/has_identity.hpp"
#include "mate/algorithm/has_inverses.hpp"
#include "mate/algorithm/mod.hpp"
#include "mate/core/set.hpp"
#include "mate/core/operation.hpp"
#include "mate/core/modulus.hpp"
#include "mate/utility/name.hpp"

namespace mate
{
    template <Domain dmn_, Operation opr_, Set Set_>
    auto make_quotient_group(Set_&& set, Modulus<dmn_> modulus);

    template <Domain dmn_, Operation opr_>
    auto make_quotient_group(Modulus<dmn_> modulus);

    template <Domain dmn, Operation opr>
    class QuotientGroup
    {
    public:
        using dmn_type = dmn;
        using opr_type = opr;
        using set_type = Set_type<dmn>;

        inline void print() const
        {
            for (auto elem : elements_)
            {
                fmt::print("{} ", elem);
            }
            fmt::print("\n");
        }

        // TODO: For quotient group, no need to store elements -- store bound.

    private:
        set_type elements_;

        template <Domain dmn_, Operation opr_>
        friend auto make_quotient_group(Modulus<dmn_> modulus);

        template <Domain dmn_, Operation opr_, Set Set_>
        friend auto make_quotient_group(Set_&& set, Modulus<dmn_> modulus);
    };

    /**
     * Creates the group Z/mZ.
     */
    template <Domain dmn_, Operation opr_>
    auto make_quotient_group(Modulus<dmn_> modulus)
    {
        std::vector<dmn_> elems(modulus.width());
        if constexpr (meta_::is_add_v<opr_>)
        {
            ranges::iota(elems, modulus.bounds().first);
        }
        else
        {
            throw std::logic_error("Unimplemented.");
        }

        using Group_t = QuotientGroup<dmn_, opr_>;
        using Set_t = typename Group_t::set_type;

        Group_t group;
        group.elements_ = Set_t(std::make_move_iterator(elems.begin()), std::make_move_iterator(elems.end()));
        return group;
    }

    template <Domain dmn_, Operation opr_, Set Set_>
    auto make_quotient_group(Set_&& set, Modulus<dmn_> modulus)
    {
        static_assert(std::is_same_v<Domain_type<Set_>, dmn_>, "Set must be over the same domain.");

        // Verify set is a group.
        if (!has_identity<opr_>(set))
        {
            throw std::invalid_argument(fmt::format("Set doesn't have an identity w.r.t {}.", name<opr_>()));
        }
        if (!has_inverses<opr_>(set, modulus))
        {
            throw std::invalid_argument("Set doesn't contain an inverse of each element.");
        }
        if (!is_closed<opr_>(set, modulus))
        {
            throw std::invalid_argument(fmt::format("Set is not closed under {}.", name<opr_>()));
        }

        using Group_t = QuotientGroup<dmn_, opr_>;

        Group_t group;
        group.elements_ = mod<Set_>(std::forward<Set_>(set), modulus);
        return group;
    }
}