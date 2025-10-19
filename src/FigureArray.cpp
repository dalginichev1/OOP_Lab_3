#include "FigureArray.hpp"

FigureArray::FigureArray() : data(new Figure*[10]), size_(0), capacity_(10) {}

FigureArray::~FigureArray() {
    delete[] data;
}

void FigureArray::push_back(Figure* fig) {
    if (size_ >= capacity_) {
        capacity_ *= 2;
        Figure** new_data = new Figure*[capacity_];
        for (int i = 0; i < size_; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[size_++] = fig;
}

Figure*& FigureArray::operator[](int index) {
    return data[index];
}

Figure* FigureArray::operator[](int index) const {
    return data[index];
}

void FigureArray::erase(int index) {
    for (int i = index; i < size_ - 1; i++) {
        data[i] = data[i + 1];
    }
    size_--;
}

int FigureArray::size() const {
    return size_;
}