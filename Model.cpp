#include <iostream>
#include <SDL_keycode.h>
#include "Model.hpp"

using namespace std;

//------------------Constructors :

Model::Model() {


}
//-------------------------------





//----------------Update :

void Model::Update() {

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

//-------------------------------
