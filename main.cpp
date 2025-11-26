#include <iostream>
#include "array.h"
#include "square.h"

int main() {
    std::cout << "Тест Array" << std::endl;
    
    Array array(5);
    
    Square* square = new Square();
    std::cout << "Введите 4 точки квадрата: ";
    std::cin >> *square;
    
    array.addFigure(square);

    Rectangle* rect = new Rectangle();
    std::cout << "Введите 4 точки прямоугольника: ";
    std::cin >> *rect;
    
    array.addFigure(rect);

    Trapezoid* trap = new Trapezoid();
    std::cout << "Введите 4 точки трапеции: ";
    std::cin >> *trap;
    
    array.addFigure(trap);
    
    array.allPrint();
    std::cout << "Общая площадь: " << array.allArea() << std::endl;
    
    array.remove(2);

    array.allPrint();
    std::cout << "Общая площадь: " << array.allArea() << std::endl;

    return 0;
}