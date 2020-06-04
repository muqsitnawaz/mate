
#pragma once

#include <unordered_set>

#include "domain.hpp"

namespace mate
{
    template <Domain domain>
    using Set = std::unordered_set<domain>;
}