#include <iostream>
#include <random>
#include "View.hpp"
//#include "SDL_ttf.h"

using namespace std;

//------------------Constructors :
View::View(Framework* framework) {
    startTime = SDL_GetTicks();
    elapsedTime = 0;

}

void View::RenderTopBar(Framework* framework, Spaceship* spaceship) {
    // Render the background for the top bar
    SDL_Rect topBarRect = {0, 0, framework->GetScreenWidth(), 50};
    SDL_SetRenderDrawColor(framework->GetRenderer(), 8, 12, 20, 255);
    SDL_RenderFillRect(framework->GetRenderer(), &topBarRect);
    int elapsedTimeX = framework->GetScreenWidth()-50;

    /*// Render the level text
    std::string levelText = "Level: 1";
    RenderText(framework, levelText, 10,15);

    // Render the shield health text
    std::string shieldText = "Shield: " + std::to_string(spaceship->GetShieldLevel());
    RenderText(framework, shieldText, elapsedTimeX-100, 15);

    // Render the invincibility time text
    std::string invincibilityText = "Invincibility: " + std::to_string(spaceship->GetInvincible()) + "s";
    RenderText(framework, invincibilityText, elapsedTimeX-50, 15);

    // Render the elapsed time text
    std::string elapsedTimeText = "Time: " + std::to_string(elapsedTime) + "s";
    RenderText(framework, elapsedTimeText, elapsedTimeX, 15);*/
}



void View::Refresh(std::vector<FlyingObject *> flyingObjects,Framework* framework) {
    // Calculate the elapsed time
    Uint32 currentTime = SDL_GetTicks();
    elapsedTime = (currentTime - startTime) / 1000;


    //----------------Test the list of FlyingObjects:
    for (FlyingObject* object : flyingObjects){
        if(object!=nullptr){
            //For an Asteroid :
            if(object->GetTypeName() == "Asteroid"){
                Asteroid* asteroid = dynamic_cast<Asteroid*>(object); // Cast to Asteroid
                framework->DrawAsteroid(asteroid->GetX(),asteroid->GetY(),asteroid->GetSize(),asteroid->GetTexture());
                std::cout << flyingObjects.size() << std::endl;
            }

            //For a Missile :
            else if(object->GetTypeName() == "Missile"){
                framework->DrawMissile(object->GetX(),object->GetY());
            }

            //For a Spaceship ??(how to get angle warning and shield if its not explicit in flyingobject)
            else if(object->GetTypeName() == "Spaceship"){
                Spaceship* spaceship = dynamic_cast<Spaceship*>(object); // Cast to Spaceship
                framework->DrawShip(spaceship->GetX(),spaceship->GetY(),spaceship->GetAngle(),spaceship->GetShieldLevel(),spaceship->GetWarning());
                RenderTopBar(framework, spaceship);
            }
        }



    }
    framework->Update();

}

