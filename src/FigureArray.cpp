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

void FigureArray::printAll() const {
    int i = 0;
    for (i = 0; i < size_; i++) {
        std::cout << *data[i] << std::endl;
    }
}

double FigureArray::totalArea() const {
    double total = 0.0;
    int i = 0;
    for (i = 0; i < size_; i++) {
        total += data[i]->area();
    }
    return total;
}

void FigureArray::erase(int index) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index is out of range");
    }

    for (int i = index; i < size_ - 1; i++) {
        data[i] = data[i + 1];
    }
    size_--;
}

int FigureArray::size() const {
    return size_;
}

Figure*& FigureArray::operator[](int index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index is out of range");
    }
    return data[index];
}

const Figure* const FigureArray::operator[](int index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index is out of range ");
    }
    return data[index];
}