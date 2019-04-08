void	swapi(int *n1, int *n2)
{
	if (n1 && n2)
	{
		int	tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
}

void	swapull(unsigned long long *n1, unsigned long long *n2)
{
	if (n1 && n2)
	{
		unsigned long long	tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
}