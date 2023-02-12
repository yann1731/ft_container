#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator.hpp"

namespace ft
{
template <typename Iterator>
    class reverse_iterator: public iterator<typename iterator_traits<Iterator>::iterator_category, typename iterator_traits<Iterator>::value_type, typename iterator_traits<Iterator>::difference_type, typename iterator_traits<Iterator>::pointer, typename iterator_traits<Iterator>::reference>
    {
    template<typename Iter>
        friend class reverse_iterator;
    
    protected:
        Iterator current;
        typedef iterator_traits<Iterator>               traits_type;

    public:
        typedef Iterator iterator_type;
        typedef typename traits_type::pointer           pointer;
        typedef typename traits_type::difference_type   difference_type;
        typedef typename traits_type::reference         reference;

    reverse_iterator(): current() { }

    explicit reverse_iterator(iterator_type x): current(x) { };
    
    reverse_iterator(const reverse_iterator& x): current(x.current) { }

    template<typename Iter>
        reverse_iterator(const reverse_iterator<Iter>& x): current(x.current) { }
    
        iterator_type base() const
        {
            return current;
        }

        reference operator*() const
        {
            Iterator tmp = current;
            return *--tmp;
        }

        pointer operator->() const
        {
            Iterator tmp = current;
            --tmp;
            return S_to_pointer(tmp);
        }

        reverse_iterator& operator++()
        {
            --current;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --current;
            return tmp;
        }

        reverse_iterator& operator--()
        {
            ++current;
            return *this;
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++current;
            return tmp;
        }

        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(current - n);
        }

        reverse_iterator& operator+=(difference_type n)
        {
            current -= n;
            return *this;
        }

        reverse_iterator operator-(difference_type n)
        {
            return reverse_iterator(current + n);
        }

        reverse_iterator& operator-=(difference_type n)
        {
            current += n;
            return *this;
        }

        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }

    private:
        template<typename T>
            static T* S_to_pointer(T* _p)
            {
                return _p;
            }

        template <typename T>
            static pointer S_to_pointer(T _t)
            {
                return _t.operator->();
            }
    };

template<typename Iterator>
    inline bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() == rhs.base();
    }

template<typename Iterator>
    inline bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return !(lhs == rhs);
    }

template<typename Iterator>
    inline bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return rhs.base < lhs.base();
    }

template<typename Iterator>
    inline bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return !(rhs < lhs);
    }

template<typename Iterator>
    inline bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return rhs < lhs;
    }

template<typename Iterator>
    inline bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return !(lhs < rhs);
    }

template<typename IteratorL, typename IteratorR>
    inline bool operator==(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    {
        return lhs.base() == rhs.base();
    }

template<typename IteratorL, typename IteratorR>
    inline bool operator!=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    {
        return lhs.base() != rhs.base();
    }

template<typename IteratorL, typename IteratorR>
    inline bool operator<(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    {
        return lhs.base() < rhs.base();
    }

template<typename IteratorL, typename IteratorR>
    inline bool operator<=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    {
        return lhs.base() <= rhs.base();
    }

template<typename IteratorL, typename IteratorR>
    inline bool operator>(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    {
        return lhs.base() > rhs.base();
    }

template<typename IteratorL, typename IteratorR>
    inline bool operator>=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    {
        return lhs.base() >= rhs.base();
    }

template<typename Iterator>
    inline typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return rhs.base() - lhs.base();
    }

template<typename IteratorL, typename IteratorR>
    inline typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
    {
        return rhs.base() - lhs.base();
    }

template<typename Iterator>
    inline reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
    {
        return reverse_iterator<Iterator>(x.base() - n);
    }
}

#endif