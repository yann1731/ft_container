//#include <iostream>
#include "vector.hpp"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{

    std::vector<int> vec(2, 10);
    std::vector<int> vec2(5, 20);

    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    //vec.assign(10, 100);
    // vec.assign(12, 2);
    // vec.push_back(1);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " " << endl;

    cout << endl;

    vec2.erase(vec.begin(), vec.end());
    // vec.erase(vec.begin());
    //vec.erase(vec.end());
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " " << endl;

    for (int i = 0; i < vec2.size(); i++)
        cout << vec2[i] << " " << endl;

    // cout << "size: " << vec.size() << endl;
    // cout << "capacity: " << vec.capacity() << endl;
    // cout << "size: " << vec2.size() << endl;
    // cout << "capacity: " << vec2.capacity() << endl;

    return 0;
}