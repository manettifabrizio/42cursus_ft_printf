/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 19:47:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/15 13:22:35 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     main()
{
    double x = 0000.20000;
	printf(" --- Return : %d - PRINTF\n", printf("%e", x));
	ft_printf(" --- Return : %d - FT_PRINTF\n", ft_printf("%e", x));
    return (0);
}
