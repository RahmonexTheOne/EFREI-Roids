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
    //Spaceship::SetX(Spaceship::GetX() + accelerationFactor);
    double newSpeed = Spaceship::GetSpeed() + accelerationFactor * cos(Spaceship::GetAngle());
    std::cout << "trying to accelerate" << std::endl;

    Spaceship::SetX(Spaceship::GetX() + newSpeed * cos(Spaceship::GetAngle()));
    Spaceship::SetY(Spaceship::GetY() + newSpeed * sin(Spaceship::GetAngle()));
    Spaceship::SetSpeed(newSpeed);

}

void Spaceship::SpeedDown(double decelerationFactor) {
    double newSpeed = Spaceship::GetSpeed() - decelerationFactor * cos(angle);

    Spaceship::SetX(Spaceship::GetX() + newSpeed * cos(Spaceship::GetAngle()));
    Spaceship::SetY(Spaceship::GetY() + newSpeed * sin(Spaceship::GetAngle()));
    Spaceship::SetSpeed(newSpeed) ;
}


void Spaceship::Move(double screenWidth, double screenHeight) {
    double deltaX = Spaceship::GetSpeed() * cos(Spaceship::GetAngle());
    double deltaY = Spaceship::GetSpeed() * sin(Spaceship::GetAngle());

    // Update the spaceship's position
    Spaceship::SetX(Spaceship::GetX() + deltaX);
    Spaceship::SetY(Spaceship::GetY() + deltaY);

    // Wrap around the screen edge
    if (Spaceship::GetX() > screenWidth) {
        Spaceship::SetX(0);
    }
    else if (Spaceship::GetX() < 0) {
        Spaceship::SetX(screenWidth);
    }

    if (Spaceship::GetY() > screenHeight) {
        Spaceship::SetY(0);
    }
    else if (Spaceship::GetY() < 0) {
        Spaceship::SetY(screenHeight);
    }
}


//-----------------------------------------------------------


//Getters :
double Spaceship::GetAngle() {
    return angle;
}

double Spaceship::GetSpeed() {
    return speed;
}



//Setters :
void Spaceship::SetAngle(double angle) {
    this->angle = angle;
}

void Spaceship::SetSpeed(double speed) {
    this->speed = speed;
}

//---------------------------------------------- Destructors :

Spaceship::~Spaceship() = default;

//-----------------------------------------------------------
