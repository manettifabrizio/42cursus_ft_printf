/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:04:09 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 08:06:46 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

void	my_putnbrx(unsigned int nb, t_lista *g)
{
	if (nb == 0 && g->prec == 0 && g->dot == 1)
		return ;
	if (nb > 9)
		my_putnbrx(nb / 10, g);
	ft_putchar(nb % 10 + '0');
}