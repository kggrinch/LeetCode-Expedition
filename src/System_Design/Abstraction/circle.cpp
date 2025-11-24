#include "circle.h"

Circle::Circle(double x, double y, double r) : Shape(x, y), radius_(r)
{

}
double Circle::area() const
{
    return std::numbers::pi * radius_ * radius_;
}
void Circle::draw() const
{
    std::cout << "Drawing a Circle at (" << x_ << ", " << y_ << ") with radius " << radius_ << "\n";
}