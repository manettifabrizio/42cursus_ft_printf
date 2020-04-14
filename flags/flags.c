/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:00:33 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/14 12:32:52 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		check(t_lista *g)
{
	if (g->width < 0)
		g->width *= -1;
	if (g->plus == 1)
		g->space = 0;
	if (g->precm == 1)
		g->prec *= -1;
	if ((g->prec >= 0 && g->conv != 's' && g->conv != 'c' \
 		&& g->conv != 'p' && g->conv != '%' && g->dot == 1) || g->dash == 1)
 		g->zero = 0;
	if (g->conv == 'f' && (g->dot == 0 || g->prec < 0))
		g->prec = 6;
}

static void		charactersflags(char *prt, int x, t_lista *g, va_list ap)
{
	int y;

	while (prt[x] != g->conv && prt[x])
	{
		y = 0;
		if ((prt[x] >= '1' && prt[x] <= '9') || prt[x] == '*')
		{
			prt = numbersandstar(prt, &x, g, ap);
			y++;
		}
		else if (prt[x] == '-' && g->dot == 0)
			g->dash = 1;
		else if (prt[x] == '-')
			g->precm = 1;
		else if (prt[x] == '+')
			g->plus = 1;
		else if (prt[x] == ' ')
			g->space = 1;
		else if (prt[x] == '0' && g->dot == 0)
			g->zero = 1;
		else if (prt[x] == '0')
			g->prec = 0;
		else if (prt[x] == '#')
			g->hashtag = 1;
		else if (prt[x] == '.')
		 	g->dot = 1;
		if (y == 0)
			x++;
	}
}

void			flags(const char *prt, t_lista *g, va_list ap)
{
	int		x;
	char	*str;

	x = 0;
	
	str = ft_strdup(prt);
	while (prt[x] != '%')
		x++;
	x++;
	charactersflags(str, x, g, ap);
	check(g);
	//printf("dash = %d\nplus = %d\nspace = %d\nzero = %d\nhashtag = %d\nwidth = %d\ndot = %d\nprec = %d\nminus = %d\nconv = %c\n", g->dash, g->plus, g->space, g->zero, g->hashtag, g->width, g->dot, g->prec, g->minus, g->conv);
}