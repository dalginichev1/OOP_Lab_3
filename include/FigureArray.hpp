#pragma once

#include "Figure.hpp"

class FigureArray {
  public:
    FigureArray();
    ~FigureArray();

    void push_back(Figure* fig);
    int size() const;
    void erase(int index);

    void printAll() const;
    double totalArea() const;

    Figure*& operator[](int index);
    const Figure* const operator[](int index) const;

  private:
    Figure** data;
    int size_ = 0;
    int capacity_ = 1;
};