#include <iostream>
#include <valarray>
#include <SDL_render.h>
#include <vector>
#include <random>
#include "../include/hpp/Asteroid.hpp"
#include "../include/hpp/framework.hpp"

using namespace std;

//------------------Constructeurs :

Asteroid::Asteroid(double x, double y, double size, double speed, double angle, int nbExplosions,SDL_Texture* texture) : FlyingObject( x, y, size, speed , angle) {
    this -> nbExplosionsLeft = nbExplosions;
    this->texture = texture;
}
//--------------------------------



//------------------Getters :

double Asteroid::GetNbExplosionsLeft() {
    return nbExplosionsLeft;
}

SDL_Texture* Asteroid::GetTexture() {
    return this->texture;
}

std::string Asteroid::GetTypeName() const {
    return "Asteroid";
}
//------------------------




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






