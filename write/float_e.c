/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 21:34:14 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/16 11:21:54 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char    *dec_to_e(char *dec, int *sign, t_lista *g)
{ //gli zeri sono già tagliati da trim
    int x;
    int y;

    x = 0;
    y = -1;
    (*sign) = 0;
    // printf("dec = %s\n", dec);
    while (dec[x] != '.' && dec[x]) //controllo prima della virgola
    {
        if (dec[x] >= '1' && dec[x] <= '9')
            y++;
        x++;
    }
    // printf("x = %d\n", x);
    if (y == -1)
    {
        y = 1; //per la virgola
        (*sign) = 1;
        while (dec[x + y] == '0' && dec[x + y])
            y++;
        // printf("dec[%d] = %c\n", x + y, dec[x + y - 1]);
        if ((dec[x + y - 1] == '0' || dec[x + y - 1] == '.') && \
            dec[x + y] == '\0')
            (*sign) = 2;
    }
    if ((*sign) != 2)
        g->expo = (*sign) == 1 ? ft_itoa(y) : ft_itoa(x - (y + 1));
    // printf("decb = %s\nx = %d\ny = %d\nsign = %d\n", dec, x, y, *sign);
    y += x;
    if ((*sign) == 0)
    {   
        while (x > 0)
        {
            dec[x] = dec[x - 1];
            x--;
        }
        dec[x + 1] = '.';
    }
    else if ((*sign) == 1)
    {
        while (x < y)
        {
            dec[x] = dec[x + 1];
            x++;
        }
        dec[x] = '.';
    }
    else if (*sign == 2)
        g->expo = ft_strdup("00");
    g->expo = ft_strlen(g->expo) == 1 ? ft_strjoin("0", g->expo) : g->expo;
    // printf("dec = %s\nexpo = %s\nsign = %d\n", dec, g->expo, *sign);
    return (ft_bigint_trim(dec));
}

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

int     set_length_e(char *decimal, t_lista *g)
{
    int i;
    int length;

	i = 0;
    while (decimal[i] != '.' && decimal[i])
		i++;
    i += 2; //+2 x e+-
    if (g->dot == 1 && g->prec == 0)
        length = i + g->hashtag + ft_strlen(g->expo);
    else
	    length = i + 1 + g->prec + ft_strlen(g->expo);
    return (length);
}

char    *zero_check(char *str, int len)
{
    int x;
    int y;
    char str1[len + 1];

    x = 0;
    y = 0;
    if (str[0] == '.')
		str = ft_strjoin("0", str);
    while (str[y] != '.' && str[y])
		y++;
	while (x <= (len - y))
	{
		str1[x] = '0';
		x++;
	}
	str1[x] = '\0';
    str = ft_strjoin(str, str1);
	return (str);
}

void    float_e(char *decimal, t_lista *g)
{
    int     sign;
    int     length;

    decimal = dec_to_e(decimal, &sign, g);
    // printf("precision = %d\n", g->prec);
    // printf("dec = %s\n", decimal);
    decimal = zero_check(decimal, g->prec);
    length = set_length_e(decimal, g);
    // printf("strlen = %d\n", ft_strlen(decimal) + width(g->expo, g));
    // printf("length = %d\n", length);
    write_e(decimal, length, sign, g);
}