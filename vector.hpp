#include <memory>
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include "pair.hpp"

using ft::iterator;

namespace ft
{
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
	
	public:
		vector():_alloc(Allocator()), _alloc(Allocator), _begin(_alloc.allocate(0)), _last(_begin), _end(_begin) {};

		explicit vector(const allocator_type& alloc): _alloc(alloc), _begin(_alloc.allocator(0)), _last(_begin), _end(_begin) {};

		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()): _alloc(alloc), _begin(_alloc.allocator(count), _last(_begin), _end(_begin) {
			alloc_range(count, value, _alloc);
		};

		explicit vector(size_type n) {};


	template<class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());

		vector( const vector& other );

		~vector() {};
	};
};