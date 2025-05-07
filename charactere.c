#include <stdlib.h>
#include <stdio.h>

#include "charactere.h"


Personnage *creerPersonnage(SDL_Renderer *renderer) {
    Personnage *mario = malloc(sizeof(Personnage));
    if (mario == NULL) {
        SDL_Log("Erreur");
        return NULL;
    }

    mario->image = malloc(sizeof(SDL_Texture*)*NUMBER_IMAGE_MARIO);
    if (mario->image == NULL) {
        SDL_Log("Erreur");
        return 0;
    }
  
        mario->image[0] = loadImage("img/Mario1.png", renderer);
        mario->image[1] = loadImage("img/Mario2.png", renderer);
        mario->image[2] = loadImage("img/Mario3.png", renderer);
        mario->image[3] = loadImage("img/Mario4.png", renderer);
        mario->image[4] = loadImage("img/Mario5.png", renderer);
        mario->image[5] = loadImage("img/Mario6.png", renderer);
        




     //structure Mario
     mario->position.x = 100;
     mario->position.y = 300;
     mario->position.w = WIDTH_MARIO ;
     mario->position.h = HEIGHT_MARIO ;
 
     mario->jump = 0;
     mario->jumptime = 0;
     mario->gravite = 0;
     mario->direction = 0;
     mario->dernieredirection = 1;
     mario->temp = 0;
     mario->win = 0;
     mario->lvl = 1;
     mario->lvlperdu = -1;
 
    return mario;
}



void freePersonnage(Personnage* mario, Personnage **goomba, int nbGoomba) {
}