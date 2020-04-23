/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 21:21:47 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:07:41 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

static void		write_f2(char *decimal, int length, t_lista *g)
{
	if (g->dash == 1)
	{
		minus(g);
		putblank(g);
		putfloat(decimal, length, g);
		putspace(g->width, length, g);
	}
	else
	{
		putblank(g);
		putspace(g->width, length, g);
		minus(g);
		putfloat(decimal, length, g);
	}
}

static void		write_f(char *decimal, int length, t_lista *g)
{
	if (g->width > length)
	{
		if (g->zero == 1 && g->inf == 0)
		{
			minus(g);
			putblank(g);
			putzero(g->width, length, g);
			putfloat(decimal, length, g);
		}
		else
			write_f2(decimal, length, g);
	}
	else
	{
		putblank(g);
		minus(g);
		putfloat(decimal, length, g);
	}
}

void			float_f(char *decimal, t_lista *g)
{
	int	length;

	if (ft_strcmp(decimal, "inf") == 0 || ft_strcmp(decimal, "nan") == 0)
	{
		g->hashtag = 0;
		g->zero = 0;
		if (ft_strcmp(decimal, "nan") == 0)
		{
			g->plus = 0;
			g->space = 0;
		}
	}
	if (g->dot == 1 && g->prec == 0)
		length = ft_strlen(decimal) + g->hashtag;
	else
		length = ft_strlen(decimal);
	if (g->minus == 1 || g->plus == 1)
		g->width--;
	write_f(decimal, length, g);
	free((void*)decimal);
}
