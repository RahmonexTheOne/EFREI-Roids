#ifndef ASTEROID_HPP_
#define ASTEROID_HPP_

#include <stdio.h>
#include <string>
#include "FlyingObject.hpp"

class Asteroid : public FlyingObject{

public :

    //---------------------Constructeur :
    // -------
    // * x, y : position dans l'écran
    // * size : diamètre de l'objet
    // * xSpeed, ySpeed : vecteur de vitesse de l'objet
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed);




private :


};

#endif ASTEROID_HPP_


