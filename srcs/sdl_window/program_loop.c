#include "tinyrenderer.h"

static t_bool	pull_event(SDL_Event *e)
{
	t_bool result = FALSE;

	while (SDL_PollEvent(e) && !result)
	{
		result = (e->type == SDL_QUIT
				  || (e->type == SDL_KEYDOWN && !e->key.repeat));
	}

	return (result);
}

void			program_loop(t_sdl *sdl)
{
	t_bool		running = TRUE;
	SDL_Event	e;

	while (running)
	{
		if (pull_event(&e))
		{
			running = !(e.type == SDL_QUIT
						|| (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE));
		}

		if (running)
		{
			draw_frame(sdl);
		}
	}
}
