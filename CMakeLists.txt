cmake_minimum_required(VERSION 3.10)

# Set the project name
project(vector_tests)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)

# Add the include directories
include_directories(${PROJECT_SOURCE_DIR}/ft_container)

# Add the test executable
add_executable(vector_tests test/vector_tests.cpp)

# Link the test executable with Google Test and your custom vector library
target_link_libraries(vector_tests gtest gtest_main pthread)

# Add the directory containing the vector header to the include directories
target_include_directories(vector_tests PUBLIC ${PROJECT_SOURCE_DIR}/ft_container)
