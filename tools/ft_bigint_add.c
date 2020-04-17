/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 19:08:23 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/16 20:57:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			getindex(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*fill_right(char *str, size_t len)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	while (i < len)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	return (str);
}

char    *set_to_add(char **dec, const char *add, size_t size)
{
    int     len;
    char    *addcp;
    int     decindex;
    int     addindex;
    int     dotindex;

    len = ft_strlen(*dec) < ft_strlen(add) ? ft_strlen(add) : ft_strlen(*dec);
    if (!(addcp = (char *)ft_memalloc((len * 2) * sizeof(char))))
		return (NULL);
	addcp = ft_strcpy(addcp, add);
    decindex = getindex(*dec, '.');
	addindex = getindex(addcp, '.');
	dotindex = decindex > addindex ? decindex : addindex;
	dotindex++;
    *dec = ft_bigint_shift_right(*dec, dotindex - decindex, size);
	addcp = ft_bigint_shift_right(addcp, dotindex - addindex, size);
	len = ft_strlen(*dec) < ft_strlen(addcp) ? ft_strlen(addcp) : ft_strlen(*dec);
	*dec = fill_right(*dec, len);
	addcp = fill_right(addcp, len);
    return (addcp);
}

char    *ft_bigint_add(char *dec, const char *toadd, size_t size)
{
    char    *add;
    int     len;
    int     change;
    int     decimal;

    change = 0;
    add = set_to_add(&dec, toadd, size);
    len = ft_strlen(dec) < ft_strlen(add) ? ft_strlen(add) : ft_strlen(dec);
	len--;
	while (len >= 0)
	{
		if (dec[len] != '.')
		{
			decimal = (add[len] - '0') + (dec[len] - '0');
			dec[len] = (decimal + change) % 10 + '0';
			change = (decimal + change) < 10 ? 0 : 1;
		}
		len--;
	}
	ft_memdel((void **)&add);
	return (ft_bigint_trim(dec));
}