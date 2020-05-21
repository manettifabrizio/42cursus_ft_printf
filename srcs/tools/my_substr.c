/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:08:25 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 08:09:31 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

void					my_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	x;

	i = 0;
	x = 0;
	if (!s)
		return ;
	while (s[x])
		x++;
	while (i < len)
	{
		s[i] = s[start + i];
		i++;
	}
	s[i] = '\0';
}