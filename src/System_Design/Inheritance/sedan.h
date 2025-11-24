#ifndef SEDAN_H
#define SEDAN_H
#include "vehicle.h"

// Different types of inheritance based on access specifiers

//* [Public Inheritance]
// Public - Public members of parent class stay public in child class
// Protected - protected member of parent class stay protected in child class
// Private - private members of vehicle class are inaccessible in child class

//? [Protected Inheritance]
// Public - Public members of parent class become protected in child class
// Protected - protected member of parent class stay protected in child class
// Private - private members of vehicle class are inaccessible in child class

//! [Private Inheritance]
// Public - Public members of parent class become private in child class
// Protected - protected member of parent class become private in child class
// Private - private members of vehicle class are inaccessible in child class

// Child Class
class Sedan : public Vehicle
{
public:
    void speed();

    // Overriding - Overrides the function that was written in the parent class
    void makeNoise();
};

#endif