/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:31:56 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:07:41 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

static const char	*g_half_powers[] =
{
	P0,
	P1,
	P2,
	P3,
	P4,
	P5,
	P6,
	P7,
	P8,
	P9,
	P10,
	P11,
	P12,
	P13,
	P14,
	P15,
	P16,
	P17,
	P18,
	P19,
	P20,
	P21,
	P22,
	P23,
	P24,
	P25,
	P26,
	P27,
	P28,
	P29,
	P30,
	P31,
	P32,
	P33,
	P34,
	P35,
	P36,
	P37,
	P38,
	P39,
	P40,
	P41,
	P42,
	P43,
	P44,
	P45,
	P46,
	P47,
	P48,
	P49,
	P50,
	P51,
	P52,
	P53,
	P54,
	P55,
	P56,
	P57,
	P58,
	P59,
	P60,
	P61,
	P62,
	P63,
	P64,
	0,
};

static char		*ft_mantissa(char *binary, char *decimal, size_t size)
{
	int x;

	x = 0;
	ft_strcpy(decimal, "1");
	while (binary[x] && x < 64)
	{
		if (binary[x] == '1')
			decimal = ft_bigint_add(decimal, g_half_powers[x + 1], size);
		x++;
	}
	if (ft_strcmp(decimal, "1") == 0)
		ft_strcpy(decimal, "0");
	return (decimal);
}

static int		ft_exponent(char *binary, int offset)
{
	int		x;
	int		exponent;
	int		poweroftwo;

	x = 1;
	exponent = 0;
	poweroftwo = offset;
	while (binary[x] && x < 12)
	{
		if (binary[x] == '1')
			exponent += poweroftwo;
		poweroftwo /= 2;
		x++;
	}
	return (exponent - (offset - 1));
}

static char		*infinity_or_nan(char *output)
{
	if (ft_strcmp(output, "0") == 0)
	{
		ft_strcpy(output, "inf");
	}
	else
	{
		ft_strcpy(output, "nan");
	}
	return (output);
}

static char		*final_str(char *output, int expo, size_t size)
{
	while (expo != 0)
	{
		if (expo < 0)
		{
			output = ft_bigint_divide_by_two(output, size);
			expo++;
		}
		else
		{
			output = ft_bigint_multiply_by_two(output, size);
			expo--;
		}
	}
	return (output);
}

char			*ft_ftoa(double nbr, char *binary, size_t size)
{
	int		exponent;
	char	*decimal;

	exponent = ft_exponent(binary, 1024);
	if (!(decimal = (char *)ft_memalloc(size * sizeof(char))))
		return (NULL);
	decimal = ft_mantissa(binary + 12, decimal, size);
	if (nbr == 1)
		ft_strcpy(decimal, "1.");
	if (nbr == 0)
		ft_strcpy(decimal, "0.");
	else if (exponent == 1024)
		decimal = infinity_or_nan(decimal);
	else if (exponent != -1022)
		decimal = final_str(decimal, exponent, size);
	return (decimal);
}
