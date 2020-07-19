
#pragma once

#include <unordered_set>

#include "domain.hpp"

namespace mate
{
    namespace meta_
    {
        template <typename>
        struct is_std_unordered_set : std::false_type {};

        template <typename V, typename H, typename P, typename A>
        struct is_std_unordered_set<std::unordered_set<V, H, P, A>> : std::true_type {};

        template <typename T>
        inline constexpr bool is_set_v = is_std_unordered_set<std::decay_t<T>>::value;
    }

    template <typename Set>
    using Domain_type = typename std::decay_t<Set>::value_type;

    template <Domain dmn>
    using Set_type = std::unordered_set<dmn>;

    template <typename T>
    concept Set = meta_::is_set_v<T> and Domain<Domain_type<T>>;
}