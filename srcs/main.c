#include "tinyrenderer.h"

int	main(void)
{
	t_sdl sdl;

	init_sdl(&sdl, 1152, 864);
	program_loop(&sdl);
	clear_sdl(&sdl);

	return (0);
}
