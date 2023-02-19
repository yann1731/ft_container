#include "vector.hpp"
#include <vector>


using std::cout;
using std::endl;

int main(void) {

    std::vector<int> v1;
    ft::vector<int> v2;

    // Initialize the variables before each test
    for (size_t i = 0; i < 5; i++) {
      v1.push_back(i);
      v2.push_back(i);
    }

    cout << v1.size() << endl;
    cout << v2.size() << endl;

    return 0;
}