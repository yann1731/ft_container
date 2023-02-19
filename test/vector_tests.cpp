#include "../vector.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

// vector()
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

// explicit vector( const Allocator& alloc )
TEST(VectorConstructors, AllocConstructor) {
  {  // constructor
    std::allocator<int> alloc;
    ft::vector<int>     v(alloc);
    EXPECT_EQ(v.size(), 0);
  }
  {  // template
    ft::vector<int, std::allocator<int>> v;
    EXPECT_EQ(v.size(), 0);
  }
}

// explicit vector( size_type count, const T& value = T(),
//                  const Allocator& alloc = Allocator())
TEST(VectorConstructors, SizeConstructor) {
  {  // size only - zero
    ft::vector<int> v(0, 1);
    EXPECT_EQ(v.size(), 0);
  }
  {  // size only - small
    ft::vector<int> v(10);
    EXPECT_GE(v.capacity(), 10);
  }
  {  // size only - large
    ft::vector<int> v(1234567);
    EXPECT_GE(v.capacity(), 1234567);
  }
  {  // size only - too large
     // TODO check if std::vector throws
    const std::vector<int>::size_type max_size = ft::vector<int>().max_size();
    EXPECT_THROW(ft::vector<int> v(max_size + 1), std::length_error);
  }
  {  // size and count - small
    ft::vector<int> v(10, 4);
    EXPECT_GE(v.capacity(), 10);
  }
  {
    ft::vector<int> v(1234567, 69);
    EXPECT_EQ(v.size(), 1234567);
    EXPECT_GE(v.capacity(), 1234567);
  }
  {  // size, count, and alloc - small
    std::allocator<int> alloc;
    ft::vector<int>     v(10, 4, alloc);
    EXPECT_GE(v.capacity(), 10);
  }
}

// template< class InputIt >
// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator())
TEST(VectorConstructors, RangeConstructor) {
  {
    std::allocator<int> alloc;
    ft::vector<int>     v1(10, 3);
    ft::vector<int>     v2(v1.begin(), v1.end());
    ft::vector<int>     v3(v1.begin(), v1.end(), alloc);

    EXPECT_LE(v1.size(), v2.size());
    EXPECT_LE(v1.size(), v3.size());
  }
}

// vector( const vector& other )
TEST(VectorConstructors, CopyConstructor) {
  {
    ft::vector<int> v1;
    ft::vector<int> v2(v1);
    EXPECT_EQ(v1.size(), v2.size());
  }
  {
    ft::vector<int> v1(100);
    ft::vector<int> v2(v1);
    EXPECT_EQ(v1.size(), v2.size());
  }
  // TODO check for deep/shallow copies
  // TODO check for std::containers compatibility
  // TODO check for input_iterator compatibility
}

// vector& operator=( const vector& other )
TEST(VectorAssignment, CopyAssignment) {
  {
    ft::vector<int> v1;
    ft::vector<int> v2 = v1;
    EXPECT_EQ(v1.size(), v2.size());
  }
  {
    ft::vector<int> v1(100, 69);
    ft::vector<int> v2 = v1;
    EXPECT_EQ(v1.size(), v2.size());
  }
}

// void assign( size_type count, const T& value )
TEST(VectorAssignment, Assign) {
  {
    ft::vector<int> v(10, 100);
    v.assign(100, 69);
    EXPECT_GE(v.size(), 100);
  }
  // TODO check with other <data-types>
}

// template< class InputIt >
// void assign( InputIt first, InputIt last )
TEST(VectorAssignment, AssignRange) {
  {
    ft::vector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    ft::vector<int> v2;
    v2.assign(v1.begin(), v1.end());

    EXPECT_EQ(v1, v2);
  }
  // TODO check with other <data-types>
}

// allocator_type get_allocator() const
TEST(VectorGetAllocator, GetAllocator) {
  {
    ft::vector<int> v;
    EXPECT_NO_THROW(v.get_allocator());
    // TODO get_allocator() is noexcept - need better test
  }
}

// reference at( size_type pos )
TEST(VectorElementAccess, At) {
  {
    ft::vector<int> v;
    v.push_back(0);
    v.push_back(1);

    EXPECT_EQ(v.at(0), 0);
    EXPECT_EQ(v.at(1), 1);
    EXPECT_THROW(v.at(2), std::out_of_range);
    EXPECT_THROW(v.at(100), std::out_of_range);
  }
}

