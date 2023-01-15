#include <memory>
#include <vector>

namespace ft
{
template <typename T, class container = std::vector<T> >
	class stack
	{
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
		template <class T, class Container>  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);	
		template <class T, class Container>  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class T, class Container>  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class T, class Container>  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class T, class Container>  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		template <class T, class Container>  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	protected:
		container<T> _container;
		size_t _size;
	};

	template <typename T, class container>
	stack<T, container>::stack()
	{

	}

	template <typename T, class container>
	stack<T, container>::stack(const ft::stack<T> &otherStack)
	{
		this->container = otherStack.container;
	}

	template <typename T, class container>
	stack<T, container>::~stack()
	{
		
	}
	
	template <typename T, class container>
	bool stack<T, container>::empty(void) const
	{

	}

	template <typename T, class container>
	size_t stack<T, container>::size(void) const
	{

	}

	template <typename T, class container>
	T &stack<T, container>::top(void)
	{

	}

	template <typename T, class container>
	const T &stack<T, container>::top(void) const
	{

	}

	template <typename T, class container>
	void stack<T, container>::push(const T &val)
	{

	}

	template <typename T, class container>
	template <class... Args> void stack<T, container>::emplace (Args&&... args)
	{

	}

	template <typename T, class container>
	void stack<T, container>::pop(void)
	{

	}

	template <typename T, class container>
	void stack<T, container>::swap(stack &x)
	{

	}
}