/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:13:59 by fmanetti          #+#    #+#             */
/*   Updated: 2020/03/31 16:14:37 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int      setlength(double nbr, t_lista *g)
{
    int i;
    int f;
    int sign;
    int length;

    sign = divide(nbr, &i, &f, g->prec);
    i = width(i, g);
    f = width(f, g);
    if (g->dot == 1)
    {
        if (g->prec > f)
            length = sign + i + 1 + g->prec;
        else
            length = sign + i + 1 + f;
    }
    else if (g->dot == 1 && g->prec == 0)
        length = sign + i;
    else
        length = sign + i;
    return (length);
}

static void		wfloat1(t_lista *g, double nbr, int length)
{
	if (g->width > length)
	{
		if (g->zero == 1)
		{
			minus(g);
			putblank(g);
			putzero(g->width, length, g);
			putfloat(nbr, g);
		}
		else
		{
			if (g->dash == 1)
			{
				minus(g);
				putblank(g);
				putfloat(nbr, g);
				putspace(g->width, length, g);
			}
			else
			{
				putblank(g);
				putspace(g->width, length, g);
				minus(g);
			    putfloat(nbr, g);
			}
		}			
	}
	else
	{
		putblank(g);
		minus(g);
		putfloat(nbr, g);
	}
}

void    wfloat(va_list ap, t_lista *g)
{
    float   nb;
    double  nbr;
    int     length;

    nbr = va_arg(ap, double);
    length = setlength(nbr, g);
	if (g->minus == 1 || g->plus == 1)
		g->width--;
	wfloat1(g, nbr, length);
}