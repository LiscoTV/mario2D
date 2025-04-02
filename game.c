#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"



int jouer(SDL_Renderer* renderer) {

	//charger image et personnage.  

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);


    int continuer = 1; //a utiliser pour savoir si on continue la boucle du jeu ou si on arrête. 
    SDL_Event events;

    while(continuer){ //coeur du jeu ici, les actions seront repété pour faire le déplacement des différentes images, ...
        SDL_RenderClear(renderer);
        //gérer les différentes actions. 
        //truc
        SDL_Event croix;
		while (SDL_PollEvent(&croix) || continuer == 1 )	{
			switch(croix.type)	{

				case SDL_QUIT:
					continuer = 0;
					break;

				case SDL_KEYDOWN:
            		switch(croix.key.keysym.sym) {
						case SDLK_ESCAPE:
                        SDL_Log("touche escape 2");
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

    return continuer;
}