#include "render.h"

t_rdata		*get_render_context()
{
	static t_rdata	render_data;

	return (&render_data);
}