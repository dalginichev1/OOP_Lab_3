#pragma once
#include "Figure.hpp"

class Hexagon : public Figure {
  public:
    Hexagon();

    void read(std::istream& input) override;
    void print(std::ostream& output) const override;
    Point center() const override;
    double area() const override;
    bool operator==(const Figure& fig) const override;

  private:
    PointArray points;
};