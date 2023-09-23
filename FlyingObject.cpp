#include <iostream>
#include <cmath>
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

