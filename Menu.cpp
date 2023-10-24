#include "Menu.hpp"
#include "framework.hpp"

Menu::Menu(Framework* framework) {
    this->framework = framework;
    this->renderer = framework->GetRenderer();
    framework->PlayBackgroundMusic("backgroundMusic.wav");

    LoadTextures();

    // Define button positions and sizes
    playButtonRect = {100, 600, 250, 87};
    settingsButtonRect = {100, 700, 250, 87};
    quitButtonRect = {100, 800, 250, 87};
}

Menu::~Menu() {
    //Destroy the buttons
    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(settingsButtonTexture);
    SDL_DestroyTexture(quitButtonTexture);
    //Destroy the background
    SDL_DestroyTexture(backgroundTexture);
}


void Menu::LoadTextures() {
    //Load button images
    playButtonTexture = framework->GetTexture("playButton.bmp");
    settingsButtonTexture = framework->GetTexture("settingsButton.bmp");
    quitButtonTexture = framework->GetTexture("quitButton.bmp");

    //Load background
    backgroundTexture = framework->GetTexture("homescreen.bmp");

}

int Menu::ShowMenu() {
    bool inMenu = true;
    SDL_Event e;

    while (inMenu) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return -1; //Quit the game
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                if (mouseX >= playButtonRect.x && mouseX < (playButtonRect.x + playButtonRect.w) &&
                    mouseY >= playButtonRect.y && mouseY < (playButtonRect.y + playButtonRect.h)) {
                    //Start the game
                    return 0;
                } else if (mouseX >= settingsButtonRect.x && mouseX < (settingsButtonRect.x + settingsButtonRect.w) &&
                           mouseY >= settingsButtonRect.y && mouseY < (settingsButtonRect.y + settingsButtonRect.h)) {
                    //settings menu
                } else if (mouseX >= quitButtonRect.x && mouseX < (quitButtonRect.x + quitButtonRect.w) &&
                           mouseY >= quitButtonRect.y && mouseY < (quitButtonRect.y + quitButtonRect.h)) {
                    //Quit the game
                    return -1;
                }
            }
        }

        RenderMenu();
    }

    return 0;
}

void Menu::RenderMenu() {
    //Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    //Render the background GIF
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    //Render buttons
    SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
    SDL_RenderCopy(renderer, settingsButtonTexture, NULL, &settingsButtonRect);
    SDL_RenderCopy(renderer, quitButtonTexture, NULL, &quitButtonRect);

    //Update the screen
    SDL_RenderPresent(renderer);
}
