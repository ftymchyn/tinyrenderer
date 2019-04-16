#include "render.h"

static void	push_vertex_to_render(t_face *face, size_t idx_in, t_rdata *rdata, size_t idx_out)
{
	const t_int3	*vdata;
	const t_float3	*v;
	const t_float3	*vn;

	vdata = vector_at(face->vdata, idx_in);
	v =  vector_at(face->owner->v, vdata->x - 1);
	vn = vector_at(face->owner->vn, vdata->x - 1);
	rdata->v[idx_out] = (v ? *v : (t_float3){0.0f, 0.0f, 0.0f});
	rdata->vn[idx_out] = (vn ? *vn : (t_float3){0.0f, 0.0f, 0.0f});
}

static void	transform(t_rdata *rd)
{
	const t_sdl		*sdl;
	t_float3		tmp;
	float			half_w;
	float			half_h;

	sdl = get_sdl_context();
	half_w = sdl->width / 2.0f;
	half_h = sdl->height / 2.0f;
	for(int i = 0; i < 3; i++)
	{
		tmp = rd->v[i] + 1.0f;
		rd->v_screen[i] = (t_int2){tmp.x * half_w, tmp.y *  half_h};
	}
}

void			draw_face(t_face *face)
{
	t_rdata		*rdata;
	size_t		vsize;
	size_t		i;

	vsize = vector_size(face->vdata);
	if (face && vsize >= 3)
	{
		rdata = get_render_context();
		push_vertex_to_render(face, 0, rdata, 0);
		i = 1;
		while (i < vsize - 1)
		{
			push_vertex_to_render(face, i, rdata, 1);
			push_vertex_to_render(face, i + 1, rdata, 2);
			transform(rdata);
			draw_triangle(rdata, (t_color){rand()});
			i++;
		}
	}
}