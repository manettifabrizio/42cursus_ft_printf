/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:00:33 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/22 13:42:58 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		check(t_lista *g)
{
	if (g->width < 0)
		g->width *= -1;
	if (g->plus == 1)
		g->space = 0;
	// if (g->prec < 0)
	// 	g->prec *= -1;
	if ((g->prec >= 0 && g->conv != 's' && g->conv != 'c' \
		&& g->conv != 'p' && g->conv != '%' && g->conv != 'f' \
		&& g->conv != 'e' && g->dot == 1) || g->dash == 1)
		g->zero = 0;
	if ((g->conv == 'f' || g->conv == 'e') && (g->dot == 0 || g->prec < 0))
		g->prec = 6;
}

static void		charactersflags(char *pr, int x, t_lista *g, va_list ap)
{
	int y;

	y = 0;
	while (pr[x] != g->conv && pr[x])
	{
		if ((pr[x] >= '1' && pr[x] <= '9') || pr[x] == '*')
		{ //se non passa da qui prt non è allocato e quindi crasha 
		// per esempio %d
			// printf("pras = %p\n", pr);
			numbersandstar(pr, x, g, ap);
			// printf("prdf = %p\n", pr);
			x = -1;
		}
		else if (pr[x] == '-' && g->dot == 0)
			g->dash = 1;
		// else if (pr[x] == '-')
		// 	g->precm = 1;
		else if (pr[x] == '+')
			g->plus = 1;
		else if (pr[x] == ' ')
			g->space = 1;
		else if (pr[x] == '0' && g->dot == 0)
			g->zero = 1;
		else if (pr[x] == '0')
			g->prec = 0;
		else if (pr[x] == '#')
			g->hashtag = 1;
		else if (pr[x] == '.')
			g->dot = 1;
		x++;
	}
}

void			flags(char *pr, t_lista *g, va_list ap)
{
	int		x;
	char	*s;

	x = 0;
	while (pr[x] != '%')
		x++;
	x++;
	s = ft_strdup(pr);
	// printf("s = %p\n", s);
	charactersflags(s, x, g, ap);
	check(g);
	free((void*)s);
}
