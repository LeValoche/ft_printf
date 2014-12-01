void				octal(int n)
{
	if (n > 0)
	{
		octal(n / 8);
		ft_putnbr(n % 8);
	}
}

void				decimal(int n)
{
	if (n > 0)
	{
		decimal(n / 10);
		ft_putnbr(n % 10);
	}
}

void				hexa(int n)
{
	if (n > 0)
		hexa(n / 16);
	if (n % 16 >= 10)
		ft_putchar(n % 16 + 87);
	else if (n > 0)
		ft_putnbr(n % 16);
}

void				hexa2(int n)
{
	if (n > 0)
		hexa2(n / 16);
	if (n % 16 >= 10)
		ft_putchar(n % 16 + 55);
	else if (n > 0)
		ft_putnbr(n % 16);
}