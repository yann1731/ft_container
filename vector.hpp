#include <memory>
namespace ft
{
    template <typename T, std::allocator<T> _allocator>
    class vector
    {
    public:
        
    private:
        T *elem;
        size_t _size;
    };
}