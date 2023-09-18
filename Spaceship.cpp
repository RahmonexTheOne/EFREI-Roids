#include <iostream>
#include "Spaceship.hpp"


//------------------Constructors :

Spaceship::Spaceship(double x, double y, double size, double angle) : FlyingObject( x, y, size ){
    this -> angle = angle;
}

//------------------ Destructors :

Spaceship::~Spaceship() = default;

