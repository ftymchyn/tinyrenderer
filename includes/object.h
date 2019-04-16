#ifndef OBJECT_H
# define OBJECT_H

# include "common.h"
# include "libft.h"

/**
 * Mesh data :
 *  "*v"     is dynamic t_float3[]  (*.obj line "v 0.5 0.5 0.5")
 *  "*vn"    is dynamic t_float3[]  (*.obj line "vn 0.5 0.5 0.5")
 *  "*faces" is dynamic t_face[]    (*.obj line "f 1/1/1 2/2/2 3/3/3")
 */
typedef struct	s_mesh
{
	t_vector	*v;
	t_vector	*vn;
	t_vector	*faces;
}				t_mesh;

/**
 * Face data :
 *  "*owner" is pointer to face's owner (t_mesh)
 *  "*vdata" is dynamic t_int3[], each t_int3 represents indexes to v/vt/vn
 */
typedef struct	s_face
{
	t_mesh		*owner;
	t_vector	*vdata;
}				t_face;


t_mesh			*load_mesh(const char *filename);
void			clear_mesh(t_mesh **mesh);

#endif