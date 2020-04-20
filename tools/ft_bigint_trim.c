/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 20:07:18 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/15 21:20:04 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char			*bigintrimright(char *str)
{
	size_t i;
	size_t len;

	len = ft_strlen(str);
	i = len - 1;
	if (len == 0)
		return (str);
	while (str[i] && str[i] == '0')
	{
		str[i] = 0;
		i--;
	}
	return (str);
}

static char		*bigintrimleft(char *str)
{
	size_t nb;
	size_t i;
	size_t len;

	nb = 0;
	len = ft_strlen(str);
	while (str[nb] && str[nb] == '0')
		nb++;
	if (nb == 0)
		return (str);
	i = 0;
	while (str[i] && i + nb <= len)
	{
		str[i] = str[i + nb];
		i++;
	}
	while (i != len)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char			*ft_bigint_trim(char *str)
{
	str = bigintrimleft(str);
	str = bigintrimright(str);
	return (str);
}
