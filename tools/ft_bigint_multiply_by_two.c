/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multiply_by_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:51:22 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/19 16:47:13 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		is_valid_digit(char c)
{
	if (ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}

static int		set_len(char *output, size_t len, size_t size)
{
	while (output[len])
		len++;
	if (len == size)
		len = size - 1;
	return (len);
}

char			*ft_bigint_multiply_by_two(char *output, size_t size)
{
	size_t	len;
	int		ret;
	int		dec;

	len = 0;
	ret = 0;
	len = set_len(output, len, size);
	output[len + 1] = 0;
	if (ft_strcmp(output, "0") == 0)
		output[0] = '1';
	while (len != 0 && is_valid_digit(output[len - 1]))
	{
		if (output[len - 1] == '.')
			output[len] = '.';
		else
		{
			dec = output[len - 1] - '0';
			output[len] = ((dec) * 2 + ret) % 10 + '0';
			ret = (dec) * 2 + ret < 10 ? 0 : 1;
		}
		len--;
	}
	output[len] = ret + '0';
	return (ft_bigint_trim(output));
}
