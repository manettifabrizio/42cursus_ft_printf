/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 21:34:14 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 00:33:47 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		write_e2(char *dec, int length, int sign, t_lista *g)
{
	if (g->dash == 1)
	{
		minus(g);
		putblank(g);
		putexpo(dec, length, sign, g);
		putspace(g->width, length, g);
	}
	else
	{
		putblank(g);
		putspace(g->width, length, g);
		minus(g);
		putexpo(dec, length, sign, g);
	}
}

static void		write_e(char *dec, int length, int sign, t_lista *g)
{
	if (g->width > length)
	{
		if (g->zero == 1)
		{
			minus(g);
			putblank(g);
			putzero(g->width, length, g);
			putexpo(dec, length, sign, g);
		}
		else
			write_e2(dec, length, sign, g);
	}
	else
	{
		putblank(g);
		minus(g);
		putexpo(dec, length, sign, g);
	}
}

static int		inf_or_nan_e(char *dec, t_lista *g)
{
	g->hashtag = 0;
	g->zero = 0;
	if (ft_strcmp(dec, "nan") == 0)
	{
		g->plus = 0;
		g->space = 0;
	}
	return (3);
}

void			float_e(char *dec, size_t size, t_lista *g)
{
	int	sign;
	int length;
	char *tmp;

	sign = 0;
	if (ft_strcmp(dec, "inf") == 0 || ft_strcmp(dec, "nan") == 0)
		length = inf_or_nan_e(dec, g);
	else
	{
		dec = dec_to_e(dec, &sign, g);
		dec = ft_bigint_round(dec, g->prec, size);
		if (dec[0] != '.' && dec[1] != ('.' && '\0'))
		{
			printf("expo1 = %p\n", g->expo);
			if (sign == 0 || sign == 2)
				tmp = ft_itoa(ft_atoi(g->expo) + (getindex(dec, '.') - 1));
			else
				tmp = ft_itoa(ft_atoi(g->expo) - (getindex(dec, '.') - 1));
			free((void*)g->expo);
			g->expo = tmp;
			printf("expo2 = %p tmp = %p\n", g->expo, tmp);
			re_dec_to_e(dec);
		}
		printf("dec1 = %p\n", dec);
		dec = zero_check(dec, g->prec);
		printf("dec2 = %p\n", dec);
		length = set_length_e(dec, g);
	}
	if (g->minus == 1 || g->plus == 1)
		g->width--;
	write_e(dec, length, sign, g);
	printf("expo5 = %p\n", g->expo);
	if (ft_strcmp(dec, "inf") != 0 && ft_strcmp(dec, "nan") != 0)
		free((void*)g->expo);
	free((void*)dec);
}
