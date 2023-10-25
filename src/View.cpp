#include <iostream>
#include <random>
#include "../include/hpp/View.hpp"
#include "SDL_ttf.h"
#include <sstream>
#include <iomanip>


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
    TTF_Font *headerFont = TTF_OpenFont("montserratRegular.ttf", 24);
    SDL_Color textColor = {255, 255, 255, 255};

    // Render the level text
    std::string levelText = "Level: 1";
    framework->RenderText( levelText, 10,10,headerFont,textColor);

    // Render the shield health text
    // Get the shield level as a double
    double shieldLevel = spaceship->GetShieldLevel();

    // Create a stringstream to format the double
    std::ostringstream ss;
    ss.imbue(std::locale(""));

    // Format the double with two decimal places and a comma as a separator
    ss << std::fixed << std::setprecision(2) << shieldLevel;

    // Get the formatted string
    std::string formattedShieldLevel = ss.str();

    // Replace the decimal point with a comma
    size_t decimalPointPos = formattedShieldLevel.find('.');
    if (decimalPointPos != std::string::npos) {
        formattedShieldLevel[decimalPointPos] = ',';
    }

    std::string shieldText = "Shield: " + formattedShieldLevel;
    framework->RenderText(shieldText, 200, 10,headerFont,textColor);

    // Render the invincibility time text
    //std::string invincibilityText = "Invincibility: " + std::to_string(spaceship->GetInvincible()) + "s";
    //framework->RenderText(invincibilityText, 350, 15,headerFont,textColor);

    // Render the elapsed time text
    std::string elapsedTimeText = "Time: " + std::to_string(elapsedTime) + "s";
    framework->RenderText(elapsedTimeText, framework->GetScreenWidth()-200, 10,headerFont,textColor);
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



