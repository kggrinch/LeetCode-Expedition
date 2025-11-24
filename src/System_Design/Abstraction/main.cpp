#include <iostream>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include <vector>

// Abstraction - abstract classes cannot be instantiated, but they can have subclasses.
//               abstract methods are declared without an implementation.
//               abstract methods do not have a body and must be declared abstract. The method must then be implemented in the child class.
//               abstraction in c++ also uses polymorphism due to the shared base class
//
// Use Case Example - magine you want to draw a shape, and a person asks you what shape are you going to
//                    draw? You reply with, I want to draw just a shape. That won't make sense since
//                    a shape is to generic (abstract), and you have to reply with an actual shape
//                    like circle, square, ect.
//                    Therefore, abstraction makes it so that you cannot instantiate something that is
//                    abstract and doesn't make sense.

int main()
{
    // Shape shape1; cannot do this because shape class is abstract

    // Circle
    Shape* circle = new Circle(1, 1, 5);
    std::cout << "Circle area: " << circle->area() << "\n";
    circle->draw();

    // Rectangle
    Shape* rectangle = new Rectangle(2, 2, 4, 4);
    std::cout << "Rectangle area: " << rectangle->area() << "\n";
    rectangle->draw();

    // Polymorphism
    // Notice how I can place both rectangle and circle into a single shape pointer vector.
    std::cout << "\nPolymorphism\n";
    std::vector<Shape*> shapes;
    shapes.push_back(circle);
    shapes.push_back(rectangle);
    for (auto shape : shapes)
    {
        shape->draw();
    }

    return 0;
}