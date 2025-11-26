#include "rectangle.h"
#include <cmath>

// Дочерний Класс Прямоугольник

// Конструктор

Rectangle::Rectangle() {
    amountOfPoints = 4;
    points = new Point[4]();
}

// Площадь
double Rectangle::area() const {
    double sX1 = points[1].x - points[0].x;
    double sY1 = points[1].y - points[0].y;
    double side1 = std::sqrt(sX1 * sX1 + sY1 * sY1);

    double sX2 = points[2].x - points[1].x;
    double sY2 = points[2].y - points[1].y;
    double side2 = std::sqrt(sX2 * sX2 + sY2 * sY2);
    return side1 * side2;
}

// Операция сравнения
bool Rectangle::operator==(const Figure& otherFig) const {
    if (otherFig.getAmountOfPoints() != amountOfPoints) {
        return false;
    }
    Point* oPoints = otherFig.getPoints();

    double sX1 = points[1].x - points[0].x;
    double sY1 = points[1].y - points[0].y;
    double side1 = std::sqrt(sX1 * sX1 + sY1 * sY1);

    double sX2 = points[2].x - points[1].x;
    double sY2 = points[2].y - points[1].y;
    double side2 = std::sqrt(sX2 * sX2 + sY2 * sY2);

    double oX1 = oPoints[1].x - oPoints[0].x;
    double oY1 = oPoints[1].y - oPoints[0].y;
    double oSide1 = std::sqrt(oX1 * oX1+ oY1 * oY1);

    double oX2 = oPoints[2].x - oPoints[1].x;
    double oY2 = oPoints[2].y - oPoints[1].y;
    double oSide2 = std::sqrt(sX2 * sX2 + sY2 * sY2);

    return (area() == otherFig.area() && side1 + side2 == oSide1 + oSide2);
}

// Вывод
void Rectangle::print(std::ostream& os) const {
    os << "Прямоугольник [";
    for (unsigned int i = 0; i < 4; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " ]";
}

// Ввод
void Rectangle::read(std::istream& is) {
    for (unsigned int i = 0; i < amountOfPoints; i++) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Неверный ввод");
        }
        points[i] = Point(x, y);
    }
}
