#include "object.h"

static void	clear_face(void *data)
{
	t_face	*face;

	face = (t_face*)data;
	if (face)
	{
		vector_clear(&face->vdata, NULL);
	}
}

void		clear_mesh(t_mesh **mesh)
{
	if (mesh && *mesh)
	{
		vector_clear(&((*mesh)->faces), &clear_face);
		vector_clear(&((*mesh)->vertexes), NULL);
		ft_memdel((void**)mesh);
	}
}