#include <SDL_ttf.h>
#include "../include/hpp/GameOver.hpp"
#include "../include/hpp/framework.hpp"

GameOver::GameOver(Framework* framework) {
    this->framework = framework;
    this->renderer = framework->GetRenderer();

    LoadTextures();

    // Define button positions and sizes
    replayButtonRect = {framework->GetScreenWidth()/2-125, 500, 250, 87};
    mainMenuButtonRect = {framework->GetScreenWidth()/2-125, 600, 250, 87};
    quitButtonRect = {framework->GetScreenWidth()/2-125, 700, 250, 87};
}

GameOver::~GameOver() {
    //Destroy the buttons
    SDL_DestroyTexture(replayButtonTexture);
    SDL_DestroyTexture(mainMenuButtonTexture);
    SDL_DestroyTexture(quitButtonTexture);
    //Destroy the background
    SDL_DestroyTexture(backgroundTexture);
}


void GameOver::LoadTextures() {
    //Load button images
    replayButtonTexture = framework->GetTexture("playButton.bmp");
    mainMenuButtonTexture = framework->GetTexture("settingsButton.bmp");
    quitButtonTexture = framework->GetTexture("quitButton.bmp");

    //Load background
    backgroundTexture = framework->GetTexture("fondjeuLost.bmp");

}

int GameOver::ShowGameOver(bool win) {
    bool inGameOver = true;
    SDL_Event e;
    if(win){
        backgroundTexture = framework->GetTexture("fondjeuWon.bmp");
    }
    else {
        backgroundTexture = framework->GetTexture("fondjeuLost.bmp");
    }

    while (inGameOver) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return -1; //Quit the game
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                if (mouseX >= replayButtonRect.x && mouseX < (replayButtonRect.x + replayButtonRect.w) &&
                    mouseY >= replayButtonRect.y && mouseY < (replayButtonRect.y + replayButtonRect.h)) {
                    //Start the game
                    return 0;
                } else if (mouseX >= mainMenuButtonRect.x && mouseX < (mainMenuButtonRect.x + mainMenuButtonRect.w) &&
                           mouseY >= mainMenuButtonRect.y && mouseY < (mainMenuButtonRect.y + mainMenuButtonRect.h)) {
                    //settings menu
                    return 1;
                } else if (mouseX >= quitButtonRect.x && mouseX < (quitButtonRect.x + quitButtonRect.w) &&
                           mouseY >= quitButtonRect.y && mouseY < (quitButtonRect.y + quitButtonRect.h)) {
                    //Quit the game
                    return -1;
                }
            }
        }

        RenderGameOver();
    }

    return 0;
}

void GameOver::RenderGameOver() {
    //Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    //Render the background
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    //Render buttons
    SDL_RenderCopy(renderer, replayButtonTexture, NULL, &replayButtonRect);
    SDL_RenderCopy(renderer, mainMenuButtonTexture, NULL, &mainMenuButtonRect);
    SDL_RenderCopy(renderer, quitButtonTexture, NULL, &quitButtonRect);


    //Update the screen
    SDL_RenderPresent(renderer);
}
