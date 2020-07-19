
#pragma once

#include <tuple>

#include "mate/core/domain.hpp"

namespace mate
{
    template <Domain dmn>
    inline void combine(std::size_t& seed, dmn v)
    {
        seed ^= std::hash<dmn>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
}

namespace std
{
    template <mate::Domain dmn>
    struct hash<std::pair<dmn, dmn>>
    {
        inline auto operator()(std::pair<dmn, dmn> pair) const
        {
            size_t seed = 0;
            mate::combine(seed, pair.first);
            mate::combine(seed, pair.second);
            return seed;
        }
    };
}