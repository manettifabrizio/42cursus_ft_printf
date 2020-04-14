/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:13:59 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/14 13:32:41 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int      setlength(char *decimal, t_lista *g)
{
    int i;
    int f;
    int length;

	i = 0;
	f = 0;
	//printf("dec = %s\n", decimal);
    while (decimal[i] != '.' && decimal[i])
		i++;
	while (decimal[i + f])
		f++;
    if (g->dot == 1 && g->prec != 0)
    {
        if (g->prec > f)
            length = i + g->prec;
        else
            length = i + f;
    }
    else if (g->dot == 1 && g->prec == 0)
        length = i + g->hashtag;
    else
        length = i;
    return (length);
}

static void		wfloat1(char *decimal, t_lista *g, int length)
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
	}
	else
	{
		putblank(g);
		minus(g);
		putfloat(decimal, length, g);
	}
}

char	*memorytobinary(unsigned char i, char *binary)
{
	int		x;
	char	tmp;
	char	base[3];
	
	x = 0;
	ft_strcpy(base, "01");
	while (i != 0)
	{
		binary[x] = base[i % 2];
		x++;
		i /= 2;
	}
	while (x != 8)
		binary[x++] = base[0];
	binary[x] = '\0';
	x = 0;
	while (x != 4)
	{
		tmp = binary[x];
		binary[x] = binary[7 - x];
		binary[7 - x] = tmp;
		x++;
	}
	return (binary);
}

char	*doubletobinary(double nbr)
{
	int				i;
	char 			*binary;
	unsigned char 	memory[sizeof(double) + 1];
	char			tmpbin[10];

	i = (sizeof(double)) - 1;
	if (!(binary = ft_memalloc(100 * sizeof(char)))) //free
		return (NULL);
	ft_memcpy(memory, &nbr, sizeof(double)); //copia gli 8bit di memoria (double) in memory
	while (i != -1)
	{
		binary = ft_strcat(binary, memorytobinary(memory[i], tmpbin));
		i--;
	}
	return (binary);
}

// static char		*deal_with_particular_cases(char *output, t_lista *g)
// {
// 	if (output[0] == '.')
// 		output = ft_str_join("0", output, flag);
// 	if (ft_strlen(output) == 0)
// 		output = ft_strcpy(output, "0");
// 	if (flag->hash && flag->precision == 0)
// 		output = ft_str_join_r(output, ".", flag);
// 	return (output);
// }

void    wfloat(va_list ap, t_lista *g)
{
    double  nbr;
    int     length;
	char	*binary;
	char	*decimal;
	long	tmp;

    nbr = va_arg(ap, double);
	//printf("nbr = %lf\n", nbr);
	binary = doubletobinary(nbr);
	//printf("bin = %s\n", binary);
	if (binary[0] == '1')
		g->minus = 1;
	decimal = ft_ftoa(nbr, binary, g);
	//printf("dec = %s\n", decimal);
	if (ft_strchr(decimal, 'i') == 0 && ft_strchr(decimal, 'n') == 0) //taglio in base alla precisione
	{
		tmp = g->prec == -1 ? 6 : g->prec;
		decimal = ft_bigint_round(decimal, g->prec);
		//decimal = deal_with_particular_cases(decimal, g);
	}
	//printf("dec = %s\n", decimal);
	length = setlength(decimal, g);
	if (g->minus == 1 || g->plus == 1 || g->hashtag == 1)
		g->width--;
	wfloat1(decimal, g, length);
	ft_memdel((void **)&binary);
	ft_memdel((void **)&decimal);
}