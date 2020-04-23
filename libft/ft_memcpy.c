/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:57:22 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:11:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*psrc;
	char	*pdst;

	i = 0;
	psrc = (char*)src;
	pdst = (char*)dst;
	if (n == 0 || dst == src)
		return (dst);
	while (n--)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
