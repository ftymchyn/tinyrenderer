#include "sdl_window.h"

int	main(void)
{
	init_sdl(1152, 864);
	program_loop();
	clear_sdl();

	return (0);
}
