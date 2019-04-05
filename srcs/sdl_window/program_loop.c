#include "tinyrenderer.h"

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

void			program_loop(t_sdl *sdl)
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
			else if (e.type == SDL_DROPFILE)
			{
				int fd = open(e.drop.file, O_RDONLY);
				ft_putendl(e.drop.file != NULL ? e.drop.file : "(null)");
				if ( fd != -1 )
				{
					char *line = NULL;

					while (get_next_line(fd, &line) > 0)
					{
						ft_putendl(line);
						free(line);
					}
				}
				SDL_free(e.drop.file);

				e.type = 0;
			}
		}

		if (running)
		{
			draw_line(sdl, (t_int2){150,150}, (t_int2){1200,540}, (t_color){0x00ffffff});
			draw_line(sdl, (t_int2){150,150}, (t_int2){200,120}, (t_color){0x000000ff});
			draw_line(sdl, (t_int2){150,150}, (t_int2){50, 30}, (t_color){0x000000ff});
			draw_line(sdl, (t_int2){150,150}, (t_int2){150,850}, (t_color){0x0000ffff});

			SDL_UpdateTexture(sdl->canvas, NULL, sdl->pixels, sdl->width << 2);
			SDL_RenderClear(sdl->renderer);
			SDL_RenderCopy(sdl->renderer, sdl->canvas, NULL, NULL);
			SDL_RenderPresent(sdl->renderer);
		}

		SDL_Delay(0);
	}
}
