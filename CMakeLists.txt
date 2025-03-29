# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Add FetchContent module
include(FetchContent)

# Fetch Crow library
FetchContent_Declare(
    crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
    GIT_TAG v1.2.1  # 使用 Crow 的特定版本
)

FetchContent_MakeAvailable(crow)

# Find Boost
find_package(Boost 1.64 REQUIRED COMPONENTS system date_time)
include_directories(${Boost_INCLUDE_DIRS})

# Add source files
add_executable(main src/main.cpp src/statement.cpp src/view.cpp)

# Include Crow
target_include_directories(main PRIVATE ${crow_SOURCE_DIR}/include)

# Link Boost and Crow dependencies
target_link_libraries(main PRIVATE ${Boost_LIBRARIES} pthread)

# Add Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add additional include directory
include_directories(/usr/local/include)
include_directories(/opt/homebrew/Cellar/asio/1.30.2/include)

# Add test executable
add_executable(test_main tests/test_main.cpp src/statement.cpp src/view.cpp)
target_link_libraries(test_main PRIVATE ${Boost_LIBRARIES} ${GTEST_LIBRARIES} pthread)

# Add test
add_test(NAME HelloWorldTest COMMAND test_main)