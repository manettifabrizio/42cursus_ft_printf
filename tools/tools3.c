/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:23:31 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/22 13:35:42 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

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

void    my_substr(char *s, unsigned int start, size_t len)
{
	size_t                  i;
	unsigned int    x;

	i = 0;
	x = 0;
	if (!s)
			return ;
	while (s[x])
			x++;
	// printf("start = %d x = %d\n", start, x);
	while (i < len)
	{
			s[i] = s[start + i];
			i++;
	}
	s[i] = '\0';
}

// void	my_strjoin(char const *s1, char *s2)
// {
// 	int		x;
// 	int		i;
// 	int		z;
// 	char	*s3;

// 	x = 0;
// 	i = 0;
// 	if (!s1 || !s2)
// 		return (0);
// 	z = ft_strlen(s1);
	
// 	if (!(tmp = (char*)malloc((z + ft_strlen(s2) + 1) * sizeof(char))))
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		s2[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[x] != '\0')
// 	{
// 		s2[x + i] = s2[x];
// 		x++;
// 	}
// 	s3[x + i] = '\0';
// 	return (s3);
// }