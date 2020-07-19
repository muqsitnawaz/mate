
#pragma once

#include "mate/concepts/std.hpp"
#include "concepts.hpp"

namespace mate
{
    template <typename T>
    concept Domain = Integer<T> or Polynomial<T>;
}