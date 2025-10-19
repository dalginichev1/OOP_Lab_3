#pragma once
#include "FigureArray.hpp"

class Array {
  private:
    FigureArray data;

  public:
    ~Array() noexcept;

    void add(Figure* fig);
    void remove(size_t i);
    void printAll() const;
    double totalArea() const;
};