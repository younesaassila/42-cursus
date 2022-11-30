/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:41:55 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/23 11:27:10 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler_uint_hex_lower(va_list arg_ptr)
{
	unsigned int	nbr;

	nbr = va_arg(arg_ptr, unsigned int);
	return (ft_put_uint_base_fd(nbr, "0123456789abcdef", STDOUT_FILENO));
}

int	ft_handler_uint_hex_upper(va_list arg_ptr)
{
	unsigned int	nbr;

	nbr = va_arg(arg_ptr, unsigned int);
	return (ft_put_uint_base_fd(nbr, "0123456789ABCDEF", STDOUT_FILENO));
}