// reference operator[]( size_type pos )
TEST(VectorElementAccess, AtOperator) {
  {
    ft::vector<int> v(10);
    v[1] = 1;

    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
  }
}

// reference front()
TEST(VectorElementAccess, Front) {
  {
    ft::vector<int> v(10, 3);
    v[0] = 1;
    EXPECT_EQ(v.front(), 1);
  }
}

// reference back()
TEST(VectorElementAccess, Back) {
  {
    ft::vector<int> v(10, 2);
    EXPECT_EQ(v.back(), 2);
  }
}

// T* data()
TEST(VectorElementAccess, Data) {
  {
    ft::vector<int> v(10, 3);
    EXPECT_EQ(*v.data(), 3);
  }
}

// iterator begin()
TEST(VectorIterator, Begin) {
  {
    ft::vector<int> v(10);
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;

    EXPECT_EQ(*(v.begin()), 0);
    EXPECT_EQ(*(v.begin() + 1), 1);
    EXPECT_EQ(*(v.begin() + 2), 2);
    EXPECT_EQ(*(v.begin() + 3), 3);
  }
}

// iterator end()
TEST(VectorIterator, End) {
  {
    std::vector<int> v;
    std::vector<int>::iterator begin = v.begin() + 1;
    std::vector<int>::iterator end = v.end();
    EXPECT_EQ(begin, end);
  }
  {
    std::vector<int> v(3);
    std::vector<int>::iterator begin = v.begin() + 4;
    std::vector<int>::iterator end = v.end();
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    EXPECT_EQ(begin, end);
  }
}

// reverse_iterator rbegin()
TEST(VectorIterator, RBegin) {
  {
    ft::vector<int> v;
    EXPECT_EQ(v.rbegin() + 1, v.rend());
  }
  {
    ft::vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    EXPECT_EQ(v.rbegin() + 4, v.rend());
  }
}

// reverse_iterator rend()
TEST(VectorIterator, REnd) {
  {
    ft::vector<int> v;
    EXPECT_EQ(v.rbegin() + 1, v.rend());
  }
  {
    ft::vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    EXPECT_EQ(v.rbegin() + 4, v.rend());
  }
}

// bool empty() const
TEST(VectorCapacity, Empty) {
  {
    ft::vector<int> v;
    EXPECT_TRUE(v.empty());

    v.push_back(1);
    v.pop_back();
    EXPECT_TRUE(v.empty());
  }
}

// size_type size() const
TEST(VectorCapacity, Size) {
  {
    ft::vector<int> v(100, 1);
    EXPECT_GE(v.size(), 100);

    v.push_back(3);
    EXPECT_GE(v.size(), 101);
  }
}

// size_type max_size() const
TEST(VectorCapacity, MaxSize) {
  {
    ft::vector<int>  v1;
    std::vector<int> v2;
    EXPECT_EQ(v1.max_size(), v2.max_size());
  }
}

// void reserve( size_type new_cap )
TEST(VectorCapacity, Reserve) {
  {
    ft::vector<int> v;
    v.reserve(69);
    EXPECT_EQ(v.capacity(), 69);

    v.reserve(1);
    EXPECT_EQ(v.capacity(), 69);
  }
  {
    ft::vector<int>                  v;
    const ft::vector<int>::size_type max_size = v.max_size();
    EXPECT_THROW(v.reserve(max_size + 1), std::length_error);
  }
}

// size_type capacity() const
TEST(VectorCapacity, Capacity) {
  {
    ft::vector<int> v(10);
    EXPECT_GE(v.capacity(), 10);

    v.reserve(69);
    EXPECT_EQ(v.capacity(), 69);
  }
}

// void clear()
TEST(VectorModifiers, Clear) {
  {
    ft::vector<int> v(10, 3);
    v.clear();
    EXPECT_EQ(v.size(), 0);
  }
}

// iterator insert( const_iterator pos, const T& value )
// TEST(VectorModifiers, Insert) {
//   {  // TODO check if insert throws when at max size
//     ft::vector<int> v(10, 3);
//     v.insert(v.begin(), 1);
//     EXPECT_EQ(v.front(), 1);
//   }
// }

