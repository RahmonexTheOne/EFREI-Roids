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
    /*double newSpeed = Spaceship::GetSpeed() + accelerationFactor * cos(Spaceship::DegToRad(Spaceship::GetAngle()));
    std::cout << "trying taccelerate" << std::endl;

    Spaceship::SetX(Spaceship::GetX() + newSpeed * cos(Spaceship::DegToRad(Spaceship::GetAngle())));
    Spaceship::SetY(Spaceship::GetY() + newSpeed * sin(Spaceship::DegToRad(Spaceship::GetAngle())));*/
    Spaceship::SetSpeed(Spaceship::GetSpeed()+accelerationFactor) ;

}

void Spaceship::SpeedDown(double decelerationFactor) {
    /*double newSpeed = Spaceship::GetSpeed() - decelerationFactor * cos(Spaceship::DegToRad(Spaceship::GetAngle()));

    Spaceship::SetX(Spaceship::GetX() + newSpeed * sin(Spaceship::DegToRad(Spaceship::GetAngle())));
    Spaceship::SetY(Spaceship::GetY() + newSpeed * cos(Spaceship::DegToRad(Spaceship::GetAngle())));*/
    Spaceship::SetSpeed(Spaceship::GetSpeed()-decelerationFactor) ;
}


void Spaceship::Move(double screenWidth, double screenHeight) {
    double speedX = Spaceship::GetSpeed() * sin(Spaceship::DegToRad(Spaceship::GetAngle()));
    double speedY = Spaceship::GetSpeed() * cos(Spaceship::DegToRad(Spaceship::GetAngle()));

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
    else {
        // Update the spaceship's position
        Spaceship::SetX(Spaceship::GetX() + speedX);
        Spaceship::SetY(Spaceship::GetY() + speedY);

    }
}

double Spaceship::DegToRad(double angle) {
    double newAngle;
    newAngle = ((M_PI)*(180-angle))/180;
    return newAngle;
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
