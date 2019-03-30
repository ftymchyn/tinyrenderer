#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef enum			e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Texture			*canvas;
	int					width;
	int					height;
	int					*pixels;
}						t_sdl;

#endif
