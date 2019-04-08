#include "render.h"

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
	int		*x = (int*)&pMid;
	int		*y = ((int*)&pMid) + 1;

	clamp_point(sdl, &pStart);
	clamp_point(sdl, &pEnd);

	if (switch_points_by_checking_deltas( &pStart, &pEnd ))
	{
		swapull((unsigned long long*)&x, (unsigned long long*)&y);
	}

	t_int2	delta = (t_int2){pEnd.x - pStart.x, pEnd.y - pStart.y};
	int		yStep = absi(delta.y) * 2;
	int		yAccum = 0;
	for(pMid = pStart; pMid.x < pEnd.x; pMid.x++)
	{
		set_pixel_color(sdl, *x, *y, color.rgba);

		yAccum += yStep;
		if (yAccum > delta.x)
		{
			pMid.y += ((delta.y > 0)? 1 : -1);
			yAccum -= delta.x * 2;
		}
	}
}