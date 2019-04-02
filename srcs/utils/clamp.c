int	clampi(int num, int min, int max)
{
	int	result = num;

	if (num < min)
	{
		result = min;
	}
	else if (num > max)
	{
		result = max;
	}

	return (result);
}