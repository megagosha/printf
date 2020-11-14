/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:18:14 by edebi             #+#    #+#             */
/*   Updated: 2020/11/14 17:00:20 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>

typedef	struct	s_params
{
	va_list list;
	int		n_args;
	char	*str;
	char	*conversions;
	char	*flags;
}				t_params;
typedef struct	s_var
{
	void			*variable;
	char			flag_zero;
	char			flag_minus;
	char			flag_dot;
	char			flag_star;
	unsigned int	width;
	unsigned int	precision;
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
char			*get_hex(unsigned nb);
#endif
