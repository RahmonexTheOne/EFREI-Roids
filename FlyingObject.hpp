#ifndef FLYINGOBJECT_HPP
#define FLYINGOBJECT_HPP

#include <stdio.h>
#include <string>

class FlyingObject {

public :

    //---------------------Constructeur :
    // -------
    // * x, y : position dans l'écran
    // * size : diamètre de l'objet
    // * xSpeed, ySpeed : vecteur de vitesse de l'objet
    FlyingObject(double x, double y, double size, double xSpeed, double ySpeed);


    //////////
    //---------------------Getters :
    double GetX();
    double GetY();
    double GetXSpeed();
    double GetYSpeed();
    double GetSize();

    //////////
    //---------------------Setters :
    void SetX(double xSpeed);
    void SetY(double ySpeed);
    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);
    void SetSize(double size);




    /////////////////////////
    //-------------------------Déplacement de l'objet :
    // déplace selon le vecteur de vitesse de l'objet
    void Move();


    ///////////////////////////////////////
    // Déplacement de l'objet avec réentrée
    // déplace selon le vecteur de vitesse de l'objet
    // en cas de sortie des limites de l'écran, fait réapparaitre l'objet
    // de l'autre côté
    // -------
    // * screenWidth, screenHeight : taille de l'écran
    void Move(double screenWidth, double screenHeight);


private :
    //-----------Cordonées de l'asteroide :
    double x;
    double y;
    double size;
    //----------Coordonnées du vecteur vitesse :
    double xSpeed;
    double ySpeed;



};

#endif FLYINGOBJECT_HPP
