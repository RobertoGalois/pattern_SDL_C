#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void    pause()
{
        signed short bool_continue = 1;
        SDL_Event ev;
 
        while (bool_continue)
        {
            SDL_WaitEvent(&ev);
            switch(ev.type)
            {
                case SDL_QUIT:
                bool_continue = 0;
            }
        }
}

int     main(int argc, char *argv[])
{
        SDL_Surface *window = NULL;
        SDL_Surface *rectangle;
        SDL_Rect position;

        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
        if (window == NULL) // Si l'ouverture a échoué, on le note et on arrête
        {
            fprintf(stderr, "Impossible de charger le mode vidéo : %s\n",
                    SDL_GetError());
            exit(EXIT_FAILURE);
        }
    
        SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);
        SDL_FillRect(window, NULL, SDL_MapRGB(window->format, 255, 255, 255));

        rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
        position.x = 0;
        position.y = 0;

        SDL_FillRect(rectangle, NULL, SDL_MapRGB(window->format, 0, 0, 0));
        SDL_BlitSurface(rectangle, NULL, window, &position);

        SDL_Flip(window);

        pause();
        SDL_Quit();

        return EXIT_SUCCESS;
} 
