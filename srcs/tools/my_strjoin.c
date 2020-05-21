/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:46:42 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/23 18:52:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libftprintf.h"

char					*my_strjoin(char *s1, char *s2)
{
	int		x;
	int		i;
	int		z;
	char	*s3;

	x = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	z = ft_strlen(s1);
	if (!(s3 = (char*)malloc((z + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		s3[x + i] = s2[x];
		x++;
	}
	s3[x + i] = '\0';
	free((void*)s2);
	return (s3);
}

char					*my_strjoin_r(char *s1, char *s2)
{
	int		x;
	int		i;
	int		z;
	char	*s3;

	x = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	z = ft_strlen(s1);
	if (!(s3 = (char*)malloc((z + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		s3[x + i] = s2[x];
		x++;
	}
	s3[x + i] = '\0';
	free((void*)s1);
	return (s3);
}
