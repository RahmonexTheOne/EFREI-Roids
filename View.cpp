#include <iostream>
#include "View.hpp"
#include "Controller.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "Spaceship.hpp"


using namespace std;

//------------------Constructors :

View::View(Framework* framework) {


}

void View::Refresh(std::vector<FlyingObject *> flyingObjects,Framework* framework, Model* model) {

    //----------------Test the list of FlyingObjects:
    for (int i=0; i<flyingObjects.size(); i++){
        //For an Asteroid :
        if(typeid(*flyingObjects[i]) == typeid(Asteroid)){
            framework->DrawAsteroid(flyingObjects[i]->GetX(),flyingObjects[i]->GetY(),flyingObjects[i]->GetSize());
        }
        //For a Missile :
        else if(typeid(*flyingObjects[i]) == typeid(Missile)){
            framework->DrawMissile(flyingObjects[i]->GetX(),flyingObjects[i]->GetY());
        }
        //For a Spaceship ??(how to get angle warning and shield if its not explicit in flyingobject)
        /*else if(typeid(*flyingObjects[i]) == typeid(Spaceship)){
            framework->DrawShip(flyingObjects[i]->GetX(),flyingObjects[i]->GetY(),flyingObjects[i]->GetSize(),flyingObjects[i]->GetAngle(),f);
        }*/

    }

}
