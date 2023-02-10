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

	// vector_iterator(const vector_iterator<Iterator, Container>)

	reference operator*() const my_noexcept
	{
		return *current;
	}

	pointer operator->() const my_noexcept
	{
		return current;
	}

	vector_iterator& operator++() my_noexcept
	{
		++current;
		return *this;
	}

	vector_iterator operator++(int) my_noexcept
	{
		return (vector_iterator(current++));
	}

	vector_iterator& operator--() my_noexcept
	{
		--current;
		return *this;
	}

	vector_iterator operator--(int) my_noexcept
	{
		return (vector_iterator(current++));
	}

	reference operator[](difference_type n) const my_noexcept
	{
		return current[n];
	}

	vector_iterator& operator+=(difference_type n) my_noexcept
    {
        current += n;
		return *this;
    }

	vector_iterator operator+(difference_type n) const my_noexcept
    {
        return vector_iterator(current + n);
    }

	vector_iterator& operator-=(difference_type n) my_noexcept
	{
		current -= n;
		return *this;
	}

	vector_iterator operator-(difference_type n) const my_noexcept
	{
		return vector_iterator(current - n);
	}

	const Iterator& base() const my_noexcept
	{
		return current;
	}
};

}