/*
Contient la création du charactère (mario) et les divers caractéristique qui le compose, pareil pour les monstres.
Va aussi gérer l'affichage des personnages et mosntres. 
Attention la map doit déjà être chargé avant de créer un charactère. 
*/

#ifndef DEF_CHARACTERE
#define DEF_CHARACTERE
    
    #include <SDL2/SDL.h>
    #include "file.h"

    #define WIDTH_MARIO 30 //largeur des images mario
    #define HEIGHT_MARIO 40 //hauteur des images mario
    #define NUMBER_IMAGE_MARIO 6 //nombre d'image de mario en tout

    typedef struct Personnage Personnage;
    struct Personnage
    {
        SDL_Texture** image; //contient toutes les images nécessaire pour mario (différentes direction et saut)
        SDL_Rect position; //sa position à l'instant t
        int jump = 0; //Si mario saute lors de la montée du saut jump = 1, sinon 0
        int jumptime = 0; //correspond à la durée depuis quand mario fait un saut, à 70 on arrête
        int gravite = 0; //vaut 1 si mario est dans les air, 0 sinon. 
        int direction, dernieredirection = 0; //direction vers laquelle est dirigé mario, 1 : droite, 2 : gauche, 0 : statique) 
        int temp; //permet de faire varier les sprites de mario dans le temps.
        int win = 0; //vaut 1 si le personnage gagne, -1 si il perd, 0 sinon. 
        int invisible = 0; //utilisé pour les goombas quand il meurt vaut 1 dans ce cas, 0 si en vit.
        int lvl = 1, lvlperdu = -1;
    };

    
    void freePersonnage(Personnage* mario, Personnage **goomba, int nbGoomba);
    
#endif