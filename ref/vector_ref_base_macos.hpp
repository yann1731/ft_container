#include <__config>
#include <__bit_reference>
#include <__debug>
#include <__functional_base>
#include <__iterator/wrap_iter.h>
#include <__split_buffer>
#include <__utility/forward.h>
#include <algorithm>
#include <climits>
#include <compare>
#include <cstdlib>
#include <cstring>
#include <initializer_list>
#include <iosfwd> // for forward declaration of vector
#include <limits>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <version>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCPP_PUSH_MACROS
#include <__undef_macros>


_LIBCPP_BEGIN_NAMESPACE_STD

template <bool>
class _LIBCPP_TEMPLATE_VIS __vector_base_common
{
protected:
    _LIBCPP_INLINE_VISIBILITY __vector_base_common() {}
    _LIBCPP_NORETURN void __throw_length_error() const;
    _LIBCPP_NORETURN void __throw_out_of_range() const;
};

template <bool __b>
void
__vector_base_common<__b>::__throw_length_error() const
{
    _VSTD::__throw_length_error("vector");
}

template <bool __b>
void
__vector_base_common<__b>::__throw_out_of_range() const
{
    _VSTD::__throw_out_of_range("vector");
}

_LIBCPP_EXTERN_TEMPLATE(class _LIBCPP_EXTERN_TEMPLATE_TYPE_VIS __vector_base_common<true>)

template <class _Tp, class _Allocator>
class __vector_base
    : protected __vector_base_common<true>
{
public:
    typedef _Allocator                               allocator_type;
    typedef allocator_traits<allocator_type>         __alloc_traits;
    typedef typename __alloc_traits::size_type       size_type;
protected:
    typedef _Tp                                      value_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    typedef typename __alloc_traits::difference_type difference_type;
    typedef typename __alloc_traits::pointer         pointer;
    typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef pointer                                  iterator;
    typedef const_pointer                            const_iterator;

    pointer                                         __begin_;
    pointer                                         __end_;
    __compressed_pair<pointer, allocator_type> __end_cap_;

    _LIBCPP_INLINE_VISIBILITY
    allocator_type& __alloc() _NOEXCEPT
        {return __end_cap_.second();}
    _LIBCPP_INLINE_VISIBILITY
    const allocator_type& __alloc() const _NOEXCEPT
        {return __end_cap_.second();}
    _LIBCPP_INLINE_VISIBILITY
    pointer& __end_cap() _NOEXCEPT
        {return __end_cap_.first();}
    _LIBCPP_INLINE_VISIBILITY
    const pointer& __end_cap() const _NOEXCEPT
        {return __end_cap_.first();}

    _LIBCPP_INLINE_VISIBILITY
    __vector_base()
        _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value);
    _LIBCPP_INLINE_VISIBILITY __vector_base(const allocator_type& __a);
    ~__vector_base();

    _LIBCPP_INLINE_VISIBILITY
    void clear() _NOEXCEPT {__destruct_at_end(__begin_);}
    _LIBCPP_INLINE_VISIBILITY
    size_type capacity() const _NOEXCEPT
        {return static_cast<size_type>(__end_cap() - __begin_);}

    _LIBCPP_INLINE_VISIBILITY
    void __destruct_at_end(pointer __new_last) _NOEXCEPT;

    _LIBCPP_INLINE_VISIBILITY
    void __copy_assign_alloc(const __vector_base& __c)
        {__copy_assign_alloc(__c, integral_constant<bool,
                      __alloc_traits::propagate_on_container_copy_assignment::value>());}

    _LIBCPP_INLINE_VISIBILITY
    void __move_assign_alloc(__vector_base& __c)
        _NOEXCEPT_(
            !__alloc_traits::propagate_on_container_move_assignment::value ||
            is_nothrow_move_assignable<allocator_type>::value)
        {__move_assign_alloc(__c, integral_constant<bool,
                      __alloc_traits::propagate_on_container_move_assignment::value>());}

    _LIBCPP_NORETURN _LIBCPP_HIDE_FROM_ABI
    void __throw_length_error() const {
        __vector_base_common<true>::__throw_length_error();
    }

    _LIBCPP_NORETURN _LIBCPP_HIDE_FROM_ABI
    void __throw_out_of_range() const {
        __vector_base_common<true>::__throw_out_of_range();
    }

private:
    _LIBCPP_INLINE_VISIBILITY
    void __copy_assign_alloc(const __vector_base& __c, true_type)
        {
            if (__alloc() != __c.__alloc())
            {
                clear();
                __alloc_traits::deallocate(__alloc(), __begin_, capacity());
                __begin_ = __end_ = __end_cap() = nullptr;
            }
            __alloc() = __c.__alloc();
        }

    _LIBCPP_INLINE_VISIBILITY
    void __copy_assign_alloc(const __vector_base&, false_type)
        {}

    _LIBCPP_INLINE_VISIBILITY
    void __move_assign_alloc(__vector_base& __c, true_type)
        _NOEXCEPT_(is_nothrow_move_assignable<allocator_type>::value)
        {
            __alloc() = _VSTD::move(__c.__alloc());
        }

    _LIBCPP_INLINE_VISIBILITY
    void __move_assign_alloc(__vector_base&, false_type)
        _NOEXCEPT
        {}
};

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
void
__vector_base<_Tp, _Allocator>::__destruct_at_end(pointer __new_last) _NOEXCEPT
{
    pointer __soon_to_be_end = __end_;
    while (__new_last != __soon_to_be_end)
        __alloc_traits::destroy(__alloc(), _VSTD::__to_address(--__soon_to_be_end));
    __end_ = __new_last;
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY __vector_base<_Tp, _Allocator>::__vector_base() _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value): __begin_(nullptr), __end_(nullptr), __end_cap_(nullptr, __default_init_tag())
{
    
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
__vector_base<_Tp, _Allocator>::__vector_base(const allocator_type& __a)
    : __begin_(nullptr),
      __end_(nullptr),
      __end_cap_(nullptr, __a)
{
}


template <class _Tp, class _Allocator>
__vector_base<_Tp, _Allocator>::~__vector_base()
{
    if (__begin_ != nullptr)
    {
        clear();
        __alloc_traits::deallocate(__alloc(), __begin_, capacity());
    }
}
