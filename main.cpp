#include <iostream>
#include "Controller.hpp"
#include "framework.hpp"
#include "asteroid.hpp"
#include "Missile.hpp"
#include "Spaceship.hpp"
#include <vector>
#include <memory>

using namespace std;


int WinMain(int argc, char* argv[])
//int main(int argc, char* argv[])
{


    std::cout << "Oppening EFREI-Roids !" << std::endl;
    Controller controller(20,60,10);
    controller.LaunchGame();

    /*bool GameRunning = true;

    //--------------------------------------------------------------------------------------------------------------- Screen Update :
    while(GameRunning){


        //--------------------------- Spaceship :
        if (spaceship!=nullptr){

            window.DrawShip(spaceship->GetX(),spaceship->GetY(),spaceship->GetAngle(),1.0,false);

            switch (window.GetInput()) {
                case SDLK_d:
                    spaceship->Rotate(30);
                    break;
                case SDLK_q:
                    spaceship->Rotate(-30);
                    break;
                case SDLK_z:
                    spaceship->SpeedUp(10);
                    break;
                case SDLK_s:
                    spaceship->SpeedDown(10);
                    break;
                case SDLK_ESCAPE:
                    GameRunning=false;
                    break;
                default:
                    break;
            }
            spaceship->Move(window.GetScreenWidth(), window.GetScreenHeight());
        }
        //-------------------------------------------------------------------------------------------




        //---------------------------------------Asteroids :
        if(asteroidOne!=nullptr){
            window.DrawAsteroid(asteroidOne->GetX(),asteroidOne->GetY(),asteroidOne->GetSize());
            asteroidOne->Move(window.GetScreenWidth(), window.GetScreenHeight());
        }
        if(asteroidTwo!=nullptr){
            window.DrawAsteroid(asteroidTwo->GetX(),asteroidTwo->GetY(),asteroidTwo->GetSize());
            asteroidTwo->Move(window.GetScreenWidth(), window.GetScreenHeight());
        }
        //---------------------------------------------------------------------------------------




        //-------------------------------------Missile :
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



        //----------------------------------- Test de Collision :
        if(missileTest != nullptr && asteroidTwo != nullptr){
            bool collision = FlyingObject::Collide(missileTest,asteroidTwo);
            if(collision){
                delete asteroidTwo;
                asteroidTwo = nullptr;
            }
        }

        //--------------------------------------------------------------------------------------


        window.Update();

    }*/
    //-------------------------------------------------------------------------------------------------------------------------

    return 0;
}