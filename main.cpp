//#include <iostream>
#include "vector.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{

    ft::vector<int> v1(10, 3);
    std::vector<int> v2(10, 5);

    //cout << v1.size() << endl;
    v1.reserve(20);

    // v1.insert(v1.end(), 20);
    v1.insert(v1.begin(), 5, 30);
    // v1.insert(v1.begin(), 30);
    // v1.insert(v1.begin(), 30);
    // v1.insert(v1.begin(), 30);
    // v1.insert(v1.begin(), 30);

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << endl;

    cout << v1.size() << endl;

    return 0;
}