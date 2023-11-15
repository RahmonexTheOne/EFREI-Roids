#include <sstream>
#include <iostream>
#include <fstream>
#include "../include/hpp/Level.hpp"

using namespace std;

Level::Level() {
    spaceshipSize = 0;
    nbAsteroids = 0;
    asteroidMinSize = 0;
    asteroidMaxSize = 0;
    invincibilityDuration = 0;
    actualLevel = 1;
    asteroidSpeed =0;
}

void Level::CreateLevel() {
    //Open the actual level text file
    stringstream filePath;
    filePath << "../Levels/level" << actualLevel << ".txt";

    ifstream levelFile(filePath.str().c_str(), ios::in);
    if(levelFile) {
        cout << "Level " << actualLevel << " is going to be loaded" << endl;
        levelFile >> spaceshipSize >> nbAsteroids >> asteroidSpeed >> asteroidMinSize >> asteroidMaxSize >> invincibilityDuration;
        levelFile.close();
        return;
    }
    cout << "Level " << actualLevel << " has not been found !" << endl;
    throw exception();
}


//---------------------------------Getters :
int Level::GetActualLevel() {
    return actualLevel;
}

double Level::GetSpaceshipSize() {
    return spaceshipSize;
}

int Level::GetNbAsteroids() {
    return nbAsteroids;
}

double Level::GetAsteroidMaxSize() {
    return asteroidMaxSize;
}

double Level::GetAsteroidMinSize() {
    return asteroidMinSize;
}

double Level::GetInvincibilityDuration() {
    return invincibilityDuration;
}

//-----------------------Setters:
void Level::SetActualLevel(int newLevel) {
    actualLevel = newLevel;
}

double Level::GetAsteroidSpeed() {
    return asteroidSpeed;
}

