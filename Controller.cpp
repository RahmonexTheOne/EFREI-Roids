#include <iostream>
#include "Controller.hpp"

using namespace std;

//------------------Constructors :

Controller::Controller(int fps, int shipSize, int missileSize){

    this->model = new Model();
    this->view = new View();
    this->framework = new Framework(fps,shipSize,missileSize);

}

void Controller::LaunchGame() {

    int input = framework->GetInput();
    model->ChooseAction(input);
    //model->Update();
    view->Refresh();

}