#ifndef MATH_H
# define MATH_H

# include "common.h"

int			absi(int num);

t_float3	cross3f(t_float3 v1, t_float3 v2);

float		dot3f(t_float3 v1, t_float3 v2);

t_float3	norm3f(t_float3 v);

#endif