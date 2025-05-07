#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "game.h"

//ligne de compilation gcc main.c file.c game.c event.c charactere.c -o mario -lSDL2main -lSDL2_image -lSDL2

int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h);

int main(int argc, char *argv[])	{

	
	
	
	//Code pour creer la fenetre
	SDL_Window *window = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))	{
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_FENETRE,  HAUTEUR_FENETRE , SDL_WINDOW_SHOWN);
    if(NULL == window)	{
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if(!renderer){
			fprintf(stderr, "erreur\n");
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
		}



		//code pour mettre l'image
		SDL_RenderClear(renderer);
		SDL_Texture * image = loadImage("img/menu.jpg",renderer);
		SDL_RenderCopy(renderer,image,NULL,NULL);
		SDL_RenderPresent(renderer); 

		
		
		
		//code pour fermer la boucle avec la croix ou echap
		SDL_Event croix;
		int continuer = 1;
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
						switch(croix.key.keysym.sym) {
							case SDLK_1:
							jouer(renderer);
							break;
						}
						
						
				
			}
	
		}	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return EXIT_SUCCESS;
}

