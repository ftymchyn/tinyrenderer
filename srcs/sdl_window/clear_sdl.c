#include "sdl_window.h"

void	clear_sdl(void)
{
	t_sdl *sdl;

	sdl = get_sdl_context();
	free(sdl->pixels);
	SDL_DestroyTexture(sdl->canvas);
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}