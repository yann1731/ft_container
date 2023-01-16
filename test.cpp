#include <vector>
#include <iostream>
#include "stack.hpp"

int main(void)
{
    ft::stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    ft::stack<int> st2 = st;

    std::cout << st.size() << std::endl;
    std::cout << st2.size() << std::endl;
    return 0;
}