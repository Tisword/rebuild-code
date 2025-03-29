# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Add source files
add_executable(main src/main.cpp src/statement.cpp src/view.cpp)

# Add Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(test_main tests/test_main.cpp src/statement.cpp src/view.cpp)
target_link_libraries(test_main ${GTEST_LIBRARIES} pthread)

# Add test
add_test(NAME HelloWorldTest COMMAND test_main)