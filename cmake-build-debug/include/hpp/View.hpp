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
    void RenderText(Framework* framework, const std::string& text, int x, int y, TTF_Font* font, SDL_Color color);

private :
    Uint32 startTime;
    Uint32 elapsedTime;


};




#endif
