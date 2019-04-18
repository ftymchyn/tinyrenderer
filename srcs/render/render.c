#include "render.h"

static void	prepare_render_context()
{
	t_sdl	*sdl;
	t_rdata	*rdata;
	int		i;

	sdl = get_sdl_context();
	rdata = get_render_context();
	i = 0;
	while (i < (sdl->width * sdl->height))
	{
		rdata->zbuffer[i] = FLOAT_MIN;
		i++;
	}
}

static void	invoke_draw_face(void *data)
{
	t_face	*face;

	face = (t_face*)data;
	draw_face(face);
}

void		render(t_mesh *mesh)
{
	if (mesh)
	{
		prepare_render_context();
		vector_foreach(mesh->faces, &invoke_draw_face);
	}
}