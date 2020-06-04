
#pragma once

#include "domain.hpp"
#include "operation.hpp"
#include "modulus.hpp"

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
        }

    private:

        set_type elements_;

        QuotientGroup() = default;

        template <Domain _dmn, Operation _opr>
        friend auto make_quotient_group(Modulus<_dmn> modulus);

        template <Domain _dmn, Operation _opr, typename _Set>
        friend auto make_quotient_group(_Set&& set, Modulus<_dmn> modulus);
    };

    template <Domain _dmn, Operation _opr>
    auto make_quotient_group(Modulus<_dmn> modulus)
    {
        // TODO: Create group modulo modulus on domain.
    }

    template <Domain _dmn, Operation _opr, typename _Set>
    auto make_quotient_group(_Set&& set, Modulus<_dmn> modulus)
    {
        // TODO: Verify set is a group.

        // TODO: Create and store quotient group.
    }
}