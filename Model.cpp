#include <iostream>
#include <SDL_keycode.h>
#include <random>
#include "Model.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"

using namespace std;

//-------------------------------------------------------------------Constructors :
Model::Model(int screenWidth, int screenHeight) {

    //----------------Create Missile :
    this->spaceship = new Spaceship(screenWidth/2,screenHeight/2,60,0);
    //-------------------------------

    //-----------------Create Asteroid :

    this->nbAsteroids = 5;
    for(int i = 0; i <nbAsteroids; i++){
        InitializeAsteroids(screenWidth,screenHeight);
    }

    //----------------------------------

    //----------------Create Missile :
    this->missileTest = new Missile(screenWidth/2, screenHeight/2,10, 10, 0);
    //-------------------------------

    //Adding them to the flyingObjects list
    flyingObjects.push_back(spaceship);
    flyingObjects.push_back(missileTest);


}
//-----------------------------------------------------------------------------





//-----------------------------------------------------------------Update :

void Model::Update(Framework* framework) {

    //Update the list of Objects :
    Model::GetFlyingObjectsInGame(flyingObjects, framework);
    //Move the objects (different move methods so we need dynamic cast):
    for (FlyingObject* object : flyingObjects){
        if(object!=nullptr){
            if (object->GetTypeName()=="Missile"){
                Missile* missile = dynamic_cast<Missile*>(object); // Cast to Missile
                missile->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
            else if(object->GetTypeName()=="Asteroid"){
                Asteroid* asteroid = dynamic_cast<Asteroid*>(object); // Cast to Asteroid
                asteroid->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
            else if(object->GetTypeName()=="Spaceship"){
                Spaceship* spaceship = dynamic_cast<Spaceship*>(object); // Cast to Spaceship
                spaceship->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
        }

    }

    std::vector<FlyingObject*> objectsToRemove;
    // Test collisions between all missiles and all asteroids
    for (int i = 0; i < flyingObjects.size(); ++i) {
        FlyingObject* object = flyingObjects[i];
        if (object != nullptr && object->GetTypeName() == "Missile") {
            for (int j = 0; j < flyingObjects.size(); ++j) {
                FlyingObject* otherObject = flyingObjects[j];
                if (otherObject != nullptr && otherObject->GetTypeName() == "Asteroid") {
                    bool collision = FlyingObject::Collide(object, otherObject);
                    if (collision) {
                        // Remove otherObject from the vector
                        flyingObjects.erase(flyingObjects.begin() + j);
                        delete otherObject;
                    }
                }
            }
        }
    }

}
//---------------------------------------------------------------------------------------






//-----------------Actions :
void Model::ChooseAction(int action) {
    switch (action) {
        case SDLK_UP:
            Model::SpeedUp();
            break;
        case SDLK_DOWN:
            Model::SpeedDown();
            break;
        case SDLK_RIGHT:
            Model::RotateRight();
            break;
        case SDLK_LEFT:
            Model::RotateLeft();
            break;
        case SDLK_ESCAPE:
            SDL_Quit();
            exit(0);
            break;
    }
}


void Model::SpeedUp() {
    spaceship->SpeedUp(10);
}

void Model::SpeedDown() {
    spaceship->SpeedDown(10);
}

void Model::RotateRight() {
    spaceship->Rotate(15);
}

void Model::RotateLeft() {
    spaceship->Rotate(-15);
}

//------------------------------------------





//---------------------Getters:
std::vector<FlyingObject *> Model::GetFlyingObjects() {
    return flyingObjects;
}



std::vector<FlyingObject*> Model::GetFlyingObjectsInGame(std::vector<FlyingObject*>& allFlyingObjects, Framework* framework) {

    // Check all the objects in the game
    for (auto it = flyingObjects.begin(); it != flyingObjects.end();) {
        FlyingObject* object = *it;

        // Check if the object is a missile
        if (object->GetTypeName() == "Missile") {
            Missile* missile = dynamic_cast<Missile*>(object);

            // Check if the missile is not on the screen
            if (missile->NotOnScreen(framework->GetScreenWidth(), framework->GetScreenHeight())) {
                delete missile;
                it = flyingObjects.erase(it); // Remove the missile from flyingObjects
                continue;
            }
        }
        ++it;

    }

    return flyingObjects;
}

void Model::InitializeAsteroids(double screenWidth, double screenHeight) {
    //---Espace de creation :
    std::uniform_int_distribution<int> spaceDistribution(0, 7);
    //std::default_random_engine generator;
    std::random_device generator;
    int spaceToUse = spaceDistribution(generator);
    std::uniform_real_distribution<double> xDistribution(0.0, screenWidth);
    std::uniform_real_distribution<double> yDistribution(0.0, screenHeight);

    //---Assignement des espaces :
    if(spaceToUse == 0){
        std::uniform_real_distribution<double> xDistribution(0.0,screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(0.0,screenHeight/3);
    }
    else if(spaceToUse == 1){
        std::uniform_real_distribution<double> xDistribution(screenWidth/3,2*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(0.0,screenHeight/3);
    }
    else if(spaceToUse == 2){
        std::uniform_real_distribution<double> xDistribution(2*screenWidth/3,3*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(0.0,screenHeight/3);
    }
    else if(spaceToUse == 3){
        std::uniform_real_distribution<double> xDistribution(0.0,screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(screenHeight/3,2*screenHeight/3);
    }
    else if(spaceToUse == 4){
        std::uniform_real_distribution<double> xDistribution(2*screenWidth/3,3*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(screenHeight/3,2*screenHeight/3);
    }
    else if(spaceToUse == 5){
        std::uniform_real_distribution<double> xDistribution(0.0,screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(2*screenHeight/3,3*screenHeight/3);
    }
    else if(spaceToUse == 6){
        std::uniform_real_distribution<double> xDistribution(screenWidth/3,2*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(2*screenHeight/3,3*screenHeight/3);
    }
    else if(spaceToUse == 7){
        std::uniform_real_distribution<double> xDistribution(2*screenWidth/3,3*screenWidth/3);
        std::uniform_real_distribution<double> yDistribution(2*screenHeight/3,3*screenHeight/3);
    }

    double xToUse = xDistribution(generator);
    double yToUse = yDistribution(generator);

    Asteroid* asteroidGenerated = new Asteroid(xToUse,yToUse,100, 10, 3);
    flyingObjects.push_back(asteroidGenerated);
    std::cout<<"Generated an asteroid with x and y values " << xToUse << "," << yToUse << std::endl;
}

//-------------------------------
