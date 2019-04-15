#include "render.h"

void	draw_triangle(t_int2 *points, t_color c)
{
	draw_line(points[0], points[1], c);
	draw_line(points[1], points[2], c);
	draw_line(points[2], points[0], c);
}