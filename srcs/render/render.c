#include "render.h"

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
		vector_foreach(mesh->faces, &invoke_draw_face);
	}
}