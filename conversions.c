unsigned int		octal(int n)
{
	unsigned int	result;
	int				i;

	i = 1;
	result = 0;
	while (n != 0)
	{
		result += n % 8 * i;
		n /= 8;
		i *= 10;
	}
	return (result);
}

unsigned int		decimal(int n)
{
	unsigned int	result;
	int				i;

	i = 1;
	result = 0;
	while (n != 0)
	{
		result += n % 10 * i;
		n /= 10;
		i *= 10;
	}
	return (result);
}