#ifndef MODEL_HPP
#define MODEL_HPP

#include "FlyingObject.hpp"
#include <vector>

class Model {


public :

    Model();
    void Update();
    //------------Actions :
    void ChooseAction(int action);
    void SpeedUp();
    void SpeedDown();
    void RotateRight();
    void RotateLeft();
    //----------Getters :
    std::vector<FlyingObject *> GetFlyingObjects();



private :

    std::vector<FlyingObject *> flyingObjects;



};



#endif MODEL_HPP
