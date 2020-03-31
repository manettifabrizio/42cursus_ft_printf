/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagstools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:48:34 by fmanetti          #+#    #+#             */
/*   Updated: 2020/03/31 18:15:12 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		count(char *ptr, int x)
{
	int	i;

	i = 0;
	while (ptr[x + i] >= '0' && ptr[x + i] <= '9')
		i++;
	while (ptr[x + i] == '*')
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

char			*numbersandstar(char *prt, int *x, t_lista *g, va_list ap)
{	
	char 	*str;
	int 	y;
	int 	z;

	y = *x + count(prt, *x);
	if (prt[*x] >= '1' && prt[*x] <= '9')
	{
		z = ft_atoi(ft_substr(prt, *x, count(prt, *x)));
		prt = ft_substr(prt, y, ft_strlen(prt) - y);
	}
	else if (prt[*x] == '*')
	{
		(*x)++;
		z = va_arg(ap, int);
		if (z <= 0)
		{
			str = ft_itoa(z);
			prt = ft_substr(prt, *x, ft_strlen(prt) - (*x));
			prt = ft_strjoin(str, prt);
		}
		else
			prt = ft_substr(prt, y, ft_strlen(prt) - y);
	}
	widthorprec(z, g);
	return (prt);
}