// iterator insert( const_iterator pos, size_type count, const T& value )
// TEST(VectorModifiers, InsertCount) {
//   {  // TODO check if insert throws when at max size
//     ft::vector<int> v(10, 3);
//     v.insert(v.begin(), 5, 1);
//     EXPECT_GE(v.size(), 15);

//     EXPECT_EQ(v[0], 1);
//     EXPECT_EQ(v[4], 1);
//     EXPECT_NE(v[6], 1);
//   }
// }

// template< class InputIt >
// iterator insert( const_iterator pos, InputIt first, InputIt last );
// TEST(VectorModifiers, InsertRange) {
//   {  // TODO check if insert throws when at max size
//     ft::vector<int> v1(10, 3);
//     ft::vector<int> v2(10, 1);
//     v1.insert(v1.begin(), v2.begin(), v2.end());

//     EXPECT_GE(v1.size(), 20);
//     EXPECT_EQ(v1[0], 1);
//     EXPECT_EQ(v1[9], 1);
//   }
// }

// iterator erase( iterator pos )
TEST(VectorModifiers, Erase) {
  {
    ft::vector<int> v(1, 0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.erase(v.begin());

    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
  }
}

// iterator erase( iterator first, iterator last )
TEST(VectorModifiers, EraseRange) {
  {
    ft::vector<int> v(10, 3);
    v.erase(v.begin(), v.end());
    EXPECT_EQ(v.size(), 0);
  }
}

// void push_back( const T& value )
TEST(VectorModifiers, PushBack) {
  {  // int - simple
    ft::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 1);
    EXPECT_EQ(v[2], 2);
  }
  {  // int - 1000 pushes
    ft::vector<int> v;
    EXPECT_NO_THROW(for (ft::vector<int>::size_type i = 0; i < 1000;
                         ++i) { v.push_back(3); });
  }
}

// void pop_back()
TEST(VectorModifiers, PopBack) {
  {
    ft::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.pop_back();

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.back(), 1);
  }
}

TEST(VectorModifiers, SimpleResize) {
  {
    ft::vector<int> v(10, 3);
    v.resize(3);
    EXPECT_EQ(v.size(), 3);
  }
}

// void resize( size_type count )
TEST(VectorModifiers, Resize) {
  {
    const ft::vector<int>::size_type max_size = ft::vector<int>().max_size();
    ft::vector<int>                  v;
    EXPECT_THROW(v.resize(max_size + 1), std::length_error);
  }
}

// void resize( size_type count, T value = T() )
TEST(VectorModifiers, ResizeSet) {
  {
    ft::vector<int> v(10, 3);
    v.resize(3, 10);

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 3);
    EXPECT_EQ(v[1], 3);
    EXPECT_EQ(v[2], 3);
  }
  {
    const ft::vector<int>::size_type max_size = ft::vector<int>().max_size();
    ft::vector<int>                  v;
    EXPECT_THROW(v.resize(max_size + 1, 3), std::length_error);
  }
}

// void swap( vector& other )
// TEST(VectorModifiers, Swap) {
//   {
//     ft::vector<int> v1(5, 20);
//     ft::vector<int> v2(3, 10);

//     ft::vector<int>::iterator it1 = v1.begin();
//     ft::vector<int>::iterator it2 = v2.begin();

//     int &ref1 = v1.front();
//     int &ref2 = v2.front();

//     v1.swap(v2);

//     EXPECT_EQ(*it1, 20);
//     EXPECT_EQ(*it2, 10);
//     EXPECT_EQ(ref1, 20);
//     EXPECT_EQ(ref2, 10);
//     EXPECT_EQ(v1.size(), 3);
//     EXPECT_EQ(v2.size(), 5);
//     EXPECT_EQ(v1.front(), 10);
//     EXPECT_EQ(v2.front(), 20);
//   }
// }

// template< class T, class Alloc >
// bool operator==( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, Equal) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(3, 3);

    EXPECT_TRUE(v1 == v1);
    EXPECT_FALSE(v1 == v2);
  }
}

// template< class T, class Alloc >
// bool operator!=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, NotEqual) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(3, 3);

    EXPECT_FALSE(v1 != v1);
    EXPECT_TRUE(v1 != v2);
  }
}

