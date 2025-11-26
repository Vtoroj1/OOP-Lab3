#ifndef ARRAY_H
#define ARRAY_H

// Класс Список

#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

class Array {
    public:
        Array(unsigned int arraySize = 10);
        ~Array();

        double allArea() const;
        void allPrint() const;

        void addFigure(Figure* fig);
        void remove(unsigned int index);

        unsigned int getSize() const;
        unsigned int getMaxSize() const;
        
    private:
        unsigned int amountOfFigures;
        unsigned int maxAmount;
        Figure** figures;
};

#endif
