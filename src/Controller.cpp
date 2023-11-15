#include <iostream>
#include "../include/hpp/Controller.hpp"


using namespace std;

//------------------Constructors :

Controller::Controller(int fps, int shipSize, int missileSize){
    this->view = new View(framework);
    this->framework = new Framework(fps,shipSize,missileSize);
    this->model = new Model(framework);
    this->menu = new Menu(framework);
    this->gameOver = new GameOver(framework);
    this->renderer = framework->GetRenderer();
    //Load background
    backgroundTexture = framework->GetTexture("fondjeu.bmp");
}



void Controller::LaunchGame() {
    int menuResult = menu->ShowMenu();

    while (menuResult == 0) {
        bool win = false;
        bool boolGameOver = false;

        while (!boolGameOver) {
            model->ChooseAction(framework->GetInput());
            int resultModelUpdate = model->Update(framework);

            if (resultModelUpdate == -1 || resultModelUpdate == 1) {
                // Game over (win or lose)
                win = (resultModelUpdate == 1);
                boolGameOver = true;

                int gameOverResult = gameOver->ShowGameOver(win);

                if (gameOverResult == 0) {
                    // Restart the game
                    boolGameOver = false;
                } else if (gameOverResult == 1) {
                    // Go back to the main menu
                    menuResult = menu->ShowMenu();
                    if (menuResult != 0) {
                        // Exit the game loop
                        boolGameOver = true;
                    }
                }
            }

            // Render the background GIF
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

            // Refresh the view
            view->Refresh(model->GetFlyingObjects(), framework);
        }
    }
}


