
#pragma once

#include <range/v3/algorithm/find.hpp>

#include "../domain.hpp"
#include "../operation.hpp"

namespace mate
{
    template <Domain domain, Operation operation>
    constexpr domain get_identity()
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
                throw std::runtime_error("Unknown operation for integers domain.");
            }
        }
        else
        {
            throw std::runtime_error("Unknown domain.");
        }
    }

    template <typename Set>
    using Domain_type = typename std::decay_t<Set>::value_type;

    template <Operation operation, typename Set>
    inline bool has_identity(Set&& set)
    {
        auto identity = get_identity<Domain_type<Set>, operation>();
        return ranges::find(set, identity) != ranges::end(set);
    }
}