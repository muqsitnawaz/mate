
#pragma once

#include <random>
#include <unordered_map>

#include "mate/core/modulus.hpp"
#include "hash.hpp"

namespace mate
{
    template <Domain dmn>
    using UniformDistType = std::uniform_int_distribution<dmn>;

    struct PRNG
    {
        template <Domain dmn>
        static auto get(std::pair<dmn, dmn> bounds) noexcept
        {
            static std::random_device device;
            static std::mt19937 engine(device());
            static std::unordered_map<std::pair<dmn, dmn>, UniformDistType<dmn>> dists;

            auto it = dists.find(bounds);
            if (it == dists.end())
            {
                it = dists.insert({bounds, UniformDistType<dmn>(bounds.first, bounds.second)}).first;
            }
            return it->second(engine);
        }
    };
}