// template< class T, class Alloc >
// bool operator<( const std::vector<T,Alloc>& lhs,
// const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, LessThan) {
  {
    std::vector<int> v1(10, 3);
    std::vector<int> v2(10, 5);
    std::vector<int> v3(3, 3);

    EXPECT_TRUE(v1 < v2);
    EXPECT_FALSE(v2 < v3);
  }
}

// template< class T, class Alloc >
// bool operator<=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, LessThanEqual) {
  {
    std::vector<int> v1(10, 3);
    std::vector<int> v2(10, 5);

    EXPECT_TRUE((v1 <= v2));
    EXPECT_FALSE((v2 <= v1));
  }
}

// template< class T, class Alloc >
// bool operator>( const std::vector<T,Alloc>& lhs,
// const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, GreaterThan) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(10, 5);
    ft::vector<int> v3(3, 3);

    EXPECT_FALSE((v1 > v2));
    EXPECT_TRUE((v2 > v3));
  }
}

// template< class T, class Alloc >
// bool operator>=( const std::vector<T,Alloc>& lhs,
//  const std::vector<T,Alloc>& rhs )
TEST(VectorNonMember, GreaterThanEqual) {
  {
    ft::vector<int> v1(10, 3);
    ft::vector<int> v2(10, 5);

    EXPECT_FALSE(v1 >= v2);
    EXPECT_TRUE(v2 >= v1);
  }
}

// template< class T, class Alloc >
// void swap( std::vector<T,Alloc>& lhs,
//  std::vector<T,Alloc>& rhs )
// TEST(VectorNonMember, Swap) {
//   {
//     ft::vector<int> v1(5, 20);
//     ft::vector<int> v2(3, 10);

//     ft::vector<int>::iterator it1 = v1.begin();
//     ft::vector<int>::iterator it2 = v2.begin();

//     int &ref1 = v1.front();
//     int &ref2 = v2.front();

//     ft::swap(v1, v2);

//     EXPECT_EQ(*it1, 20);
//     EXPECT_EQ(*it2, 10);
//     EXPECT_EQ(ref1, 20);
//     EXPECT_EQ(ref2, 10);
//     EXPECT_EQ(v1.size(), 3);
//     EXPECT_EQ(v2.size(), 5);
//     EXPECT_EQ(v1.front(), 10);
//     EXPECT_EQ(v2.front(), 20);
//   }
// }





// #include <gtest/gtest.h>
// #include <vector>
// #include "../vector.hpp"

// // Test the default constructor
// TEST(VectorTest, DefaultConstructorTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   EXPECT_EQ(v1.size(), v2.size());
// }

// // Test the allocator constructor
// TEST(VectorTest, AllocatorConstructorTest) {
//   std::allocator<int> a;
//   std::vector<int, std::allocator<int> > v1(a);
//   ft::vector<int, std::allocator<int> > v2(a);
//   EXPECT_EQ(v1.size(), v2.size());
//   EXPECT_EQ(v1.get_allocator(), v2.get_allocator());
// }

// // Test the iterator range constructor
// TEST(VectorTest, IteratorRangeConstructorTest) {
//   std::vector<int> v1(5, 10);
//   ft::vector<int> v2(v1.begin(), v1.end());
//   EXPECT_EQ(v1.size(), v2.size());
//   EXPECT_EQ(v1[2], v2[2]);
// }

// // Test the copy constructor
// TEST(VectorTest, CopyConstructorTest) {
//   std::vector<int> v1(5, 10);
//   ft::vector<int> v2(v1);
//   EXPECT_EQ(v1.size(), v2.size());
//   EXPECT_EQ(v1[2], v2[2]);
// }

// // Test the size() function
// TEST(VectorTest, SizeTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   EXPECT_EQ(v1.size(), v2.size());
// }

// // Test the max_size() function
// TEST(VectorTest, MaxSizeTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   EXPECT_EQ(v1.max_size(), v2.max_size());
// }

// // Test the empty() function
// TEST(VectorTest, EmptyTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   EXPECT_EQ(v1.empty(), v2.empty());
// }

// TEST(VectorTest, EmptyTest2) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   EXPECT_EQ(v1.empty(), v2.empty());
// }

// // Test the operator[] function
// TEST(VectorTest, SubscriptTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   EXPECT_EQ(v1[2], v2[2]);
// }

