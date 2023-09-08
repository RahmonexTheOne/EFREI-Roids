                ///////////////////////////////////////////////////
                //                   Framework
                // Bibliothèque encapsulant l'utilisation de SDL 2

#include "framework.hpp"
#include <iostream>

using namespace std;

// pour construire les chemins de fichiers
const string pathSep =
#ifdef _WIN32
        "\\";
#else
        "/";
#endif


                        /////////////////////////////////
                        // CONSTRUCTEUR ET DESTRUCTEUR //
                        /////////////////////////////////


//////////////////////////////////////////////
// Constructeur, lance l'affichage plein écran
// --------
// * width, height : résolution d'affichage
// * fps : taux de rafraichissement de l'écran (nombre d'images par seconde)
// * shipSize : taille d'affichage du vaisseau, en pixels
// * missileSize : taille d'affichage du missile, en pixels
Framework::Framework(int width, int height, int fps, int shipSize, int missileSize) {
    Init(width, height, fps, shipSize, missileSize);
}

//////////////////////////////////////////////
// Constructeur, lance l'affichage plein écran
// --------
// * width, height : résolution d'affichage
// * fps : taux de rafraichissement de l'écran (nombre d'images par seconde)
// * shipSize : taille d'affichage du vaisseau, en pixels
// * missileSize : taille d'affichage du missile, en pixels
Framework::Framework(int fps, int shipSize, int missileSize) {
    Init(-1, -1, fps, shipSize, missileSize);
}

//////////////
// Destructeur
Framework::~Framework() {
    SDL_Quit();
}


                        ////////////////
                        // ACCESSEURS //
                        ////////////////


int Framework::GetScreenWidth() {
    return width;
}

int Framework::GetScreenHeight() {
    return height;
}



                        ////////////////////////////////
                        // MÉTHODES D'ENTÉES/SORTIES //
                        /////////////////////////////////


/////////////////////////////
// Entrée du joeur eu clavier
// Renvoie un code clavier SDL2 (https://wiki.libsdl.org/SDL2/SDL_Keycode)
int Framework::GetInput() {
    SDL_Event e;

    if (e.type == SDL_QUIT) {
        SDL_Quit();
        exit(0);
    }
    else if (SDL_PollEvent(&e) && e.type == SDL_KEYDOWN)
        return e.key.keysym.sym;
    else
        return (int)NULL;
}

//////////////////////////////////////////////////////
// Méthode à appeler à chaque rafraichissement d'image
// Cette fonction effectue une attente active afin de caler l'affichage sur le fps
// -------
// * trackFrameDrop : indique s'il faut afficher un FPS trop important
void Framework::Update() {
    // On attend le temps nécessaire pour atteindre le taux de FPS
    int nbTicksWait = 0;
    int now = SDL_GetTicks();
    while (now-lastTimeScreenUpdate < ticks_for_next_frame) {
        SDL_Delay(1);
        nbTicksWait++;
        now = SDL_GetTicks();
    }

    if (nbTicksWait == 0)
        cout << "Warning, FPS too high, lagged for " << now-lastTimeScreenUpdate << " ms\n";

    // On met à jour l'écran
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    // On réarme le temps d'attente pour le prochain rafraichissement
    lastTimeScreenUpdate = SDL_GetTicks();
}


                        /////////////////////////////////////////////
                        // MÉTHODES D'AFFICHAGE DES SPRITES DU JEU //
                        /////////////////////////////////////////////


//////////////////////////////////////////
// Affichage du vaisseau avec son bouclier
// Le sprite du vaisseau est dans "spaceship.bmp"
// Le sprite du vaisseau en alerte est dans "redSpaceship.bmp"
// Le sprite du bouclier est dans "shield.bmp"
// --------
// * x, y : coordonnées du centre du vaisseau, en pixels
// * angle : orientation, en degrés. 0 correspond à la direction nord
// * shieldLevel : niveau d'intensité du bouclier, entre 0.0 et 1.0. Affect la transparence du sprite
// * warning : indique si le vaisseau est en état d'alerte (apparait en rouge)
void Framework::DrawShip(int x, int y, float angle, float shieldLevel, bool warning) {
    int shieldSize = shipSize * 1.3;

    if (warning)
        DrawSprite(textureShipWarning, x, y, shipSize, shipSize, angle);
    else
        DrawSprite(textureShip, x, y, shipSize, shipSize, angle);

    if (shieldLevel > 0.0)
        DrawSpriteAlpha(textureShield, x, y, shieldSize, shieldSize, 0.0, shieldLevel);
}

///////////////////////////
// Affichage d'un astéroïde
// Le sprite est dans "asteroid.bmp"
// --------
// * x, y : coordonnées du centre du vaisseau, en pixels
// * size : taille du sprite, en pixels
void Framework::DrawAsteroid(int x, int y, int size) {
    DrawSprite(textureAsteroid, x, y, size, size, 0);
}

