#include <memory>
#include <vector>


// value_type	T
// allocator_type	Allocator
// size_type	Unsigned integer type (usually std::size_t)
// difference_type	Signed integer type (usually std::ptrdiff_t)
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
namespace ft
{
    template <typename T, typename _allocator = std::allocator<T> >
    class vector
    {
    public:
        
    private:
        T *elem;
        size_t _size;
    };
}