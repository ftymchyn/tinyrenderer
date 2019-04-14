#include "render.h"
#include <stdio.h>

void	draw_face(t_face *face)
{
	t_sdl	*sdl;
	t_color	c;
	size_t	i;

	if (face && vector_size(face->vdata) >= 3)
	{
		c.rgba = rand();
		sdl = get_sdl_context();
		i = 0;
		while (i < 3)
		{
			t_int3		*vdata0 = vector_at(face->vdata, i);
			t_int3		*vdata1 = vector_at(face->vdata, ((i + 1) % 3));
			t_float3	*v0 = vector_at(face->owner->vertexes, vdata0->x - 1);
			t_float3	*v1 = vector_at(face->owner->vertexes, vdata1->x - 1);
			t_int2		p0 = (t_int2){(v0->x + 1.0f) * sdl->width / 2.0f, (v0->y + 1.0f) * sdl->height / 2.0f };
			t_int2		p1 = (t_int2){(v1->x + 1.0f) * sdl->width / 2.0f, (v1->y + 1.0f) * sdl->height / 2.0f };

			draw_line(p0, p1, c);
			i++;
		}
	}
}