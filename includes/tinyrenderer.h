#ifndef TINYRENDERER_H
# define TINYRENDERER_H

# include <assert.h>
# include "libft.h" 
# include "SDL.h"
# include "typedefs.h"

# define PROGRAM_NAME "tinyrenderer"

void	init_sdl(t_sdl *sdl, int width, int height);
void	program_loop(t_sdl *sdl);
void	draw_frame(t_sdl *sdl);
void	clear_sdl(t_sdl *sdl);

void	set_pixel_color(t_sdl *sdl, int x, int y, int c);
void	draw_line(t_sdl *sdl, t_int2 pStart, t_int2 pEnd, t_color color);

int		clampi(int num, int min, int max);

void	swapi(int *n1, int *n2);
void	swapull(unsigned long long *n1, unsigned long long *n2);

int		absi(int num);

#endif
