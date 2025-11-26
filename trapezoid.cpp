#include "trapezoid.h"
#include <cmath>

// Дочерний Класс Трапеция

// Конструктор

Trapezoid::Trapezoid() {
    amountOfPoints = 4;
    points = new Point[4]();
}

// Площадь
double Trapezoid::area() const {
    double sX1 = points[1].x - points[0].x;
    double sY1 = points[1].y - points[0].y;
    double side1 = std::sqrt(sX1 * sX1 + sY1 * sY1);

    double sX2 = points[2].x - points[3].x;
    double sY2 = points[2].y - points[3].y;
    double side2 = std::sqrt(sX2 * sX2 + sY2 * sY2);

    double h = std::abs(points[2].y - points[0].y);
    
    return (side1 + side2) * h / 2.0;
}

// Операция сравнения
bool Trapezoid::operator==(const Figure& otherFig) const {
    if (otherFig.getAmountOfPoints() != amountOfPoints) {
        return false;
    }

    Point* oPoints = otherFig.getPoints();

    double sX1 = points[1].x - points[0].x;
    double sY1 = points[1].y - points[0].y;
    double side1 = std::sqrt(sX1 * sX1 + sY1 * sY1);

    double sX2 = points[2].x - points[3].x;
    double sY2 = points[2].y - points[3].y;
    double side2 = std::sqrt(sX2 * sX2 + sY2 * sY2);

    double h = std::abs(points[2].y - points[0].y);

    double oX1 = oPoints[1].x - oPoints[0].x;
    double oY1 = oPoints[1].y - oPoints[0].y;
    double oSide1 = std::sqrt(oX1 * oX1 + oY1 * oY1);

    double oX2 = oPoints[2].x - oPoints[3].x;
    double oY2 = oPoints[2].y - oPoints[3].y;
    double oSide2 = std::sqrt(oX2 * oX2 + oY2 * oY2);

    double oH = std::abs(oPoints[2].y - oPoints[0].y);

    return (area() == otherFig.area()) && (side1 == oSide1) && (side2 == oSide2) && (h == oH);
}

// Вывод
void Trapezoid::print(std::ostream& os) const {
    os << "Трапеция [";
    for (unsigned int i = 0; i < 4; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " ]";
}

// Вывод
void Trapezoid::read(std::istream& is) {
    for (unsigned int i = 0; i < amountOfPoints; i++) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Неверный ввод");
        }
        points[i] = Point(x, y);
    }
}