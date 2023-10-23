#ifndef MENU_HPP
#define MENU_HPP

#include <SDL.h>
#include <vector>
#include "framework.hpp"

class Menu {
public:
    Menu(Framework* framework);
    ~Menu();

    int ShowMenu();

private:
    Framework* framework;
    SDL_Texture* playButtonTexture;
    SDL_Texture* settingsButtonTexture;
    SDL_Texture* quitButtonTexture;
    SDL_Texture* backgroundTexture;

    SDL_Rect playButtonRect;
    SDL_Rect settingsButtonRect;
    SDL_Rect quitButtonRect;

    SDL_Renderer* renderer;

    void LoadTextures();
    void RenderMenu();
};


#endif
