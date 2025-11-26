#include "array.h"

// Класс Список
Array::Array(unsigned int spisokSize) : amountOfFigures(0), maxAmount(spisokSize) {
    figures = new Figure*[maxAmount];
    for (unsigned int i = 0; i < maxAmount; i++) {
        figures[i] = nullptr;
    }
}

Array::~Array() {
    delete[] figures;
}

void Array::addFigure(Figure* fig) {
    if (amountOfFigures < maxAmount) {
        figures[amountOfFigures++] = fig;
    } else {
        throw std::overflow_error("Массив фигур перполнен!");
    }
}

void Array::remove(unsigned int index) {
    if (index < amountOfFigures) {
        for (unsigned int i = index; i < amountOfFigures - 1; i++) {
            figures[i] = figures[i + 1];
        }
        
        figures[--amountOfFigures] = nullptr;
    }
}

void Array::allPrint() const {
    std::cout << "=== Все фигуры в массиве ===" << std::endl;
    for (unsigned int i = 0; i < amountOfFigures; i++) {
        std::cout << "Фигура " << i + 1 << ": " << *figures[i] << std::endl;
        
        Point center = figures[i]->center();
        std::cout << "Центр: (" << center.x << ", " << center.y << ")" << std::endl;
        
        double area = figures[i]->area();
        std::cout << "Площадь: " << area << std::endl;
        
        std::cout << "============================" << std::endl;
    }
}

double Array::allArea() const {
    double ans = 0.0;
    for (unsigned int i = 0; i < amountOfFigures; i++) {
        ans += figures[i]->area();
    }
    return ans;
}

unsigned int Array::getSize() const {
    return amountOfFigures;
}

unsigned int Array::getMaxSize() const {
    return maxAmount;
}