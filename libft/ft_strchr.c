/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:26:03 by fmanetti          #+#    #+#             */
/*   Updated: 2019/11/12 18:25:58 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	d = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == d)
		return ((char*)&s[i]);
	return (0);
}
