#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <stdio.h>
#include <string>
#include "Model.hpp"
#include "View.hpp"
#include "framework.hpp"
#include "Menu.hpp"
#include "GameOver.hpp"
#include "Level.hpp"
#include "SettingsMenu.hpp"


class Controller {


public :

    //---------------------Constructor :
    Controller();

    void LaunchGame();
    void Reset();

    //-------------Getters :
    Framework* GetFramework();




private :
    Model* model;
    Framework* framework;
    View* view;
    Menu* menu;
    SettingsMenu* settingsMenu;
    Level* level;
    GameOver* gameOver;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;
    std::string shipImage;
    std::string shipImageWarning;

    void MenuPlay();
};


#endif
