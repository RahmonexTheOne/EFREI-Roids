#include <iostream>
#include "FlyingObject.hpp"

using namespace std;

//------------------Constructeurs :

FlyingObject::FlyingObject(double x, double y, double size) {

    this->x =x;
    this->y =y;
    this->size =size;

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


//--------------------- Movement :

/*void FlyingObject::Move() {
    this->x = x + xSpeed;
    this->y = y + ySpeed;
}*/

/*void FlyingObject::Move(double screenWidth, double screenHeight) {
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
}*/
