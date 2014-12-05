/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 13:19:27 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/03 13:19:31 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

typedef struct 		s_format
{
	char			flag;
	int				width;
	int				precision;
	char			*length;
	char			format;
}					t_format;

void		reset_struct(t_format **format)
{
	(*format)->flag = 0;
	(*format)->width = 0;
	(*format)->precision = 0;
	(*format)->length = NULL;
	(*format)->flag = 0;
}