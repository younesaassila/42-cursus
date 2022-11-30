/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:41:46 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/23 11:27:32 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag
{
	char	character;
	int		(*handler)(va_list);
}			t_flag;

int			ft_printf(const char *str, ...);

t_list		*ft_get_flags(void);
t_flag		*ft_get_flag(t_list *flags, char character);

int			ft_put_int_fd(int n, int fd);
int			ft_put_uint_base_fd(uintptr_t nbr, char *base_str, int fd);

int			ft_handler_char(va_list arg_ptr);
int			ft_handler_str(va_list arg_ptr);
int			ft_handler_ptr(va_list arg_ptr);
int			ft_handler_int(va_list arg_ptr);
int			ft_handler_uint(va_list arg_ptr);
int			ft_handler_uint_hex_lower(va_list arg_ptr);
int			ft_handler_uint_hex_upper(va_list arg_ptr);

#endif
