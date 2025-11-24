#include "rectangle.h"

Rectangle::Rectangle(double x, double y, double w, double h) : Shape(x, y), width_(w), height_(h)
{

}

double Rectangle::area() const
{
    return width_ * height_;
}

void Rectangle::draw() const
{
    std::cout << "Drawing a Rectangle at (" << x_ << ", " << y_ << ") with width: " << width_ << " height: " << height_ << "\n";
}