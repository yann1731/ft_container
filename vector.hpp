#include <memory>
#include <iterator>

#define my_noexcept throw();

namespace ft
{

template <typename T, class Allocator>

struct _vector_base
{
	typedef Allocator                               allocator_type;
    typedef allocator_traits<allocator_type>         __alloc_traits;
    typedef typename __alloc_traits::size_type       size_type;

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
		vec_impl(): T_Alloc_Type(){}

		vec_impl(_Tp_alloc_type const& a) my_noexcept: T_Alloc_Type(a){}
	}
	
	T_Alloc_Type& _M_get_T_Allocator() my_noexcept
	{
		return this->mImpl;
	}

	const T_Alloc_Type& _M_get_Allocator() const my_noexcept
	{
		return this->mImpl;
	}

	Allocator get_allocator() const my_noexcept
	{
		return Allocator(_M_get_T_Allocator());
	}

	_vector_base() {};
	_vector_base(const Allocator& alloc): mImpl(alloc){};
	_vector_base(size_t n): mImpl()
	{
		create_storage(n);
	}
	_vector_base(size_t, const Allocator& alloc): mImpl()
	{
		create_storage(n);
	}
	~_vector_base()
	{
		deallocate(mImpl._start, mImpl._end - mImpl._start);
	}

	vec_impl mImpl;

	pointer allocate(size_t n)
	{
		typedef __gnu_cxx::__alloc_traits<T_Alloc_Type> _Tr;
		return (n != 0 ? _Tr::allocate(mImpl, n) : pointer());
	}

	void deallocate(pointer p, size_t n)
	{
		typedef __gnu_cxx::__alloc_traits<T_Alloc_Type> _Tr;
		if (p)
	  		_Tr::deallocate(mImpl, p, n);
	}
protected:
	void create_storage(size_t n)
	{
		this->mImpl._start = this->allocate(n);
		this->mImpl._finish = this->mImpl._start;
		this->mImpl._end = this->mImpl._finish + n;
	}
};

template <typename T, class Allocator = std::allocator<T> >

class vector: protected _vector_base
{
	typedef _vector_base<T, Allocator>					_Base;
	typedef _Base::T_Alloc_Type							T_Alloc_Type;
	typedef __gnu_cxx::__alloc_traits<T_Alloc_Type>		_Alloc_traits;

protected:
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