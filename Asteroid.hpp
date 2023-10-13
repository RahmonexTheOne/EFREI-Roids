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
    Asteroid(double x, double y, double size, double speed, double angle);

    //////////
    //---------------------Getters :
    double GetSpeed();
    double GetAngle();
    std::string GetTypeName() const override;

    //////////
    //---------------------Setters :
    void SetSpeed(double speed);
    void SetAngle(double angle);


    ///////////////////////////////////////
    // Déplacement de l'objet avec réentrée
    // déplace selon le vecteur de vitesse de l'objet
    // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
    // de l'autre côté
    // -------
    // * screenWidth, screenHeight : taille de l'écran
    void Move(double screenWidth, double screenHeight);


private :
    double speed;
    double angle;

};

#endif ASTEROID_HPP_


