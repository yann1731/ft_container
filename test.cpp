#include <vector>
#include <iostream>
#include "stack.hpp"
#include <stack>
#include <gtest/gtest.h>

TEST(StackConstructors, Constructor) {
  {
    std::vector<int> v(10, 10);
    ft::stack<int>  s(v);
    EXPECT_EQ(s.size(), 10);
  }
}