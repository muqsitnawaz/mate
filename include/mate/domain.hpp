
#pragma once

#include "concepts/std.hpp"
#include "concepts/core.hpp"

namespace mate
{
    template <typename T>
    concept Domain = Integer<T> or Polynomial<T>;
}