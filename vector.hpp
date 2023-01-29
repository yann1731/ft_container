#include <memory>
#include <iterator>
#include <vector>

#define my_noexcept throw();

namespace ft
{

template <typename T, class Allocator = std::allocator<T> >

class vector
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
	typedef value_type* iterator;
	typedef const value_type* const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

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
		Allocator alloc;
		alloc.deallocate(_elem, _size);
	};

	const vector<value_type> &operator=(const vector<value_type> &otherVector)
	{
		this->_elem = otherVector._elem;
		this->_size = otherVector._size;
	};

	iterator begin(void)
	{
		return this->_elem[0];
	};

	iterator end(void)
	{
		return this->_elem[_size];
	};
};
};