#include "event.h"


void deplacement(SDL_Renderer* renderer, Personnage* mario, SDL_Event events) {
    if (events.type == SDL_KEYDOWN) {
        switch (events.key.keysym.sym) {
            case SDLK_UP:
                if (mario->jump == 0 && mario->gravite == 0) {
                    mario->jump = 1;
                    mario->gravite = 1;
                }
                break;
            case SDLK_LEFT:
                mario->position.x -= 5;
                mario->direction = 2;
                mario->dernieredirection = 2;
                break;
            case SDLK_RIGHT:
                mario->position.x += 5;
                mario->direction = 1;
                mario->dernieredirection = 1;
                break;
        }
    }

