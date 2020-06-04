
#pragma once

#include <optional>
#include <unordered_set>

#include <range/v3/algorithm/find.hpp>

#include "domain.hpp"
#include "operation.hpp"

namespace mate
{
    template <Domain domain, Operation operation>
    domain get_identity()
    {
        if constexpr (std::is_integral_v<domain>)
        {
            if constexpr (std::is_same_v<operation, Addition>)
            {
                return static_cast<domain>(0);
            }
            else if (std::is_same_v<operation, Multiplication>)
            {
                return static_cast<domain>(1);
            }
            else
            {
                throw std::logic_error("Unknown operation.");
            }
        }
        else
        {
            throw std::logic_error("Unknown domain.");
        }
    }

    template <typename Set>
    using Domain_type = typename Set::value_type;

    template <Operation operation, typename Set>
    inline bool has_identity(Set&& set)
    {
        auto identity = get_identity<Domain_type<std::decay_t<Set>>, operation>();
        return ranges::find(set, identity) != ranges::end(set);
    }
}