#ifndef VIEW_HPP
#define VIEW_HPP


#include <vector>
#include "FlyingObject.hpp"
#include "Model.hpp"
#include "framework.hpp"

class View{


public:

    //---------------------Constructor :
    View(Framework* framework);

    void Refresh(std::vector<FlyingObject *>, Framework* framework, Model* model);


private :



};




#endif VIEW_HPP
