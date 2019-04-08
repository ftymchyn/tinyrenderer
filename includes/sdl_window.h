#ifndef SDL_WINDOW_H
# define SDL_WINDOW_H

# include <SDL.h>
# include "common.h" 

# define WINDOW_NAME "tinyrenderer"

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*canvas;
	int				width;
	int				height;
	int				*pixels;
}					t_sdl;

void				init_sdl(t_sdl *sdl, int width, int height);
void				program_loop(t_sdl *sdl);
void				clear_sdl(t_sdl *sdl);

#endif