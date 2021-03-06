#include "render.h"

static void		compute_triangle_bbox(t_int2 *bbox, t_float3 *points)
{
	bbox[0] = (t_int2){points[0].x, points[0].y};
	bbox[1] = (t_int2){points[0].x, points[0].y};

	for (int i = 1; i < 3; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if ((int)points[i][j] < bbox[0][j])
				bbox[0][j] = (int)points[i][j];
			else if (bbox[1][j] < (int)points[i][j])
				bbox[1][j] = (int)points[i][j];
		}
	}
	clamp_screen_coord(bbox);
	clamp_screen_coord(bbox + 1);
}

static t_bool	is_inside_triangle(int x, int y, t_rdata *rdata)
{
	t_float3	*pts;
	t_float3	v1;
	t_float3	v2;
	t_float3	bc;

	pts = rdata->v_screen;
	v1 = (t_float3){pts[1].x - pts[0].x, pts[2].x - pts[0].x, pts[0].x - x};
	v2 = (t_float3){pts[1].y - pts[0].y, pts[2].y - pts[0].y, pts[0].y - y};
	bc = cross3f(v1, v2);
	bc = (t_float3){1.0f - (bc.x + bc.y) / bc.z, bc.x / bc.z, bc.y / bc.z};
	rdata->bc_screen = bc;
	return (bc.x >= 0.0f && bc.y >= 0.0f && bc.z >= 0.0f);
}

static t_bool	check_zbuffer(int x, int y, t_rdata *rdata)
{
	t_bool		result;
	const t_sdl	*sdl;
	float		z;

	result = FALSE;
	sdl = get_sdl_context();
	z = 0.0f;
	for (int i = 0; i < 3; i++)
	{
		z += rdata->v_screen[i].z * rdata->bc_screen[i];
	}
	if (rdata->zbuffer[x + y * sdl->width] < z)
	{
		rdata->zbuffer[x + y * sdl->width] = z;
		result = TRUE;
	}
	return (result);
}

void			draw_triangle(t_rdata *rdata)
{
	t_int2		bbox[2];
	t_float3	normal;
	t_color		c;
	float		intensity;

	compute_triangle_bbox(bbox, rdata->v_screen);
	for(int x = bbox[0].x; x <= bbox[1].x; x++)
	{
		for(int y = bbox[0].y; y <= bbox[1].y; y++)
		{
			if (is_inside_triangle(x, y, rdata) && check_zbuffer(x, y, rdata))
			{
				normal = (t_float3)(0.0f);
				for (int i = 0; i < 3; i++)
				{
					normal += rdata->vn[i] * rdata->bc_screen[i];
				}
				intensity = dot3f(norm3f(normal), rdata->screen_dir);
				if (intensity < 0.0f)
				{
					intensity = 0.0f;
				}
				c.bytes =  (t_byte4)(intensity * 250);
				set_pixel_color(x, y, c.rgba);
			}
		}
	}
}