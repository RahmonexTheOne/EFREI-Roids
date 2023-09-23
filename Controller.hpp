#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <stdio.h>
#include <string>
#include "Model.hpp"
#include "View.hpp"
#include "Framework.hpp"


class Controller {


public :

    //---------------------Constructor :
    Controller(int fps, int shipSize, int missileSize);


    void LaunchGame();




private :
    Model* model;
    Framework* framework;
    View* view;

};


#endif CONTROLLER_HPP
