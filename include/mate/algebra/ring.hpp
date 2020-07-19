
#pragma once

#include "mate/algorithm/is_abelian.hpp"

namespace mate
{
    template <Domain dmn>
    auto make_ring(group<dmn, Addition> set);

    template <Domain dmn>
    class ring
    {
    public:
        using dmn_type = dmn;


    private:
        template <Domain dmn_, Operation opr_, Set Set_>
        friend auto make_group(Set_&& elements);
    };

    template <Domain dmn>
    auto make_ring(group<dmn, Addition> group)
    {
        // TODO: Change assert below to static_assert -- need to use a constexpr set.
        assert(is_abelian(group));

        // TODO: Verify other axioms of the ring.

        ring<dmn> ring;
        return ring;
    }
}