/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_divide_by_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:51:34 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/19 16:12:22 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	ft_get_next_digit(char digit, int next_is_even)
{
	if (next_is_even == 0)
	{
		if (digit == '0' || digit == '1')
			return ('0');
		if (digit == '2' || digit == '3')
			return ('1');
		if (digit == '4' || digit == '5')
			return ('2');
		if (digit == '6' || digit == '7')
			return ('3');
		if (digit == '8' || digit == '9')
			return ('4');
	}
	if (digit == '0' || digit == '1')
		return ('5');
	if (digit == '2' || digit == '3')
		return ('6');
	if (digit == '4' || digit == '5')
		return ('7');
	if (digit == '6' || digit == '7')
		return ('8');
	if (digit == '8' || digit == '9')
		return ('9');
	return (0);
}

static int	is_over(char *output, size_t *i, size_t *j, size_t size)
{
	int finished;

	finished = 0;
	while (*i < size - 1 && ft_isdigit(output[*i]) == 0 && output[*i])
	{
		output[*i - 1] = output[*i];
		(*i)++;
	}
	(*j)++;
	while (*j < size - 1 && (ft_isdigit(output[*j]) == 0) && output[*j])
	{
		output[*j - 1] = output[*j];
		(*i)++;
		(*j)++;
	}
	if (output[*j] == 0)
	{
		output[*j] = '0';
		output[*j + 1] = 0;
		finished = 1;
	}
	return (finished);
}

char		*ft_bigint_divide_by_two(char *output, size_t size)
{
	size_t	i;
	size_t	j;
	int		finished;
	int		even;

	output = ft_bigint_shift_right(output, 1, size);
	output[0] = '0';
	i = 0;
	j = 0;
	finished = 0;
	while (i < size && output[i] && finished != 1)
	{
		even = (output[i] - '0') % 2;
		finished = is_over(output, &i, &j, size);
		output[i] = ft_get_next_digit(output[j], even);
		i = j;
	}
	return (ft_bigint_trim(output));
}
