#include <iostream>
#include <valarray>
#include "Asteroid.hpp"

using namespace std;

//------------------Constructeurs :

Asteroid::Asteroid(double x, double y, double size, double speed, double angle) : FlyingObject( x, y, size) {
    this -> speed = speed;
    this -> angle = angle;

}

//------------------Getters :

double Asteroid::GetSpeed() {
    return speed;
}

double Asteroid::GetAngle() {
    return angle;
}

//-----------------Setters :

void Asteroid::SetSpeed(double speed) {
    this->speed = speed;
}

void Asteroid::SetAngle(double angle) {
    this->angle = angle;
}


void Asteroid::Move(double screenWidth, double screenHeight) {
    double speedX = Asteroid::GetSpeed() * sin(FlyingObject::DegToRad(Asteroid::GetAngle()));
    double speedY = Asteroid::GetSpeed() * cos(FlyingObject::DegToRad(Asteroid::GetAngle()));

    // Wrap around the screen edge
    if (Asteroid::GetX() > screenWidth) {
        Asteroid::SetX(0);
    }
    else if (Asteroid::GetX() < 0) {
        Asteroid::SetX(screenWidth);
    }

    if (Asteroid::GetY() > screenHeight) {
        Asteroid::SetY(0);
    }
    else if (Asteroid::GetY() < 0) {
        Asteroid::SetY(screenHeight);
    }
    else {
        // Update the FlyingObject's position
        Asteroid::SetX(Asteroid::GetX() + speedX);
        Asteroid::SetY(Asteroid::GetY() + speedY);

    }
}

std::string Asteroid::GetTypeName() const {
    return "Asteroid";
}


