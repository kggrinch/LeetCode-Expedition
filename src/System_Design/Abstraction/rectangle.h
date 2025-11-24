#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"


// child class
class Rectangle : public Shape
{
private:
    double width_;
    double height_;

public:
    Rectangle(double x, double y, double w, double h);
    double area() const override;
    void draw() const override;
};


#endif