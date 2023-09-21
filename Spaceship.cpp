#include <iostream>
#include <cmath>
#include "Spaceship.hpp"


//-----------------------------------------Constructors :

Spaceship::Spaceship(double x, double y, double size, double angle) : FlyingObject( x, y, size ){
    this -> angle = angle;
}
//----------------------------------------------------------

//-------------------------------------------------Movement :

void Spaceship::Rotate(double rAngle) {
    //Spaceship::SetAngle(((M_PI)*(180-rAngle))/180 + Spaceship::GetAngle());
    double newAngle = (rAngle + Spaceship::GetAngle());
    Spaceship::SetAngle(newAngle);
    std::cout << "angle = " << angle << std::endl;
}

void Spaceship::SpeedUp(double accelerationFactor) {

}

void Spaceship::SpeedDown(double decelerationFactor) {

}
//-----------------------------------------------------------


//Getters :
double Spaceship::GetAngle() {
    return angle;
}

//Setters :
void Spaceship::SetAngle(double angle) {
    this->angle = angle;
}

//---------------------------------------------- Destructors :

Spaceship::~Spaceship() = default;

//-----------------------------------------------------------
