/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 21:17:38 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/19 15:58:54 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void    putblank(t_lista *g)
{
    if (g->space == 1 && g->minus == 0)
    {
        write(1, " ", 1);
        g->width--;
        g->written++;
    }
}

void    puthashtag(char *hexa, t_lista *g)
{
    if (g->hashtag == 1)
    {
        if (ft_strncmp(hexa, "0", 1) == 0)
            return ;
        if (g->conv == 'x')
            write(1, "0x", 2);
        else if (g->conv == 'X')
            write(1, "0X", 2);
        g->written += 2;
    }
}

void    putfloat(char *dec, int length, t_lista *g)
{
    int i;

    i = 0;
    while (i <= length && dec[i])
    {
        ft_putchar(dec[i]);
        i++;
        g->written++;
    }
    if (g->hashtag == 1 && g->dot == 1 && g->prec == 0)
    {
        ft_putchar('.');
        g->written++;
    }
}

int     set_length_e(char *decimal, t_lista *g)
{
    int i;
    int length;

	i = 0;
    g->expo = ft_strlen(g->expo) == 1 ? ft_strjoin("0", g->expo) : g->expo;
    while (decimal[i] != '.' && decimal[i])
		i++;
    i += 2;
    if (g->dot == 1 && g->prec == 0)
        length = i + g->hashtag + ft_strlen(g->expo);
    else
	    length = i + 1 + g->prec + ft_strlen(g->expo);
    return (length);
}

void    putexpo(char *dec, int length, int sign, t_lista *g)
{
    int i;

    i = 0;
    if ((ft_strcmp(dec, "inf") && ft_strcmp(dec, "nan")) != 0)
        length -= (2 + ft_strlen(g->expo));
    while (i < length && dec[i])
    {
        ft_putchar(dec[i++]);
        g->written++;
    }
    if (g->dot == 1 && g->prec == 0 && g->hashtag)
    {
        ft_putchar('.');
        g->written++;
    }
    if ((ft_strcmp(dec, "inf") && ft_strcmp(dec, "nan")) != 0)
    {
        if (sign == 0 || sign == 2)
            my_putstr("e+", 2, g);
        else
            my_putstr("e-", 2, g);
        g->written += (2 + ft_strlen(g->expo));
        ft_putstr(g->expo);
    }
}
