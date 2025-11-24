#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <numbers>

class Circle : public Shape
{
private:
    double radius_;

public:
    Circle(double x, double y, double r);

    // const on the inside parameter means cannot modify that parameter
    // const on the outside of the function means cannot modify class attributes
    double area() const override;
    void draw() const override;
};

#endif