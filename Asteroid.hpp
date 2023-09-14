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

    //////////
    //---------------------Getters :
    double GetXSpeed();
    double GetYSpeed();

    //////////
    //---------------------Setters :
    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);


    ///////////////////////////////////////
    // Déplacement de l'objet avec réentrée
    // déplace selon le vecteur de vitesse de l'objet
    // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
    // de l'autre côté
    // -------
    // * screenWidth, screenHeight : taille de l'écran
    void Move(double screenWidth, double screenHeight);


private :
    double xSpeed;
    double ySpeed;

};

#endif ASTEROID_HPP_


