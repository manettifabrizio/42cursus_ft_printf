/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:10:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/03/31 18:13:29 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft/libft.h"

typedef	struct		s_lista
{
	int				dash;
	int				plus;
	int				space;
	int				zero;
	int				hashtag;
	int				written;
	int				dot;
	int				prec;
	int				precm;
	int				width;
	int				minus;
	char			conv;
}					t_lista;

int					ft_printf(const char *prt, ...);
//void				choice(char c, t_lista *g);

void				flags(const char *prt, t_lista *g, va_list ap);
char				*numbersandstar(char *prt, int *x, t_lista *g, va_list ap);

void				integer(va_list ap, t_lista *g);
void				uinteger(va_list ap, t_lista *g);
void				character(va_list ap, t_lista *g);
void				string(va_list ap, t_lista *g);
void				pointer(va_list ap, t_lista *g);
void				hexadecimal(va_list ap, t_lista *g);
void    			number(va_list ap, t_lista *g);
void    			wfloat(va_list ap, t_lista *g);
void    			percent(t_lista *g);

void				putspace(int x, int y, t_lista *g);
void				putzero(int x, int y, t_lista *g);
void				my_putnbrx(unsigned int nb, t_lista *g);
void				puthexa(char *str, int y, t_lista *g);
void				putstrm(char *str, int prec, int x, t_lista *g);

void    			putblank(t_lista *g);
void    			puthashtag(char *hexa, t_lista *g);
int     			divide(double nbr, int *i, int *f, int prec);
void    			putfloat(double nbr, t_lista *g);
int					widthf(int x, t_lista *g);

void				minus(t_lista *g);
char				*up(char *str);
int					setx(const char *prt, int x, t_lista *g);
int					width(int x, t_lista *g);
int					widthu(unsigned int x, t_lista *g);

char				*ft_conv_hexa(long y);
char				*ft_conv_hexa2(unsigned int i);

void				my_putnbr(int nb, t_lista *g);
void				my_putstr(char *str, int x, t_lista *g);

#endif
