#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape
{

public:

    // Constructor
    Shape(const double& x, const double& y);

    // virtual deconstructor - must be overridden
    // default keyword - tells the compiler to generate the default constructor implementation so no need for manual implementaions
    virtual ~Shape() = default;

    // Pure Virtual functions - must be overridden
    virtual double area() const = 0;
    virtual void draw() const = 0;

    // Normal method
    void moveTo(const double& new_x, const double& new_y);

protected:
    double x_;
    double y_;

};

#endif