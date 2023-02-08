#include <memory>
#include <iterator>

#define my_noexcept throw();

namespace ft
{

template <typename T, class Allocator>

struct _vector_base
{
	typedef typename __gnu_cxx::__alloc_traits<Allocator>template rebind<T>::other T_Alloc_Type;
	typedef typename __gnu_cxx::__alloc_traits<T_Alloc_Type>::pointer pointer;

	struct vec_impl_data
	{
		pointer _start;
		pointer _finish;
		pointer _end;

		vec_impl_data: _start(), _finish(), _end() {};

		void copy_data (const vec_impl_data& other)
		{
			_start = other._start;
			_finish = other._finish;
			_end = other._end;
		}

		void swap_data (vec_impl_data &other)
		{
			vec_impl_data tmp;
			tmp.copy_data(*this);
			copy_data(other);
			other.copy_data(tmp);
		}
	};

	struct vec_impl: public T_Alloc_type, public vec_impl_data
	{
		
	}
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

	pointer begin_;
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
		return (iterator(begin_));
	};

	iterator end(void)
	{
		return (iterator(end_));
	};
};
};