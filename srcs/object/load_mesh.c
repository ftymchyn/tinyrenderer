#include "object.h"

static void		clear_str(void *data)
{
	free(*(char**)data);
}

static t_float3	parse_coord(t_vector *strvec)
{
	t_float3	result;

	result.xyz = 0.0f;
	if (vector_size(strvec) >= 4)
	{
		// TODO : implement atof in libft
		result.x = atof(*(char**)vector_at(strvec, 1));
		result.y = atof(*(char**)vector_at(strvec, 2));
		result.z = atof(*(char**)vector_at(strvec, 3));
	}
	return (result);
}

static t_face	parse_face(t_vector *strvec)
{
	size_t	i;
	size_t	j;
	t_face	result;
	t_int3	vdata;
	char	*str;

	i = 1;
	result.vdata = vector_create(sizeof(t_int3));
	str = NULL;
	while (i < vector_size(strvec))
	{
		str = *(char**)vector_at(strvec, i);
		j = 0;
		while (j < 3)
		{
			vdata[j] = ft_atoi(str);
			str = ft_strchr(str, '/') + 1;
			j++;
		}
		vector_pushback(result.vdata, &vdata);
		i++;
	}
	return (result);
}

static void		parse_obj_line(const char *line, t_mesh *mesh)
{
	t_vector	*line_split;
	char		*line_type;
	t_float3	coord;
	t_face		face;

	line_split = ft_strsplit_vec(line, ' ');
	line_type = NULL;
	face.owner = mesh;
	if (vector_size(line_split) >= 1)
	{
		line_type = *(char**)vector_at(line_split, 0);
		if (ft_strequ(line_type, "v") || ft_strequ(line_type, "vn"))
		{
			coord = parse_coord(line_split);
			if (ft_strequ(line_type, "v"))
				vector_pushback(mesh->v, &coord);
			else
				vector_pushback(mesh->vn, &coord);
		}
		else if (ft_strequ(line_type, "f"))
		{
			face = parse_face(line_split); 
			vector_pushback(mesh->faces, &face);
		}
	}
	vector_clear(&line_split, &clear_str);
}

t_mesh			*load_mesh(const char *filename)
{
	t_mesh	*result;
	char	*line;
	int		fd;

	result = (t_mesh*)ft_memalloc(sizeof(t_mesh));
	line = NULL;
	fd = open(filename, O_RDONLY);
	if ( fd != -1 && result)
	{
		result->v = vector_create(sizeof(t_float3));
		result->vn = vector_create(sizeof(t_float3));
		result->faces = vector_create(sizeof(t_face));
		while (get_next_line(fd, &line) > 0)
		{
			parse_obj_line(line, result);
			ft_memdel((void**)&line);
		}
	}
	return (result);
}