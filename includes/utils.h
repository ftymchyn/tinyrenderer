#ifndef UTILS_H
# define UTILS_H

# include "sdl_window.h"

int		clampi(int num, int min, int max);
void	clamp_screen_coord(t_int2 *point);

void	swapi(int *n1, int *n2);
void	swaps(size_t *n1, size_t *n2);

#endif