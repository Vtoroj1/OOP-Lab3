#include "square.h"
#include <cmath>

// Дочерний Класс Квадрат

// Конструктор

Square::Square() {
    amountOfPoints = 4;
    points = new Point[4]();
}

// Площадь
double Square::area() const {
    double sX = points[1].x - points[0].x;
    double sY = points[1].y - points[0].y;
    double sideSquared = sX * sX + sY * sY;
    return sideSquared;
}

// Операция сравнения
bool Square::operator==(const Figure& otherFig) const {
    if (otherFig.getAmountOfPoints() != amountOfPoints) {
        return false;
    }

    Point* oPoints = otherFig.getPoints();

    double sX = points[1].x - points[0].x;
    double sY = points[1].y - points[0].y;
    double sSide = std::sqrt(sX * sX + sY * sY);

    double oX = oPoints[1].x - oPoints[0].x;
    double oY = oPoints[1].y - oPoints[0].y;
    double oSide = std::sqrt(oX * oX + oY * oY);

    return (area() == otherFig.area() && std::abs(sSide - oSide) < 1e-12);
}

// Вывод
void Square::print(std::ostream& os) const {
    os << "Квадрат [";
    for (unsigned int i = 0; i < 4; i++) {
        os << " (" << points[i].x << ", " << points[i].y << ")";
    }
    os << " ]";
}

// Ввод
void Square::read(std::istream& is) {
    for (unsigned int i = 0; i < amountOfPoints; i++) {
        double x, y;
        if (!(is >> x >> y)) {
            throw std::runtime_error("Неверный ввод");
        }
        points[i] = Point(x, y);
    }
}
