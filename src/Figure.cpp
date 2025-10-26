#include "Figure.hpp"

#include <cmath>

double figureArea(const PointArray& points) {
    double sum = 0;
    int n = points.size();
    int i = 0;
    int j = 0;
    for (i = 0; i < n; ++i) {
        j = (i + 1) % n;
        sum += points[i].x * points[j].y - points[j].x * points[i].y;
    }

    return std::abs(sum) / 2;
}

Point figureCenter(const PointArray& points) {
    double cx = 0, cy = 0;
    int n = points.size();
    int i = 0;

    for (i = 0; i < n; ++i) {
        cx += points[i].x;
        cy += points[i].y;
    }

    return Point(cx / n, cy / n);
}