#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include "pair.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"
#include <iostream>
#include <vector>

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
		typedef T* 													pointer;
		typedef const T* 											const_pointer;
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
		vector(): _alloc(Allocator()), _begin(_alloc.allocate(0)), _last(_begin), _end(_last) {};

		explicit vector(const allocator_type& alloc): _alloc(alloc), _begin(_alloc.allocate(0)), _last(_begin), _end(_last) {};

		explicit vector(size_type count, const T& value = T(), const allocator_type& alloc = Allocator()): _alloc(alloc) {
			if (count >= max_size())
				throw std::length_error("cannot create ft::vector larger than max_size()");
			_begin = _alloc.allocate(count);
			_last = _begin + count;
			_end = _begin + count;
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_begin + i, value);
		};

	template<class InputIt>
		vector(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last, const allocator_type& alloc = Allocator()): _alloc(alloc) {
			size_type n = std::distance(first, last);
			_begin = _alloc.allocate(n);
			_last = _begin + n;
			_end = _last;
			std::copy(first, last, _begin);
		}
	
		vector(const vector& other): _alloc(other.get_allocator()) {
			_begin = _alloc.allocate(other.size());
			_last = _begin + other.size();
			_end = _begin + other.capacity();

			size_type other_size = other.size();
			for (size_type i = 0; i < other_size; i++)
				_alloc.construct(_begin + i, *(other._begin + i));
		}

		vector(vector& other): _alloc(other.get_allocator()) {
			_begin = _alloc.allocate(other.size());
			_last = _begin + other.size();
			_end = _begin + other.capacity();

			size_type other_size = other.size();
			for (size_type i = 0; i < other_size; i++)
				_alloc.construct(_begin + i, *(other._begin + i));
		}

		~vector() {
			clear();
			deallocate_data();
		}

	template<class Container>
		vector& operator=(const Container& other) {
			if (this == &other)
				return *this;
			if (this->size() < other.size())
				reserve(other.size());
			for (size_type i; i < other.size(); i++) {
				_alloc.construct(_begin + i, other._begin + i);
				// this->_begin[i] = other._begin[i];
			}
			return *this;
		}

		void assign(size_type count, const T& value) {
			size_type old_size = size();
			if (count > capacity()) //if new size > old_size allocate count memory
				reallocate(count);
			clear();
			for (size_type i = 0; i < old_size; i++) //destroy old elements
			{
				_alloc.destroy(_begin + i);
				_alloc.construct(_begin + i, value);
			}
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_begin + i, value);
			_last = _begin + count;
			//Replaces the contents with count copies of value value
		}

	template< class InputIt >
		void assign(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last) {
			if ((last - first) > capacity())
				reallocate(last - first);
			clear();
			_last = std::copy(first, last, _begin);
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
				return NULL;
			else
				return _begin;
		}

		const T* data(void) const {
			if (this->size() == 0)
				return NULL;
			else
				return _begin;
		}

		iterator begin(void) {
			return iterator(_begin);
		}

		const_iterator begin(void) const {
			return const_iterator(_begin);
		}

		iterator end(void) {
			return iterator(_last);
		}

		const_iterator end(void) const {
			return const_iterator(_last);
		}

		reverse_iterator rbegin(void) {
			return reverse_iterator(_begin);
		}

		const_reverse_iterator rbegin(void) const {
			return const_reverse_iterator(_begin);
		}

		reverse_iterator rend(void) {
			return reverse_iterator(_last + 1);
		}

		const_reverse_iterator rend(void) const {
			return const_reverse_iterator(_last + 1);
		}

		bool empty(void) const {
			return (size() == 0);
		}

		size_type size() const {
			return (_last - _begin); //Returns the number of elements in the container, i.e. std::distance(begin(), end()).
		}

		size_type max_size() const {
			return std::numeric_limits<difference_type>::max() / sizeof(T);
			//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
			//This value typically reflects the theoretical limit on the size of the container, at most std::numeric_limits<difference_type>::max(). At runtime, the size of the container may be limited to a value smaller than max_size() by the amount of RAM available.
		}

		void reserve(size_type new_cap) {
			if (new_cap >= max_size())
				throw std::length_error("cannot reserve more than max_size()");
			if (new_cap > this->capacity()) {
				reallocate(new_cap);
			}
			/* Increase the capacity of the vector (the total number of elements that the vector can hold without requiring reallocation) to a value that's greater or equal to new_cap. If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function does nothing.
			reserve() does not change the size of the vector.
			If new_cap is greater than capacity(), all iterators, including the past-the-end iterator, and all references to the elements are invalidated. Otherwise, no iterators or references are invalidated.
			After a call to reserve(), insertions will not trigger reallocation unless the insertion would make the size of the vector greater than the value of capacity().
			std::length_error if new_cap > max_size().
			any exception thrown by Allocator::allocate() (typically std::bad_alloc) */
		}

		size_type capacity() const {
			 return size_type(_end - _begin);
			//Returns the number of elements that the container has currently allocated space for.
		}

		void clear() {
			size_type old_size = size();
        	for (size_type i = 0; i < old_size; ++i) {
            	_alloc.destroy(_begin + i);
				// _begin[i].~T();
        	}
			_last = _begin;
			/* Erases all elements from the container. After this call, size() returns zero.
			Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators are also invalidated.  
			Leaves the capacity() of the vector unchanged (note: the standard's restriction on the changes to capacity is in the specification of vector::reserve, see [1]) */
		}

		iterator insert(const iterator pos, const T& value) {
			return insert(pos, 1, value);
				//inserts value before pos.
		}

		iterator insert(const iterator pos, size_type count, const T& value) {
			size_type index = pos - begin();
			size_type new_size = size() + count;
			if (new_size > capacity()) {
				pointer new_begin = _alloc.allocate(new_size);
				for (size_type i = 0; i < index; i++) {
					_alloc.construct(new_begin + i, _begin[i]);
					_alloc.destroy(_begin + i);
				}
				for (size_type i = 0; i < count; i++) {
					_alloc.construct(new_begin + (index + i), value);
				}
				for (size_type i = index + count; i < new_size; i++) {
					_alloc.construct(new_begin + i, _begin[i - count]);
					_alloc.destroy(_begin + (i - count));
				}
				_alloc.deallocate(_begin, capacity());
				_begin = new_begin;
				_last = _begin + new_size;
				_end = _last;
				return pos + count;
			}

			for (size_type i = 0; i < index; i++) {
				_alloc.construct(_begin + i, _begin[i]);
			}
			for (size_type i = index; i < new_size; i++) {
				_alloc.construct(_begin + (i + count), _begin[i]);
				_alloc.destroy(_begin + i);
				if (i < (index + count))
					_alloc.construct(_begin + i, value);
			}
			_last += count;
			return iterator(pos + count);
			//inserts count copies of the value before pos
		}

	template< class InputIt >
		iterator insert(const iterator pos, InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last) {
			size_type range = last - first;
			size_type index = pos - begin();
			size_type new_size = range + size();
			if (new_size > capacity()) {
				pointer new_begin = _alloc.allocate(new_size);
				for (size_type i = 0; i < index; i++) {
					_alloc.construct(new_begin + i, _begin[i]);
					_alloc.destroy(_begin + i);
				}
				for (size_type i = 0; i < range; i++) {
					_alloc.construct(new_begin + (index + i), first[i]);
				}
				for (size_type i = index + range; i < new_size; i++) {
					_alloc.construct(new_begin + i, _begin[i - range]);
					_alloc.destroy(_begin + (i - range));
				}
				_alloc.deallocate(_begin, capacity());
				_begin = new_begin;
				_last = _begin + new_size;
				_end = _last;
				return iterator(pos + range);
			}

			for (size_type i = 0; i < index; i++) {
				_alloc.construct(_begin + i, _begin[i]);
			}
			for (size_type i = index; i < new_size; i++) {
				_alloc.construct(_begin + (i + range), _begin[i]);
				_alloc.destroy(_begin + i);
				if (i < (index + range))
					_alloc.construct(_begin + i, first[i]);
			}
			_last += range;
			return iterator(pos + range);
		}

		iterator erase(iterator pos) {
			if (pos == end())
				return pos;
			size_type range = end() - begin();
			
			for (size_type i = 0; i < range; i++) {
				_alloc.destroy(_begin + i);
				_alloc.construct(_begin + i, *(_begin + i + 1));
			}
			_last--;
			return (pos++);
			/* Erases the specified elements from the container.
			1) Removes the element at pos.
			2) Removes the elements in the range [first, last) */
		}

		iterator erase(iterator first, iterator last) {
			for (iterator it = first; it < last; it++) {
				erase(first);
			}
			return (first + 1);
		}

		void push_back(const T& value) {
			if (size() == capacity()) {
				reallocate_double();
			}
			_alloc.construct(_last, value);
			_last++;
 			//appends the given element value to the end of the container. the new element is initialized as a copy of value
			//value is moved into the new element. If the new size() is greater than capacity() then all
			//iterators and references (including the past-the-end iterator) are invalidated.
			//Otherwise only the past-the-end iterator is invalidated.
		}

		void pop_back() {
			--_last;
			_alloc.destroy(_last);
			//Removes the last element of the container. UB if container empty
		}

		void resize(size_type count, T value = T()) {
			if (count >= max_size())
				throw std::length_error("Cannot resize ft::vector to max_size");
			if (size() > count) {
				size_type tmp_size = size();
				for (size_type i = 0; i < (tmp_size - count); i++) {
					pop_back();
				}
			}
			else {
				size_type index = count - size();
				for (size_type i = index; i < count; i++) {
					push_back(value);	
				}
			}
			/* Resizes the container to contain count elements.
			If the current size is greater than count, the container is reduced to its first count elements.
			If the current size is less than count,
			1) additional default-inserted elements are appended
			2) additional copies of value are appended.*/
		}

		void swap(vector& other) {
			pointer tmp_begin = _begin;
			pointer tmp_last = _last;
			pointer tmp_end = _end;

			_begin = other._begin;
			_last = other._last;
			_end = other._end;

			other._begin = tmp_begin;
			other._last = tmp_last;
			other._end = tmp_end;
		}

	private:
		void deallocate_data() {
			if (_begin)
			{
				size_type cap = capacity();
				_alloc.deallocate(_begin, cap);
				_begin = NULL;
				_last = NULL;
				_end = NULL;
			}
		}

		void reallocate(size_type new_cap) {
			pointer _new_begin = _alloc.allocate(new_cap);
			size_type old_size = size();
        	for (size_type i = 0; i < size(); ++i) {
            	_alloc.construct(_new_begin + i, _begin[i]);
            	_alloc.destroy(_begin + i);
        	}
        	_alloc.deallocate(_begin, capacity());
        	_begin = _new_begin;
			_last = _begin + old_size;
        	_end = _begin + new_cap;
		}

		void reallocate_double() {
			size_type new_cap = capacity() * 2;
			pointer _new_begin = _alloc.allocate(new_cap);
			size_type old_size = size();
			for (size_type i = 0; i < old_size; ++i) {
            	_alloc.construct(_new_begin + i, _begin[i]);
            	_alloc.destroy(_begin + i);
        	}
        	_alloc.deallocate(_begin, capacity());
        	_begin = _new_begin;
			_last = _begin + old_size;
        	_end = _begin + new_cap;
		};

		size_type reallocate_one(iterator pos, const T& value) {
			size_type index = begin() - pos;
			size_type new_cap = capacity() + 1;
			pointer _new_begin = _alloc.allocate(new_cap);
			size_type old_size = size();
			for (size_type i = index; i < old_size; ++i) {
            	_alloc.construct(_new_begin + i, _begin[i + 1]);
            	_alloc.destroy(_begin + i);
        	}
			_new_begin[index] = value;
        	_alloc.deallocate(_begin, capacity());
        	_begin = _new_begin;
			_last = _begin + old_size;
        	_end = _begin + new_cap;
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

template<class Allocator>
	class vector<bool, Allocator> {
	};
};

#endif