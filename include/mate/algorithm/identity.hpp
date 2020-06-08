
#pragma once

#include <range/v3/algorithm/find.hpp>

#include "../alias.hpp"
#include "../domain.hpp"
#include "../operation.hpp"

namespace mate
{
    template <Domain dmn, Operation opr>
    inline constexpr dmn get_identity()
    {
        if constexpr (meta_::is_signed_integral_t<dmn>())
        {
            if constexpr (meta_::is_add_t<opr>())
            {
                // Return additive identity.
                return static_cast<dmn>(0);
            }
            else
            {
                // Return multiplicative identity.
                return static_cast<dmn>(1);
            }
        }
        else
        {
            throw std::logic_error("Unknown domain.");
        }
    }

    template <Operation operation, typename Set>
    inline constexpr bool has_identity(Set&& set) noexcept
    {
        auto identity = get_identity<Domain_type<Set>, operation>();
        return ranges::find(set, identity) != ranges::end(set);
    }
}