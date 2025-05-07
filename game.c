#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

                



int jouer(SDL_Renderer* renderer) {

	//charger image et personnage.
    

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

    Personnage *mario = creerPersonnage(renderer);
    if (mario == NULL) {
        SDL_Log("Erreur");
        return 0;
    }


    int continuer = 1; 
    SDL_Event events;

    while(continuer){ 
        SDL_RenderClear(renderer);
        SDL_Event croix;
		while (SDL_PollEvent(&croix) || continuer == 1 )	{
			switch(croix.type)	{

				case SDL_QUIT:
					continuer = 0;
					break;

				case SDL_KEYDOWN:
            		switch(croix.key.keysym.sym) {
						case SDLK_ESCAPE:
						continuer = 0;
                        break;
						}
                case SDLK_UP:
                        if (mario->jump == 0 && mario->gravite == 0) {
                            mario->jump = 1;
                            mario->gravite = 1;
                        }
                        break;
                case SDLK_LEFT:
                        
                        mario->direction = 2;
                        mario->dernieredirection = 2;
                        break;
                case SDLK_RIGHT:
                        
                        mario->direction = 1;
                        mario->dernieredirection = 1;
                        break;
                 
            }

            SDL_RenderCopy(renderer, mario->image[0], NULL, &mario->position); 


            SDL_RenderPresent(renderer);

        }

    }

    freePersonnage(mario, NULL, 0);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        return continuer;
}


//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    //LibererMap(map, sprites);
    //
      
    