#include <iostream>
#include "FlyingObject.hpp"

using namespace std;

//------------------Constructeurs :

FlyingObject::FlyingObject(double x, double y, double size, double xSpeed, double ySpeed) {

    this->x =x;
    this->y =y;
    this->size =size;
    this->xSpeed =xSpeed;
    this->ySpeed =ySpeed;

}

//-----------------Getters :
double FlyingObject::GetX() {
    return x;
}

double FlyingObject::GetY() {
    return y;
}

double FlyingObject::GetSize() {
    return size;
}

double FlyingObject::GetXSpeed() {
    return xSpeed;
}

double FlyingObject::GetYSpeed() {
    return ySpeed;
}

//-----------------Setters :


void FlyingObject::SetX(double xSpeed) {
    this->xSpeed = xSpeed;
}

void FlyingObject::SetY(double ySpeed) {
    this->ySpeed = ySpeed;
}

void FlyingObject::SetSize(double size) {
    this->size = size;
}

void FlyingObject::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void FlyingObject::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

//--------------------- Movement :

void FlyingObject::Move() {
    this->x = x + xSpeed;
    this->y = y + ySpeed;
}

void FlyingObject::Move(double screenWidth, double screenHeight) {
    if(x + xSpeed >= screenWidth){
        this->x = 0;
    }
    else if(x+xSpeed<=0){
        this->x = screenWidth;
    }
    else if(y+ySpeed >= screenHeight){
        this->y = 0;
    }
    else if(y+ySpeed <=0){
        this->y = screenHeight;
    }
    else {
        this->x = x + xSpeed;
        this->y = y + ySpeed;
    }
}
