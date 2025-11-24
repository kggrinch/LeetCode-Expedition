#include "shape.h"

// Virtual functions are not implemented in the cpp file.

// Constructor
Shape::Shape(const double& x, const double& y) : x_{x}, y_{y} {}

void Shape::moveTo(const double& new_x, const double& new_y)
{
    x_ = new_x;
    y_ = new_y;
}