/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 21:21:47 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/15 13:40:50 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		write_f2(char *decimal, t_lista *g, int length)
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

static void		write_f(char *decimal, t_lista *g, int length)
{
	if (g->width > length)
	{
		if (g->zero == 1)
		{
			minus(g);
			putblank(g);
			putzero(g->width, length, g);
			putfloat(decimal, length, g);
		}
		else
			write_f2(decimal, g, length);		
	}
	else
	{
		putblank(g);
		minus(g);
		putfloat(decimal, length, g);
	}
}

static int      set_length_f(char *decimal, t_lista *g)
{
    int i;
    int f;
    int length;

	i = 0;
	f = 0;
    while (decimal[i] != '.' && decimal[i])
		i++;
	while (decimal[i + f])
		f++;
    if (g->dot == 1 && g->prec != 0)
        length = i + 1 + g->prec;
    else if (g->dot == 1 && g->prec == 0)
        length = i + g->hashtag;
    else
	    length = i + 1 + g->prec;
    return (length);
}

void    		float_f(char *decimal, t_lista *g)
{
    int length;

    length = set_length_f(decimal, g);
    if (g->minus == 1 || g->plus == 1)
		g->width--;
	write_f(decimal, g, length);
}