#ifndef ITERATOR_TRAIT_HPP
#define ITERATOR_TRAIT_HPP

#include "iterator_tags.hpp"
namespace ft
{

template<typename Iter>
    struct iterator_traits;

template <class Iter>
struct iterator_traits
{
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::value_type value_type;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
	typedef typename Iter::iterator_category iterator_category;
};

template <class T>
struct iterator_traits<T*>
{
	typedef ft::random_access_iterator_tag	iterator_category;
    typedef T                         		value_type;
    typedef ptrdiff_t                   	difference_type;
    typedef T*                        		pointer;
    typedef T&                        		reference;
};

template <class T>
struct iterator_traits<const T*>
{
	typedef ft::random_access_iterator_tag	iterator_category;
    typedef T                         		value_type;
    typedef ptrdiff_t                   	difference_type;
    typedef T*                        		pointer;
    typedef T&                        		reference;
};	


}

#endif