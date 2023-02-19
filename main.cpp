//#include <iostream>
#include "vector.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{

    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(10, 5);

    cout << (v1 <= v2) << endl;
    cout << (v2 <= v1) << endl;

    return 0;
}