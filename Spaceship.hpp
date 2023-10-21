#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <chrono>
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
    double GetWarning();
    double GetShieldLevel();
    std::string GetTypeName() const override;

    void SetAngle(double angle);
    void SetSpeed(double speed);
    void SetShieldLevel(double shieldLevel);

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

    ////////////////////////////////////////
// Indique si le vaisseau est invincible
// -------
// Renvoie:  true si le vaisseau est dans une période d'invincibilité, false sinon
    bool GetInvincible();

///////////////////////////////////////
// Place le vaisseau en mode invincible
// -------
// * duration : durée pendant laquelle le vaisseau est invincible
    void SetInvincibleFor(double duration);

    void Move(double screenWidth, double screenHeight);

private :
    double angle;
    double speed;
    bool warning;
    double shieldLevel;
    std::chrono::time_point<std::chrono::system_clock> invincibilityEndTime;




};


#endif SPACESHIP_HPP
