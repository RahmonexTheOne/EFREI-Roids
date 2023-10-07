#include <iostream>
#include "Controller.hpp"

using namespace std;

//------------------Constructors :

Controller::Controller(int fps, int shipSize, int missileSize){

    this->view = new View(framework);
    this->framework = new Framework(fps,shipSize,missileSize);
    this->model = new Model(framework->GetScreenWidth(),framework->GetScreenHeight());

}


void Controller::LaunchGame() {

    framework->GetInput();
    bool gameIsRunning = true;

    while(gameIsRunning){
        model->ChooseAction(framework->GetInput());
        model->Update(framework);
        view->Refresh(model->GetFlyingObjects(),framework);
        if(framework->GetInput() == SDLK_ESCAPE){
            gameIsRunning = false;
        }
    }



}

