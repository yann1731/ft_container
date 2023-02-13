#include <memory>
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include <iterator>

using ft::iterator;

namespace ft
{
template <class T, class Allocator>
	class _vector_base
	{
	public:
		typedef Allocator 							allocator_type;
		typedef typename Allocator::size_type 		size_type;
	protected:
		typedef T 									value_type;
		typedef value_type& 						reference;
		typedef const value_type& 					const_reference;
		typedef typename Allocator::pointer 		pointer;
		typedef typename Allocator::const_pointer 	const_pointer;
		typedef pointer 							iterator;
		typedef const_pointer 						const_iterator;

		pointer _start;
		pointer _end;
		pointer _end_ptr;
		allocator_type _end_type;

		allocator_type& alloc() my_noexcept
		{
			return _end_type;
		}

		const allocator_type& alloc() const my_noexcept
		{
			return _end_type;
		}

		pointer& _end_cap() my_noexcept
		{
			return _end_ptr;
		}

		const pointer& _end_cap() const my_noexcept
		{
			return _end_ptr;
		}

		_vector_base();

		_vector_base(const allocator_type& alloc);

		~_vector_base();

		void clear() my_noexcept
		{
			destruct_at_end(_begin);
		}

		size_type capacity() const my_noexcept
		{
			return static_cast<size_type>()
		}
	};

};