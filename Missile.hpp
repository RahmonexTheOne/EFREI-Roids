#ifndef MISSILE_HPP
#define MISSILE_HPP


#include "FlyingObject.hpp"

class Missile : public FlyingObject{

    ///////////////
    // Constructeur
    // -------
    // * x, y : position dans l'écran
    // * size : diamètre du missile
    // * speed : vitesse de déplacement
    // * angle : orientation

    Missile(double x, double y, double size, double speed, double angle);



    ///////////////////////////////////////////////////////
    // déplace selon les vitesses de déplacement de l'objet
    // -------
    // Renvoie : un booléen indiquant s'il y a sortie des limites de l'écran
    bool Move(double screenWidth, double screenHeight);


private :
    double angle;



};

#endif MISSILE_HPP
