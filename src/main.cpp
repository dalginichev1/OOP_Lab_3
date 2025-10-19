#include "Array.hpp"
#include "Hexagon.hpp"
#include "Octagon.hpp"
#include "Triangle.hpp"

#include <iostream>

int main() {
    Array figures;

    std::cout << "=== Создан треугольник ===" << std::endl;
    Figure* triangle = new Triangle();
    std::cin >> *triangle;
    figures.add(triangle);

    std::cout << "\n=== Создан шестиугольник ===" << std::endl;
    Figure* hexagon = new Hexagon();
    std::cin >> *hexagon;
    figures.add(hexagon);

    std::cout << "\n=== Создан восьмиугольник ===" << std::endl;
    Figure* octagon = new Octagon();
    std::cin >> *octagon;
    figures.add(octagon);

    std::cout << "\n=== Все фигуры ===" << std::endl;
    figures.printAll();

    std::cout << "\n=== Итоговая площадь ===" << std::endl;
    std::cout << "Итоговая площадь: " << figures.totalArea() << std::endl;

    return 0;
}