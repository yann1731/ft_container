#include "iterator.hpp"
#include "iterator_trait.hpp"

#define my_noexcept throw()

namespace ft
{

template <typename Iterator, typename Container>
class vector_iterator
{
protected:
	Iterator current;

	typedef ft::iterator_traits<Iterator> 				traits_type;

public:
	typedef Iterator									iterator_type;
	typedef typename traits_type::iterator_category 	iterator_category;
	typedef typename traits_type::value_type 			value_type;
	typedef typename traits_type::difference_type 		difference_type;
	typedef typename traits_type::reference 			reference;
	typedef typename traits_type::pointer 				pointer;

	vector_iterator() my_noexcept: current(Iterator) {}

	vector_iterator(const Iterator& iter) my_noexcept: current(iter) {}
};

}