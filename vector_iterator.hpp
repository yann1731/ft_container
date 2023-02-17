#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
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

	vector_iterator() my_noexcept: current(Iterator()) {}

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

template <typename IteratorL, typename IteratorR, typename Container>
	inline bool operator==(const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) my_noexcept
	{
		return lhs.base() == rhs.base();
	}

template <typename Iterator, typename Container>
	inline bool operator==(const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) my_noexcept
	{
		return rhs.base() == lhs.base();
	}

template <typename IteratorL, typename IteratorR, typename Container>
	inline bool operator!=(const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) my_noexcept
	{
		return lhs.base() != rhs.base();
	}

template <typename Iterator, typename Container>
	inline bool operator!=(const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) my_noexcept
	{
		return rhs.base() != lhs.base();
	}

template <typename IteratorL, typename IteratorR, typename Container>
	inline bool operator<(const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) my_noexcept
	{
		return lhs.base() < rhs.base();
	}

template <typename Iterator, typename Container>
	inline bool operator<(const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) my_noexcept
	{
		return rhs.base() < lhs.base();
	}

template <typename IteratorL, typename IteratorR, typename Container>
	inline bool operator>(const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) my_noexcept
	{
		return lhs.base() > rhs.base();
	}

template <typename Iterator, typename Container>
	inline bool operator>(const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) my_noexcept
	{
		return rhs.base() > lhs.base();
	}

template <typename IteratorL, typename IteratorR, typename Container>
	inline bool operator<=(const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) my_noexcept
	{
		return lhs.base() <= rhs.base();
	}

template <typename Iterator, typename Container>
	inline bool operator<=(const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) my_noexcept
	{
		return rhs.base() <= lhs.base();
	}

template <typename IteratorL, typename IteratorR, typename Container>
	inline bool operator>=(const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs) my_noexcept
	{
		return lhs.base() >= rhs.base();
	}

template <typename Iterator, typename Container>
	inline bool operator>=(const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) my_noexcept
	{
		return rhs.base() >= lhs.base();
	}

template<typename IteratorL, typename IteratorR, typename Container>
    inline typename vector_iterator<IteratorL, Container>::difference_type operator-(const vector_iterator<IteratorL, Container>& lhs, const vector_iterator<IteratorR, Container>& rhs)
    {
      return lhs.base() - rhs.base();
    }

template<typename Iterator, typename Container>
    inline typename vector_iterator<Iterator, Container>::difference_type operator-(const vector_iterator<Iterator, Container>& lhs, const vector_iterator<Iterator, Container>& rhs) my_noexcept
    {
      return lhs.base() - rhs.base();
    }

template<typename Iterator, typename Container>
    inline vector_iterator<Iterator, Container> operator+(typename vector_iterator<Iterator, Container>::difference_type __n, const vector_iterator<Iterator, Container>& __i) my_noexcept
    {
      return vector_iterator<Iterator, Container>(__i.base() + __n);
    }
}

#endif