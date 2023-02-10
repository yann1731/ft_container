#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include "iterator_tags.hpp"
namespace ft
{

template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
    typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};


}

#endif