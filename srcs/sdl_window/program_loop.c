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
	SDL_Event	e;
	
	while (running)
	{
		if (pull_event(&e))
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
			{
				running = FALSE;
			}
		}

		if (running)
		{
			draw_line((t_int2){150,150}, (t_int2){1200,540}, (t_color){0x00ffffff});
			draw_line((t_int2){150,150}, (t_int2){200,120}, (t_color){0x000000ff});
			draw_line((t_int2){150,150}, (t_int2){50, 30}, (t_color){0x000000ff});
			draw_line((t_int2){150,150}, (t_int2){150,850}, (t_color){0x0000ffff});

			render_canvas();
		}

		SDL_Delay(0);
	}
}
