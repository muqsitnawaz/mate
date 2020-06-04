
#pragma once

#include <unordered_set>

#include "domain.hpp"

namespace mate
{
    template <Domain dmn>
    using Set = std::unordered_set<dmn>;
}