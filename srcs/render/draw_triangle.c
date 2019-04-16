#include "render.h"

static void		compute_triangle_bbox(t_int2 *bbox, t_int2 *points)
{
	bbox[0] = points[0];
	bbox[1] = points[0];

	for (int i = 1; i < 3; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if (points[i][j] < bbox[0][j])
				bbox[0][j] = points[i][j];
			else if (bbox[1][j] < points[i][j])
				bbox[1][j] = points[i][j];
		}
	}
	clamp_screen_coord(bbox);
	clamp_screen_coord(bbox + 1);
}

static t_bool	is_inside_triangle(int x, int y, t_int2 *pts)
{
	t_float3	v1;
	t_float3	v2;
	t_float3	bc;

	v1 = (t_float3){pts[1].x - pts[0].x, pts[2].x - pts[0].x, pts[0].x - x};
	v2 = (t_float3){pts[1].y - pts[0].y, pts[2].y - pts[0].y, pts[0].y - y};
	bc = cross3f(v1, v2);
	bc = (t_float3){1.0f - (bc.x + bc.y) / bc.z, bc.x / bc.z, bc.y / bc.z};
	return (bc.x >= 0.0f && bc.y >= 0.0f && bc.z >= 0.0f);
}

void			draw_triangle(t_int2 *points, t_color c)
{
	t_int2	bbox[2];

	compute_triangle_bbox(bbox, points);
	for(int x = bbox[0].x; x <= bbox[1].x; x++)
	{
		for(int y = bbox[0].y; y <= bbox[1].y; y++)
		{
			if (is_inside_triangle(x, y, points))
			{
				set_pixel_color(x, y, c.rgba);
			}
		}
	}
}