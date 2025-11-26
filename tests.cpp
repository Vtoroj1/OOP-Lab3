#include <gtest/gtest.h>
#include "point.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "array.h"
#include <sstream>
#include <cmath>
#include <stdexcept>

TEST(SquareTest, AreaCalculation) {
    Square square;
    std::stringstream input("0 0 2 0 2 2 0 2"); // Квадрат 2x2
    input >> square;
    
    EXPECT_NEAR(square.area(), 4.0, 1e-6);
    EXPECT_NEAR(static_cast<double>(square), 4.0, 1e-6);
}

TEST(SquareTest, CenterTest) {
    Square square;
    std::stringstream input("0 0 2 0 2 2 0 2");
    input >> square;
    
    Point center = square.center();
    EXPECT_NEAR(center.x, 1.0, 1e-6);
    EXPECT_NEAR(center.y, 1.0, 1e-6);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rect;
    std::stringstream input("0 0 3 0 3 2 0 2"); // Прямоугольник 3x2
    input >> rect;
    
    EXPECT_NEAR(rect.area(), 6.0, 1e-6);
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trap;
    std::stringstream input("0 0 4 0 3 3 1 3"); // Трапеция с основаниями 4 и 2, высотой 3
    input >> trap;
    
    EXPECT_NEAR(trap.area(), 9.0, 1e-6);
}

TEST(ArrayTest, AddAndSize) {
    Array array(5);
    
    Square* square = new Square();
    std::stringstream input("0 0 1 0 1 1 0 1");
    input >> *square;
    
    EXPECT_EQ(array.getSize(), 0);
    array.addFigure(square);
    EXPECT_EQ(array.getSize(), 1);
}

TEST(ArrayTest, RemoveFigure) {
    Array array(5);
    
    Square* square = new Square();
    std::stringstream input("0 0 1 0 1 1 0 1");
    input >> *square;
    
    array.addFigure(square);
    EXPECT_EQ(array.getSize(), 1);
    
    array.remove(0);
    EXPECT_EQ(array.getSize(), 0);
}

TEST(ArrayTest, TotalArea) {
    Array array(5);
    
    Square* square = new Square();
    std::stringstream input1("0 0 1 0 1 1 0 1");
    input1 >> *square;
    array.addFigure(square);
    
    Rectangle* rect = new Rectangle();
    std::stringstream input2("0 0 3 0 3 2 0 2");
    input2 >> *rect;
    array.addFigure(rect);
    
    EXPECT_NEAR(array.allArea(), 7.0, 1e-6);
}

TEST(ArrayTest, OverflowMoment) {
    Array array(2);
    
    Square* square1 = new Square();
    std::stringstream input1("0 0 1 0 1 1 0 1");
    input1 >> *square1;
    
    Square* square2 = new Square(); 
    std::stringstream input2("0 0 1 0 1 1 0 1");
    input2 >> *square2;
    
    array.addFigure(square1);
    array.addFigure(square2);
    
    Square* square3 = new Square();
    std::stringstream input3("0 0 1 0 1 1 0 1");
    input3 >> *square3;
    
    EXPECT_THROW(array.addFigure(square3), std::overflow_error);
}

TEST(ComparisonTest, Ravenstvo) {
    Square sq1, sq2;
    std::stringstream input1("0 0 2 0 2 2 0 2");
    std::stringstream input2("0 0 2 0 2 2 0 2");
    
    input1 >> sq1;
    input2 >> sq2;
    
    EXPECT_TRUE(sq1 == sq2);
}