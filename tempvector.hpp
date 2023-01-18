<typename T, class Allocator>
class _base_vector
{
public:
    using allocator_type = Allocator;
    using _alloc_traits = allocator_traits<allocator_type>;
    using size_type = typename _alloc_traits::size_type;
protected:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;;
    using difference_type = typename __alloc_traits::difference_type;
    using pointer = typename __alloc_traits::pointer;
    using const_pointer = typename __alloc_traits::const_pointer;
    using iterator = pointer;
    using const_iterator = const_pointer;
private:
};


// reference	value_type&
// const_reference	const value_type&
// pointer	 
// Allocator::pointer	(until C++11)
// std::allocator_traits<Allocator>::pointer	(since C++11)
 
// const_pointer	 
// Allocator::const_pointer	(until C++11)
// std::allocator_traits<Allocator>::const_pointer	(since C++11)
 
// iterator	 
// LegacyRandomAccessIterator and LegacyContiguousIterator to value_type

// (until C++20)
// LegacyRandomAccessIterator, contiguous_iterator, and ConstexprIterator to value_type

// (since C++20)
 
// const_iterator	 
// LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type

// (until C++20)
// LegacyRandomAccessIterator, contiguous_iterator, and ConstexprIterator to const value_type

// (since C++20)
 
// reverse_iterator	std::reverse_iterator<iterator>
// const_reverse_iterator	std::reverse_iterator<const_iterator>
using std::size_t;
using std::ptrdiff_t;
namespace ft
{
    template <typename T, typename Allocator = std::allocator<T> >
    class vector: protected _vector_base<T, Allocator>
    {
    public:
        typedef Allocator               				allocator_type;
        typedef size_t                  				size_type;
        typedef T                       				value_type;
        typedef ptrdiff_t 								difference_type;
        typedef value_type& 							reference;
        typedef const value_type&						const_reference;
        typedef Allocator::pointer						pointer;
        typedef Allocator::const_pointer				const_pointer;
        typedef value_type* 							iterator;
        typedef const value_type*						const_iterator;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
    protected:
        vector()
    private:
        using _Base = _vector_base<_Tp, _Alloc>;
        using _Tp_alloc_type =  typename _Base::_Tp_alloc_type;
        using _Alloc_traits = __gnu_cxx::__alloc_traits<_Tp_alloc_type>;
        
        T *elem;
        size_t _size;
    };
}