#ifndef COMMON_H
# define COMMON_H

# include <assert.h>

typedef unsigned char	t_byte4 __attribute__((ext_vector_type(4)));
typedef float			t_float4 __attribute__((ext_vector_type(4)));
typedef int				t_int2 __attribute__((ext_vector_type(2)));

typedef enum			e_bool
{
	FALSE,
	TRUE
}						t_bool;

#endif