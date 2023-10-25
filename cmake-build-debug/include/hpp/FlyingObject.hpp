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
    FlyingObject(double x, double y, double size);

    //----
    /////////////////////////////
    // Détermination de collision
    // calcul basé sur l'hypothèse que les objets sont sphériques
    // -------
    // * o1, o2 : les deux objets à tester
    // -------
    // Renvoie : true si les deux objets se touchent, false sinon
    static bool Collide(FlyingObject *o1, FlyingObject *o2);
    //----


    //////////
    //---------------------Getters :
    double GetX();
    double GetY();
    double GetSize();
    virtual std::string GetTypeName() const;

    //////////
    //---------------------Setters :
    void SetX(double x);
    void SetY(double y);
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

    double DegToRad(double angle);


private :
    //-----------Cordonées de l'asteroide :
    double x;
    double y;
    double size;

};

#endif
