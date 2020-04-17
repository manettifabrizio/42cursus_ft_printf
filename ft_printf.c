/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:08:48 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/16 21:07:30 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		choice(char c, t_lista *g)
{
	if (c == 'd')
		g->conv = 'd';
	else if (c == 's')
		g->conv = 's';
	else if (c == 'c')
		g->conv = 'c';
	else if (c == 'p')
		g->conv = 'p';
	else if (c == 'i')
		g->conv = 'i';
	else if (c == 'u')
		g->conv = 'u';
	else if (c == 'x')
		g->conv = 'x';
	else if (c == 'X')
		g->conv = 'X';
	else if (c == '%')
	 	g->conv = '%';
	else if (c == 'n')
		g->conv = 'n';
	else if (c == 'f')
	 	g->conv = 'f';
	else if (c == 'e')
		g->conv = 'e';
	// else if (c == 'g')
	// 	g->conv = 'g';
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
	else if (g->conv == 'f' || g->conv == 'e' || g->conv == 'g')
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
	g->precm = 0;
	g->width = 0;
	g->minus = 0;
	g->expo = ft_strdup("00");
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
	va_list 	ap;
	t_lista 	g;

	i = 0;
	va_start(ap, prt);
	g.written = 0;
	while (prt[i])
	{
		if (prt[i] != '%')
			print(prt, &i, &g);
		else
		{
			//printf("prt = %s\n", prt);
			flagbegin(&g);
			x = setx(prt, i, &g);
			flags(prt, &g, ap);
			decide(&g, ap);
			prt = ft_substr(prt, x, ft_strlen(prt) - x);
			i = 0;
			//printf("dash = %d\nplus = %d\nspace = %d\nzero = %d\nhashtag = %d\nwidth = %d\ndot = %d\nprec = %d\nminus = %d\nconv = %c\n", g.dash, g.plus, g.space, g.zero, g.hashtag, g.width, g.dot, g.prec, g.minus, g.conv);
		}
	}
	va_end(ap);
	return(g.written);
}