#include "sdl_window.h"

void	clear_sdl(t_sdl *sdl)
{
	free(sdl->pixels);
	SDL_DestroyTexture(sdl->canvas);
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}