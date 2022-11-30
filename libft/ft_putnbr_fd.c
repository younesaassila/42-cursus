/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:31:49 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/13 12:13:29 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int n)
{
	unsigned int	result;

	if (n < 0)
		result = -n;
	else
		result = n;
	return (result);
}

static unsigned int	ft_get_leading_place_factor(unsigned int nbr)
{
	unsigned int	place_factor;

	place_factor = 1;
	while (nbr / place_factor >= 10)
		place_factor *= 10;
	return (place_factor);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	unsigned int	place_factor;

	if (n < 0)
		ft_putchar_fd('-', fd);
	nbr = ft_abs(n);
	place_factor = ft_get_leading_place_factor(nbr);
	while (place_factor > 0)
	{
		ft_putchar_fd((nbr / place_factor) + '0', fd);
		nbr %= place_factor;
		place_factor /= 10;
	}
}
