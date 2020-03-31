/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:49:47 by fmanetti          #+#    #+#             */
/*   Updated: 2020/03/31 16:23:36 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		hexa1(char *hexa, int length, t_lista *g)
{
	if (g->width > g->prec)
	{
		if (g->dash == 1)
		{
			puthashtag(hexa, g);
			putzero(g->prec, length, g);
			puthexa(hexa, length, g);
			putspace(g->width, g->prec, g);
		}
		else
		{ 
			putspace(g->width, g->prec, g);
			puthashtag(hexa, g);
			putzero(g->prec, length, g);
			puthexa(hexa, length, g);
		}
	}
	else
	{
		puthashtag(hexa, g);
		putzero(g->prec, length, g);
		puthexa(hexa, length, g);
	}
}

static void		hexa2(char *hexa, int length, t_lista *g)
{
	if (g->width > g->prec)
	{
		if (g->zero == 1)
		{
			puthashtag(hexa, g);
			putzero(g->width, length, g);
			puthexa(hexa, length, g);
		}
		else
		{
			if (g->dash == 1)
			{
				puthashtag(hexa, g);
				puthexa(hexa, length, g);
				putspace(g->width, length, g);
			}
			else
			{
				putspace(g->width, length, g);
				puthashtag(hexa, g);
				puthexa(hexa, length, g);
			}
		}			
	}
	else
	{
		puthashtag(hexa, g);
		puthexa(hexa, length, g);
	}
}

void			hexadecimal(va_list ap, t_lista *g)
{
	int		nb;
	char	*hexa;
	int		length;

	nb = va_arg(ap, long);
	hexa = ft_conv_hexa2(nb);
	length = ft_strlen(hexa);
	if (g->minus == 1)
		g->width--;
	if (g->hashtag == 1 && !(ft_strncmp(hexa, "0", 1) == 0))
		g->width -= 2;
	if (ft_strncmp(hexa, "0", 1) == 0 && g->prec == 0 && g->dot == 1)
		g->width++;
	if (g->prec > length)
		hexa1(hexa, length, g);
	else
		hexa2(hexa, length, g);
}