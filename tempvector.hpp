#include <vector>

  /***** START OF _VECTOR_BASE *****/

  template<typename _Tp, typename _Alloc>
    struct _Vector_base
    {
      typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template rebind<_Tp>::other _Tp_alloc_type;
      typedef typename __gnu_cxx::__alloc_traits<_Tp_alloc_type>::pointer pointer;

      struct _Vector_impl_data
      {
	      pointer _M_start;
	      pointer _M_finish;
	      pointer _M_end_of_storage;

	      _Vector_impl_data() : _M_start(), _M_finish(), _M_end_of_storage() { }

	      void _M_copy_data(_Vector_impl_data const& __x) _GLIBCXX_NOEXCEPT
	      {
	        _M_start = __x._M_start;
	        _M_finish = __x._M_finish;
	        _M_end_of_storage = __x._M_end_of_storage;
	      }

	      void _M_swap_data(_Vector_impl_data& __x)
	      {
	        // Do not use std::swap(_M_start, __x._M_start), etc as it loses
	        // information used by TBAA.
	        _Vector_impl_data __tmp;
	        __tmp._M_copy_data(*this);
	        _M_copy_data(__x);
	        __x._M_copy_data(__tmp);
	      }
      };

      struct _Vector_impl: public _Tp_alloc_type, public _Vector_impl_data
      {
	        _Vector_impl() _GLIBCXX_NOEXCEPT_IF(is_nothrow_default_constructible<_Tp_alloc_type>::value) : _Tp_alloc_type() { }

	        _Vector_impl(_Tp_alloc_type const& __a): _Tp_alloc_type(__a) { }
      };

      public:
        typedef _Alloc allocator_type;

        _Tp_alloc_type& _M_get_Tp_allocator()
        {
          return this->_M_impl;
        }

        const _Tp_alloc_type& _M_get_Tp_allocator() const
        {
          return this->_M_impl;
        }

        allocator_type get_allocator() const _GLIBCXX_NOEXCEPT
        {
          return allocator_type(_M_get_Tp_allocator());
        }

        _Vector_base() { }

        _Vector_base(const allocator_type& __a): _M_impl(__a) { }

        // Kept for ABI compatibility.
        _Vector_base(size_t __n): _M_impl()
        {
          _M_create_storage(__n);
        }

        _Vector_base(size_t __n, const allocator_type& __a): _M_impl(__a)
        { 
          _M_create_storage(__n);
        }

        ~_Vector_base()
        {
	        _M_deallocate(_M_impl._M_start,
		      _M_impl._M_end_of_storage - _M_impl._M_start);
        }

      public:
        _Vector_impl _M_impl;

        pointer _M_allocate(size_t __n)
        {
	        typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
	        return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
        }

        void _M_deallocate(pointer __p, size_t __n)
        {
	        typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
        	if (__p)
	        _Tr::deallocate(_M_impl, __p, __n);
        }

      protected:
        void _M_create_storage(size_t __n)
        {
	        this->_M_impl._M_start = this->_M_allocate(__n);
	        this->_M_impl._M_finish = this->_M_impl._M_start;
	        this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
        }
    };

    /***** END OF _VECTOR_BASE *****/
    /***** START OF VECTOR *****/

    template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class vector : protected _Vector_base<_Tp, _Alloc>
    {
        typedef _Vector_base<_Tp, _Alloc>			_Base;
      typedef typename _Base::_Tp_alloc_type		_Tp_alloc_type;
      typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type>	_Alloc_traits;

    public:
      typedef _Tp					value_type;
      typedef typename _Base::pointer			pointer;
      typedef typename _Alloc_traits::const_pointer	const_pointer;
      typedef typename _Alloc_traits::reference		reference;
      typedef typename _Alloc_traits::const_reference	const_reference;
      typedef __gnu_cxx::__normal_iterator<pointer, vector> iterator;
      typedef __gnu_cxx::__normal_iterator<const_pointer, vector>
      const_iterator;
      typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
      typedef std::reverse_iterator<iterator>		reverse_iterator;
      typedef size_t					size_type;
      typedef ptrdiff_t					difference_type;
      typedef _Alloc					allocator_type;

    private:

    protected:
      using _Base::_M_allocate;
      using _Base::_M_deallocate;
      using _Base::_M_impl;
      using _Base::_M_get_Tp_allocator;

      vector(const allocator_type& __a): _Base(__a) { }

      vector(size_type __n, const value_type& __value = value_type(), const allocator_type& __a = allocator_type()): _Base(_S_check_init_len(__n, __a), __a)
      {
        _M_fill_initialize(__n, __value);
      }

      vector(const vector& __x): _Base(__x.size(), _Alloc_traits::_S_select_on_copy(__x._M_get_Tp_allocator()))
      {
	      this->_M_impl._M_finish = std::__uninitialized_copy_a(__x.begin(), __x.end(),
	      this->_M_impl._M_start, _M_get_Tp_allocator());
      }

      template<typename _InputIterator>
	    vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a = allocator_type()): _Base(__a)
	    {
	      // Check whether it's an integral type.  If so, it's not an iterator.
	      typedef typename std::__is_integer<_InputIterator>::__type _Integral;
	      _M_initialize_dispatch(__first, __last, _Integral());
	    }

      ~vector() _GLIBCXX_NOEXCEPT
      {
	      std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish, _M_get_Tp_allocator());
      }

      vector& operator=(const vector& __x);

      void assign(size_type __n, const value_type& __val)
      { 
          _M_fill_assign(__n, __val);
      }

      template<typename _InputIterator>
	    void assign(_InputIterator __first, _InputIterator __last)
	    {
	      // Check whether it's an integral type.  If so, it's not an iterator.
	      typedef typename std::__is_integer<_InputIterator>::__type _Integral;
	      _M_assign_dispatch(__first, __last, _Integral());
	    }

      iterator begin() _GLIBCXX_NOEXCEPT
      {
        return iterator(this->_M_impl._M_start);
      }

      const_iterator begin() const _GLIBCXX_NOEXCEPT
      {
        return const_iterator(this->_M_impl._M_start);
      }

      iterator end() _GLIBCXX_NOEXCEPT
      {
        return iterator(this->_M_impl._M_finish);
      }

      const_iterator end() const _GLIBCXX_NOEXCEPT
      {
        return const_iterator(this->_M_impl._M_finish);
      }

      reverse_iterator rbegin() _GLIBCXX_NOEXCEPT
      {
        return reverse_iterator(end());
      }

      const_reverse_iterator rbegin() const _GLIBCXX_NOEXCEPT
      {
        return const_reverse_iterator(end());
      }

      reverse_iterator rend() _GLIBCXX_NOEXCEPT
      {
        return reverse_iterator(begin());
      }

      const_reverse_iterator rend() const _GLIBCXX_NOEXCEPT
      {
        return const_reverse_iterator(begin());
      }

      size_type size() const _GLIBCXX_NOEXCEPT
      {
        return size_type(this->_M_impl._M_finish - this->_M_impl._M_start);
      }

      size_type max_size() const _GLIBCXX_NOEXCEPT
      {
        return _S_max_size(_M_get_Tp_allocator());
      }

      void resize(size_type __new_size, value_type __x = value_type())
      {
	      if (__new_size > size())
	        _M_fill_insert(end(), __new_size - size(), __x);
	      else if (__new_size < size())
	        _M_erase_at_end(this->_M_impl._M_start + __new_size);
      }

  /***** END OF VECTOR *****/


