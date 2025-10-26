#pragma once

#include <iostream>

struct Point {
    double x = 0, y = 0;
    Point(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}
    bool operator==(const Point& other) const { return x == other.x && y == other.y; }
};

inline std::istream& operator>>(std::istream& input, Point& p) {
    input >> p.x >> p.y;
    return input;
}

inline std::ostream& operator<<(std::ostream& output, const Point& p) {
    output << "(" << p.x << ", " << p.y << ")";
    return output;
}