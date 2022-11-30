/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:59:08 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/23 11:58:39 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_abs(int n)
{
	unsigned int	result;

	if (n < 0)
		result = -n;
	else
		result = n;
	return (result);
}

static unsigned int	ft_get_leading_uint_place_factor(unsigned int nbr)
{
	unsigned int	place_factor;

	place_factor = 1;
	while (nbr / place_factor >= 10)
		place_factor *= 10;
	return (place_factor);
}

static uintptr_t	ft_get_leading_uintptr_place_factor(uintptr_t nbr,
														uintptr_t base)
{
	uintptr_t	place_factor;

	place_factor = 1;
	while (nbr / place_factor >= base)
		place_factor *= base;
	return (place_factor);
}

int	ft_put_int_fd(int n, int fd)
{
	int				printed;
	unsigned int	nbr;
	unsigned int	place_factor;
	char			c;

	printed = 0;
	if (n < 0)
	{
		c = '-';
		if (write(fd, &c, 1) == -1)
			return (-1);
		printed++;
	}
	nbr = ft_abs(n);
	place_factor = ft_get_leading_uint_place_factor(nbr);
	while (place_factor > 0)
	{
		c = (nbr / place_factor) + '0';
		if (write(fd, &c, 1) == -1)
			return (-1);
		printed++;
		nbr %= place_factor;
		place_factor /= 10;
	}
	return (printed);
}

int	ft_put_uint_base_fd(uintptr_t nbr, char *base_str, int fd)
{
	int			printed;
	uintptr_t	base;
	uintptr_t	place_factor;

	printed = 0;
	base = ft_strlen(base_str);
	place_factor = ft_get_leading_uintptr_place_factor(nbr, base);
	while (place_factor > 0)
	{
		if (write(fd, &(base_str[nbr / place_factor]), 1) == -1)
			return (-1);
		printed++;
		nbr %= place_factor;
		place_factor /= base;
	}
	return (printed);
}
