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
	private:
		std::vector<T> container;
		size_t _size;
	};
}