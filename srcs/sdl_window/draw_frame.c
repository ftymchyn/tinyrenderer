#include "tinyrenderer.h"

void	draw_frame(t_sdl *sdl)
{
	SDL_UpdateTexture(sdl->canvas, NULL, sdl->pixels, sdl->width << 2);
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->canvas, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}
