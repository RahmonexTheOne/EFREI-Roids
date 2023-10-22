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
    Asteroid(double x, double y, double size, double speed, double angle, int nbExplosions);

    //////////
    //---------------------Getters :
    double GetSpeed();
    double GetAngle();
    std::string GetTypeName() const override;
    double GetNbExplosionsLeft();

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


    ///////////////////////////////////////
    // Applique une explosion à l'astéroïde
    // Si l'astéroïde a encore des explosions autorisées, sa taille est diminuée,
    // et un nouvel astéroïde est créé
    // -------
    // * xSpeed, ySpeed : vecteur de vitesse du nouvel astéroïde si créé
    // -------
    // Renvoie :
    // * Si l'astéroïde a encore des explosions autorisées: Le nouvel astéroïde avec la même position et le vecteur de vitesse passé en paramètre
    // * Sinon : nullptr
    Asteroid * Explode(double speed, double angle);


private :
    double speed;
    double angle;
    int nbExplosionsLeft;

};

#endif ASTEROID_HPP_


