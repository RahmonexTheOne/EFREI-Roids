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
    bool win;
    bool boolGameOver = false;

    if (menuResult == 0) {
        while (!boolGameOver) { // Change to a game loop controlled by the gameOver flag
            model->ChooseAction(framework->GetInput());

            int resultModelUpdate = model->Update(framework);

            if (resultModelUpdate == -1) {
                win = false;
                boolGameOver = true;
                // When the game is over, show the game over menu
                int gameOverResult = gameOver->ShowGameOver(win);

                if (gameOverResult == 0) {
                    // Restart the game
                    boolGameOver = false;
                    win = false;
                } else if (gameOverResult == 1) {
                    // Go back to the main menu
                    menuResult = menu->ShowMenu();
                    if (menuResult != 0) {
                        boolGameOver = true; // Exit the game loop
                    }
                }
            } else if (resultModelUpdate == 0) {
                // Continue the game
            } else if (resultModelUpdate == 1){
                // Win
                win = true;
                boolGameOver = true;
                // When the game is over, show the game over menu
                int gameOverResult = gameOver->ShowGameOver(win);

                if (gameOverResult == 0) {
                    // Restart the game
                    boolGameOver = false;
                    win = false;
                } else if (gameOverResult == 1) {
                    // Go back to the main menu
                    menuResult = menu->ShowMenu();
                    std::cout << "Trying to go to main menu" << std::endl;
                    if (menuResult != 0) {
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


