/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagstools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:48:34 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/20 11:42:53 by fmanetti         ###   ########.fr       */
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

static char		*numbers(char *prt, int x, int y, int *z)
{
	(*z) = ft_atoi(ft_substr(prt, x, count(prt, x)));
	prt = ft_substr(prt, y, ft_strlen(prt) - y);
	return (prt);
}

char			*numbersandstar(char *prt, int x, t_lista *g, va_list ap)
{
	char	*str;
	int		y;
	int		z;

	z = 0;
	str = NULL;
	y = x + count(prt, x);
	if (prt[x] >= '0' && prt[x] <= '9')
		prt = numbers(prt, x, y, &z);
	else if (prt[x] == '*')
	{
		z = va_arg(ap, int);
		x++;
		if (z <= 0)
		{
			str = ft_itoa(z);
			prt = ft_substr(prt, x, ft_strlen(prt) - x);
			prt = ft_strjoin(str, prt);
		}
		else
			prt = ft_substr(prt, y, ft_strlen(prt) - y);
	}
	widthorprec(z, g);
	return (prt);
}
