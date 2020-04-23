/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_round.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 10:54:41 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:51:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

static char	*get_to_add(int n)
{
	int		i;
	char	*to_add;

	if (!(to_add = (char *)ft_memalloc((n + 4) * sizeof(char))))
		return (NULL);
	ft_strcpy(to_add, "0.1");
	i = 2;
	while (n != 0)
	{
		to_add[i] = '0';
		i++;
		n--;
	}
	to_add[i] = '1';
	i++;
	to_add[i] = 0;
	return (to_add);
}

static char	*ft_banker_round(char *dst, int precision, int i, size_t size)
{
	int		j;
	char	*to_add;

	j = i - 1;
	if (i < (int)size)
	{
		if (dst[i - 1] == '.')
		{
			i--;
			j--;
		}
		if ((dst[j] - '0') % 2 == 0)
		{
			dst[i] = 0;
			return (dst);
		}
		else
		{
			to_add = get_to_add(precision);
			dst = ft_bigint_add(dst, to_add, size);
			ft_memdel((void **)&to_add);
			return (ft_bigint_round(dst, precision, size));
		}
	}
	return (NULL);
}

static char	*ft_big_int_round_inf(char *dst, int precision, int i, size_t size)
{
	if (i < (int)size)
	{
		(void)precision;
		if (dst[i - 1] == '.')
			i--;
		dst[i] = '\0';
	}
	return (dst);
}

static char	*ft_big_int_round_add(char *dst, int precision, int i, size_t size)
{
	while (precision != 0 && i < (int)size)
	{
		dst[i] = '0';
		i++;
		precision--;
	}
	if (dst[i - 1] == '.')
		i--;
	dst[i] = '\0';
	return (dst);
}

char		*ft_bigint_round(char *dst, int precision, size_t size)
{
	int		i;
	char	*to_add;
	int		precision_cpy;

	if (precision < 0 || dst == NULL)
		return (dst);
	precision_cpy = precision;
	i = getindex(dst, '.');
	if (dst[i] == 0)
		dst[i] = '.';
	while (dst[++i] && precision != 0)
		precision--;
	if (dst[i] == 0)
		return (ft_big_int_round_add(dst, precision, i, size));
	else if (dst[i] == '5' && dst[i + 1] == 0)
		return (ft_banker_round(dst, precision_cpy, i, size));
	else if (dst[i] < '5')
		return (ft_big_int_round_inf(dst, precision_cpy, i, size));
	to_add = get_to_add(precision_cpy);
	dst = ft_bigint_add(dst, to_add, size);
	ft_memdel((void **)&to_add);
	return (ft_bigint_round(dst, precision_cpy, size));
}
