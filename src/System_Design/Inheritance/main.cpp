#include <iostream>
#include "vehicle.h"
#include "sedan.h"

// Inheritance - A class that inherits attributes and methods from another class

int main()
{
    // Parent class
    Vehicle vehicle;
    vehicle.drive();

    // Child Class
    Sedan sedan;
    sedan.drive();
    sedan.speed();

    // Example of overridden functions
    vehicle.makeNoise();
    sedan.makeNoise();
}