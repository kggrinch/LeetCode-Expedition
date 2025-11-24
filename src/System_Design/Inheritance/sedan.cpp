#include "sedan.h"

void Sedan::speed()
{
    std::cout << "Sedan is speeding" << "\n";
}

// Overriding - Overrides the function that was written in the parent class
void Sedan::makeNoise()
{
    std::cout << "Sedan makes noise" << "\n";
}