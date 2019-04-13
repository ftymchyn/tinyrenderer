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

t_sdl				*get_sdl_context(void);
void				init_sdl(int width, int height);
void				program_loop(void);
void				render_canvas(void);
void				clear_sdl(void);

#endif