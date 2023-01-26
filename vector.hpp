#include <memory>
#include <iterator>
#include <vector>

namespace ft
{


template <typename T, class Allocator = std::allocator<T> >

class vector
{
protected:
	typedef T value_type;
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
		Allocator alloc;
		_elem = alloc.allocate(0);
		_size = 0;
	};

	vector (size_type n, T value)
	{
		Allocator alloc;
		_elem = alloc.allocate(n);
		for (size_t i = 0; i < n; i++)
			_elem[i] = value;
	};

	vector(const vector &otherVector)
	{
		*this = otherVector;
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

private:
	pointer _elem;
	size_type _size;
};
};