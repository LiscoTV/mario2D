/*
Gère les différents évènements du jeu comme le mouvement des personnages et des ennemies, les collisions, le scroll de la map
et si le niveau est fini (win et loose). 
*/

#ifndef DEF_EVENT
#define DEF_EVENT
    
    #include "file.h"
    #include "charactere.h"

    void deplacement(SDL_Renderer *renderer, Personnage *mario);
    void afficherPersonnage(SDL_Renderer *renderer, Personnage *mario);
#endif