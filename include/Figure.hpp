#pragma once

#include <iostream>

#include "Point.hpp"
#include "PointArray.hpp"

class Figure {
  public:
    virtual ~Figure() = default;

    virtual Point center() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream&) const = 0;
    virtual void read(std::istream&) = 0;
    virtual bool operator==(const Figure& other) const = 0;

    friend std::ostream& operator<<(std::ostream&, const Figure& fig);
    friend std::istream& operator>>(std::istream&, Figure& fig);
};

inline std::ostream& operator<<(std::ostream& output, const Figure& fig) {
    fig.print(output);
    return output;
}

inline std::istream& operator>>(std::istream& input, Figure& fig) {
    fig.read(input);
    return input;
}

double figureArea(const PointArray& points);
Point figureCenter(const PointArray& points);