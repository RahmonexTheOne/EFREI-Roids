#include <SDL_ttf.h>
#include "../include/hpp/SettingsMenu.hpp"

SettingsMenu::SettingsMenu(Framework* framework) {
    this->framework = framework;
    this->renderer = framework->GetRenderer();
    //framework->PlayBackgroundMusic("assets/sound/backgroundMusic.wav");
    LoadTextures();
    // Define button positions and sizes
    mainMenuButtonRect = {100, 900, 250, 87};
    spaceship1ButtonRect = {150, 100, 200, 250};
    spaceship2ButtonRect = {390, 100, 200, 250};
    spaceship3ButtonRect = {640, 100, 200, 250};
    spaceship4ButtonRect = {890, 100, 200, 250};
}

SettingsMenu::~SettingsMenu() {
    //Destroy the buttons
    SDL_DestroyTexture(mainMenuButtonTexture);
    SDL_DestroyTexture(spaceship1ButtonTexture);
    SDL_DestroyTexture(spaceship2ButtonTexture);
    SDL_DestroyTexture(spaceship3ButtonTexture);
    SDL_DestroyTexture(spaceship4ButtonTexture);
    //Destroy the background
    SDL_DestroyTexture(backgroundTexture);
}


void SettingsMenu::LoadTextures() {
    //Load button images
    mainMenuButtonTexture = framework->GetTexture("quitButton.bmp");
    spaceship1ButtonTexture = framework->GetTexture("cardSpaceship.bmp");
    spaceship2ButtonTexture = framework->GetTexture("cardSpaceship2.bmp");
    spaceship3ButtonTexture = framework->GetTexture("cardSpaceship3.bmp");
    spaceship4ButtonTexture = framework->GetTexture("cardSpaceship4.bmp");

    //Load background
    backgroundTexture = framework->GetTexture("fondjeu.bmp");

}

int SettingsMenu::ShowSettingsMenu() {
    bool inSettingsMenu = true;
    SDL_Event e;

    while (inSettingsMenu) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return -1; //Quit the game
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                if (mouseX >= mainMenuButtonRect.x && mouseX < (mainMenuButtonRect.x + mainMenuButtonRect.w) &&
                           mouseY >= mainMenuButtonRect.y && mouseY < (mainMenuButtonRect.y + mainMenuButtonRect.h)) {
                    //Main menu the game
                    return -1;
                }
                else if (mouseX >= spaceship1ButtonRect.x && mouseX < (spaceship1ButtonRect.x + spaceship1ButtonRect.w) &&
                    mouseY >= spaceship1ButtonRect.y && mouseY < (spaceship1ButtonRect.y + spaceship1ButtonRect.h)) {
                    return 1;
                }
                else if (mouseX >= spaceship2ButtonRect.x && mouseX < (spaceship2ButtonRect.x + spaceship2ButtonRect.w) &&
                         mouseY >= spaceship2ButtonRect.y && mouseY < (spaceship2ButtonRect.y + spaceship2ButtonRect.h)) {
                    return 2;
                }
                else if (mouseX >= spaceship3ButtonRect.x && mouseX < (spaceship3ButtonRect.x + spaceship3ButtonRect.w) &&
                         mouseY >= spaceship3ButtonRect.y && mouseY < (spaceship3ButtonRect.y + spaceship3ButtonRect.h)) {
                    return 3;
                }
                else if (mouseX >= spaceship4ButtonRect.x && mouseX < (spaceship4ButtonRect.x + spaceship4ButtonRect.w) &&
                         mouseY >= spaceship4ButtonRect.y && mouseY < (spaceship4ButtonRect.y + spaceship4ButtonRect.h)) {
                    return 4;
                }
            }
        }

        RenderSettingsMenu();
    }

    return 0;
}

void SettingsMenu::RenderSettingsMenu() {
    //Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    //Render the background GIF
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    //Render buttons
    SDL_RenderCopy(renderer, mainMenuButtonTexture, NULL, &mainMenuButtonRect);
    SDL_RenderCopy(renderer, spaceship1ButtonTexture, NULL, &spaceship1ButtonRect);
    SDL_RenderCopy(renderer, spaceship2ButtonTexture, NULL, &spaceship2ButtonRect);
    SDL_RenderCopy(renderer, spaceship3ButtonTexture, NULL, &spaceship3ButtonRect);
    SDL_RenderCopy(renderer, spaceship4ButtonTexture, NULL, &spaceship4ButtonRect);


    //Update the screen
    SDL_RenderPresent(renderer);
}
