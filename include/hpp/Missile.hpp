#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "FlyingObject.hpp"

class Missile : public FlyingObject{

public :

    ///////////////
    // Constructor
    // -------
    // * x, y : position in the screen
    // * size : diamètre du missile
    // * speed : vitesse de déplacement
    // * angle : orientation
    Missile(double x, double y, double size, double speed, double angle);




    ///////////////
    // Destructor
    // -------
    ~Missile();



    ///////////////////////////////////////////////////////
    // déplace selon les vitesses de déplacement de l'objet
    // -------
    // Renvoie : un booléen indiquant s'il y a sortie des limites de l'écran
    void Move(double screenWidth, double screenHeight);

    bool NotOnScreen(double screenWidth, double screenHeight);

    std::string GetTypeName() const override;


private :



};

#endif
