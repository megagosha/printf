/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:18:14 by edebi             #+#    #+#             */
/*   Updated: 2020/11/20 01:42:59 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>

typedef	struct	s_params
{
	va_list list;
	char	*str;
	char	*conversions;
	char	*flags;
	int		return_val;
}				t_params;
typedef struct	s_var
{
	void			*variable;
	char			flag_zero;
	char			flag_minus;
	char			flag_dot;
	int				width;
	int				precision;
	int				length;
	char			specifier;
}				t_var;
extern t_params	*g_params;
extern t_var	*g_var;
void			ft_putstr(char *str);
int				ft_putstr_count(char *str);
char			*ft_itoa_long(long long n);
void			print_char(void);
void			print_string(void);
void			print_pointer(void);
void			print_decimal(void);
void			print_unsigned(void);
void			print_hex(void);
char			*check_width(char *str);
int				ft_putstr_count(char *str);
char			*get_hex(unsigned long nb);
char			*get_dec_precision(char *str);
void			print_global_debug(void);
char			*ft_itoa_unsigned(unsigned long n);
#endif
