#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP
#include <cstddef>

#ifndef my_noexcept
# define my_noexcept throw()
#endif

namespace ft
{
template <bool B, class T = void>
struct enable_if
{
};

template <typename T>
struct enable_if<true, T>
{
    typedef T type;
};

template<class T, T v>
struct integral_constant
{
    typedef T value_type;
    typedef integral_constant<T, v> type;

    static const T value = v;

    operator value_type() const my_noexcept
    {
        return value;
    }

    value_type operator()() const my_noexcept
    {
        return value;
    }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <class T>
    struct _is_integral: public false_type {};

    struct _is_integral<bool>: public true_type {};

    struct _is_integral<char>: public true_type {};

    struct _is_integral<unsigned char>: public true_type {};

    struct _is_integral<wchar_t>: public true_type {};

    struct _is_integral<short>: public true_type {};

    struct _is_integral<unsigned short>: public true_type {};

    struct _is_integral<int>: public true_type {};

    struct _is_integral<unsigned int>: public true_type {};

    struct _is_integral<long>: public true_type {};

    struct _is_integral<unsigned long>: public true_type {};

    struct _is_integral<long long>: public true_type {};

    struct _is_integral<unsigned long long>: public true_type {};

template<class T>
    struct remove_cv { typedef T type; };

template<class T>
    struct remove_cv<const T> { typedef T type; };

template<class T>
    struct remove_cv<volatile T> { typedef T type; };

template<class T>
    struct remove_cv<const volatile T> { typedef T type; };


template<typename T>
    struct is_integral: public _is_integral<remove_cv<T>::type> {};
}

#endif