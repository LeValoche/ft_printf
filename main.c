/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:19:49 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/03 13:19:51 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "includes/libft.h"
#include <stdio.h> // A ENLEVER

typedef struct 		s_format
{
	char			flag;
	int				width;
	int				precision;
	char			*length;
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

int					get_nb(const char *str)
{
	int				i;
	char			*result;

	i = -1;
	result = (char *)malloc(sizeof(char) * 3);
	while (ft_isdigit(str[++i]) && str[i])
		;
	return (ft_atoi(ft_strncpy(result, (char *)str, i)));
}

void				parse_format(char *str, t_format **format)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr("+-#0 ", str[i]))
			(*format)->flag = str[i];
		else if (ft_isdigit(str[i]))
			i += ft_intlen((*format)->width = get_nb(str + i)) - 1;
		else if (str[i] == '.')
			i += ft_intlen((*format)->precision = get_nb(str + i + 1));
		else if (!ft_strncmp(str + i, "ll", 2) || !ft_strncmp(str + i, "hh", 2))
			i += ft_strlen((*format)->length = ft_strsub(str, i, 2)) - 1;
		else if (ft_strchr("lLzj", str[i]))
		{
			(*format)->length = (char *)malloc(sizeof(char) * 2);
			(*format)->length[0] = str[i];
			(*format)->length[1] = '\0';
		}
		else if (ft_strchr("sSpDioOuUxXcC%", str[i]))
		{
			(*format)->format = str[i];
			break;
		}
		else
			break;
	}
}

int					find_type(va_list ap, char *str, int i)
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
	t_format		*format;

	i = -1;
	va_start(ap, str);
	format = (t_format *)malloc(sizeof(t_format));
	while (str[++i])
	{
		if (str[i] == '%')
		{
			reset_struct(&format);
			parse_format((char *)str + i + 1, &format);
			ft_putchar(format->flag);
			ft_putstr(" / ");
			ft_putnbr(format->width);
			ft_putstr(" / ");
			ft_putchar('.');
			ft_putnbr(format->precision);
			ft_putstr(" / ");
			ft_putstr(format->length);
			ft_putstr(" / ");
			ft_putchar(format->format);
		}
		else
			ft_putchar(str[i]);
	}
	va_end(ap);
	return (1);
}

int					main(int argc, char **argv)
{
	ft_printf("%#88.3lls");
	return (0);
}