/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:08:48 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/22 13:41:59 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			choice(char c, t_lista *g)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == 's' || c == 'p' \
		|| c == 'x' || c == 'X' || c == '%' || c == 'n' || c == 'f' \
			|| c == 'e')
		g->conv = c;
}

static int		decide(t_lista *g, va_list ap)
{
	int		x;

	x = 0;
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

static void		flagbegin(t_lista *g)
{
	g->dash = 0;
	g->plus = 0;
	g->space = 0;
	g->zero = 0;
	g->hashtag = 0;
	g->dot = 0;
	g->prec = 0;
	// g->precm = 0;
	g->width = 0;
	g->minus = 0;
	g->expo = "00";
	g->inf = 1;
	g->conv = 'a';
}

static void		print(const char *prt, int *i, t_lista *g)
{
	write(1, &(prt[*i]), 1);
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
	// printf("pr1 = %p\n", prt);
	pr = ft_strdup(prt);
	// printf("pr2 = %p\n", pr);
	while (pr[i])
	{
		if (pr[i] != '%')
			print(pr, &i, &g);
		else
		{
			// printf("pr3 = %p\n", pr);
			flagbegin(&g);
			x = setx(pr, i, &g);
			flags(pr, &g, ap);
			// printf("pr4 = %p\n", pr);
			decide(&g, ap);
			my_substr(pr, x, ft_strlen(pr) - x);
			// printf("pr7 = %p\n", pr);
			i = 0;
		}
	}
	va_end(ap);
	free((void*)pr);
	return (g.written);
}
