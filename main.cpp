#include <iostream>
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
    bool GameRunning = true;

    //---------------- Initialize FrameWork :
    Framework window(20,60,10);
    //-----------------------------------------

    //----------------Create Missile :
    Spaceship* spaceship = new Spaceship(window.GetScreenWidth()/2,window.GetScreenHeight()/2,60,0);
    //-------------------------------

    //-----------------Create Asteroid :
    Asteroid* asteroidOne= new Asteroid(150, 500,100, 10, 3);
    Asteroid* asteroidTwo = new Asteroid(1600,window.GetScreenHeight(), 100, -5, -2);
    //----------------------------------


    //----------------Create Missile :
    Missile* missileTest = new Missile(window.GetScreenWidth()/2, window.GetScreenHeight()/2,10, 10, 0);
    //-------------------------------

    window.Update();



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

    }
    //-------------------------------------------------------------------------------------------------------------------------

    return 0;
}