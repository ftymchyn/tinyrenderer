#include "render.h"

void	set_pixel_color(int x, int y, int c)
{
	t_sdl	*sdl;

	sdl = get_sdl_context();
	sdl->pixels[(sdl->height - y) * sdl->width + x] = c;
}