// <typename T, class Allocator>
// class _base_vector
// {
// public:
//     using allocator_type = Allocator;
//     using _alloc_traits = allocator_traits<allocator_type>;
//     using size_type = typename _alloc_traits::size_type;
// protected:
//     using value_type = T;
//     using reference = value_type&;
//     using const_reference = const value_type&;;
//     using difference_type = typename __alloc_traits::difference_type;
//     using pointer = typename __alloc_traits::pointer;
//     using const_pointer = typename __alloc_traits::const_pointer;
//     using iterator = pointer;
//     using const_iterator = const_pointer;
// private:
// };


// // reference	value_type&
// // const_reference	const value_type&
// // pointer	 
// // Allocator::pointer	(until C++11)
// // std::allocator_traits<Allocator>::pointer	(since C++11)
 
// // const_pointer	 
// // Allocator::const_pointer	(until C++11)
// // std::allocator_traits<Allocator>::const_pointer	(since C++11)
 
// // iterator	 
// // LegacyRandomAccessIterator and LegacyContiguousIterator to value_type

// // (until C++20)
// // LegacyRandomAccessIterator, contiguous_iterator, and ConstexprIterator to value_type

// // (since C++20)
 
// // const_iterator	 
// // LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type

// // (until C++20)
// // LegacyRandomAccessIterator, contiguous_iterator, and ConstexprIterator to const value_type

// // (since C++20)
 
// // reverse_iterator	std::reverse_iterator<iterator>
// // const_reverse_iterator	std::reverse_iterator<const_iterator>
// using std::size_t;
// using std::ptrdiff_t;
// namespace ft
// {
//     template <typename T, typename Allocator = std::allocator<T> >
//     class vector: protected _vector_base<T, Allocator>
//     {
//     public:
//         typedef Allocator               				allocator_type;
//         typedef size_t                  				size_type;
//         typedef T                       				value_type;
//         typedef ptrdiff_t 								difference_type;
//         typedef value_type& 							reference;
//         typedef const value_type&						const_reference;
//         typedef Allocator::pointer						pointer;
//         typedef Allocator::const_pointer				const_pointer;
//         typedef value_type* 							iterator;
//         typedef const value_type*						const_iterator;
// 		typedef std::reverse_iterator<iterator>			reverse_iterator;
// 		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
//     protected:
//         vector()
//     private:
//         using _Base = _vector_base<_Tp, _Alloc>;
//         using _Tp_alloc_type =  typename _Base::_Tp_alloc_type;
//         using _Alloc_traits = __gnu_cxx::__alloc_traits<_Tp_alloc_type>;
        
//         T *elem;
//         size_t _size;
//     };
// }