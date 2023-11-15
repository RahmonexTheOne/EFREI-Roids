#include <iostream>
#include <cmath>
#include "../include/hpp/FlyingObject.hpp"

using namespace std;

//------------------Constructeurs :
FlyingObject::FlyingObject(double x, double y, double size, double speed, double angle) {
    this -> x = x;
    this -> y = y;
    this -> size = size;
    this -> speed = speed;
    this -> angle = angle;
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

double FlyingObject::GetSpeed() {
    return speed;
}

double FlyingObject::GetAngle() {
    return angle;
}

std::string FlyingObject::GetTypeName() const {
    return "FlyingObject";
}
//--------------------------



//-----------------Setters :
void FlyingObject::SetX(double x) {
    this->x = x;
}

void FlyingObject::SetY(double y) {
    this->y = y;
}

void FlyingObject::SetSize(double size) {
    this->size = size;
}

void FlyingObject::SetSpeed(double speed) {
    this->speed = speed;
}

void FlyingObject::SetAngle(double angle) {
    this->angle = angle;
}
//------------------------


bool FlyingObject::Collide(FlyingObject *o1,FlyingObject *o2) {
    // Calcul de la distance entre els 2 centres des objets
    double distance = sqrt(pow(o2->x - o1->x, 2) + pow(o2->y - o1->y, 2));
    double rayon1 = o1->size/2;
    double rayon2 = o2->size/2;

    // calculer si la distance est sup ou inf a la somme de leurs rayons
    if (distance <= rayon1 + rayon2) {
        return true;
    } else {
        return false;
    }
}

double FlyingObject::DegToRad(double angle) {
    double newAngle;
    newAngle = ((M_PI)*(180-angle))/180;
    return newAngle;
}

void FlyingObject::Move(double screenWidth, double screenHeight) {
    double speedX = GetSpeed() * sin(DegToRad(GetAngle()));
    double speedY = GetSpeed() * cos(DegToRad(GetAngle()));

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
        SetX(GetX() + speedX);
        SetY(GetY() + speedY);

    }
}

