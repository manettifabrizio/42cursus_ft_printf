/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 15:11:59 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/20 10:34:51 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char			*zero_check(char *str, int len)
{
	int		x;
	int		y;
	char	str1[len + 1];

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

static char		*move_dot(char *dec, int sign, int x, int y)
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

char			*re_dec_to_e(char *dec)
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

static void		set_expo(int x, int y, int *sign, t_lista *g)
{
	if ((*sign) == 1)
		g->expo = ft_itoa(y);
	else if ((*sign) == 0)
		g->expo = ft_itoa(x - (y + 1));
	else
		g->expo = ft_strdup("00");
}

char			*dec_to_e(char *dec, int *sign, t_lista *g)
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
	if (y == -1)
	{
		y = 1;
		(*sign) = 1;
		while (dec[x + y] == '0' && dec[x + y])
			y++;
		if ((dec[x + y - 1] == '0' && dec[x + y] == '\0') || \
			(dec[x + y - 1] == '.' && dec[x + y] == '\0'))
			(*sign) = 2;
	}
	dec = move_dot(dec, (*sign), x, y);
	set_expo(x, y, sign, g);
	return (ft_bigint_trim(dec));
}
