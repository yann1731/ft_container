#include <memory>
#include <iterator>
#include <vector>

template <typename T, class Allocator = std::allocator<T> >

class vector
{
public:
	vector()
	{
		_elem = Allocator.allocate(0);
		_size = 0;
	};

	vector (size_type n, T value)
	{
		_elem = Allocator.allocate(n);
		for (size_t i = 0; i < n; i++)
			_elem[i] = value;
	};

	vector(const vector &otherVector)
	{
		*this = otherVector;
	};

	~vector()
	{
		Allocator.deallocate(_elem, _size);
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
	using value_type = T;
	using size_type = size_t;
	using difference_type = std::ptrdiff_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = std::allocator_traits<Allocator>::pointer;
	using const_pointer = std::allocator_traits<Allocator>::const_pointer;
	using iterator = value_type*;
	using const_iterator = const value_type*;
	using reverse_iterator = std::reverse_iterator<iterator>
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;
};