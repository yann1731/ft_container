#include <memory>
#include <iterator>
#include <vector>

#define my_noexcept throw();

namespace ft
{

template <typename T, class Allocator>

class _vector_base
{
public:
    typedef Allocator                              	 allocator_type;
    typedef std::allocator_traits<allocator_type>    __alloc_traits;
    typedef typename __alloc_traits::size_type       size_type;
protected:
    typedef T                                     	 value_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    typedef typename __alloc_traits::difference_type difference_type;
    typedef typename __alloc_traits::pointer         pointer;
    typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef pointer                                  iterator;
    typedef const_pointer                            const_iterator;

};

template <typename T, class Allocator = std::allocator<T> >

class vector: public _vector_base
{
protected:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef typename std::allocator_traits<Allocator>::pointer pointer;
	typedef typename std::allocator_traits<Allocator>::const_pointer const_pointer;
	typedef std::iterator<std::random_access_iterator_tag, value_type, difference_type, value_type*, value_type&> iterator;
	typedef const std::iterator<std::random_access_iterator_tag, const value_type, difference_type, const value_type*, const value_type&> const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	pointer start_;
	pointer end_;
	pointer last_;

public:
	vector()
	{

	};

	
	explicit vector(const Allocator& alloc)
	{
		
	};

	explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
	{
		
	};

	~vector()
	{
		
	};

	const vector<value_type> &operator=(const vector<value_type> &otherVector)
	{
	
	};

	iterator begin(void)
	{
	
	};

	iterator end(void)
	{
	
	};
};
};