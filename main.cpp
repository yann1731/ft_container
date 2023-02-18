//#include <iostream>
#include "vector.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{

    std::vector<int> vec(5, 10);

    cout << "capacity: " << vec.capacity() << endl;
    vec.assign(10, 100);
    // vec.assign(12, 2);
    // vec.push_back(1);
    cout << "size: " << vec.size() << endl;
    // vec.erase(vec.begin());
    //vec.erase(vec.end());
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;

    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;


    return 0;
}