#include <iostream>
#include <cmath>
#include <chrono>
#include "../include/hpp/Spaceship.hpp"


//-----------------------------------------Constructors :

Spaceship::Spaceship(double x, double y, double size, double angle) : FlyingObject( x, y, size ){
    this -> angle = angle;
    this -> warning = false;
    this -> shieldLevel = 1.0;
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
    double speedX = Spaceship::GetSpeed() * sin(FlyingObject::DegToRad(Spaceship::GetAngle()));
    double speedY = Spaceship::GetSpeed() * cos(FlyingObject::DegToRad(Spaceship::GetAngle()));

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

//-----------------------------------------------------------

void Spaceship::SetInvincibleFor(double duration) {
    invincibilityEndTime = std::chrono::system_clock::now() + std::chrono::seconds(static_cast<long>(duration));

}





//Getters :
double Spaceship::GetAngle() {
    return angle;
}

double Spaceship::GetSpeed() {
    return speed;
}

std::string Spaceship::GetTypeName() const {
    return "Spaceship";
}

bool Spaceship::GetWarning() {
    return std::chrono::system_clock::now() < invincibilityEndTime;
}

double Spaceship::GetShieldLevel() {
    return this->shieldLevel;
}

bool Spaceship::GetInvincible() {
    return std::chrono::system_clock::now() < invincibilityEndTime;
}



//Setters :
void Spaceship::SetAngle(double angle) {
    this->angle = angle;
}

void Spaceship::SetSpeed(double speed) {
    this->speed = speed;
}

void Spaceship::SetShieldLevel(double shieldLevel) {
    this->shieldLevel = shieldLevel;
}

void Spaceship::SetWarning(bool warning) {
    this->warning = warning;
}



//---------------------------------------------- Destructors :

Spaceship::~Spaceship() = default;

//-----------------------------------------------------------
