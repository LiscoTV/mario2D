#include "event.h"

void deplacement(SDL_Renderer *renderer, Personnage *mario)
{
    // deplacement de mario
    if (mario->direction == 1)
    {
        mario->position.x += 1;
        mario->temp++;
        if (mario->temp >= 6)
        {
            mario->temp = 0;
        }
    }
    else if (mario->direction == 2)
    {
        mario->position.x -= 1;
        mario->temp++;
        if (mario->temp >= 6)
        {
            mario->temp = 0;
        }
    }
    else
    {
        mario->temp = 0;
    }
    // saut de mario
    if (mario->jump == 1)
    {
        if (mario->jumptime < 70)
        {
            mario->position.y -= 1;
            mario->jumptime++;
        }
        else
        {
            mario->jump = 0;
            mario->gravite = 1;
            mario->jumptime = 0;
        }
    }
    else if (mario->gravite == 1)
    {
        if (mario->position.y < 700)
        {
            mario->position.y += 1;
        }
        else
        {
            mario->gravite = 0;
            mario->position.y = 700;
        }
    }
    

}

    void afficherPersonnage(SDL_Renderer *renderer, Personnage *mario)  {
    if (mario->direction == 1)
    {
        SDL_RenderCopy(renderer, mario->image[1], NULL, &mario->position);
    }
    else if (mario->direction == 2)
    {
        SDL_RenderCopy(renderer, mario->image[4], NULL, &mario->position);
    }
    else if (mario->jump == 1 && mario->dernieredirection == 1)
    {
        SDL_RenderCopy(renderer, mario->image[2], NULL, &mario->position);
    }
    else if (mario->jump == 1 && mario->dernieredirection == 2)
    {
        SDL_RenderCopy(renderer, mario->image[5], NULL, &mario->position);
    }
    else if (mario->direction == 0 && mario->dernieredirection == 1)
    {
        SDL_RenderCopy(renderer, mario->image[0], NULL, &mario->position);
    }
    else if (mario->direction == 0 && mario->dernieredirection == 2)
    {
        SDL_RenderCopy(renderer, mario->image[3], NULL, &mario->position);
    }
    else if (mario->win == 1)
    {
        SDL_RenderCopy(renderer, mario->image[0], NULL, &mario->position);
    }
    else if (mario->win == -1)
    {
        SDL_RenderCopy(renderer, mario->image[0], NULL, &mario->position);
    }
    else
    {
        SDL_RenderCopy(renderer, mario->image[0], NULL, &mario->position);
    }
    }
