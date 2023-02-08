// #include <vector>
// #include <iostream>
// #include "stack.hpp"
// #include <stack>
// #include <gtest/gtest.h>

// using ft::stack;


// TEST(StackConstructors, Constructor) {
//   {
//     std::vector<int> v(10, 10);
//     stack<int>  s(v);
//     EXPECT_EQ(s.size(), 10);
//   }
// }

// TEST(STACK_INSTANTIATION, stack_instantiation) {
//     {
//         ft::stack  s1(10);
//         EXPECT_EQ();
//     }
// }


#include "stack.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <stack>
#include <vector>

using ft::stack;
using std::vector;  // Change to vector when it's tested

// explicit stack(const Container& cont = Container());
TEST(StackConstructors, Constructor) {
  {
    vector<int> v(10, 10);
    stack<int>  s(v);
    EXPECT_EQ(s.size(), 10);
  }
}