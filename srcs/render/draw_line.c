#include "render.h"

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

void		draw_line(t_int2 pStart, t_int2 pEnd, t_color color)
{
	t_int2	pMid;
	int		*x = (int*)&pMid;
	int		*y = ((int*)&pMid) + 1;

	clamp_screen_coord(&pStart);
	clamp_screen_coord(&pEnd);

	if (switch_points_by_checking_deltas( &pStart, &pEnd ))
	{
		swaps((size_t*)&x, (size_t*)&y);
	}

	t_int2	delta = (t_int2){pEnd.x - pStart.x, pEnd.y - pStart.y};
	int		yStep = absi(delta.y) * 2;
	int		yAccum = 0;
	for(pMid = pStart; pMid.x < pEnd.x; pMid.x++)
	{
		set_pixel_color(*x, *y, color.rgba);

		yAccum += yStep;
		if (yAccum > delta.x)
		{
			pMid.y += ((delta.y > 0)? 1 : -1);
			yAccum -= delta.x * 2;
		}
	}
}