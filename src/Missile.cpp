#include <iostream>
#include <cmath>
#include "../include/hpp/Missile.hpp"

using namespace std;

//------------------Constructors :

Missile::Missile(double x, double y, double size, double speed, double angle) : FlyingObject( x, y, size, speed, angle ) {
}

//------------------ Destructors :

Missile::~Missile() = default;



//----------------Other Functions

void Missile::Move(double screenWidth, double screenHeight) {
    double speedX = GetSpeed() * sin(DegToRad(GetAngle()));
    double speedY = GetSpeed() * cos(DegToRad(GetAngle()));

    if (GetX() + GetSpeed() >= screenWidth || GetX() + GetSpeed() <= 0 ||
        GetY() + GetSpeed() >= screenHeight || GetY() + GetSpeed() <= 0) {

    }
    else {
        SetX(GetX() + speedX);
        SetY(GetY() + speedY);
    }
}


//Getters :
std::string Missile::GetTypeName() const {
    return "Missile";
}

bool Missile::NotOnScreen(double screenWidth, double screenHeight) {
    if (GetX() + GetSpeed() >= screenWidth || GetX() + GetSpeed() <= 0 ||
        GetY() + GetSpeed() >= screenHeight || GetY() + GetSpeed() <= 0) {
        return true;
    }
    else {
        return false;
    }
}
