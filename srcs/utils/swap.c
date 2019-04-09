#include "common.h"

void	swapi(int *n1, int *n2)
{
	if (n1 && n2)
	{
		int	tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
}

void	swaps(size_t *n1, size_t *n2)
{
	if (n1 && n2)
	{
		unsigned long long	tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
}