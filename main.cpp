#include <iostream>
#include "framework.hpp"
#include "asteroid.hpp"
#include "Missile.hpp"
#include <vector>

using namespace std;


int WinMain(int argc, char* argv[])
//int main(int argc, char* argv[])
{

    std::cout << "Oppening EFREI-Roids !" << std::endl;

    //---------------- Initialize FrameWork :
    Framework window(20,20,10);

    //-----------------Create Asteroid :
    Asteroid asteroidOne(150, 500,100, 10, 3);
    Asteroid asteroidTwo(1600,window.GetScreenHeight(), 100, -5, -10);
    //----------------Create Missile :
    Missile missileOne(window.GetScreenWidth()/2, window.GetScreenHeight()/2,10, 10, 3);
    //Missile* missiles = new Missile(window.GetScreenWidth()/2, window.GetScreenHeight()/2,10, 10, 3);
    window.Update();
    vector<Missile*> missileList;
    missileList.push_back(&missileOne);



    while(window.GetInput()!= SDLK_ESCAPE){

        //Asteroids :
        window.DrawAsteroid(asteroidOne.GetX(),asteroidOne.GetY(),asteroidOne.GetSize());
        window.DrawAsteroid(asteroidTwo.GetX(),asteroidTwo.GetY(),asteroidTwo.GetSize());
        asteroidOne.Move(window.GetScreenWidth(), window.GetScreenHeight());
        asteroidTwo.Move(window.GetScreenWidth(), window.GetScreenHeight());
        //---------------------------------------------------------------------------------------

        //Missile :
        //window.DrawMissile(missileOne.GetX(),missileOne.GetY());
        //missileOne.Move(window.GetScreenWidth(),window.GetScreenHeight());
        window.DrawMissile(missileList[0]->GetX(),missileList[0]->GetY());
        missileList[0]->Move(window.GetScreenWidth(),window.GetScreenHeight());

        /*if(missileList[0]->Move(window.GetScreenWidth(),window.GetScreenHeight())==false){
            delete missileList[0];
        }*/

        //--------------------------------------------------------------------------------------


        window.Update();

    }

    return 0;
}