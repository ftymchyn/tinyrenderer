#ifndef RENDER_H
# define RENDER_H

# include "common.h"
# include "sdl_window.h"
# include "math.h"
# include "utils.h"

typedef union	u_color
{
	int			rgba;
	t_byte4		bytes;
}				t_color;

void			set_pixel_color(t_sdl *sdl, int x, int y, int c);
void			draw_line(t_sdl *sdl, t_int2 pStart, t_int2 pEnd, t_color color);

#endif