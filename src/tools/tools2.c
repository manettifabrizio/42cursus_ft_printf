/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:49:21 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:07:41 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

void	minus(t_lista *g)
{
	if (g->minus == 1)
	{
		write(1, "-", 1);
		g->written++;
	}
	else if (g->plus == 1)
	{
		write(1, "+", 1);
		g->written++;
	}
}

char	*up(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		str[x] = ft_toupper(str[x]);
		x++;
	}
	return (str);
}

int		x_and_conv(const char *prt, int x, t_lista *g)
{
	x++;
	while (g->conv == 'a' && prt[x] != '\0')
	{
		choice(prt[x], g);
		x++;
	}
	return (x);
}

int		width(int x, t_lista *g)
{
	int		y;
	long	z;

	z = x;
	y = 0;
	if (z == 0)
	{
		if (g->dot == 1 && g->prec == 0)
			return (0);
		g->written++;
		return (1);
	}
	if (z < 0)
	{
		g->minus = 1;
		z *= -1;
	}
	while (z > 0)
	{
		z /= 10;
		y++;
	}
	g->written += y;
	return (y);
}

int		widthu(unsigned int x, t_lista *g)
{
	unsigned int y;

	y = 0;
	if (x == 0)
	{
		if (g->dot == 1 && g->prec == 0)
			return (0);
		g->written++;
		return (1);
	}
	while (x > 0)
	{
		x /= 10;
		y++;
	}
	g->written += y;
	return (y);
}
