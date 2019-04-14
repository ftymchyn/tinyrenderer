#ifndef RENDER_H
# define RENDER_H

# include "common.h"
# include "sdl_window.h"
# include "math.h"
# include "utils.h"
# include "object.h"

typedef union	u_color
{
	int			rgba;
	t_byte4		bytes;
}				t_color;

void			set_pixel_color(int x, int y, int c);
void			draw_line(t_int2 pStart, t_int2 pEnd, t_color color);
void			draw_face(t_face *face);
void			render(t_mesh *mesh);

#endif