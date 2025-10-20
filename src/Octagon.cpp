#include "Octagon.hpp"

#include <iostream>

Octagon::Octagon() {}

void Octagon::read(std::istream& input) {
    points.clear();
    std::cout << "Введите 8 точек (формат: x y):" << std::endl;
    for (int i = 0; i < 8; i++) {
        Point p;
        std::cout << "Точка " << (i + 1) << ": ";
        input >> p;
        points.push_back(p);
    }
}

void Octagon::print(std::ostream& output) const {
    output << "Восьмиугольник";
    int i = 0;
    for (i = 0; i < points.size(); ++i) {
        output << points[i] << " ";
    }
}

Point Octagon::center() const {
    return figureCenter(points);
}
double Octagon::area() const {
    return figureArea(points);
}

bool Octagon::operator==(const Figure& fig) const {
    const Octagon* other = dynamic_cast<const Octagon*>(&fig);

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