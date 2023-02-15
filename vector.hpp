#include <memory>
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include "pair.hpp"

using ft::iterator;

namespace ft
{

	// template<typename _Integer>
	//     void _M_initialize_dispatch(_Integer __n, _Integer __value, __true_type)
	//     {
	//         this->_M_impl._M_start = _M_allocate(_S_check_init_len(static_cast<size_type>(__n), _M_get_Tp_allocator()));
	//         this->_M_impl._M_end_of_storage = this->_M_impl._M_start + static_cast<size_type>(__n);
	//         _M_fill_initialize(static_cast<size_type>(__n), __value);
	//     }

	// 	template<typename _InputIterator>
	//     void _M_initialize_dispatch(_InputIterator __first, _InputIterator __last, __false_type)
	//     {
	//         _M_range_initialize(__first, __last, std::__iterator_category(__first));
	//     }

	// 	template<typename _InputIterator>
	//     void _M_range_initialize(_InputIterator __first, _InputIterator __last, std::input_iterator_tag)
	//     {
	//         __try
    //         {
	//             for (; __first != __last; ++__first)
    //                 push_back(*__first);
	//         }
    //         __catch(...)
    //         {
	//             clear();
	//         __throw_exception_again;
	//         }
	//     }

	// 	template<typename _ForwardIterator>
	//     void _M_range_initialize(_ForwardIterator __first, _ForwardIterator __last, std::forward_iterator_tag)
	//     {
	//         const size_type __n = std::distance(__first, __last);
	//         this->_M_impl._M_start = this->_M_allocate(_S_check_init_len(__n, _M_get_Tp_allocator()));
	//         this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
	//         this->_M_impl._M_finish = std::__uninitialized_copy_a(__first, __last, this->_M_impl._M_start, _M_get_Tp_allocator());
	//     }

	// 	 void _M_fill_initialize(size_type __n, const value_type& __value)
    //     {
	//         this->_M_impl._M_finish = std::__uninitialized_fill_n_a(this->_M_impl._M_start, __n, __value, _M_get_Tp_allocator());
    //     }

	// 	template<typename _Integer>
	//     void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
	//     {
    //         _M_fill_assign(__n, __val);
    //   	}

	// 	template<typename _InputIterator>
	//     void _M_assign_dispatch(_InputIterator __first, _InputIterator __last, __false_type)
	//     {
    //         _M_assign_aux(__first, __last, std::__iterator_category(__first));
    //     }

	// 	template<typename _Integer>
    //   void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val, __true_type)
	//     {
    //         _M_fill_insert(__pos, __n, __val);
    //   	}

	// template<typename _InputIterator>
	//     void _M_insert_dispatch(iterator __pos, _InputIterator __first, _InputIterator __last, __false_type)
	//     {
	//         _M_range_insert(__pos, __first, __last, std::__iterator_category(__first));
	//     }

	// 	size_type _M_check_len(size_type __n, const char* __s) const
    //  	{
	//       if (max_size() - size() < __n)
	//           __throw_length_error(__N(__s));
	//       const size_type __len = size() + (std::max)(size(), __n);
	//       return (__len < size() || __len > max_size()) ? max_size() : __len;
    //  	}

	// 	static size_type _S_check_init_len(size_type __n, const allocator_type& __a)
    //   	{
	//       if (__n > _S_max_size(_Tp_alloc_type(__a)))
	//           __throw_length_error(
	//       __N("cannot create std::vector larger than max_size()"));
	//       return __n;
    //   	}

	// 	static size_type _S_max_size(const _Tp_alloc_type& __a) _GLIBCXX_NOEXCEPT
    //   	{
	//       // std::distance(begin(), end()) cannot be greater than PTRDIFF_MAX,
	//       // and realistically we can't store more than PTRDIFF_MAX/sizeof(T)
	//       // (even if std::allocator_traits::max_size says we can).
	//       const size_t __diffmax = __gnu_cxx::__numeric_traits<ptrdiff_t>::__max / sizeof(_Tp);
	//       const size_t __allocmax = _Alloc_traits::max_size(__a);
	//       return (std::min)(__diffmax, __allocmax);
    //   	}

	// 	void _M_erase_at_end(pointer __pos) _GLIBCXX_NOEXCEPT
    //   	{
	//       if (size_type __n = this->_M_impl._M_finish - __pos)
	//       {
	//           std::_Destroy(__pos, this->_M_impl._M_finish, _M_get_Tp_allocator());
	//           this->_M_impl._M_finish = __pos;
	//           _GLIBCXX_ASAN_ANNOTATE_SHRINK(__n);
	//       }
    //   	}

	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T 											value_type;
		typedef Allocator 									allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::size_type 			size_type;
		typedef typename allocator_type::difference_type 	difference_type;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef typename iterator<pointer> 					iterator;
		typedef typename iterator<const_pointer> 			const_iterator;
		typedef typename reverse_iterator<iterator> 		reverse_iterator;
		typedef typename reverse_iterator<const_iterator> 	const_reverse_iterator;

