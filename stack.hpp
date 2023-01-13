#include <memory>
#include <vector>

namespace ft
{
template <typename T>
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
	private:
		std::vector<T> container;
		size_t _size;
	};

	template <typename T>
	stack<T>::stack()
	{

	}

	template <typename T>
	stack<T>::stack(const ft::stack<T> &otherStack)
	{
		this->container = otherStack.container;
	}

	template <typename T>
	stack<T>::~stack()
	{
		
	}
	
	template <typename T>
	bool stack<T>::empty(void) const
	{

	}

	template <typename T>
	size_t stack<T>::size(void) const
	{

	}

	template <typename T>
	T &stack<T>::top(void)
	{

	}

	template <typename T>
	const T &stack<T>::top(void) const
	{

	}

	template <typename T>
	void stack<T>::push(const T &val)
	{

	}

	template <typename T>
	template <class... Args> void stack<T>::emplace (Args&&... args)
	{

	}

	template <typename T>
	void stack<T>::pop(void)
	{

	}

	template <typename T>
	void stack<T>::swap(stack &x) noexcept
	{

	}
}