/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:41:42 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/23 11:27:15 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler_char(va_list arg_ptr)
{
	char	c;

	c = va_arg(arg_ptr, int);
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_handler_str(va_list arg_ptr)
{
	char	*str;

	str = va_arg(arg_ptr, char *);
	if (!str)
		return (write(STDOUT_FILENO, "(null)", 6));
	return (write(STDOUT_FILENO, str, ft_strlen(str)));
}

int	ft_handler_ptr(va_list arg_ptr)
{
	uintptr_t	ptr;

	ptr = va_arg(arg_ptr, uintptr_t);
	if (!ptr)
		return (write(STDOUT_FILENO, "(nil)", 5));
	if (write(STDOUT_FILENO, "0x", 2) == -1)
		return (-1);
	return (2 + ft_put_uint_base_fd(ptr, "0123456789abcdef", STDOUT_FILENO));
}

int	ft_handler_int(va_list arg_ptr)
{
	int	nbr;

	nbr = va_arg(arg_ptr, int);
	return (ft_put_int_fd(nbr, STDOUT_FILENO));
}

int	ft_handler_uint(va_list arg_ptr)
{
	unsigned int	nbr;

	nbr = va_arg(arg_ptr, unsigned int);
	return (ft_put_uint_base_fd(nbr, "0123456789", STDOUT_FILENO));
}
