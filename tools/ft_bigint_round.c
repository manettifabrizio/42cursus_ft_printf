/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_round.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 10:54:41 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/14 11:46:14 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*get_to_add(int n)
{
	int		i;
	char	*to_add;

	if (!(to_add = (char *)ft_memalloc((n + 4) * sizeof(char))))
		return (NULL);
	to_add = ft_strcpy(to_add, "0.1");
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

static char	*ft_banker_round(char *dst, int precision, int i)
{
	int		j;
	char	*to_add;
    j = i - 1;
    if (dst[i - 1] == '.') //se dst[i] è il numero dopo la virgola
    {
        i--;
        j--;
    }
    if ((dst[j] - '0') % 2 == 0) //nel caso in cui il numero prima di 5 sia pari mette lo spazio al 5
    {
        dst[i] = 0;
        return (dst);
    }
    else //se è dispari aggiunge 1 
    {
        to_add = get_to_add(precision);
        dst = ft_bigint_add(dst, to_add);
        ft_memdel((void **)&to_add);
        return (ft_bigint_round(dst, precision));
    }
	return (NULL);
}

static char	*ft_big_int_round_inf(char *dst, int precision, int i)
{
	(void)precision;
    if (dst[i - 1] == '.')
        i--;
    dst[i] = '\0';
    return (dst);
}

static char	*ft_big_int_round_add(char *dst, int precision, int i)
{
	while (precision != 0)
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

int	ft_bigint_get_index(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char		*ft_bigint_round(char *dst, int precision)
{
	int		i;
	char	*to_add;
	int		precision_cpy;

	if (precision < 0 || dst == NULL)
		return (dst);
	precision_cpy = precision;
	i = ft_bigint_get_index(dst, '.');
	if (dst[i] == 0)
		dst[i] = '.'; 
	while (dst[++i] && precision != 0)
		precision--;
	if (dst[i] == 0)
		return (ft_big_int_round_add(dst, precision, i));
	else if (dst[i] == '5' && dst[i + 1] == 0)
	 	return (ft_banker_round(dst, precision_cpy, i));
	else if (dst[i] < '5')
		return (ft_big_int_round_inf(dst, precision_cpy, i));
	to_add = get_to_add(precision_cpy);
	dst = ft_bigint_add(dst, to_add);
	ft_memdel((void **)&to_add);
	return (ft_bigint_round(dst, precision_cpy));
}