/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:18:14 by edebi             #+#    #+#             */
/*   Updated: 2020/11/11 19:44:58 by edebi            ###   ########.fr       */
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
}				t_params;
typedef struct	s_var
{
	void	**variable;
	char	type;
	int		width;
	int		precision;
}				t_var;
#endif
