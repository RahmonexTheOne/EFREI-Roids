#include <iostream>
#include <cmath>
#include "../include/hpp/Missile.hpp"

using namespace std;

//------------------Constructors :

Missile::Missile(double x, double y, double size, double speed, double angle) : FlyingObject( x, y, size ) {
    this -> speed = speed;
    this -> angle = angle;
}

//------------------ Destructors :

Missile::~Missile() = default;



//----------------Other Functions

void Missile::Move(double screenWidth, double screenHeight) {
    double speedX = Missile::GetSpeed() * sin(FlyingObject::DegToRad(Missile::GetAngle()));
    double speedY = Missile::GetSpeed() * cos(FlyingObject::DegToRad(Missile::GetAngle()));

    if (FlyingObject::GetX() + speed >= screenWidth || FlyingObject::GetX() + speed <= 0 ||
        FlyingObject::GetY() + speed >= screenHeight || FlyingObject::GetY() + speed <= 0) {

    }
    else {
        FlyingObject::SetX(FlyingObject::GetX() + speedX);
        FlyingObject::SetY(FlyingObject::GetY() + speedY);
    }
}


//Getters :
double Missile::GetAngle() {
    return angle;
}

double Missile::GetSpeed() {
    return speed;
}
std::string Missile::GetTypeName() const {
    return "Missile";
}

bool Missile::NotOnScreen(double screenWidth, double screenHeight) {
    if (FlyingObject::GetX() + speed >= screenWidth || FlyingObject::GetX() + speed <= 0 ||
        FlyingObject::GetY() + speed >= screenHeight || FlyingObject::GetY() + speed <= 0) {
        return true;

    }
    else {
        return false;
    }
}
