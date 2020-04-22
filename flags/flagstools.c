/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagstools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:48:34 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/22 13:35:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		count(char *prt, int x)
{
	int	i;

	i = 0;
	while (prt[x + i] == '*')
		i++;
	while (prt[x + i] >= '0' && prt[x + i] <= '9')
		i++;
	return (i);
}

static void		widthorprec(int x, t_lista *g)
{
	if (g->dot == 1)
		g->prec = x;
	else
		g->width = x;
}

static void		numbers(char *prt, int x, int y, int *z)
{
	char	*str;

	str = ft_substr(prt, x, count(prt, x));
	// printf("ciao1 = %s %p\n", prt, prt);
	(*z) = ft_atoi(str);
	free((void*)str);
	my_substr(prt, y, ft_strlen(prt) - y);
	// printf("ciao2 = %p\n", prt);
}

void			numbersandstar(char *prt, int x, t_lista *g, va_list ap)
{
	// char	*str;
	// char	*tmp;
	int		y;
	int		z;

	z = 0;
	//str = NULL;
	y = x + count(prt, x);
	if (prt[x] >= '0' && prt[x] <= '9')
		numbers(prt, x, y, &z);
	else if (prt[x] == '*')
	{
		z = va_arg(ap, int);
		x++;
		if (z <= 0)
		{
			// str = ft_itoa(z);
			// printf("prt6 = %p\n", prt);
			// my_substr(prt, x, ft_strlen(prt) - x);
			// printf("prt7 = %p\n", prt);
			// tmp = ft_strjoin(str, prt);
			// free((void*)str);
			// free((void*)prt);
			// prt = tmp;
			// (*c) = 1;
			//free((void*)tmp);
			if (g->dot == 0)
				g->dash = 1;
			my_substr(prt, y, ft_strlen(prt) - y);
		}
		else
			my_substr(prt, y, ft_strlen(prt) - y);
	}
	widthorprec(z, g);
	// printf("prt8 = %p\n", prt);
}
