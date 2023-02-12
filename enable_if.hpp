#include <cstddef>

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
}