	private:
		allocator_type 	_alloc;
		pointer 		_begin;
		pointer 		_last;
		pointer 		_end;
		alloc_range(size_type count, const T& value = T()) {
			_begin = _alloc.allocate(count);
			_alloc.construct(_begin, value);
		}
	
	public:
		vector(): _alloc(Allocator()) {};

		explicit vector(const allocator_type& alloc): _alloc(alloc), _begin(nullptr), _last(nullptr), _end(nullptr) {};

		explicit vector(size_type count, const T& value = T(), const allocator_type& alloc = Allocator()) {
			_begin = alloc.allocate(count);
			_last = _begin;
			_end = _begin + count;
			alloc.construct(_begin, value);
		};

	template<class InputIt>
		vector(InputIt first, InputIt last, const allocator_type& alloc = Allocator()) {
			size_type n = static_cast<size_type>(last - first);
			_begin = alloc.allocate(n);
			_last = _begin;
			_end = _begin + n;
			alloc.construct(_begin, value);
		}

		vector(const vector& other) {
			_begin = alloc.allocate(static_cast<size_type>(other.end() - other.begin()));
		}

		~vector() {

		}

		vector& operator=(const vector& other) {

		}

		void assign(size_type count, const T& value) {

		}

	template< class InputIt >
		void assign(InputIt first, InputIt last) {

		}

		allocator_type get_allocator(void) const {
			return _alloc;
		}

		reference at(size_type pos) {
			//std::out_of_range if !(pos < size()).
		}

		const_reference at(size_type pos) const {
			//std::out_of_range if !(pos < size()).
		}

		reference operator[](size_type pos) {
			//undefined behavior if trying to access element out of range
		}

		const_reference operator[](size_type pos) {
			//undefined behavior if trying to access element out of range
		}

		reference front(void) {

		}

		const_reference front(void) const {

		}

		reference back(void) {

		}

		const_reference back(void) const {

		}

		T* data(void) {

		}

		const T* data(void) const {

		}

		iterator begin(void) {

		}

		const_iterator begin(void) {

		}

		iterator end(void) {

		}

		const_iterator end(void) const {

		}

		reverse_iterator rbegin(void) {

		}

		const_reverse_iterator rbegin(void) const {

		}

		reverse_iterator rend(void) {

		}

		const_reverse_iterator rend(void) const {

		}

		bool empty(void) const {

		}

		size_type size() const {
			//Returns the number of elements in the container, i.e. std::distance(begin(), end()).
		}

		size_type max_size() const {
			//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
			//This value typically reflects the theoretical limit on the size of the container, at most std::numeric_limits<difference_type>::max(). At runtime, the size of the container may be limited to a value smaller than max_size() by the amount of RAM available.
		}

		void reserve(size_type new_cap) {
			/* Increase the capacity of the vector (the total number of elements that the vector can hold without requiring reallocation) to a value that's greater or equal to new_cap. If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function does nothing.
			reserve() does not change the size of the vector.
			If new_cap is greater than capacity(), all iterators, including the past-the-end iterator, and all references to the elements are invalidated. Otherwise, no iterators or references are invalidated.
			After a call to reserve(), insertions will not trigger reallocation unless the insertion would make the size of the vector greater than the value of capacity().
			std::length_error if new_cap > max_size().
			any exception thrown by Allocator::allocate() (typically std::bad_alloc) */
		}

		size_type capacity() const {
			//Returns the number of elements that the container has currently allocated space for.
		}

		void clear() {
			/* Erases all elements from the container. After this call, size() returns zero.
			Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators are also invalidated.  
			Leaves the capacity() of the vector unchanged (note: the standard's restriction on the changes to capacity is in the specification of vector::reserve, see [1]) */
		}

		iterator insert(const iterator pos, const T& value) {

		}

		iterator insert(const iterator pos, size_type count, const T& value) {

		}

	template< class InputIt >
		iterator insert(const_iterator pos, InputIt first, InputIt last) {

		}

		iterator erase(iterator pos) {
			/* Erases the specified elements from the container.
			1) Removes the element at pos.
			2) Removes the elements in the range [first, last) */
		}

		iterator erase(iterator first, iterator last) {

		}

		void push_back(const T& value) {
			//appends the given element value to the end of the container. the new element is initialized as a copy of value
			//value is moved into the new element. If the new size() is greater than capacity() then all
			//iterators and references (including the past-the-end iterator) are invalidated.
			//Otherwise only the past-the-end iterator is invalidated.
		}

		void pop_back() {
			//Removes the last element of the container. UB if container empty
		}

		void resize(size_type count, T value = T()) {
			/* Resizes the container to contain count elements.
			If the current size is greater than count, the container is reduced to its first count elements.
			If the current size is less than count,
			1) additional default-inserted elements are appended
			2) additional copies of value are appended.*/
		}

		void swap(vector& other) {

		}
	};

template<class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const std::vector<T, Alloc>& rhs) {

	}

template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const std::vector<T, Alloc>& rhs) {

	}

template<class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

	}

template<class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

	}

template<class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

	}

template<class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		
	}
};