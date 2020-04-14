/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:46:14 by fmanetti          #+#    #+#             */
/*   Updated: 2020/03/20 21:17:11 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	my_putstr(char *str, int x, t_lista *g)
{
	int i;

	i = 0;
	if (x == 0 || (ft_strncmp(str, "0", 1) == 0 && g->prec == 0 && g->dot == 1))
		return ;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
