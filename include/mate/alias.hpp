
#pragma once

#include <type_traits>

template <typename Set>
using Domain_type = typename std::decay_t<Set>::value_type;