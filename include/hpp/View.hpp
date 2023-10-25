#ifndef VIEW_HPP
#define VIEW_HPP


#include <vector>
#include <SDL_ttf.h>
#include "FlyingObject.hpp"
#include "Model.hpp"
#include "framework.hpp"

class View{


public:

    //---------------------Constructor :
    View(Framework* framework);

    void Refresh(std::vector<FlyingObject *>, Framework* framework);
    void RenderTopBar(Framework* framework, Spaceship* spaceship);

private :
    Uint32 startTime;
    Uint32 elapsedTime;


};




#endif
