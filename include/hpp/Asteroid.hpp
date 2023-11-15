#ifndef ASTEROID_HPP_
#define ASTEROID_HPP_

#include <stdio.h>
#include <string>
#include "FlyingObject.hpp"
#include "framework.hpp"

class Asteroid : public FlyingObject{

public :

    //---------------------Constructeur :
    // -------
    // * x, y : position dans l'écran
    // * size : diamètre de l'objet
    // * xSpeed, ySpeed : vecteur de vitesse de l'objet
    Asteroid(double x, double y, double size, double speed, double angle, int nbExplosions, SDL_Texture* texture);

    //////////
    //---------------------Getters :
    SDL_Texture* GetTexture();
    std::string GetTypeName() const override;
    double GetNbExplosionsLeft();


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
    SDL_Texture* texture;
    int nbExplosionsLeft;

};

#endif


