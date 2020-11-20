/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:18:14 by edebi             #+#    #+#             */
/*   Updated: 2020/11/20 22:11:10 by edebi            ###   ########.fr       */
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
	int		error;
}				t_params;
typedef struct	s_var
{
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
int				ft_printf(const char *str, ...);
int				init_params(char *c_str);
void			init_var(void);
int				set_flag(char *str);
int				get_width(char *str);
int				get_precision(char *str);
int				get_specifier(char *str);
void			print_var(void);
void			print_hex(void);
int				free_mem(void);
void			print_end_char(char *str);
int				check_global(void);
#endif
