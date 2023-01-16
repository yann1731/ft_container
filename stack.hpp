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
		stack<T>();
		stack<T>(const ft::stack<T> &otherStack);
		~stack();
		bool empty(void) const;
		size_t size(void) const;
		T &top(void);
		const T &top() const;
		void push(const T &val);
		template <class... Args> void emplace (Args&&... args);
		void pop(void);
		void swap(stack &x) noexcept;

	stack()
	{

	}

	stack(const ft::stack<T> &otherStack)
	{
		this->c = otherStack.c;
	}

	~stack()
	{
		c.clear();
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

	const T &top(void) const
	{
		return c.back();
	}

	void push(const T &val)
	{
		c.push_back(val);
	}

	template <class... Args>
	template <class... Args> emplace (Args&&... args)
	{
		return (c.emplace_back(std::forward<Args>(args)...);
	}

	void pop(void)
	{
		c.pop_back();
	}

	void swap(stack &x)
	{
		std::swap(c, x.c);
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
		return !(rhs < lhs)
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