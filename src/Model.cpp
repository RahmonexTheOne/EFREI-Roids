#include <iostream>
#include <random>
#include "../include/hpp/Model.hpp"


using namespace std;

//-------------------------------------------------------------------Constructors :
Model::Model(Framework* framework, double shipSize, int nbAsteroids, double minSize, double maxSize, double asteroidSpeed) {

    //----------------Create Spaceship :
    this->spaceship = new Spaceship(framework->GetScreenWidth()/2,framework->GetScreenHeight()/2,shipSize,0);
    //-------------------------------

    //-----------------Create Asteroid :
    this->nbAsteroids = nbAsteroids;
    for(int i = 0; i <nbAsteroids; i++){
        InitializeAsteroids(framework, minSize, maxSize, asteroidSpeed);
    }
    flyingObjects.insert(flyingObjects.end(), asteroids.begin(), asteroids.end());
    //----------------------------------

    //Adding them to the flyingObjects list
    flyingObjects.push_back(spaceship);

    this->missileNotOnScreen=false;
}
//-----------------------------------------------------------------------------





//-----------------------------------------------------------------Update :

int Model::Update(Framework* framework) {

    //Move the objects (different move methods so we need dynamic cast):
    for (FlyingObject* object : Model::GetFlyingObjectsInGame(flyingObjects, framework)){
        if(object!=nullptr){
            if (object->GetTypeName()=="Missile"){
                Missile* missile = dynamic_cast<Missile*>(object); // Cast to Missile
                missile->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
                if (missile->NotOnScreen(framework->GetScreenWidth(), framework->GetScreenHeight())){
                    this->missileNotOnScreen= true;
                }
            }
            else if(object->GetTypeName()=="Spaceship" || object->GetTypeName()=="Asteroid"){
                object->Move(framework->GetScreenWidth(), framework->GetScreenHeight());
            }
        }
    }


    // Test collisions between all missiles and all asteroids
    for (int i = 0; i < flyingObjects.size(); ++i) {
        FlyingObject* object = flyingObjects[i];
        if (object != nullptr && object->GetTypeName() == "Asteroid") {
            for (int j = 0; j < flyingObjects.size(); ++j) {
                FlyingObject* otherObject = flyingObjects[j];
                if (otherObject != nullptr && otherObject->GetTypeName() == "Missile") {
                    bool collisionWithMissile = FlyingObject::Collide(object, otherObject);
                    if (collisionWithMissile) {
                        //Dynamic cast to access the specific functions
                        Asteroid* asteroidToExplode = dynamic_cast<Asteroid*>(object); // Cast to Asteroid
                        Missile* missile = dynamic_cast<Missile*>(otherObject); // Cast to Missile
                        //To avoid nullptr in the list
                        if(asteroidToExplode->GetNbExplosionsLeft()>=2){
                            //Add the two other asteroids
                            flyingObjects.push_back(asteroidToExplode->Explode(asteroidToExplode->GetSpeed(),missile->GetAngle()+30));
                            flyingObjects.push_back(asteroidToExplode->Explode(asteroidToExplode->GetSpeed(),missile->GetAngle()-30));
                            //2 new asteroids
                            nbAsteroids = nbAsteroids + 2;
                        }

                        // Remove Missile from the vector
                        flyingObjects.erase(flyingObjects.begin() + j);
                        delete otherObject;
                        nbAsteroids--;
                        // Delete the asteroid object
                        flyingObjects.erase(flyingObjects.begin() + i);
                        delete object;
                    }
                }
                else if (otherObject != nullptr && otherObject->GetTypeName() == "Spaceship") {
                    bool collisionWithSpaceship = FlyingObject::Collide(object, otherObject);
                    if (collisionWithSpaceship) {
                        if (!spaceship->GetInvincible()) {
                            // Check if shield is zero and handle destruction if needed
                            if(spaceship->GetShieldLevel() <= 0){
                                //Exit Game
                                return -1;
                            }
                            else {
                                // Reduce the shield of the spaceship
                                spaceship->SetShieldLevel(spaceship->GetShieldLevel()-0.25);
                                spaceship->SetInvincibleFor(3.0);
                            }
                        }
                        else {
                            // Spaceship Invincible
                        }
                    }
                }
            }
        }
    }

    std::cout << nbAsteroids << std::endl;
    if(nbAsteroids==0){
        std::cout << "you Won !" << std::endl;
        return 1;
    }

    return 0;

    //Test if there are still Asteroids in the Level


}
//---------------------------------------------------------------------------------------






//------------------------------------------------------------------------------Actions :
void Model::ChooseAction(int action) {
    switch (action) {
        case SDLK_UP:
            Model::SpeedUp();
            break;
        case SDLK_DOWN:
            Model::SpeedDown();
            break;
        case SDLK_RIGHT:
            Model::RotateRight();
            break;
        case SDLK_LEFT:
            Model::RotateLeft();
            break;
        case SDLK_SPACE:
            Model::ShootMissile();
            break;
        case SDLK_ESCAPE:
            SDL_Quit();
            exit(0);
            break;
    }
}


void Model::SpeedUp() {
    spaceship->SpeedUp(5);
}

void Model::SpeedDown() {
    spaceship->SpeedDown(5);
}

void Model::RotateRight() {
    spaceship->Rotate(30);
}

void Model::RotateLeft() {
    spaceship->Rotate(-30);
}

void Model::ShootMissile() {
    bool noMissilesOnScreen = true;
    for (const FlyingObject* object : flyingObjects) {
        if (object != nullptr && object->GetTypeName() == "Missile") {
            noMissilesOnScreen = false;
            break;
        }
    }

    if (noMissilesOnScreen) {
        this->missile = new Missile(spaceship->GetX(), spaceship->GetY(), 10, 30, spaceship->GetAngle());
        flyingObjects.push_back(missile);
    }

}

