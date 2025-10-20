#include "Hexagon.hpp"

#include <iostream>

Hexagon::Hexagon() {}

void Hexagon::read(std::istream& input) {
    points.clear();
    std::cout << "Введите 6 точек (формат: x y):" << std::endl;
    for (int i = 0; i < 6; i++) {
        Point p;
        std::cout << "Point " << (i + 1) << ": ";
        input >> p;
        points.push_back(p);
    }
}

void Hexagon::print(std::ostream& output) const {
    output << "Шестиугольник";
    int i = 0;
    for (i = 0; i < points.size(); ++i) {
        output << points[i] << " ";
    }
}

Point Hexagon::center() const {
    return figureCenter(points);
}
double Hexagon::area() const {
    return figureArea(points);
}

bool Hexagon::operator==(const Figure& fig) const {
    const Hexagon* other = dynamic_cast<const Hexagon*>(&fig);

    if (other == nullptr) {
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