/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:08:48 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/24 11:29:10 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

void			choice(char c, t_lista *g)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == 's' || c == 'p' \
		|| c == 'x' || c == 'X' || c == '%' || c == 'n' || c == 'f' \
			|| c == 'e')
		g->conv = c;
}

static int		decide(t_lista *g, va_list ap)
{
	if (g->conv == 'd' || g->conv == 'i')
		integer(ap, g);
	else if (g->conv == 'u')
		uinteger(ap, g);
	else if (g->conv == 'c')
		character(ap, g);
	else if (g->conv == 's')
		string(ap, g);
	else if (g->conv == 'p')
		pointer(ap, g);
	else if (g->conv == 'x' || g->conv == 'X')
		hexadecimal(ap, g);
	else if (g->conv == 'n')
		number(ap, g);
	else if (g->conv == 'f' || g->conv == 'e')
		convert_float(ap, g);
	else if (g->conv == '%')
		percent(g);
	return (0);
}

static void		print(char *pr, int *i, t_lista *g)
{
	write(1, &(pr[*i]), 1);
	g->written++;
	(*i)++;
}

int				ft_printf(const char *prt, ...)
{
	int			i;
	int			x;
	char		*pr;
	va_list		ap;
	t_lista		g;

	i = 0;
	va_start(ap, prt);
	g.written = 0;
	pr = ft_strdup(prt);
	while (pr[i])
	{
		if (pr[i] != '%')
			print(pr, &i, &g);
		else
		{
			x = flags(pr, i, &g, ap);
			decide(&g, ap);
			my_substr(pr, x, ft_strlen(pr) - x);
			i = 0;
		}
	}
	va_end(ap);
	free((void*)pr);
	return (g.written);
}
