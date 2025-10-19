#include <gtest/gtest.h>

#include <sstream>

#include "Array.hpp"
#include "Hexagon.hpp"
#include "Octagon.hpp"
#include "Triangle.hpp"

// Базовые тесты для Point
TEST(PointTest, Basic) {
    Point p(1.5, 2.5);
    EXPECT_DOUBLE_EQ(p.x, 1.5);
    EXPECT_DOUBLE_EQ(p.y, 2.5);
}

TEST(PointTest, IO) {
    Point p;
    std::stringstream ss("3.0 4.0");
    ss >> p;

    std::stringstream out;
    out << p;
    EXPECT_EQ(out.str(), "(3, 4)");
}

// Тесты для Triangle
TEST(TriangleTest, Area) {
    Triangle t;
    std::stringstream ss("0 0 1 0 0 1");
    t.read(ss);
    EXPECT_NEAR(t.area(), 0.5, 0.001);
}

TEST(TriangleTest, Center) {
    Triangle t;
    std::stringstream ss("0 0 3 0 0 3");
    t.read(ss);
    Point center = t.center();
    EXPECT_NEAR(center.x, 1.0, 0.001);
    EXPECT_NEAR(center.y, 1.0, 0.001);
}

// Тесты для Hexagon
TEST(HexagonTest, Area) {
    Hexagon h;
    std::stringstream ss("0 0 1 0 1.5 0.866 1 1.732 0 1.732 -0.5 0.866");
    h.read(ss);
    EXPECT_GT(h.area(), 2.0);
}

// Тесты для Octagon
TEST(OctagonTest, Area) {
    Octagon o;
    std::stringstream ss("1 0 0.707 0.707 0 1 -0.707 0.707 -1 0 -0.707 -0.707 0 -1 0.707 -0.707");
    o.read(ss);
    EXPECT_GT(o.area(), 2.0);
}

// Тесты для Array
TEST(ArrayTest, AddAndTotalArea) {
    Array arr;

    Triangle* t = new Triangle();
    std::stringstream ss1("0 0 1 0 0 1");
    t->read(ss1);
    arr.add(t);

    EXPECT_NEAR(arr.totalArea(), 0.5, 0.001);
}

TEST(ArrayTest, Remove) {
    Array arr;

    Triangle* t = new Triangle();
    std::stringstream ss1("0 0 1 0 0 1");
    t->read(ss1);
    arr.add(t);

    Hexagon* h = new Hexagon();
    std::stringstream ss2("0 0 1 0 1.5 0.866 1 1.732 0 1.732 -0.5 0.866");
    h->read(ss2);
    arr.add(h);

    double totalWithTriangle = arr.totalArea();
    arr.remove(0); // Удаляем треугольник
    double totalWithoutTriangle = arr.totalArea();

    EXPECT_LT(totalWithoutTriangle, totalWithTriangle);
}

TEST(ArrayTest, EmptyArray) {
    Array arr;
    EXPECT_DOUBLE_EQ(arr.totalArea(), 0.0);
}

// Интеграционный тест
TEST(IntegrationTest, AllFigures) {
    Array arr;

    Triangle* t = new Triangle();
    std::stringstream ss1("0 0 1 0 0 1");
    t->read(ss1);
    arr.add(t);

    Hexagon* h = new Hexagon();
    std::stringstream ss2("0 0 1 0 1.5 0.866 1 1.732 0 1.732 -0.5 0.866");
    h->read(ss2);
    arr.add(h);

    Octagon* o = new Octagon();
    std::stringstream ss3("1 0 0.707 0.707 0 1 -0.707 0.707 -1 0 -0.707 -0.707 0 -1 0.707 -0.707");
    o->read(ss3);
    arr.add(o);

    double total = arr.totalArea();
    EXPECT_GT(total, 5.0);
    EXPECT_LT(total, 6.0);
}
