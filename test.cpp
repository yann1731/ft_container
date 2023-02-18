#include <vector>
#include <iostream>
#include "stack.hpp"
#include <stack>
#include <gtest/gtest.h>

TEST(VectorConstructors, DefaultConstructor) {
  {  // default constructor - int
    ft::vector<int> v;
    EXPECT_EQ(v.size(), 0);
  }
  {  // default constructor - string
    ft::vector<std::string> v;
    EXPECT_EQ(v.size(), 0);
  }
  {  // default constructor - ft::vector<ft::vector<int>>
    ft::vector<ft::vector<int> > v;
    EXPECT_EQ(v.size(), 0);
  }
  {  // default constructor - std::vector<ft::vector<int>>
    std::vector<ft::vector<int> > v;
    EXPECT_EQ(v.size(), 0);
  }
}