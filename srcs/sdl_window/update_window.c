#include "sdl_window.h"

void	update_window(void)
{
	t_sdl	*sdl;

	sdl = get_sdl_context();
	SDL_UpdateTexture(sdl->canvas, NULL, sdl->pixels, sdl->width << 2);
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->canvas, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
	bzero(sdl->pixels, sizeof(int) * ((sdl->width * sdl->height)));
}