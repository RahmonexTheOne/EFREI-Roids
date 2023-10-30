#ifndef EFREI_ROIDS_GAMEOVER_HPP
#define EFREI_ROIDS_GAMEOVER_HPP

#include <SDL.h>
#include <vector>
#include "framework.hpp"

class GameOver {
public:
    GameOver(Framework* framework);
    ~GameOver();

    int ShowGameOver(bool win);

private:
    Framework* framework;
    bool win;
    SDL_Texture* replayButtonTexture;
    SDL_Texture* mainMenuButtonTexture;
    SDL_Texture* quitButtonTexture;
    SDL_Texture* backgroundTexture;

    SDL_Rect replayButtonRect;
    SDL_Rect mainMenuButtonRect;
    SDL_Rect quitButtonRect;

    SDL_Renderer* renderer;

    void LoadTextures();
    void RenderGameOver();
};


#endif


