#include "PointArray.hpp"

PointArray::PointArray() : data(new Point[8]), size_(0), capacity_(8) {}

PointArray::~PointArray() {
    delete[] data;
}

void PointArray::push_back(const Point& p) {
    if (size_ >= capacity_) {
        capacity_ *= 2;
        Point* new_data = new Point[capacity_];
        for (int i = 0; i < size_; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[size_++] = p;
}

Point& PointArray::operator[](int index) {
    return data[index];
}

const Point& PointArray::operator[](int index) const {
    return data[index];
}

int PointArray::size() const {
    return size_;
}

void PointArray::clear() {
    size_ = 0;
}