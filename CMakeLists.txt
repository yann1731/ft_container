cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")
project(ft_containers VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_MAKE_PROGRAM make)
add_compile_options(-Wall -Werror -Wextra)

find_package(GTest CONFIG REQUIRED)

add_library(
  ft_STL
  SHARED
  algorithm.hpp
  iterator.hpp
  iterator_trait.hpp
  pair.hpp
  reverse_iterator.hpp
  type_traits.hpp
  vector_iterator.hpp
  vector.hpp
)
set_target_properties(
  ft_STL
  PROPERTIES LINKER_LANGUAGE CXX
)
target_include_directories(
  ft_STL
  INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Test executables
enable_testing()

add_executable(vector_test test/vector_tests.cpp)
target_link_libraries(
  vector_test 
  PUBLIC ft_STL
  GTest::gtest_main
)
add_test(
  NAME vector_test
  COMMAND $<TARGET_FILE:vector_test>
)

add_executable(stack_test test/stack_tests.cpp)
target_link_libraries(
    stack_test
    PUBLIC ft_STL
    GTest::gtest_main
)
add_test(
    NAME stack_test
    COMMAND $<TARGET_FILE:stack_test>
)



# cmake_minimum_required(VERSION 3.10)

# # Set the project name
# project(vector_tests)

# # Set the C++ standard to use
# set(CMAKE_CXX_STANDARD 11)

# # Add the include directories
# include_directories(${PROJECT_SOURCE_DIR}/ft_container)

# # Add the test executable
# add_executable(vector_tests test/vector_tests.cpp)

# # Link the test executable with Google Test and your custom vector library
# target_link_libraries(vector_tests gtest gtest_main pthread)

# # Add the directory containing the vector header to the include directories
# target_include_directories(vector_tests PUBLIC ${PROJECT_SOURCE_DIR}/ft_container)
