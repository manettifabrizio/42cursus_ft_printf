/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 19:47:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/14 16:32:55 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     main()
{

    double x = 0.562746;


	printf(" --- Return : %d - PRINTF\n", printf("%# -4.4f", x));
	ft_printf(" --- Return : %d - FT_PRINTF\n", ft_printf("%# -4.4f", x));
    return (0);
}
