#include "tinyrenderer.h"

void	set_pixel_color(t_sdl *sdl, int x, int y, int c)
{
	sdl->pixels[(sdl->height - y) * sdl->width + x] = c;
}