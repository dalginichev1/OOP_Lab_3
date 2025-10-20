#pragma once

#include "Point.hpp"

class PointArray {
  public:
    PointArray();
    ~PointArray() noexcept;

    void push_back(const Point& point);
    Point& operator[](int index);
    const Point& operator[](int index) const;
    int size() const;
    void clear();

  private:
    Point* data;
    int size_ = 0;
    int capacity_ = 1;
};