#ifndef MODEL_HPP
#define MODEL_HPP

#include "FlyingObject.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "framework.hpp"
#include <vector>

class Model {


public :

    Model(Framework* framework, double shipSize, int nbAsteroids, double minSize, double maxSize,double asteroidSpeed);
    int Update(Framework* framework);
    //------------Actions :
    void ChooseAction(int action);
    void SpeedUp();
    void SpeedDown();
    void RotateRight();
    void RotateLeft();
    void ShootMissile();
    void InitializeAsteroids(Framework* framework, double minSize, double maxSize, double asteroidSpeed);
    SDL_Texture* GetRandomAsteroidTexture(Framework* framework);

    //----------Getters :
    std::vector<FlyingObject *> GetFlyingObjects();
    std::vector<FlyingObject *> GetFlyingObjectsInGame(std::vector<FlyingObject*>& allFlyingObjects, Framework* framework);



private :
    //List of Flying Objects
    std::vector<FlyingObject *> flyingObjects;
    std::vector<Asteroid *> asteroids;

    bool missileNotOnScreen;
    //Flying Objects
    Spaceship* spaceship;
    Missile* missile;
    int nbAsteroids;



};



#endif