//--------------------------------------------------------------------------





//------------------------------------------------------------------------------------------------------Getters:
std::vector<FlyingObject *> Model::GetFlyingObjects() {
    std::vector<FlyingObject*> allFlyingObjects(flyingObjects.begin(), flyingObjects.end());
    return allFlyingObjects;
}



std::vector<FlyingObject*> Model::GetFlyingObjectsInGame(std::vector<FlyingObject*>& allFlyingObjects, Framework* framework) {
    // Check all the objects in the game
    for (auto it = allFlyingObjects.begin(); it != allFlyingObjects.end();) {
        FlyingObject* object = *it;

        // Check if the object is a missile
        if (object->GetTypeName() == "Missile") {
            Missile* missile = dynamic_cast<Missile*>(object);

            // Check if the missile is not on the screen
            if (missile->NotOnScreen(framework->GetScreenWidth(), framework->GetScreenHeight())) {
                it = allFlyingObjects.erase(it);// Remove the missile from flyingObjects
                delete missile;
                continue;
            }
        }
        ++it;
    }
    return allFlyingObjects;
}
//----------------------------------------------------------------------------------------------------------


//Generate a random image for the asteroid :
SDL_Texture* Model::GetRandomAsteroidTexture(Framework* framework) {
    // Define an array or vector with paths to asteroid images.
    std::vector<std::string> asteroidImages = {
            "asteroid.bmp",
            "asteroid1.bmp",
            "asteroid2.bmp",
            "asteroid3.bmp"
    };

    // Use a random number generator to select a random index.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, asteroidImages.size() - 1);
    int randomIndex = distribution(gen);

    // Get the randomly selected image path.
    std::string randomAsteroidImagePath = asteroidImages[randomIndex];

    // Load the randomly selected image.
    return framework->GetTexture(randomAsteroidImagePath);
}





//------------------------------------------------------------------------------Asteroids Inititialization
void Model::InitializeAsteroids(Framework* framework, double minSize, double maxSize, double asteroidSpeed) {
    //---Espace de creation :
    std::random_device generator;
    std::uniform_int_distribution<int> spaceDistribution(0, 7);
    int spaceToUse = spaceDistribution(generator);
    std::uniform_real_distribution<double> xDistribution(0.0, framework->GetScreenWidth());
    std::uniform_real_distribution<double> yDistribution(0.0, framework->GetScreenHeight());


    //---Assignement des espaces :
    if(spaceToUse == 0){
        std::uniform_real_distribution<double> xDistribution(0.0,framework->GetScreenWidth()/3);
        std::uniform_real_distribution<double> yDistribution(0.0,framework->GetScreenHeight()/3);
    }
    else if(spaceToUse == 1){
        std::uniform_real_distribution<double> xDistribution(framework->GetScreenWidth()/3,2*framework->GetScreenWidth()/3);
        std::uniform_real_distribution<double> yDistribution(0.0,framework->GetScreenHeight()/3);
    }
    else if(spaceToUse == 2){
        std::uniform_real_distribution<double> xDistribution(2*framework->GetScreenWidth()/3,3*framework->GetScreenWidth()/3);
        std::uniform_real_distribution<double> yDistribution(0.0,framework->GetScreenHeight()/3);
    }
    else if(spaceToUse == 3){
        std::uniform_real_distribution<double> xDistribution(0.0,framework->GetScreenWidth()/3);
        std::uniform_real_distribution<double> yDistribution(framework->GetScreenHeight()/3,2*framework->GetScreenHeight()/3);
    }
    else if(spaceToUse == 4){
        std::uniform_real_distribution<double> xDistribution(2*framework->GetScreenWidth()/3,3*framework->GetScreenWidth()/3);
        std::uniform_real_distribution<double> yDistribution(framework->GetScreenHeight()/3,2*framework->GetScreenHeight()/3);
    }
    else if(spaceToUse == 5){
        std::uniform_real_distribution<double> xDistribution(0.0,framework->GetScreenWidth()/3);
        std::uniform_real_distribution<double> yDistribution(2*framework->GetScreenHeight()/3,3*framework->GetScreenHeight()/3);
    }
    else if(spaceToUse == 6){
        std::uniform_real_distribution<double> xDistribution(framework->GetScreenWidth()/3,2*framework->GetScreenWidth()/3);
        std::uniform_real_distribution<double> yDistribution(2*framework->GetScreenHeight()/3,3*framework->GetScreenHeight()/3);
    }
    else if(spaceToUse == 7){
        std::uniform_real_distribution<double> xDistribution(2*framework->GetScreenWidth()/3,3*framework->GetScreenWidth()/3);
        std::uniform_real_distribution<double> yDistribution(2*framework->GetScreenHeight()/3,3*framework->GetScreenHeight()/3);
    }

    double xToUse = xDistribution(generator);
    double yToUse = yDistribution(generator);

    std::uniform_int_distribution<int> angleValues(-180, 180);
    int angle = angleValues(generator);

    std::uniform_real_distribution<double> sizeValues(minSize, maxSize);
    double size = sizeValues(generator);

    Asteroid* asteroidGenerated = new Asteroid(xToUse,yToUse,size, asteroidSpeed, angle,2, GetRandomAsteroidTexture(framework));
    asteroids.push_back(asteroidGenerated);//add the asteroids generated to list asteroids
    //flyingObjects.push_back(asteroidGenerated);
}



//-------------------------------
