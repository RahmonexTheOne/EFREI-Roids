#include <iostream>
#include "framework.hpp"
#include "asteroid.hpp"


int WinMain(int argc, char* argv[])
//int main(int argc, char* argv[])
{

    std::cout << "Oppening EFREIRoids !" << std::endl;

    //---------------- Initialize FrameWork :
    Framework window(20,20,10);
    window.DrawMissile(window.GetScreenWidth()/2,window.GetScreenHeight()/2);

    //-----------------Create Asteroid :
    Asteroid asteroidOne(50,10,100,20,20);
    window.DrawAsteroid(asteroidOne.GetX(),asteroidOne.GetY(),asteroidOne.GetSize());
    window.Update();

    asteroidOne.Move();
    for(int i=0;i<100;i++){
        asteroidOne.Move();
        window.Update();
    }



    while(window.GetInput()!= SDLK_ESCAPE){

    }

    return 0;
}