#include <iostream>
#include "Controller.hpp"

using namespace std;


int WinMain(int argc, char* argv[])
{


    std::cout << "Oppening EFREI-Roids !" << std::endl;
    Controller controller(20,60,10);
    controller.LaunchGame();

    return 0;
}