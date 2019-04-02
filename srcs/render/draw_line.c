#include "tinyrenderer.h"

static void	clamp_point(t_sdl *sdl, t_int2 *point)
{
	point->x = clampi(point->x, 0, sdl->width - 1);
	point->y = clampi(point->y, 0, sdl->height - 1);
}

static t_bool	switch_points_by_checking_deltas(t_int2 *pStart, t_int2 *pEnd)
{
	t_bool	result = (absi(pStart->x - pEnd->x) < absi(pStart->y - pEnd->y));

	if (result)
	{
		swapi((int*)pStart, ((int*)pStart) + 1);
		swapi((int*)pEnd, ((int*)pEnd) + 1);
	}

	if (pStart->x > pEnd->x)
	{
		swapi((int*)pStart, (int*)pEnd);
		swapi(((int*)pStart) + 1, ((int*)pEnd) + 1);
	}

	return (result);
}

void		draw_line(t_sdl *sdl, t_int2 pStart, t_int2 pEnd, t_color color)
{
	t_int2	pMid;
	float	t;
	int		*x = (int*)&pMid;
	int		*y = ((int*)&pMid) + 1;

	clamp_point(sdl, &pStart);
	clamp_point(sdl, &pEnd);

	if (switch_points_by_checking_deltas( &pStart, &pEnd ))
	{
		x = ((int*)&pMid) + 1;
		y = (int*)&pMid;
	}

	for(pMid = pStart; pMid.x < pEnd.x; pMid.x++)
	{
		t = (pMid.x - pStart.x) / (float)(pEnd.x - pStart.x);
		pMid.y = pStart.y * (1.0f - t) + pEnd.y * t;

		sdl->pixels[(sdl->height - *y) * sdl->width + *x] = color.rgba;
	}
}