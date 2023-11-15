#include <iostream>
#include "../include/hpp/Controller.hpp"

using namespace std;


int WinMain(int argc, char* argv[])
{
    std::cout << "Oppening EFREI-Roids !" << std::endl;
    Controller controller;
    controller.LaunchGame();

    return 0;
}