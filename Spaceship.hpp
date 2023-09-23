#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP


#include "FlyingObject.hpp"

class Spaceship : public FlyingObject {

public :

    ///////////////
    // Constructeur
    // -------
    // * x, y : coordonnées du centre de l'astéroïde, en pixels
    // * size : diamètre du vaisseau
    // * angle d'orientation
    Spaceship(double x, double y, double size, double angle);

    ~Spaceship();

    //////////
    // Getters
    double GetAngle();
    double GetSpeed();

    void SetAngle(double angle);
    void SetSpeed(double speed);

    ///////////////////////
    // Accélère le vaisseau
    // -------
    // * accelerationFactor : le facteur d'accéleration appliqué
    void SpeedUp(double accelerationFactor);

    ///////////////////////
    // Décélère le vaisseau
    // -------
    // * decelerationFactor : le facteur de décéleration appliqué
    void SpeedDown(double decelerationFactor);

    ///////////////////////////
    // Fait pivoter le vaisseau
    // -------
    // * angle : l'angle de rotation, en degrés.
    void Rotate(double angle);
    double DegToRad(double angle);

    void Move(double screenWidth, double screenHeight);

private :
    double angle;
    double speed;


};


#endif SPACESHIP_HPP
