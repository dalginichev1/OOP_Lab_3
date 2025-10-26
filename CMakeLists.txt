cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
find_package(GTest REQUIRED)
include_directories(include)

add_executable(Figures
    src/Figure.cpp
    src/FigureArray.cpp
    src/PointArray.cpp
    src/Triangle.cpp
    src/Hexagon.cpp
    src/main.cpp
    src/Octagon.cpp
)

add_executable(FiguresTest
    src/Figure.cpp
    src/FigureArray.cpp
    src/PointArray.cpp
    src/Triangle.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    tests/test_figure.cpp
    tests/main_test.cpp
)

target_link_libraries(FiguresTest GTest::gtest GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(FiguresTest)