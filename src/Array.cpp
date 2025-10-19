#include "Array.hpp"

#include <iostream>

Array::~Array() {
    int i = 0;
    for (i = 0; i < data.size(); ++i) {
        delete data[i];
        data[i] = nullptr;
    }
}

void Array::add(Figure* fig) {
    data.push_back(fig);
}

void Array::remove(size_t i) {
    if (i >= 0 && i < data.size()) {
        delete data[i];
        data.erase(i);
    }
}

void Array::printAll() const {
    int i = 0;
    for (i = 0; i < data.size(); i++) {
        std::cout << *data[i] << std::endl;
    }
}

double Array::totalArea() const {
    double total = 0.0;
    int i = 0;
    for (i = 0; i < data.size(); i++) {
        total += data[i]->area();
    }
    return total;
}