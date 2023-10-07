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

    int input = framework->GetInput();

    if(input!= SDLK_ESCAPE){
        model->ChooseAction(input);
        model->Update();
        view->Refresh(model->GetFlyingObjects(),framework,model);
    }
    else{

    }


}

