#include <iostream>
#include <random>
#include "View.hpp"


using namespace std;

//------------------Constructors :
View::View(Framework* framework) {


}

void View::RenderTopBar(Framework* framework) {
    // Render the background for the top bar
    SDL_Rect topBarRect = {0, 0, framework->GetScreenWidth(), 100};
    SDL_SetRenderDrawColor(framework->GetRenderer(), 0, 14, 120, 255);
    SDL_RenderFillRect(framework->GetRenderer(), &topBarRect);

    // Render the shield health text
    /*std::string shieldText = "Shield: " + std::to_string(spaceship.GetShieldHealth());
    RenderText(shieldText, shieldTextX, topBarTextY);

    // Render the invincibility time text
    std::string invincibilityText = "Invincibility: " + std::to_string(spaceship.GetInvincibilityTime()) + "s";
    RenderText(invincibilityText, invincibilityTextX, topBarTextY);

    // Render the elapsed time text
    std::string elapsedTimeText = "Time: " + std::to_string(elapsedTime) + "s";
    RenderText(elapsedTimeText, elapsedTimeTextX, topBarTextY);*/
}





void View::Refresh(std::vector<FlyingObject *> flyingObjects,Framework* framework) {

    //----------------Test the list of FlyingObjects:
    for (FlyingObject* object : flyingObjects){
        RenderTopBar(framework);
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
            }
        }



    }
    framework->Update();

}
