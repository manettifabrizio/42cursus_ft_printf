/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:05:30 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/20 01:11:51 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		pointer1(char *add, int length, t_lista *g)
{
	if (g->zero == 1)
	{
		write(1, "0x", 2);
		putzero(g->width, (length + 2), g);
		my_putstr(add, length, g);
	}
	else
	{
		if (g->dash == 1)
		{
			write(1, "0x", 2);
			my_putstr(add, length, g);
			putspace(g->width, (length + 2), g);
		}
		else
		{
			putspace(g->width, (length + 2), g);
			write(1, "0x", 2);
			my_putstr(add, length, g);
		}
	}
}

void			pointer(va_list ap, t_lista *g)
{
	long	nb;
	char	*add;
	int		length;

	nb = va_arg(ap, long);
	add = ft_conv_hexa(nb);
	if (add == NULL)
		add = "(null)";
	length = ft_strlen(add);
	if (ft_strncmp(add, "0", 1) == 0 && g->prec == 0 && g->dot == 1)
		length = 0;
	g->written += (length + 2);
	if (g->width > length)
		pointer1(add, length, g);
	else
	{
		write(1, "0x", 2);
		putzero(g->prec, length, g);
		my_putstr(add, length, g);
	}
}
