/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:10:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/04/19 16:57:50 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# define P0 "1"
# define P1 "0.5"
# define P2 "0.25"
# define P3 "0.125"
# define P4 "0.0625"
# define P5 "0.03125"
# define P6 "0.015625"
# define P7 "0.0078125"
# define P8 "0.00390625"
# define P9 "0.001953125"
# define P10 "0.0009765625"
# define P11 "0.00048828125"
# define P12 "0.000244140625"
# define P13 "0.0001220703125"
# define P14 "0.00006103515625"
# define P15 "0.000030517578125"
# define P16 "0.0000152587890625"
# define P17 "0.00000762939453125"
# define P18 "0.000003814697265625"
# define P19 "0.0000019073486328125"
# define P20 "0.00000095367431640625"
# define P21 "0.000000476837158203125"
# define P22 "0.0000002384185791015625"
# define P23 "0.00000011920928955078125"
# define P24 "0.000000059604644775390625"
# define P25 "0.0000000298023223876953125"
# define P26 "0.00000001490116119384765625"
# define P27 "0.000000007450580596923828125"
# define P28 "0.0000000037252902984619140625"
# define P29 "0.00000000186264514923095703125"
# define P30 "0.000000000931322574615478515625"
# define P31 "0.0000000004656612873077392578125"
# define P32 "0.00000000023283064365386962890625"
# define P33 "0.000000000116415321826934814453125"
# define P34 "0.0000000000582076609134674072265625"
# define P35 "0.00000000002910383045673370361328125"
# define P36 "0.000000000014551915228366851806640625"
# define P37 "0.0000000000072759576141834259033203125"
# define P38 "0.00000000000363797880709171295166015625"
# define P39 "0.000000000001818989403545856475830078125"
# define P40 "0.0000000000009094947017729282379150390625"
# define P41 "0.00000000000045474735088646411895751953125"
# define P42 "0.000000000000227373675443232059478759765625"
# define P43 "0.0000000000001136868377216160297393798828125"
# define P44 "0.00000000000005684341886080801486968994140625"
# define P45 "0.000000000000028421709430404007434844970703125"
# define P46 "0.0000000000000142108547152020037174224853515625"
# define P47 "0.00000000000000710542735760100185871124267578125"
# define P48 "0.000000000000003552713678800500929355621337890625"
# define P49 "0.0000000000000017763568394002504646778106689453125"
# define P50 "0.00000000000000088817841970012523233890533447265625"
# define P51 "0.000000000000000444089209850062616169452667236328125"
# define P52 "0.0000000000000002220446049250313080847263336181640625"
# define P53 "0.00000000000000011102230246251565404236316680908203125"
# define P54 "0.000000000000000055511151231257827021181583404541015625"
# define P55 "0.0000000000000000277555756156289135105907917022705078125"
# define P56 "0.00000000000000001387778780781445675529539585113525390625"
# define P57 "0.000000000000000006938893903907228377647697925567626953125"
# define P58 "0.0000000000000000034694469519536141888238489627838134765625"
# define P59 "0.00000000000000000173472347597680709441192448139190673828125"
# define P60 "0.000000000000000000867361737988403547205962240695953369140625"
# define P61 "0.0000000000000000004336808689942017736029811203479766845703125"
# define P62 "0.00000000000000000021684043449710088680149056017398834228515625"
# define P63 "0.000000000000000000108420217248550443400745280086994171142578125"
# define P64 "0.000000000000000000054210108624275221700372640043497085571289062"

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
	int 			inf;
	char			*expo;
	char			conv;
}					t_lista;

int					ft_printf(const char *prt, ...);
void				choice(char c, t_lista *g);

void				flags(const char *prt, t_lista *g, va_list ap);
char				*numbersandstar(char *prt, int x, t_lista *g, va_list ap);

void				integer(va_list ap, t_lista *g);
void				uinteger(va_list ap, t_lista *g);
void				character(va_list ap, t_lista *g);
void				string(va_list ap, t_lista *g);
void				pointer(va_list ap, t_lista *g);
void				hexadecimal(va_list ap, t_lista *g);
void    			number(va_list ap, t_lista *g);
void    			percent(t_lista *g);
void    			float_f(char *decimal, t_lista *g);
void    			float_e(char *decimal, size_t size, t_lista *g);

void				putspace(int x, int y, t_lista *g);
void				putzero(int x, int y, t_lista *g);
void				my_putnbrx(unsigned int nb, t_lista *g);
void				puthexa(char *str, int y, t_lista *g);
void				putstrm(char *str, int prec, int x, t_lista *g);

void    			putblank(t_lista *g);
void    			puthashtag(char *hexa, t_lista *g);
void    			putfloat(char *dec, int length, t_lista *g);
int     			set_length_e(char *decimal, t_lista *g);
void    			putexpo(char *dec, int length, int sign, t_lista *g);

void				minus(t_lista *g);
char				*up(char *str);
int					setx(const char *prt, int x, t_lista *g);
int					width(int x, t_lista *g);
int					widthu(unsigned int x, t_lista *g);

char				*ft_conv_hexa(long y);
char				*ft_conv_hexa2(unsigned int i);

void    			convert_float(va_list ap, t_lista *g);
char    			*ft_ftoa(double nbr, char *binary, size_t size);
char    			*ft_bigint_add(char *decimal, const char *toadd, size_t size);
int					getindex(char *str, char c);
char				*ft_bigint_trim(char *str);
char				*ft_bigint_shift_right(char *str, size_t nb, size_t size);
char				*ft_bigint_multiply_by_two(char *output, size_t size);
char				*ft_bigint_divide_by_two(char *output, size_t size);
char				*ft_bigint_round(char *dst, int precision, size_t size);

char    			*dec_to_e(char *dec, int *sign, t_lista *g);
char    			*re_dec_to_e(char *dec);
char    			*zero_check(char *str, int len);

void				my_putnbr(int nb, t_lista *g);
void				my_putstr(char *str, int x, t_lista *g);

#endif
