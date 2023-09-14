#include <iostream>
#include "Asteroid.hpp"

using namespace std;

//------------------Constructeurs :

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed) : FlyingObject( x, y, size) {

    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;

}

//------------------Getters :

double Asteroid::GetXSpeed() {
    return xSpeed;
}

double Asteroid::GetYSpeed() {
    return ySpeed;
}

//-----------------Setters :

void Asteroid::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void Asteroid::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}


void Asteroid::Move(double screenWidth, double screenHeight) {
    if( FlyingObject::GetX() + xSpeed >= screenWidth){
        FlyingObject::SetX(0) ;
    }
    else if(FlyingObject::GetX() + xSpeed<=0){
        FlyingObject::SetX(screenWidth) ;
    }
    else if(FlyingObject::GetY() + ySpeed >= screenHeight){
        FlyingObject::SetY(0);
    }
    else if(FlyingObject::GetY() +ySpeed <=0){
        FlyingObject::SetY(screenHeight);
    }
    else {
        FlyingObject::SetX(FlyingObject::GetX() + xSpeed) ;
        FlyingObject::SetY(FlyingObject::GetY() + ySpeed) ;
    }
}


