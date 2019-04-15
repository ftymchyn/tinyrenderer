#include "render.h"

t_int2		transform(t_face *face, size_t vindex)
{
	t_int2			result;
	const t_sdl		*sdl;
	const t_int3	*vdata;
	const t_float3	*v;

	sdl = get_sdl_context();
	vdata = vector_at(face->vdata, vindex);
	v = vector_at(face->owner->vertexes, vdata->x - 1);
	result = (t_int2){(v->x + 1.0f) * sdl->width / 2.0f, (v->y + 1.0f) * sdl->height / 2.0f };
	return (result);
}

void		draw_face(t_face *face)
{
	t_int2		screen_coords[3];
	size_t		vsize;
	size_t		i;

	vsize = vector_size(face->vdata);
	if (face && vsize >= 3)
	{
		screen_coords[0] = transform(face, 0);
		i = 1;
		while (i < vsize - 1)
		{
			screen_coords[1] = transform(face, i);
			screen_coords[2] = transform(face, i + 1);
			draw_triangle(screen_coords, (t_color){rand()});
			i++;
		}
	}
}