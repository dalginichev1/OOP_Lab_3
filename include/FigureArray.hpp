#pragma once
#include "Figure.hpp"

class FigureArray {
  public:
    FigureArray();
    ~FigureArray();
    void push_back(Figure* fig);
    Figure*& operator[](int index);
    Figure* operator[](int index) const;
    void erase(int index);
    int size() const;

  private:
    Figure** data;
    int size_ = 0;
    int capacity_ = 1;
};