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

    Model(Framework* framework);
    int Update(Framework* framework);
    //------------Actions :
    void ChooseAction(int action);
    void SpeedUp();
    void SpeedDown();
    void RotateRight();
    void RotateLeft();
    void ShootMissile();
    void InitializeAsteroids(Framework* framework);
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
