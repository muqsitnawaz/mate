
#pragma once

#include <range/v3/algorithm/find.hpp>

#include "mate/core/identity.hpp"
#include "mate/core/set.hpp"

namespace mate
{
    template <Operation operation, Set Set_>
    inline constexpr bool has_identity(Set_&& set) noexcept
    {
        const auto identity = get_identity<Domain_type<Set_>, operation>();
        return ranges::find(set, identity) != ranges::end(set);
    }
}