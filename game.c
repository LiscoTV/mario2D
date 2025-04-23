#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"




int jouer(SDL_Renderer* renderer) {

	//charger image et personnage.  
    Personnage *mario = creerPersonnage(renderer);
    SDL_RenderCopy(renderer, mario->image[frame], NULL, &mario->position);

    




    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    

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
                        
            }
            SDL_RenderPresent(renderer);
        }
    }
    
	//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    //LibererMap(map, sprites);
    //freePersonnage(mario, goomba, nbGoomba);
    void freePersonnage(Personnage *mario) {
        if (mario) {
            for (int i = 0; i < 6; i++) {
                if (mario->image[i]) SDL_DestroyTexture(mario->image[i]);
            }
            free(mario->image);
            free(mario);
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return continuer;
}