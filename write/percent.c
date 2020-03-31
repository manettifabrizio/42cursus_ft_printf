/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:55:29 by fmanetti          #+#    #+#             */
/*   Updated: 2020/03/31 16:35:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		percent1(t_lista *g)
{
	if (g->width > 1)
	{
		if (g->zero == 1)
		{
			putzero(g->width, 1, g);
			write(1, "%", 1);
		}
		else
		{
			if (g->dash == 1)
			{
				write(1, "%", 1);
				putspace(g->width, 1, g);
			}
			else
			{
				putspace(g->width, 1, g);
				write(1, "%", 1);
			}
		}			
	}
	else
		write(1, "%", 1);
}

void    		percent(t_lista *g)
{
	percent1(g);
	g->written++;
}
