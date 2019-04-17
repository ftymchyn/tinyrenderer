#include "render.h"

static void	push_vertex_to_render(t_face *face, size_t idx_in, t_rdata *rdata, size_t idx_out)
{
	const t_int3	*vdata;
	const t_float3	*v;
	const t_float3	*vn;

	vdata = vector_at(face->vdata, idx_in);
	v =  vector_at(face->owner->v, vdata->x - 1);
	vn =  vector_at(face->owner->vn, vdata->z - 1);
	rdata->v[idx_out] = (v ? *v : (t_float3)(0.0f));
	rdata->vn[idx_out] = (vn ? *vn : (t_float3)(0.0f));
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
	t_float3	normal;
	t_color		c;
	size_t		i;
	float		cosa;

	if (face && vector_size(face->vdata) >= 3)
	{
		rdata = get_render_context();
		push_vertex_to_render(face, 0, rdata, 0);
		i = 1;
		while (i < vector_size(face->vdata) - 1)
		{
			push_vertex_to_render(face, i, rdata, 1);
			push_vertex_to_render(face, i + 1, rdata, 2);
			normal = norm3f(cross3f(rdata->v[1] - rdata->v[0], rdata->v[2] - rdata->v[0]));
			cosa = dot3f(normal, rdata->screen_dir);
			if (cosa > 0.0f)
			{
				transform(rdata);
				c.bytes = (t_byte4)( cosa * 255);
				draw_triangle(rdata, c);
			}
			i++;
		}
	}
}