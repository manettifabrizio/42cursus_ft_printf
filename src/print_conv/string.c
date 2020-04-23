/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:20:16 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:07:41 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

static void		string3(char *str, int length, t_lista *g)
{
	if (g->width > length)
	{
		if (g->dash == 1)
		{
			putstrm(str, g->prec, length, g);
			putspace(g->width, g->prec, g);
		}
		else
		{
			putspace(g->width, g->prec, g);
			putstrm(str, g->prec, length, g);
		}
	}
	else
		putstrm(str, g->prec, length, g);
}

static void		string2(int length, t_lista *g)
{
	if (g->zero == 1)
		putzero(g->width, length, g);
	else
	{
		if (g->dash == 1)
			putspace(g->width, length, g);
		else
			putspace(g->width, length, g);
	}
}

static void		string1(char *str, int length, t_lista *g)
{
	g->written += length;
	if (g->width > length)
	{
		if (g->zero == 1)
		{
			putzero(g->width, length, g);
			my_putstr(str, length, g);
		}
		else
		{
			if (g->dash == 1)
			{
				my_putstr(str, length, g);
				putspace(g->width, length, g);
			}
			else
			{
				putspace(g->width, length, g);
				my_putstr(str, length, g);
			}
		}
	}
	else
		my_putstr(str, length, g);
}

void			string(va_list ap, t_lista *g)
{
	char	*str;
	int		length;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	length = ft_strlen(str);
	if (g->prec == 0 && g->dot == 1)
		length = 0;
	else if (g->prec < 0)
		g->prec = length;
	else if (g->prec < length && g->prec != 0)
		length = g->prec;
	if (g->prec > length || (g->prec == 0 && g->dot == 0))
		string1(str, length, g);
	else if (g->prec == 0 && g->dot == 1)
		string2(length, g);
	else
		string3(str, length, g);
}
