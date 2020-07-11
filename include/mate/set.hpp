
#pragma once

#include <unordered_set>

#include "domain.hpp"

namespace mate
{
    template <typename>
    struct is_std_unordered_set : std::false_type {};

    template <typename V, typename H, typename P, typename A>
    struct is_std_unordered_set<std::unordered_set<V, H, P, A>> : std::true_type {};

    template <typename T>
    inline constexpr bool is_set_v = is_std_unordered_set<std::decay_t<T>>::value;

    template <Domain dmn>
    using Set = std::unordered_set<dmn>;
}