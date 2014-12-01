#include <stdarg.h>
#include "includes/libft.h"
#include <stdio.h> // A ENLEVER

typedef struct 		s_format
{
	char			flag;
	int				width;
	int				precision;
	char			length;
	char			format;
}					t_format;

int					ft_lenc(const char *str, char c)
{
	int				i;

	i = -1;
	while (str[++i] != c)
		;
	return (i);
}

void				parse_format(char *str)
{
	t_format		*format;
	int				i;

	i = 0;
	if (str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == 0 || str[i] == ' ')
	{
		format->flag = str[i];
		i++;
	}
	while (isdigit(str[i])
	{
		
	}

}

int					find_type(va_list ap, const char *str, int i)
{
		if (str[i] == '%' && str[i + 1] == 's')
			ft_putstr(va_arg(ap, char *));
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			ft_putnbr(va_arg(ap, int));
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar('%');
		else if (str[i] == '%' && str[i + 1] == 'o')
			octal(va_arg(ap, unsigned int));
		else if (str[i] == '%' && str[i + 1] == 'u')
			decimal(va_arg(ap, unsigned int));
		else if (str[i] == '%' && str[i + 1] == 'x')
			hexa(va_arg(ap, unsigned int));
		else if (str[i] == '%' && str[i + 1] == 'X')
			hexa2(va_arg(ap, unsigned int));
		else if (str[i] == '%' && str[i + 1] == 'c')
			ft_putchar(va_arg(ap, int));
		else
		{
			ft_putchar(str[i]);
			return (0);
		}
		return (1);
}

int					ft_printf(const char *str, ...)
{
	va_list			ap;
	int				i;

	i = -1;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
			parse_format(ft_strsub(str, i + 1, ft_lenc(str, ' ')));
		// i += find_type(ap, str, i);
	}
	va_end(ap);
	return (1);
}

int					main(int argc, char **argv)
{
	ft_printf("Coucou %s, j'ai %d fraises et %x limaces\n", "yolo", 1873, 0b010110);
	return (0);
}
