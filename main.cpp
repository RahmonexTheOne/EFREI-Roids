#include <iostream>
#include "framework.hpp"
#include "asteroid.hpp"


int WinMain(int argc, char* argv[])
//int main(int argc, char* argv[])
{

    std::cout << "Oppening EFREI-Roids !" << std::endl;

    //---------------- Initialize FrameWork :
    Framework window(20,20,10);
    window.DrawMissile(window.GetScreenWidth()/2,window.GetScreenHeight()/2);

    //-----------------Create Asteroid :
    Asteroid asteroidOne(150, 500,100, 10, 3);
    Asteroid asteroidTwo(1600,window.GetScreenHeight(), 100, -5, -10);
    window.Update();



    while(window.GetInput()!= SDLK_ESCAPE){

        window.DrawMissile(window.GetScreenWidth()/2,window.GetScreenHeight()/2);
        window.DrawAsteroid(asteroidOne.GetX(),asteroidOne.GetY(),asteroidOne.GetSize());
        window.DrawAsteroid(asteroidTwo.GetX(),asteroidTwo.GetY(),asteroidTwo.GetSize());

        asteroidOne.Move(window.GetScreenWidth(), window.GetScreenHeight());
        asteroidTwo.Move(window.GetScreenWidth(), window.GetScreenHeight());
        window.Update();

    }

    return 0;
}