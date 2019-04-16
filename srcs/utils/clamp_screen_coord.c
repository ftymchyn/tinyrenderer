#include "utils.h"

void	clamp_screen_coord(t_int2 *point)
{
	t_sdl	*sdl;

	sdl = get_sdl_context();
	point->x = clampi(point->x, 0, sdl->width - 1);
	point->y = clampi(point->y, 0, sdl->height - 1);
}