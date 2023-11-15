#include <iostream>
#include <cmath>
#include <chrono>
#include "../include/hpp/Spaceship.hpp"


//-----------------------------------------Constructors :

Spaceship::Spaceship(double x, double y, double size, double angle) : FlyingObject( x, y, size ,10,angle){
    this -> warning = false;
    this -> shieldLevel = 1.0;
}
//----------------------------------------------------------


//-------------------------------------------------Movement :

void Spaceship::Rotate(double rAngle) {
    double newAngle = (rAngle + GetAngle());
    SetAngle(newAngle);
}

void Spaceship::SpeedUp(double accelerationFactor) {
    //20 speed limit
    if(GetSpeed()+accelerationFactor <= 20){
        SetSpeed(GetSpeed() + accelerationFactor);
    }
    else{}
}

void Spaceship::SpeedDown(double decelerationFactor) {
    if((GetSpeed()-decelerationFactor)<0){

    }
    else if ((GetSpeed()-decelerationFactor)>=0){
        SetSpeed(GetSpeed()-decelerationFactor) ;
    }
}

//-----------------------------------------------------------

void Spaceship::SetInvincibleFor(double duration) {
    invincibilityEndTime = std::chrono::system_clock::now() + std::chrono::seconds(static_cast<long>(duration));

}





//Getters :
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
void Spaceship::SetShieldLevel(double shieldLevel) {
    this->shieldLevel = shieldLevel;
}

void Spaceship::SetWarning(bool warning) {
    this->warning = warning;
}



//---------------------------------------------- Destructors :

Spaceship::~Spaceship() = default;

//-----------------------------------------------------------
