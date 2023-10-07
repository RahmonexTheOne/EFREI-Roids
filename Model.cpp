#include <iostream>
#include <SDL_keycode.h>
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
    this->asteroidOne= new Asteroid(150, 500,100, 10, 3);
    this->asteroidTwo = new Asteroid(1600,screenHeight, 100, -5, -2);
    //----------------------------------

    //----------------Create Missile :
    this->missileTest = new Missile(screenWidth/2, screenHeight/2,10, 10, 0);
    //-------------------------------


}
//-----------------------------------------------------------------------------





//----------------Update :

void Model::Update() {
//Move the objects :

}
//-------------------------------






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
    }
}


void Model::SpeedUp() {

}

void Model::SpeedDown() {

}

void Model::RotateRight() {

}

void Model::RotateLeft() {

}

//------------------------------------------





//---------------------Getters:
std::vector<FlyingObject *> Model::GetFlyingObjects() {
    return std::vector<FlyingObject *>();
}


std::vector<FlyingObject*> GetFlyingObjectsInGame(std::vector<FlyingObject*>& allFlyingObjects) {
    std::vector<FlyingObject*> flyingObjectsInGame;

    // Parcourez tous les objets du jeu
    for (FlyingObject* object : allFlyingObjects) {

        // Vérifiez si l'objet est un missile tiré par le joueur et toujours dans l'écran
        if ((typeid(object)== typeid(Missile))){
            /*if (object->Move(window.GetScreenWidth(), window.GetScreenHeight())) {
                flyingObjectsInGame.push_back(object);
            }*/
        }
        else{
            flyingObjectsInGame.push_back(object);
        }
    }

    return flyingObjectsInGame;
}

//-------------------------------
