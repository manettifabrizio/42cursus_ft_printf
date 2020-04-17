/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 21:34:14 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/17 17:22:42 by fmanetti         ###   ########.fr       */
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

int     set_length_e(char *decimal, t_lista *g)
{
    int i;
    int length;

	i = 0;
    g->expo = ft_strlen(g->expo) == 1 ? ft_strjoin("0", g->expo) : g->expo;
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

char    *move_dot(char *dec, int sign, int x, int y)
{
    y += x;
    if (sign == 0)
    {   
        while (x > 0)
        {
            dec[x] = dec[x - 1];
            x--;
        }
        dec[x + 1] = '.';
    }
    else if (sign == 1)
    {
        while (x < y)
        {
            dec[x] = dec[x + 1];
            x++;
        }
        dec[x] = '.';
    }
    return (dec);
}

char    *dec_to_e(char *dec, int *sign, t_lista *g)
{ 
    int x;
    int y;

    x = 0;
    y = -1;
    while (dec[x] != '.' && dec[x]) 
    {
        if (dec[x] >= '1' && dec[x] <= '9' && y == -1)
            y++;
        x++;
        (*sign) = 0;
    }
    if (y == -1)
    {
        y = 1;
        (*sign) = 1;
        while (dec[x + y] == '0' && dec[x + y])
            y++;
        printf("\ndec[%d + %d - 1] = %c\ndec[x + y] = %c\n", x, y, dec[x + y - 1], dec[x + y]);
        if ((dec[x + y - 1] == '0' && dec[x + y] == '\0') || \
            (dec[x + y - 1] == '.' && dec[x + y] == '\0'))
            (*sign) = 2;
    }
    printf("sign = %d\n", *sign);
    printf("0dec = %s\n", dec);
    dec = move_dot(dec, (*sign), x, y);
    printf("1dec = %s\n", dec);
    if ((*sign) == 1)
        g->expo = ft_itoa(y);
    else if ((*sign) == 0)
        g->expo = ft_itoa(x - (y + 1));
    else
        g->expo = ft_strdup("00");
    printf("expo = %s\n", g->expo);
    return (ft_bigint_trim(dec));
}

char    *re_dec_to_e(char *dec)
{
    int x;
    int y;

    x = 0;
    y = -1;
    while (dec[x] != '.' && dec[x]) 
    {
        if (dec[x] >= '1' && dec[x] <= '9' && y == -1)
            y++;
        x++;
    }
    move_dot(dec, 0, x, y);
    return (ft_bigint_trim(dec));
}

void    float_e(char *decimal, size_t size, t_lista *g)
{
    int     sign;
    int     length;
    
    sign = -1;
    if (ft_strcmp(decimal, "inf") == 0 || ft_strcmp(decimal, "nan") == 0)
	{
		g->hashtag = 0;
		g->zero = 0;
		if (ft_strcmp(decimal, "nan") == 0)
		{
			g->plus = 0;
			g->space = 0;
		}
        length = 3;
	}
    else
    {
        decimal = dec_to_e(decimal, &sign, g);
        decimal = ft_bigint_round(decimal, g->prec, size);
        printf("2dec = %s\nexpob = %s\n", decimal, g->expo);
        if (decimal[0] != '.' && decimal[1] != ('.' && '\0'))
        {
            if (sign == 0 || sign == 2)
                g->expo = ft_itoa(ft_atoi(g->expo) + (getindex(decimal, '.') - 1));
            else
                g->expo = ft_itoa(ft_atoi(g->expo) - (getindex(decimal, '.') - 1));
            re_dec_to_e(decimal);
        }
        printf("3dec = %s\nexpoa = %s\n", decimal, g->expo);
        printf("sign = %d\n", sign);
        decimal = zero_check(decimal, g->prec);
        length = set_length_e(decimal, g);
        printf("\n\n");
    }
    if (g->minus == 1 || g->plus == 1)
		g->width--;
    write_e(decimal, length, sign, g);
}