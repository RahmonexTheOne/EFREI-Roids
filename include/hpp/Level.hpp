#ifndef EFREI_ROIDS_LEVEL_HPP
#define EFREI_ROIDS_LEVEL_HPP

class Level {

public:

    Level();
    void CreateLevel();
    //To increment the level maybe ?
    void SetActualLevel(int newLevel);

    //Getters :
    int GetActualLevel();
    double GetSpaceshipSize();
    int GetNbAsteroids();
    double GetAsteroidMaxSize();
    double GetAsteroidMinSize();
    double GetAsteroidSpeed();
    double GetInvincibilityDuration();

private :
    int actualLevel;
    double spaceshipSize;
    int nbAsteroids;
    double asteroidMaxSize;
    double asteroidMinSize;
    double asteroidSpeed;
    double invincibilityDuration;

};

#endif
