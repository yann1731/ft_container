#include <memory>
#include <vector>

namespace ft
{
template <typename T, class _Container = std::vector<T> >
	class stack
	{
	public:
    	typedef _Container                               container_type;
    	typedef typename container_type::value_type      value_type;
    	typedef typename container_type::reference       reference;
    	typedef typename container_type::const_reference const_reference;
    	typedef typename container_type::size_type       size_type;
	protected:
		container_type c;
	public:
		stack(): c() {};
		stack(const stack &otherStack) {c = otherStack.c;};
		~stack() {};
		stack &operator=(const stack &rhs)
		{
			c = rhs.c;
			return *this;
		}

		bool empty(void) const
		{
			return c.empty();
		}

		size_t size(void) const
		{
			return c.size();
		}

		T &top(void)
		{
			return c.back();
		}

		const T &top() const
		{
			return c.back();
		}

		void push(const T &val)
		{
			c.push_back(val);
		}

		void pop(void)
		{
			c.pop_back();
		}

		template <class T1, class C1>
		friend bool operator== (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);	
		template <class T1, class C1>
		friend bool operator<  (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
	};

	template <class T, class _Container>
	bool operator==(const stack<T, _Container>& lhs, const stack<T, _Container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template <class T, class _Container>
	bool operator<(const stack<T, _Container>& lhs, const stack<T, _Container>& rhs)
	{
		return lhs.c < rhs.c;
	}

	template <class T, class _Container>
	bool operator!= (const stack<T, _Container>& lhs, const stack<T, _Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class _Container>
	bool operator<= (const stack<T, _Container>& lhs, const stack<T, _Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class _Container>
	bool operator>  (const stack<T, _Container>& lhs, const stack<T, _Container>& rhs)
	{
		return rhs < lhs;
	}

	template <class T, class _Container>
	bool operator>= (const stack<T, _Container>& lhs, const stack<T, _Container>& rhs)
	{
		return !(lhs < rhs);
	}
};