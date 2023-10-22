#include <iostream>
#include <valarray>
#include <SDL_render.h>
#include <vector>
#include <random>
#include "Asteroid.hpp"
#include "framework.hpp"

using namespace std;

//------------------Constructeurs :

Asteroid::Asteroid(double x, double y, double size, double speed, double angle, int nbExplosions,SDL_Texture* texture) : FlyingObject( x, y, size) {
    this -> speed = speed;
    this -> angle = angle;
    this -> nbExplosionsLeft = nbExplosions;
    this->texture = texture;

}

//------------------Getters :

double Asteroid::GetSpeed() {
    return speed;
}

double Asteroid::GetAngle() {
    return angle;
}

double Asteroid::GetNbExplosionsLeft() {
    return nbExplosionsLeft;
}

SDL_Texture* Asteroid::GetTexture() {
    return this->texture;
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

Asteroid *Asteroid::Explode(double speed, double angle) {
    if(this->nbExplosionsLeft>0){
        //Each asteroids generated reduce the nbExplosionsLeft (means that when a missile hits an asteroids the nbOfExplosions reduce by 2)
        double newSize = Asteroid::GetSize()/2; //Reduce size
        Asteroid* newAsteroid = new Asteroid(Asteroid::GetX(), Asteroid::GetY(), newSize, speed, angle,nbExplosionsLeft-2, Asteroid::GetTexture());
        this->nbExplosionsLeft--;
        return newAsteroid;

    }
    else{
        return nullptr;
    }
}






