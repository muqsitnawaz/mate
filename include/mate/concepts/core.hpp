
#include "../polynomial.hpp"

namespace mate
{
    namespace meta_
    {
        template <typename>
        struct is_polynomial : std::false_type {};

        template <typename T>
        struct is_polynomial<is_polynomial<T>> : std::true_type {};

        template <typename T>
        inline constexpr bool is_polynomial_v = is_polynomial<T>::value;
    }

    template <typename T>
    concept Polynomial = meta_::is_polynomial_v<T>;
}