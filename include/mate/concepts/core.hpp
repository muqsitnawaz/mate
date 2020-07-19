
#include <type_traits>

#include <initializer_list>

namespace mate
{
    namespace meta_
    {
        template <typename>
        struct is_std_initializer_list : std::false_type {};

        template <typename E>
        struct is_std_initializer_list<std::initializer_list<E>> : std::true_type {};

        template <typename T>
        inline constexpr bool is_std_initializer_list_v = is_std_initializer_list<T>::value;
    }

    template <typename T>
    concept InitializerList = meta_::is_std_initializer_list_v<T>;
}