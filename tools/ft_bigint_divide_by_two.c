/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_divide_by_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:51:34 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/13 17:55:28 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	ft_get_next_digit(char digit, int next_is_even)
{ //ha catalogato i primi 20 casi poi si ripetono per la periodicità
	if (next_is_even == 0) //se pari
	{ // 0/2 o 1/2 = 0 o 0,5 ...
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

static int	is_over(char *output, size_t *i, size_t *j)
{
	int finished;

	finished = 0;
	while ((ft_isdigit(output[*i]) == 0) && output[*i])
	{
		output[*i - 1] = output[*i];
		(*i)++;
	}
	(*j)++;
	while ((ft_isdigit(output[*j]) == 0) && output[*j])
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

char		*ft_bigint_divide_by_two(char *output)
{
	size_t	i;
	size_t	j;
	int		finished;
	int		even;

	printf("before = %s\n", output);
	output = ft_bigint_shift_right(output, 1);
	output[0] = '0';
	i = 0;
	j = 0;
	finished = 0;
	while (output[i] && finished != 1)
	{
		even = (output[i] - '0') % 2;
		finished = is_over(output, &i, &j);
		output[i] = ft_get_next_digit(output[j], even); //sostituisce i in base 
		i = j;
	}
	return (ft_bigint_trim(output));
}
