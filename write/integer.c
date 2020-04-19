/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:00:25 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/20 01:14:55 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		integer2(int nbr, int length, t_lista *g)
{
	putblank(g);
	minus(g);
	putzero(g->prec, length, g);
	my_putnbr(nbr, g);
}

static void		integer1(int nbr, int length, t_lista *g)
{
	if (g->width > g->prec)
	{
		if (g->dash == 1)
		{
			putblank(g);
			minus(g);
			putzero(g->prec, length, g);
			my_putnbr(nbr, g);
			putspace(g->width, g->prec, g);
		}
		else
		{
			putblank(g);
			putspace(g->width, g->prec, g);
			minus(g);
			putzero(g->prec, length, g);
			my_putnbr(nbr, g);
		}
	}
	else
		integer2(nbr, length, g);
}

static void		integer4(int nbr, int length, t_lista *g)
{
	if (g->dash == 1)
	{
		minus(g);
		putblank(g);
		my_putnbr(nbr, g);
		putspace(g->width, length, g);
	}
	else
	{
		putblank(g);
		putspace(g->width, length, g);
		minus(g);
		my_putnbr(nbr, g);
	}
}

static void		integer3(int nbr, int length, t_lista *g)
{
	if (g->width > g->prec)
	{
		if (g->zero == 1)
		{
			minus(g);
			putblank(g);
			putzero(g->width, length, g);
			my_putnbr(nbr, g);
		}
		else
			integer4(nbr, length, g);
	}
	else
	{
		putblank(g);
		minus(g);
		my_putnbr(nbr, g);
	}
}

void			integer(va_list ap, t_lista *g)
{
	int					nbr;
	int					length;

	nbr = va_arg(ap, int);
	length = width(nbr, g);
	if (g->minus == 1 || g->plus == 1)
		g->width--;
	if (g->prec > length)
		integer1(nbr, length, g);
	else
		integer3(nbr, length, g);
}
