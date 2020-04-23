/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:22:52 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:07:41 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

void	my_putnbr(int nb, t_lista *g)
{
	long nbr;

	if (nb == 0 && g->prec == 0 && g->dot == 1)
		return ;
	nbr = nb;
	if (nbr < 0)
		nbr *= -1;
	if (nbr > 9)
		my_putnbr(nbr / 10, g);
	ft_putchar(nbr % 10 + '0');
}
