#include <memory>
#include <vector>

namespace ft
{
template <typename T>
	class stack
	{
	public:
		stack();
		stack(const ft::stack<T> &otherStack);
		~stack();
		bool empty(void) const;
		size_t size(void) const;
		T &top(void);
		const T &top() const;
		void push(const T& val);
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
}