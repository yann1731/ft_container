#include <iostream>
#include <stack>
#include "vector.hpp"

class Whatever
{
    void amipublic(void)
    {
        std::cout << "I am public apparently. wtf" << std::endl;
    };
    public:
    Whatever();
    ~Whatever();
};

int main(void)
{
    Whatever we;

    we.amipublic();
    return 0;
}