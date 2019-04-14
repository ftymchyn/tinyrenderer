#include "sdl_window.h"
#include "render.h"
#include "libft.h"

static t_bool	pull_event(SDL_Event *e)
{
	t_bool result = FALSE;

	while (!result && SDL_PollEvent(e))
	{
		result = (e->type == SDL_QUIT
				  || (e->type == SDL_KEYDOWN && !e->key.repeat)
				  || e->type == SDL_DROPFILE);
	}

	return (result);
}
void			program_loop(void)
{
	t_bool		running = TRUE;
	t_mesh		*mesh = NULL;
	SDL_Event	e;
	
	while (running)
	{
		if (pull_event(&e))
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
			{
				running = FALSE;
			}
			else if (e.type == SDL_DROPFILE)
			{
				clear_mesh(&mesh);
				mesh = load_mesh(e.drop.file);
				SDL_free(e.drop.file);
			}
		}

		if (running)
		{
			render(mesh);
			update_window();
		}

		SDL_Delay(0);
	}

	clear_mesh(&mesh);
}
