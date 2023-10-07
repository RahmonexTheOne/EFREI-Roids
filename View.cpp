#include <iostream>
#include "View.hpp"


using namespace std;

//------------------Constructors :

View::View(Framework* framework) {


}

void View::Refresh(std::vector<FlyingObject *> flyingObjects,Framework* framework) {

    //----------------Test the list of FlyingObjects:
    for (FlyingObject* object : flyingObjects){

        //For an Asteroid :
        if(object->GetTypeName() == "Asteroid"){
            framework->DrawAsteroid(object->GetX(),object->GetY(),object->GetSize());
            std::cout << flyingObjects.size() << std::endl;
        }

        //For a Missile :
        else if(object->GetTypeName() == "Missile"){
            framework->DrawMissile(object->GetX(),object->GetY());
        }

        //For a Spaceship ??(how to get angle warning and shield if its not explicit in flyingobject)
        /*else if(flyingObjects[i]->GetTypeName() == "Spaceship"){
            framework->DrawShip(flyingObjects[i]->GetX(),flyingObjects[i]->GetY(),flyingObjects[i]->GetSize(),flyingObjects[i]->GetAngle(),f);
        }*/

    }
    framework->Update();

}
