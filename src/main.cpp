#include <iostream>

#include "FigureArray.hpp"
#include "Hexagon.hpp"
#include "Octagon.hpp"
#include "Triangle.hpp"

int main() {
    FigureArray figures;

    std::cout << "=== Создан треугольник ===" << std::endl;
    Figure* triangle = new Triangle();
    std::cin >> *triangle;
    figures.push_back(triangle);

    std::cout << "\n=== Создан шестиугольник ===" << std::endl;
    Figure* hexagon = new Hexagon();
    std::cin >> *hexagon;
    figures.push_back(hexagon);

    std::cout << "\n=== Создан восьмиугольник ===" << std::endl;
    Figure* octagon = new Octagon();
    std::cin >> *octagon;
    figures.push_back(octagon);

    std::cout << "\n=== Все фигуры ===" << std::endl;
    figures.printAll();

    std::cout << "\n=== Итоговая площадь ===" << std::endl;
    std::cout << "Итоговая площадь: " << figures.totalArea() << std::endl;

    return 0;
}