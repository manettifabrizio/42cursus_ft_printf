/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 12:41:05 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 00:53:57 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     main()
{
    int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			ft_printf(" --- Return : %d\n", ft_printf("%5.8e|%-5.8f|%+5.8e|% 5.8f|%#5.8e|%05.8f", 0., 0., 0., 0., 0., 0.));
			ft_printf(" --- Return : %d\n", ft_printf("%+8.14f|%+ 8.14e|%+-8.14f|%+#8.14e|%+08.14f|%+ -#08.14e", 42., 42., 42., 42., 42., 42.));
            ft_printf(" --- Return : %d\n", ft_printf("|%-*.*d|", a, b, l));
			ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			b++;
		}
		a++;
	}
    while (1)
    ;
    return (0);
}