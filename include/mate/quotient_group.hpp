
#pragma once

#include <range/v3/numeric/iota.hpp>

#include "algorithm/mod.hpp"
#include "domain.hpp"
#include "operation.hpp"
#include "modulus.hpp"

#include "utility/type.hpp"

namespace mate
{
    template <Domain _dmn, Operation _opr, typename _Set>
    auto make_quotient_group(_Set&& set, Modulus<_dmn> modulus);

    template <Domain _dmn, Operation _opr>
    auto make_quotient_group(Modulus<_dmn> modulus);

    template <Domain dmn, Operation opr>
    class QuotientGroup
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
            fmt::print("\n");
        }

        // TODO: For quotient group, no need to store elements -- store bound.

    private:
        set_type elements_;

        QuotientGroup() = default;

        template <Domain _dmn, Operation _opr>
        friend auto make_quotient_group(Modulus<_dmn> modulus);

        template <Domain _dmn, Operation _opr, typename _Set>
        friend auto make_quotient_group(_Set&& set, Modulus<_dmn> modulus);
    };

    /**
     * Creates the group Z/mZ.
     */
    template <Domain _dmn, Operation _opr>
    auto make_quotient_group(Modulus<_dmn> modulus)
    {
        std::vector<_dmn> elems(modulus.width());
        if constexpr (meta_::is_add_t<_opr>())
        {
            ranges::iota(elems, modulus.bounds().first);
        }
        else
        {
            throw std::logic_error("Unimplemented.");
        }

        using Group_t = QuotientGroup<_dmn, _opr>;
        using Set_t = typename Group_t::set_type;

        Group_t group;
        group.elements_ = Set_t(std::make_move_iterator(elems.begin()), std::make_move_iterator(elems.end()));
        return group;
    }

    template <Domain _dmn, Operation _opr, typename _Set>
    auto make_quotient_group(_Set&& set, Modulus<_dmn> modulus)
    {
        // Verify set is a group.
        if (!has_identity<_opr>(set))
        {
            throw std::invalid_argument(fmt::format("Set doesn't have an identity w.r.t {}.", name<_opr>()));
        }
        if (!has_inverses<_dmn, _opr>(set, modulus))
        {
            throw std::invalid_argument("Set doesn't contain an inverse of each element.");
        }
        if (!is_closed<_dmn, _opr>(set, modulus))
        {
            throw std::invalid_argument(fmt::format("Set is not closed under {}.", name<_opr>()));
        }

        using Group_t = QuotientGroup<_dmn, _opr>;

        Group_t group;
        group.elements_ = mod(std::forward<_Set>(set), modulus);
        return group;
    }
}