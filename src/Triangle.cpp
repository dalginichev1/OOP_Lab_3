#include "Triangle.hpp"

#include <iostream>

Triangle::Triangle() {}

void Triangle::read(std::istream& input) {
    points.clear();
    std::cout << "Введите 3 точки (формат: x y):" << std::endl;
    for (int i = 0; i < 3; i++) {
        Point p;
        std::cout << "Point " << (i + 1) << ": ";
        input >> p;
        points.push_back(p);
    }
}

void Triangle::print(std::ostream& output) const {
    output << "Треугольник";
    int i = 0;
    for (i = 0; i < points.size(); ++i) {
        output << points[i] << " ";
    }
}

Point Triangle::center() const {
    return figureCenter(points);
}
double Triangle::area() const {
    return figureArea(points);
}

bool Triangle::operator==(const Figure& fig) const {
    const Triangle* other = dynamic_cast<const Triangle*>(&fig);

    if (!other) {
        return false;
    }

    if (points.size() != other->points.size()) {
        return false;
    }

    int i = 0;
    for (i = 0; i < points.size(); ++i) {
        if (!(points[i] == other->points[i])) {
            return false;
        }
    }
    return true;
}