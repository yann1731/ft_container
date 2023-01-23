#include <vector>
#include <iostream>
#include "stack.hpp"
#include <stack>
#include <iterator>
#include <algorithm>
#include <memory>

int main(void)
{
    ft::stack<int> st;
    ft::stack<int> st3;

    st.push(1);
    st.push(2);
    st.push(3);

    ft::stack<int> st2 = st;

    std::cout << st.size() << std::endl;
    std::cout << st2.size() << std::endl;

    std::cout << (st == st2) << std::endl;
    std::cout << (st == st3) << std::endl;
    return 0;
}