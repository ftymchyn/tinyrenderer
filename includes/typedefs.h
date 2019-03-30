#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef unsigned char	t_byte4 __attribute__((ext_vector_type(4)));
typedef float			t_float4 __attribute__((ext_vector_type(4)));
typedef int				t_int2 __attribute__((ext_vector_type(2)));

typedef union			u_color
{
	t_byte4				bytes;
	int					rgba;
}						t_color;

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
