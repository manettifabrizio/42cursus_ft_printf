/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinteger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:11:56 by fmanetti          #+#    #+#             */
/*   Updated: 2020/03/31 16:33:49 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		uinteger1(t_lista *g, unsigned int nbr, int length)
{
	if (g->width > g->prec)
	{
		if (g->dash == 1)
		{
			putzero(g->prec, length, g);
			my_putnbrx(nbr, g);
			putspace(g->width, g->prec, g);
		}
		else
		{
			putspace(g->width, g->prec, g);
			putzero(g->prec, length, g);
			my_putnbrx(nbr, g);
		}
	}
	else
	{
		putzero(g->prec, length, g);
		my_putnbrx(nbr, g);
	}
}

static void		uinteger2(t_lista *g, unsigned int x, int length)
{
	if (g->width > g->prec)
	{
		if (g->zero == 1)
		{
			putzero(g->width, length, g);
			my_putnbrx(x, g);
		}
		else
		{
			if (g->dash == 1)
			{
				my_putnbrx(x, g);
				putspace(g->width, length, g);
			}
			else
			{
				putspace(g->width, length, g);
				my_putnbrx(x, g);
			}
		}			
	}
	else
		my_putnbrx(x, g);
}

void			uinteger(va_list ap, t_lista *g)
{
	unsigned int		nbr;
	int					length;

	nbr = va_arg(ap, unsigned int);
	length = widthu(nbr, g);
	if (g->prec > length)
		uinteger1(g, nbr, length);
	else
		uinteger2(g, nbr, length);
}