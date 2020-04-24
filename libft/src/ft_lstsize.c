/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:11:38 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:11:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_lstsize(t_list *lst)
{
	int			elem;
	t_list		*actual;

	elem = 0;
	if (!lst)
		return (0);
	actual = lst;
	while (actual != NULL)
	{
		actual = actual->next;
		elem++;
	}
	return (elem);
}
