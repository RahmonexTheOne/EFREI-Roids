                ///////////////////////////////////////////////////
                //                   Framework
                // Bibliothèque encapsulant l'utilisation de SDL 2


#ifndef FRAMEWORK_HPP_
#define FRAMEWORK_HPP_

#include <string>
#include "include/SDL2/SDL.h"

using std::string;

class Framework {
    public:
        /////////////////////////////////
        // CONSTRUCTEUR ET DESTRUCTEUR //
        /////////////////////////////////


        //////////////////////////////////////////////
        // Constructeur.
        // Lance l'affichage plein écran dans la résolution courante
        // --------
        // * fps : taux de rafraichissement de l'écran (nombre d'images par seconde)
        // * shipSize : taille d'affichage du vaisseau, en pixels
        // * missileSize : taille d'affichage du missile, en pixels
        Framework(int width, int height, int fps, int shipSize, int missileSize);

        //////////////////////////////////////////////
        // Constructeur.
        // Lance l'affichage plein écran dans la résolution choisie
        // --------
        // * width, height : résolution d'affichage
        // * fps : taux de rafraichissement de l'écran (nombre d'images par seconde)
        // * shipSize : taille d'affichage du vaisseau, en pixels
        // * missileSize : taille d'affichage du missile, en pixels
        Framework(int fps, int shipSize, int missileSize);

        ~Framework();


        ////////////////
        // ACCESSEURS //
        ////////////////
        int GetScreenWidth();
        int GetScreenHeight();

        ////////////////////////////////
        // MÉTHODES D'ENTÉES/SORTIES //
        /////////////////////////////////

        ///////////////////////////
        // Entrée/sortie du clavier
        // -------
        // Renvoie : un code clavier SDL2 (https://wiki.libsdl.org/SDL2/SDL_Keycode)
        int GetInput();

        //////////////////////////////////////////////////////
        // Méthode à appeler à chaque rafraichissement d'image
        // Cette fonction effectue une attente active afin de caler l'affichage sur 60fps
        void Update();

        /////////////////////////////////////////////
        // MÉTHODES D'AFFICHAGE DES SPRITES DU JEU //
        /////////////////////////////////////////////

        //////////////////////////////////////////////////
        // Méthode affichant le vaisseau avec son bouclier
        // Le sprite du vaisseau est dans "spaceship.bmp"
        // Le sprite du vaisseau en alerte est dans "redSpaceship.bmp"
        // Le sprite du bouclier est dans "shield.bmp"
        // --------
        // * x, y : coordonnées du centre du vaisseau, en pixels
        // * angle : orientation, en degrés. 0 correspond à la direction nord
        // * shieldLevel : niveau d'intensité du bouclier, entre 0.0 et 1.0. Affect la transparence du sprite
        // * warning : indique si le vaisseau est en état d'alerte (apparait en rouge)
        void DrawShip(int x, int y, float angle, float shieldLevel, bool warning);

        /////////////////////////////////
        // Méthode affichant un astéroïde
        // Le sprite est dans "asteroid.bmp"
        // --------
        // * x, y : coordonnées du centre du vaisseau, en pixels
        // * size : taille du sprite, en pixels
        void DrawAsteroid(int x, int y, int size);

        ///////////////////////////////
        // Méthode affichant un missile
        // Le sprite est dans "missile.bmp"
        // --------
        // * x, y : coordonnées du centre du missile, en pixels
        void DrawMissile(int x, int y);

    private:
        //////////
        // Fenêtre
        SDL_Window *   window;
        SDL_Renderer * renderer;
        int width;
        int height;
        int ticks_for_next_frame;
        int lastTimeScreenUpdate = 0;

        //////////
        // Sprites
        SDL_Texture * textureShip;
        SDL_Texture * textureShipWarning;
        SDL_Texture * textureAsteroid;
        SDL_Texture * textureMissile;
        SDL_Texture * textureShield;
        int shipSize;
        int missileSize;

        //////////////////////////////
        // Initialisation du framweork
        //
        // Lance l'affichage plein écran dans la résolution courante. Méthode appelée par les différents constructeurs
        // --------
        // * width, height : résolution d'affichage
        // * fps : taux de rafraichissement de l'écran (nombre d'images par seconde)
        // * shipSize : taille d'affichage du vaisseau, en pixels
        // * missileSize : taille d'affichage du missile, en pixels
        void Init(int width, int height, int fps, int shipSize, int missileSize);

        //////////////////////
        // Affichage de sprite
        // * texture : texture du sprite à recopier à l'écran
        // * x, y : coordonnées du centre du sprite, en pixels
        // * w, h : taille du sprite, en pixels
        // * angle : angle de rotation, en degrés. 0 correspond à la direction nord
        void DrawSprite(SDL_Texture * texture, int x, int y, int w, int h, float angle);

        ////////////////////////////////////////
        // Affichage de sprite avec transparence
        // * texture : texture du sprite à recopier à l'écran
        // * x, y : coordonnées du centre du sprite, en pixels
        // * w, h : taille du sprite, en pixels
        // * angle : angle de rotation, en degrés. 0 correspond à la direction nord
        // * alpha : niveau de transparence, entre 0.0 (transparent) et  1.0 (opaque)
        void DrawSpriteAlpha(SDL_Texture * texture, int x, int y, int w, int h, float angle, float alpha);

        ///////////////////////////////////
        // Création d'une texture de sprite
        // -------
        // * imgPath : chemin vers l'image (format BMP avec alpha)
        // -------
        // Renvoie : la texture contenant l'image chargée
        SDL_Texture * GetTexture(string imgName);
};

#endif