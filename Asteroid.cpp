#include <iostream>
#include "Asteroid.hpp"

using namespace std;

//------------------Constructeurs :

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed) {

    this->x =x;
    this->y =y;
    this->size =size;
    this->xSpeed =xSpeed;
    this->ySpeed =ySpeed;

}

//-----------------Getters :
double Asteroid::GetX() {
    return x;
}

double Asteroid::GetY() {
    return y;
}

double Asteroid::GetSize() {
    return size;
}

double Asteroid::GetXSpeed() {
    return xSpeed;
}

double Asteroid::GetYSpeed() {
    return ySpeed;
}

//-----------------Setters :


void Asteroid::SetX(double xSpeed) {
    this->xSpeed = xSpeed;
}

void Asteroid::SetY(double ySpeed) {
    this->ySpeed = ySpeed;
}

void Asteroid::SetSize(double size) {
    this->size = size;
}

void Asteroid::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void Asteroid::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

//--------------------- Movement :

void Asteroid::Move() {
    this->x = x + xSpeed;
    cout << "X :" << x+xSpeed<< endl;
    this->y = y + ySpeed;
    cout << "Y :" << y+ySpeed<< endl;

}

void Asteroid::Move(double screenWidth, double screenHeight) {
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
