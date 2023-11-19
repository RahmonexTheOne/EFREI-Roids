#include <iostream>
#include "../include/hpp/Controller.hpp"


using namespace std;

//------------------Constructors :

Controller::Controller(){
    //Create The Level
    this->level = new Level();
    level->CreateLevel();
    //Create Model View Framework with the level arguments
    this->view = new View(framework,level->GetActualLevel());
    this->framework = new Framework(30,level->GetSpaceshipSize(),10);
    shipImage = "spaceship.bmp";
    shipImageWarning = "redSpaceship.bmp";
    this->model = new Model(framework,level->GetSpaceshipSize(),level->GetNbAsteroids(), level->GetAsteroidMinSize(), level->GetAsteroidMaxSize(), level->GetAsteroidSpeed(), shipImage, shipImageWarning);
    //Interfaces
    this->menu = new Menu(framework);
    this->settingsMenu = new SettingsMenu(framework);
    this->gameOver = new GameOver(framework);
    this->renderer = framework->GetRenderer();
    //Load background
    backgroundTexture = framework->GetTexture("fondjeu.bmp");
}



void Controller::LaunchGame() {

    int menuResult = menu->ShowMenu();
    while(true){
        if(menuResult==1){
            int settingsMenuResult = settingsMenu->ShowSettingsMenu();
            if (settingsMenuResult==-1){
                MenuPlay();
            }
            else if(settingsMenuResult == 1){
                shipImage = "spaceship.bmp";
                shipImageWarning = "redSpaceship.bmp";
                framework->SetShipTexture(shipImage,shipImageWarning);
            }
            else if(settingsMenuResult == 2){
                shipImage = "spaceship2.bmp";
                shipImageWarning = "redSpaceship2.bmp";
                framework->SetShipTexture(shipImage,shipImageWarning);
            }
            else if(settingsMenuResult == 3){
                shipImage = "spaceship3.bmp";
                shipImageWarning = "redSpaceship3.bmp";
                framework->SetShipTexture(shipImage,shipImageWarning);
            }
            else if(settingsMenuResult == 4){
                shipImage = "spaceship4.bmp";
                shipImageWarning = "redSpaceship4.bmp";
                framework->SetShipTexture(shipImage,shipImageWarning);
            }
        }

    }



}

void Controller::MenuPlay(){
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
                if (win){
                    level->SetActualLevel(level->GetActualLevel()+1);
                }
                boolGameOver = true;

                int gameOverResult = gameOver->ShowGameOver(win);

                if (gameOverResult == 0) {
                    // Restart the game
                    Reset();
                    boolGameOver = false;
                } else if (gameOverResult == 1) {
                    // Go back to the main menu
                    LaunchGame();
                    if (menuResult != 0) {
                        // Exit the game loop
                        boolGameOver = true;
                    }
                }
            }

            // Render the background
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

            // Refresh the view
            view->Refresh(model->GetFlyingObjects(), framework);
        }
    }
}

void Controller::Reset() {
    //Create The Level
    level->CreateLevel();
    //Create Model View Framework with the level arguments
    this->view = new View(framework,level->GetActualLevel());
    this->framework = new Framework(30,level->GetSpaceshipSize(),10);
    this->model = new Model(framework,level->GetSpaceshipSize(),level->GetNbAsteroids(), level->GetAsteroidMinSize(), level->GetAsteroidMaxSize(), level->GetAsteroidSpeed(), shipImage, shipImageWarning);
    //Interfaces
    this->menu = new Menu(framework);
    this->gameOver = new GameOver(framework);
    this->renderer = framework->GetRenderer();
    //Load background
    backgroundTexture = framework->GetTexture("fondjeu.bmp");
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

}


