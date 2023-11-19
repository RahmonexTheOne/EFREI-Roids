#include <iostream>
#include <chrono>
#include <cmath>
#include "../include/hpp/Spaceship.hpp"


//-----------------------------------------Constructors :
Spaceship::Spaceship(double x, double y, double size, double angle) : FlyingObject( x, y, size ,0,angle){
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
        m_xSpeed += accelerationFactor * sin((M_PI)*(GetAngle()/180));
        m_ySpeed -= accelerationFactor * cos((M_PI)*(GetAngle()/180));
    }
    else{}
}

void Spaceship::SpeedDown(double decelerationFactor) {
    if ((GetSpeed()+decelerationFactor)>=-20){
        m_xSpeed -= decelerationFactor * sin((M_PI)*(GetAngle()/180));
        m_ySpeed += decelerationFactor * cos((M_PI)*(GetAngle()/180));
    }
    else{}
}
//-----------------------------------------------------------



//--------------------------------------------------Getters :
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
//-----------------------------------------------------------





//--------------------------------------------------Setters :
void Spaceship::SetShieldLevel(double shieldLevel) {
    this->shieldLevel = shieldLevel;
}

void Spaceship::SetWarning(bool warning) {
    this->warning = warning;
}
//----------------------------------------------------------





//---------------------------------------------- Destructors :
Spaceship::~Spaceship() = default;
//-----------------------------------------------------------


//----------------------------------------------Other Functions :
void Spaceship::ShipMove(double screenWidth, double screenHeight) {

    // Wrap around the screen edge
    if (GetX() > screenWidth) {
        SetX(0);
    }
    else if (GetX() < 0) {
        SetX(screenWidth);
    }

    if (GetY() > screenHeight) {
        SetY(0);
    }
    else if (GetY() < 0) {
        SetY(screenHeight);
    }
    else {
        // Update the spaceship's position
        SetX(GetX() + m_xSpeed);
        SetY(GetY() + m_ySpeed);

    }
}


void Spaceship::SetInvincibleFor(double duration) {
    invincibilityEndTime = std::chrono::system_clock::now() + std::chrono::seconds(static_cast<long>(duration));

}


