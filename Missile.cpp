#include <iostream>
#include "Missile.hpp"

using namespace std;

using namespace std;

//------------------Constructors :

Missile::Missile(double x, double y, double size, double speed, double angle) : FlyingObject( x, y, size ) {
    this -> speed = speed;
    this -> angle = angle;
}

//------------------ Destructors :

Missile::~Missile() = default;



bool Missile::Move(double screenWidth, double screenHeight) {
    if (FlyingObject::GetX() + speed >= screenWidth || FlyingObject::GetX() + speed <= 0 ||
        FlyingObject::GetY() + speed >= screenHeight || FlyingObject::GetY() + speed <= 0) {
        cout << "stop " << endl;
        return false;
    } else {
        FlyingObject::SetX(FlyingObject::GetX() + speed);
        FlyingObject::SetY(FlyingObject::GetY() + speed);
        return true;
    }
}
