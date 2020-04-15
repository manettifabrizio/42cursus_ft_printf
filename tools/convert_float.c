/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 16:13:59 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/15 13:19:07 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

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

void	which(char *decimal, t_lista *g)
{
	if (g->conv == 'f')
		float_f(decimal, g);
	if (g->conv == 'e')
		float_e(decimal, g);
}

static char		*deal_with_particular_cases(char *output)
{
	if (output[0] == '.')
		output = ft_strjoin("0", output);
	if (ft_strlen(output) == 0)
		output = ft_strcpy(output, "0");
	return (output);
}

void    convert_float(va_list ap, t_lista *g)
{
    double  nbr;
	char	*binary;
	char	*decimal;

    nbr = va_arg(ap, double);
	binary = doubletobinary(nbr);
	if (binary[0] == '1')
		g->minus = 1;
	decimal = ft_ftoa(nbr, binary);
	if (ft_strchr(decimal, 'i') == 0 && ft_strchr(decimal, 'n') == 0) //taglio in base alla precisione
	{
		decimal = ft_bigint_round(decimal, g->prec);
		decimal = deal_with_particular_cases(decimal);
	}
	which(decimal, g);
	ft_memdel((void **)&binary);
	ft_memdel((void **)&decimal);
}