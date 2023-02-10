#include <memory>
#include "iterator.hpp"
#include "vector_iterator.hpp"
#include <iterator>

#define my_noexcept throw();
using ft::iterator;

namespace ft
{

template <class T, class Allocator>
	class _vector_base
	{
	public:
		typedef Allocator allocator_type;
		typedef typename Allocator::size_type size_type;
	protected:
		typedef T value_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename vector_iterator<pointer> iterator;
		typedef typename vector_iterator<const_pointer> const_iterator;

		pointer _start;
		pointer _end;
		pointer _finish;

		allocator_type& alloc() my_noexcept
		{
			return _end;
		}
	}

};