// // Test the at() function
// TEST(VectorTest, AtTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   EXPECT_EQ(v1.at(3), v2.at(3));
// }

// // Test the front() function
// TEST(VectorTest, FrontTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   EXPECT_EQ(v1.front(), v2.front());
// }

// // Test the back() function
// TEST(VectorTest, BackTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   EXPECT_EQ(v1.back(), v2.back());
// }

// // Test the data() function
// TEST(VectorTest, DataTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   const int* v1data = v1.data();
//   const int* v2data = v2.data();
//   for (size_t i = 0; i < v1.size(); i++) {
//     EXPECT_EQ(v1data[i], v2data[i]);
//   }
// }

// // Test the assign() function
// TEST(VectorTest, AssignTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   v1.assign(3, 9);
//   v2.assign(3, 9);
//   EXPECT_EQ(v1.size(), v2.size());
//   EXPECT_EQ(v1[2], v2[2]);
// }

// // Test the push_back() function
// TEST(VectorTest, PushBackTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   v1.push_back(6);
//   v2.push_back(6);
//   EXPECT_EQ(v1.size(), v2.size());
//   EXPECT_EQ(v1.back(), v2.back());
// }

// // Test the pop_back() function
// TEST(VectorTest, PopBackTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   v1.pop_back();
//   v2.pop_back();
//   EXPECT_EQ(v1.size(), v2.size());
//   EXPECT_EQ(v1.back(), v2.back());
// }

// // Test the insert() function
// // TEST_F(VectorTest, InsertTest) {
// //   std::vector<int>::iterator v1it = v1.begin() + 3;
// //   ft::vector<int>::iterator v2it = v2.begin() + 3;
// //   v1.insert(v1it, 8);
// //   v2.insert(v2it, 8);
// //   EXPECT_EQ(v1.size(), v2.size());
// //   EXPECT_EQ(v1[3], v2[3]);
// // }

// // Test the erase() function
// TEST(VectorTest, EraseTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   std::vector<int>::iterator v1it = v1.begin() + 2;
//   ft::vector<int>::iterator v2it = v2.begin() + 2;
//   v1.erase(v1it);
//   v2.erase(v2it);
//   EXPECT_EQ(v1.size(), v2.size());
//   EXPECT_EQ(v1[2], v2[2]);
// }

// // Test the swap() function
// // TEST(VectorTest, SwapTest) {
// //   std::vector<int> v1_swap;
// //   ft::vector<int> v2_swap;
// //   for (size_t i = 0; i < 3; i++)
// //     v1_swap.push_back(i);
// //   for (size_t i = 0; i < 3; i++)
// //     v2_swap.push_back(i);
// //   v1.swap(v1_swap);
// //   v2.swap(v2_swap);
// //   EXPECT_EQ(v1.size(), v2.size());
// //   EXPECT_EQ(v1[2], v2[2]);
// // }

// // Test the clear() function
// TEST(VectorTest, ClearTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   v1.clear();
//   v2.clear();
//   EXPECT_EQ(v1.size(), v2.size());
//   EXPECT_TRUE(v1.empty());
//   EXPECT_TRUE(v2.empty());
// }

// // Test the relational operators
// TEST(VectorTest, RelationalOperatorsTest) {
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   for (size_t i = 0; i < 5; i++) {
//       v1.push_back(1);
//       v2.push_back(1);
//     }
//   std::vector<int> v1_compare(5, 15);
//   std::vector<int> v1_lesser(4, 15);
//   std::vector<int> v1_greater(6, 15);
//   ft::vector<int> v2_compare(5, 15);
//   ft::vector<int> v2_lesser(4, 15);
//   ft::vector<int> v2_greater(6, 15);
//   EXPECT_TRUE(v1 == v1_compare && v2 == v2_compare);
//   EXPECT_TRUE(v1 < v1_greater && v2 < v2_greater);
//   EXPECT_TRUE(v1 > v1_lesser && v2 > v2_lesser);
//   EXPECT_TRUE(v1 != v1_lesser && v2 != v2_lesser);
//   EXPECT_TRUE(v1 >= v1_compare && v2 >= v2_compare);
//   EXPECT_TRUE(v1 <= v1_compare && v2 <= v2_compare);
// }