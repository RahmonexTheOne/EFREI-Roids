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
    double newAngle = (rAngle + Spaceship::GetAngle());
    Spaceship::SetAngle(newAngle);
}

void Spaceship::SpeedUp(double accelerationFactor) {
    //20 speed limit
    if((Spaceship::GetSpeed()+accelerationFactor)>20){

    }
    else if ((Spaceship::GetSpeed()+accelerationFactor)<=20){
        Spaceship::SetSpeed(Spaceship::GetSpeed()+accelerationFactor) ;
    }

}

void Spaceship::SpeedDown(double decelerationFactor) {
    if((Spaceship::GetSpeed()-decelerationFactor)<0){

    }
    else if ((Spaceship::GetSpeed()-decelerationFactor)>=0){
        Spaceship::SetSpeed(Spaceship::GetSpeed()-decelerationFactor) ;
    }
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