/////////////////////////
// Affichage d'un missile
// Le sprite est dans "missile.bmp"
// --------
// * x, y : coordonnées du centre du missile, en pixels
void Framework::DrawMissile(int x, int y) {
    DrawSprite(textureMissile, x, y, missileSize, missileSize, 0.0);
}


                    //////////////////////
                    // MÉTHODES PRIVÉES //
                    //////////////////////


//////////////////////////////
// Initialisation du framweork
//
// Lance l'affichage plein écran dans la résolution courante. Méthode appelée par les différents constructeurs
// --------
// * width, height : résolution d'affichage
// * fps : taux de rafraichissement de l'écran (nombre d'images par seconde)
// * shipSize : taille d'affichage du vaisseau, en pixels
// * missileSize : taille d'affichage du missile, en pixels
void Framework::Init(int width, int height, int fps, int shipSize, int missileSize) {
    // Initialisation de SDL2
    if (SDL_Init(SDL_INIT_VIDEO)) {
        cerr << "Framework -> SDL_Init failed: "  << SDL_GetError();
        exit(1);
    }

    if (width == -1 && height == -1) {
        SDL_DisplayMode DM;
        SDL_GetCurrentDisplayMode(0, &DM);
        width = DM.w;
        height = DM.h;
    }

    // Création de la fenêtre plein écran
    window = SDL_CreateWindow("EFREIroid", 0, 0, width, height, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        cerr << "Framework -> SDL_CreateWindow Error: " << SDL_GetError();
        SDL_Quit();
        exit(1);
    }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    // Création du moteur de rendu graphique
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        cerr << "Framework -> SDL_CreateRenderer Error: " << SDL_GetError();
        SDL_Quit();
        SDL_DestroyWindow(window);
        exit(1);
    }

    // Textures de chacun des sprites du jeu
    textureShip        = GetTexture("spaceship.bmp");
    textureShipWarning = GetTexture("redspaceship.bmp");
    textureShield      = GetTexture("shield.bmp");
    textureAsteroid    = GetTexture("asteroid.bmp");
    textureMissile     = GetTexture("missile.bmp");

    //SDL_RenderSetLogicalSize(renderer, 800, 600);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2" );

    // Délai de rafraichissement
    ticks_for_next_frame = 1000 / fps;

    this->width  = width;
    this->height = height;
    this->shipSize    = shipSize;
    this->missileSize = missileSize;
}

///////////////////////////////////
// Création d'une texture de sprite
// --------
// * imgName : nom du fichier de l'image (format BMP avec alpha)
SDL_Texture * Framework::GetTexture(string imgName) {
    string imgPath = "images" + pathSep + imgName;
    SDL_Surface * sprite = SDL_LoadBMP(imgPath.c_str());

if (!sprite) {
    cerr << "SDL_LoadBMP failed: "  << SDL_GetError();
    exit(1);
}
SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, sprite);
if (!texture) {
    cerr << "DrawSpriteAlpha -> SDL_CreateTextureFromSurface failed: "  << SDL_GetError();
    exit(1);
}

return texture;
}

//////////////////////
// Affichage de sprite
// --------
// * texture : texture du sprite à recopier à l'écran
// * x, y : coordonnées du centre du sprite, en pixels
// * w, h : taille du sprite, en pixels
// * angle : orientation, en degrés. 0 correspond à la direction nord
void Framework::DrawSprite(SDL_Texture * texture, int x, int y, int w, int h, float angle) {
    DrawSpriteAlpha(texture, x, y, w, h, angle, 1.0);
}

////////////////////////////////////////
// Affichage de sprite avec transparence
// --------
// * texture : texture du sprite à recopier à l'écran
// * x, y : coordonnées du centre du sprite, en pixels
// * w, h : taille du sprite, en pixels
// * angle : orientation, en degrés. 0 correspond à la direction nord
// * alpha : niveau de transparence, entre 0.0 (transparent) et  1.0 (opaque)
void Framework::DrawSpriteAlpha(SDL_Texture * texture, int x, int y, int w, int h, float angle, float alpha) {
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (alpha < 1.0) {
        if (SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND))
            cerr << "DrawSpriteAlpha -> SDL_SetTextureBlendMode failed: "  << SDL_GetError();
        if (SDL_SetTextureAlphaMod(texture, 255*alpha) == -1)
            cerr << "DrawSpriteAlpha -> SDL_SetTextureAlphaMod failed: Alpha mode not supported";
    }

    SDL_Rect dest = {x-(w/2),  y-(h/2), w, h};
    if (SDL_RenderCopyEx(renderer, texture, NULL, &dest, angle, NULL, flip))
        cerr << "DrawSpriteAlpha -> SDL_RenderCopyEx failed: "  << SDL_GetError();
}
