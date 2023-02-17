#include <memory>
#include <limits>
#include <stdexcept>
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include "pair.hpp"
#include "algorithm.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T 													value_type;
		typedef Allocator 											allocator_type;
		typedef typename allocator_type::reference 					reference;
		typedef typename allocator_type::const_reference 			const_reference;
		typedef typename allocator_type::size_type 					size_type;
		typedef typename allocator_type::difference_type 			difference_type;
		typedef typename allocator_type::pointer 					pointer;
		typedef typename allocator_type::const_pointer 				const_pointer;
		typedef ft::vector_iterator<pointer, vector<T> > 			iterator;
		typedef ft::vector_iterator<const_pointer, vector<T> > 		const_iterator;
		typedef ft::reverse_iterator<iterator> 						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 				const_reverse_iterator;

	private:
		allocator_type 	_alloc;
		pointer 		_begin;
		pointer 		_last;
		pointer 		_end;
	
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
			alloc.construct(_begin, *_begin);
		}

		vector(const vector& other) {
			_begin = _alloc.allocate(static_cast<size_type>(other.end() - other.begin()));
		}

		~vector() {

		}

		vector& operator=(const vector& other) {
			if (this == &other)
				return *this;
			if (this->size() < other.size())
				reserve(other.size());
			for (size_type i; i < other.size(); i++)
			{
				this->_begin[i] = other._begin[i];
			}
			return *this;
		}

		void assign(size_type count, const T& value) {
			
			//Replaces the contents with count copies of value value
		}

	template< class InputIt >
		void assign(InputIt first, InputIt last) {
			//Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either argument is an iterator into *this.
		}

		allocator_type get_allocator(void) const {
			return _alloc;
		}

		reference at(size_type pos) {
			if (pos < size()) {
				return _begin[pos];
			}
			else
				throw std::out_of_range("out of range");
			//std::out_of_range if !(pos < size()).
		}

		const_reference at(size_type pos) const {
			if (pos < size()) {
				return _begin[pos];
			}
			else
				throw std::out_of_range("out of range");
			//std::out_of_range if !(pos < size()).
		}

		reference operator[](size_type pos) {
			return *(this->_begin + pos);
			//undefined behavior if trying to access element out of range
		}

		const_reference operator[](size_type pos) const {
			return *(this->_begin + pos);
			//undefined behavior if trying to access element out of range
		}

		reference front(void) {
			return *begin();
		}

		const_reference front(void) const {
			return *begin();
		}

		reference back(void) {
			return *(end() - 1);
		}

		const_reference back(void) const {
			return *(end() - 1);
		}

		T* data(void) {
			if (this->size() == 0)
				return nullptr;
			else
				_begin;
		}

		const T* data(void) const {
			if (this->size() == 0)
				return nullptr;
			else
				_begin;
		}

		iterator begin(void) {
			return iterator(_begin);
		}

		const_iterator begin(void) const {
			return const_iterator(_begin);
		}

		iterator end(void) {
			return iterator(_end);
		}

		const_iterator end(void) const {
			return const_iterator(_end);
		}

		reverse_iterator rbegin(void) {
			return reverse_iterator(_begin);
		}

		const_reverse_iterator rbegin(void) const {
			return const_reverse_iterator(_begin);
		}

		reverse_iterator rend(void) {
			return reverse_iterator(_end);
		}

		const_reverse_iterator rend(void) const {
			return const_reverse_iterator(_end);
		}

		bool empty(void) const {
			if (_begin == _end)
				return true;
			else
				return false;
		}

		size_type size() const {
			return std::distance(_begin, _end); //Returns the number of elements in the container, i.e. std::distance(begin(), end()).
		}

		size_type max_size() const {
			return std::numeric_limits<difference_type>::max();
			//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
			//This value typically reflects the theoretical limit on the size of the container, at most std::numeric_limits<difference_type>::max(). At runtime, the size of the container may be limited to a value smaller than max_size() by the amount of RAM available.
		}

		void reserve(size_type new_cap) {
			if (new_cap < this->size())
			{
				return ;
			}
			else
			{
				pointer _new_begin;
				std::uninitialized_copy(iterator(_begin), iterator(_last), iterator(_new_begin));
				_alloc.deallocate(_begin);
				_begin = _new_begin;
			}
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
				//inserts value before pos.
		}

		iterator insert(const iterator pos, size_type count, const T& value) {
			//inserts count copies of the value before pos
		}

	template< class InputIt >
		iterator insert(const_iterator pos, InputIt first, InputIt last) {
			//inserts elements from range [first, last) before pos.
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
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return rhs < lhs;
	}

template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}
};