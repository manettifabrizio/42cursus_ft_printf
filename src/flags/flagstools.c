/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagstools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:48:34 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:07:41 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

static int		count(char *prt, int x)
{
	int	i;

	i = 0;
	while (prt[x + i] == '*')
		i++;
	while (prt[x + i] >= '0' && prt[x + i] <= '9')
		i++;
	return (i);
}

static void		widthorprec(int x, t_lista *g)
{
	if (g->dot == 1)
		g->prec = x;
	else
		g->width = x;
}

static void		numbers(char *prt, int x, int y, int *z)
{
	char	*str;

	str = ft_substr(prt, x, count(prt, x));
	(*z) = ft_atoi(str);
	free((void*)str);
	my_substr(prt, y, ft_strlen(prt) - y);
}

void			numbersandstar(char *prt, int x, t_lista *g, va_list ap)
{
	int		y;
	int		z;

	z = 0;
	y = x + count(prt, x);
	if (prt[x] >= '0' && prt[x] <= '9')
		numbers(prt, x, y, &z);
	else if (prt[x] == '*')
	{
		z = va_arg(ap, int);
		x++;
		if (z <= 0)
		{
			if (g->dot == 0)
				g->dash = 1;
			my_substr(prt, y, ft_strlen(prt) - y);
		}
		else
			my_substr(prt, y, ft_strlen(prt) - y);
	}
	widthorprec(z, g);
}
