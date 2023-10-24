#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <stdio.h>
#include <string>
#include "Model.hpp"
#include "View.hpp"
#include "Framework.hpp"
#include "Menu.hpp"


class Controller {


public :

    //---------------------Constructor :
    Controller(int fps, int shipSize, int missileSize);

    void LaunchGame();

    //-------------Getters :
    Framework* GetFramework();




private :
    Model* model;
    Framework* framework;
    View* view;
    Menu* menu;
    SDL_Renderer* renderer;

};


#endif
