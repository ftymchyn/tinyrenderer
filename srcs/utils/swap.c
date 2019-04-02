void	swapi(int *n1, int *n2)
{
	if (n1 && n2)
	{
		int	tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
}