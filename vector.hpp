#include <memory>
#include <iterator>

template <typename T, class Allocator = std::allocator<T> >

class vector
{
public:
    vector() {_elem = Allocator.allocate(0);};
    vector(const vector &otherVector){*this = otherVector;};
    ~vector(_elem Allocator.deallocate());
protected:
    
private:
    T *_elem;
    size_t _size;
};