#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include <SDL.h>
#include <vector>
#include "framework.hpp"

class SettingsMenu {
public:
    SettingsMenu(Framework* framework);
    ~SettingsMenu();

    int ShowSettingsMenu();

private:
    Framework* framework;
    SDL_Texture* mainMenuButtonTexture;
    SDL_Texture* spaceship1ButtonTexture;
    SDL_Texture* spaceship2ButtonTexture;
    SDL_Texture* spaceship3ButtonTexture;
    SDL_Texture* spaceship4ButtonTexture;
    SDL_Texture* backgroundTexture;


    SDL_Rect mainMenuButtonRect;
    SDL_Rect spaceship1ButtonRect;
    SDL_Rect spaceship2ButtonRect;
    SDL_Rect spaceship3ButtonRect;
    SDL_Rect spaceship4ButtonRect;


    SDL_Renderer* renderer;

    void LoadTextures();
    void RenderSettingsMenu();
};


#endif
