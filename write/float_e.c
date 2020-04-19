/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 21:34:14 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/19 15:57:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		write_e2(char *decimal, int length, int sign, t_lista *g)
{
	if (g->dash == 1)
	{
		minus(g);
		putblank(g);
		putexpo(decimal, length, sign, g);
		putspace(g->width, length, g);
	}
	else
	{
		putblank(g);
		putspace(g->width, length, g);
		minus(g);
		putexpo(decimal, length, sign, g);
	}
}

static void		write_e(char *decimal, int length, int sign, t_lista *g)
{
	if (g->width > length)
	{
		if (g->zero == 1)
		{
			minus(g);
			putblank(g);
			putzero(g->width, length, g);
			putexpo(decimal, length, sign, g);
		}
		else
			write_e2(decimal, length, sign, g);		
	}
	else
	{
		putblank(g);
		minus(g);
		putexpo(decimal, length, sign, g);
	}
}

static int     inf_or_nan_e(char *decimal, t_lista *g)
{
    g->hashtag = 0;
    g->zero = 0;
    if (ft_strcmp(decimal, "nan") == 0)
    {
        g->plus = 0;
        g->space = 0;
    }
    return (3);
}

void            float_e(char *decimal, size_t size, t_lista *g)
{
    int     sign;
    int     length;
    
    sign = 0;
    if (ft_strcmp(decimal, "inf") == 0 || ft_strcmp(decimal, "nan") == 0)
		length = inf_or_nan_e(decimal, g);
    else
    {
        decimal = dec_to_e(decimal, &sign, g);
        decimal = ft_bigint_round(decimal, g->prec, size);
        if (decimal[0] != '.' && decimal[1] != ('.' && '\0'))
        {
            if (sign == 0 || sign == 2)
                g->expo = ft_itoa(ft_atoi(g->expo) + (getindex(decimal, '.') - 1));
            else
                g->expo = ft_itoa(ft_atoi(g->expo) - (getindex(decimal, '.') - 1));
            re_dec_to_e(decimal);
        }
        decimal = zero_check(decimal, g->prec);
        length = set_length_e(decimal, g);
    }
    if (g->minus == 1 || g->plus == 1)
		g->width--;
    write_e(decimal, length, sign, g);
}