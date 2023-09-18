#include <iostream>
#include "framework.hpp"
#include "asteroid.hpp"
#include "Missile.hpp"
#include <vector>
#include <memory>

using namespace std;


int WinMain(int argc, char* argv[])
//int main(int argc, char* argv[])
{

    std::cout << "Oppening EFREI-Roids !" << std::endl;

    //---------------- Initialize FrameWork :
    Framework window(20,20,10);

    //-----------------Create Asteroid :
    Asteroid* asteroidOne= new Asteroid(150, 500,100, 10, 3);
    Asteroid* asteroidTwo = new Asteroid(1600,window.GetScreenHeight(), 100, -5, -2);


    //----------------Create Missile :
    Missile* missileTest = new Missile(window.GetScreenWidth()/2, window.GetScreenHeight()/2,10, 10, 3);

    window.Update();



    while(window.GetInput()!= SDLK_ESCAPE){

        //-------------------------------------------------------------------------------Asteroids :
        if(asteroidOne!=nullptr){
            window.DrawAsteroid(asteroidOne->GetX(),asteroidOne->GetY(),asteroidOne->GetSize());
            asteroidOne->Move(window.GetScreenWidth(), window.GetScreenHeight());
        }
        if(asteroidTwo!=nullptr){
            window.DrawAsteroid(asteroidTwo->GetX(),asteroidTwo->GetY(),asteroidTwo->GetSize());
            asteroidTwo->Move(window.GetScreenWidth(), window.GetScreenHeight());
        }
        //---------------------------------------------------------------------------------------




        //------------------------------------------------------------------------------Missile :
        if(missileTest != nullptr){
            window.DrawMissile(missileTest->GetX(),missileTest->GetY());
            //Check if the missile is on the screen
            if(!missileTest->Move(window.GetScreenWidth(), window.GetScreenHeight())){
                if (missileTest!=nullptr) {
                    delete missileTest;
                    missileTest = nullptr;
                }
            }
        }
        //-------------------------------------------------------------------------------------



        //------------------------------------------------------------ Test de Collision :
        if(missileTest != nullptr && asteroidTwo != nullptr){
            bool collision = FlyingObject::Collide(missileTest,asteroidTwo);
            if(collision){
                cout << "Collision entre missile et asteroid" << endl;
                delete asteroidTwo;
                asteroidTwo = nullptr;
            }
            else {
                cout << "Pas de collision entre missile et asteroid" << endl;
            }
        }

        //--------------------------------------------------------------------------------------


        window.Update();

    }

    return 0;
}