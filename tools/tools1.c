/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 21:17:38 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/14 13:33:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void    putblank(t_lista *g)
{
    if (g->space == 1 && g->minus == 0)
    {
        //printf("a");
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

// int     divide(double nbr, int *i, int *f, int prec)
// {
//     int sign;

//     (*f) = 0;
//     sign = 0;
// //    printf("DIVIDE\n");
//     (*i) = (int)nbr;
// 	nbr -= (*i);
//     if (nbr < 0)
//         sign = 1;
// //    printf("nbr = %lf\n", nbr);
// 	while (nbr > 0 && prec > 0)
// 	{
//         // printf("nbr = %lf f = %d\n", nbr, (*f));
// 		(*f) *= 10;
// 		(*f) += (int)(nbr *= 10);
// 		nbr -= (int)nbr;
// 		prec--;
//         // printf("f = %d\n", (*f));
// 	}
//     // printf("finalf = %d\n", (*f));
//     return (sign);
// }

void    putfloat(char *dec, int length, t_lista *g)
{
    int i;
    int f;

    i = 0;
    //printf("len = %d\n", length);
    while (i <= length && dec[i])
    {
        //printf("dec[%d] = %c\n", i, dec[i]);
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

int		widthf(int x, t_lista *g)
{
	int y;
	long z;

	z = x;
	y = 0;
	if (z == 0)
	{	
		if (g->dot == 1 && g->prec == 0)
			return (0);
		return (1);
	}
	if (z < 0)
	{
		g->minus = 1;
		z *= -1;
	}
	while (z > 0)
	{
		z /= 10;
		y++;
	}
	return (y);
}