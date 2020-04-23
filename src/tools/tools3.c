/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:23:31 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:49:59 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

void					which(char *decimal, size_t size, t_lista *g)
{
	if (g->conv == 'f')
		float_f(decimal, g);
	if (g->conv == 'e')
		float_e(decimal, size, g);
}

static unsigned long	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		exit(0);
	else if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
}

char					*ft_conv_hexa(long i)
{
	char	*str;
	int		x;
	int		j;
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = 1;
	j = -1;
	while (i / ft_recursive_power(16, len) > 0)
		len++;
	if (!(str = malloc(sizeof(char) * len + 1)))
		exit(0);
	x = --len;
	while (++j <= x)
	{
		str[j] = base[(i / ft_recursive_power(16, len))];
		i = i % ft_recursive_power(16, len);
		len--;
	}
	str[j] = '\0';
	return (str);
}

char					*ft_conv_hexa2(unsigned int i)
{
	char	*str;
	int		x;
	int		j;
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = 1;
	j = -1;
	while (i / ft_recursive_power(16, len) > 0)
		len++;
	if (!(str = malloc(sizeof(char) * len + 1)))
		exit(0);
	x = --len;
	while (++j <= x)
	{
		str[j] = base[(i / ft_recursive_power(16, len))];
		i = i % ft_recursive_power(16, len);
		len--;
	}
	str[j] = '\0';
	return (str);
}

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
