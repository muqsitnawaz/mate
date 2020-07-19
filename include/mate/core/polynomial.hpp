
#pragma once

#include <vector>

#include <fmt/format.h>

#include <range/v3/view/indices.hpp>
#include <range/v3/algorithm/move.hpp>
#include <range/v3/algorithm/transform.hpp>
#include <range/v3/view/zip_with.hpp>
#include <range/v3/iterator/insert_iterators.hpp>
#include <range/v3/range/conversion.hpp>

#include "mate/concepts/std.hpp"

// TODO: Needs a memory pool.

namespace mate
{
    /**
     * Uni-variate polynomial type.
     */
    template <Integer Int>
    class polynomial
    {
    public:
        using coeff_type = Int;

        inline void print() const noexcept
        {
            fmt::memory_buffer out;
            for (const auto index : ranges::views::indices(data_.size()))
            {
                if (!index)
                {
                    format_to(out, "{}", data_.at(index));
                }
                else
                {
                    format_to(out, " + {}x^{}", data_.at(index), index);
                }
            }
            fmt::print("{}\n", std::string(out.begin(), out.end()));
        }

    private:
        std::vector<Int> data_;

    public:
        explicit polynomial(size_t degree) noexcept
        {
            data_.resize(degree);
        }

        explicit polynomial(std::initializer_list<Int> data)
        {
            data_.reserve(data.size());
            ranges::move(data, ranges::back_inserter(data_));
        }

        inline polynomial operator+(const polynomial& other) const
        {
            assert(data_.size() == other.data_.size());

            polynomial sum(data_.size());
            ranges::transform(data_, other.data_, sum.data_.begin(), std::plus());
            return sum;
        }

        inline polynomial operator*(const polynomial& other) const
        {
            assert(data_.size() == other.data_.size());

            polynomial sum(data_.size());
            ranges::transform(data_, other.data_, sum.data_.begin(), std::multiplies());
            return sum;
        }

        inline polynomial operator%(const Int modulus) const
        {
            polynomial reduced(data_.size());
            const auto fn_reduce = [modulus](const auto elem) { return elem % modulus; };
            ranges::transform(data_, reduced.data_.begin(), fn_reduce);
            return reduced;
        }
    };
}