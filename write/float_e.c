/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 21:34:14 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/15 13:41:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char    *dec_to_e(char *decimal)
{ //gli zeri sono già tagliati da trim
    int x;
    int y;
    int exponent;
    int exposign;

    x = 0;
    y = -1;
    exposign = 0;
    printf("dec = %s\n", decimal);
    while (decimal[x] != '.' && decimal[x]) //controllo prima della virgola
    {
        if (decimal[x] >= '1' && decimal[x] <= '9')
            y++;;
        x++;
    }
    printf("x = %d\n", x);
    if (y == -1)
    {
        while (decimal[x + y] == '0' && decimal[x + y])
            y++;
        exposign = 1;
    }
    exponent = exposign == 1 ? y + 1 : x - (y + 1);
    y += x;
    printf("decimalb = %s\nx = %d\ny = %d\n", decimal, x, y);
    if (exposign == 0)
    {   
        while (x > 0)
        {
            decimal[x] = decimal[x - 1];
            x--;
        }
        decimal[x + 1] = '.';
    }
    else if (exposign == 1)
    {
        while (x <= y)
        {
            decimal[x] = decimal[x + 1];
            x++;
        }
        decimal[x] = '.';
    }
    printf("decimal = %s\nexponent = %d\nexposign = %d\n", decimal, exponent, exposign);
    return (ft_bigint_trim(decimal));
}

int     set_length_e(char *decimal, t_lista *g)
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

void    float_e(char *decimal, t_lista *g)
{
    int     length;

    decimal = dec_to_e(decimal);
    printf("precision = %d\n", g->prec);
    decimal = fill_right(decimal, (g->prec + 2));
    printf("dec = %s\n", decimal);
    length = set_length_e(decimal, g);
    write_e(decimal, g, length);
}