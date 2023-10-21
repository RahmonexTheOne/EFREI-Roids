#include <iostream>
#include "Controller.hpp"

using namespace std;


int WinMain(int argc, char* argv[])
{


    std::cout << "Oppening EFREI-Roids !" << std::endl;
    Controller controller(30,50,10);
    controller.LaunchGame();

    return 0;
}