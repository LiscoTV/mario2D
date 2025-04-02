#include <stdlib.h>
#include <stdio.h>

#include "charactere.h"


void freePersonnage(Personnage* mario, Personnage **goomba, int nbGoomba) {
     

    //rectangle pour Mario
    SDL_Rect rect = {50, 50,WIDTH_MARIO,HEIGHT_MARIO}; 
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
     

    // Mario dans le rectangle
    SDL_Surface *imageSurface = IMG_Load("Mario1.png"); 
    if (!imageSurface) {
        printf("Erreur de chargement de l'image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }



    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);  
    if (!imageTexture) {
        printf("Erreur de création de la texture : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    
    
    SDL_Rect imageRect = {50, 50, WIDTH_MARIO,HEIGHT_MARIO }; 
    SDL_RenderCopy(renderer, imageTexture, NULL, &imageRect);
    SDL_RenderPresent(renderer);
 }

