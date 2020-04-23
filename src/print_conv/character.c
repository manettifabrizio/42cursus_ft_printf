/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:15:24 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:07:41 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

void	character(va_list ap, t_lista *g)
{
	char	c;

	c = va_arg(ap, int);
	g->written += 1;
	if (g->width > 1)
	{
		if (g->dash == 1)
		{
			ft_putchar(c);
			putspace(g->width, 1, g);
		}
		else
		{
			putspace(g->width, 1, g);
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
}
