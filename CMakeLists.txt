cmake_minimum_required(VERSION 3.10)
project(CartPendulumSimulator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Find Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
# Add executable
add_executable(CartPendulumSimulator
    cart_pendulum.cpp
    controller.cpp
    main.cpp

)

# Add include directories
target_include_directories(CartPendulumSimulator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/matplotlib-cpp)

# Find and link Python library
find_package(Python3 COMPONENTS Development NumPy)
target_include_directories(CartPendulumSimulator PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(CartPendulumSimulator PRIVATE Python3::Python Python3::NumPy)
