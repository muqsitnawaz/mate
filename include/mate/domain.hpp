
#pragma once

#include <type_traits>

namespace mate
{
    template <typename T>
    concept Domain = std::is_integral_v<T>;
}