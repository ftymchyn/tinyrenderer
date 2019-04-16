#ifndef RENDER_H
# define RENDER_H

# include "common.h"
# include "sdl_window.h"
# include "math.h"
# include "utils.h"
# include "object.h"

typedef struct	s_rdata
{
	t_float3	light_dir;
	t_float3	v[3];
	t_float3	vn[3];
	t_int2		v_screen[3];
}				t_rdata;


typedef union	u_color
{
	int			rgba;
	t_byte4		bytes;
}				t_color;

t_rdata			*get_render_context();
void			set_pixel_color(int x, int y, int c);
void			draw_line(t_int2 pStart, t_int2 pEnd, t_color color);
void			draw_face(t_face *face);
void			draw_triangle(t_rdata *rdata, t_color c);
void			render(t_mesh *mesh);

#endif