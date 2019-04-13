#include "sdl_window.h"

t_sdl	*get_sdl_context(void)
{
	static t_sdl sdl;

	return &sdl;
}