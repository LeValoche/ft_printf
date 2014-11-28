#include <stdarg.h>
#include "includes/libft.h"
#include <stdio.h> // A ENLEVER

int					ft_printf(const char *str, ...)
{
	va_list			ap;
	int				i;

	i = -1;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			ft_putstr(va_arg(ap, char *));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'd' || str[i + 1] == 'i')
		{
			ft_putnbr(va_arg(ap, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'o')
		{
			ft_putnbr(octal(va_arg(ap, unsigned int)));
			i++;
		}
		else if (tr[i] == '%' && str[i + 1] == 'u')
		{
			ft_putnbr(decimal(va_arg(ap, unsigned int)));
			i++;
		}
		else
			ft_putchar(str[i]);
	}
	va_end(ap);
	return (1);
}

int					main(int argc, char **argv)
{
	char			*str = "Coucou toi";

	ft_printf("Coucou %o\n", 0b1111);
	ft_putnbr(decimal(0b101));
	return (0);
}