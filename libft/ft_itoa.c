/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:37:22 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/15 15:04:03 by yaassila         ###   ########.fr       */
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

static size_t	ft_intlen(int n)
{
	size_t			len;
	unsigned int	nbr;

	len = 1;
	if (n < 0)
		len++;
	nbr = ft_abs(n);
	while (nbr >= 10)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static unsigned int	ft_get_leading_place_factor(unsigned int nbr)
{
	unsigned int	place_factor;

	place_factor = 1;
	while (nbr / place_factor >= 10)
		place_factor *= 10;
	return (place_factor);
}

char	*ft_itoa(int n)
{
	size_t			result_len;
	char			*result;
	size_t			i;
	unsigned int	nbr;
	unsigned int	place_factor;

	result_len = ft_intlen(n);
	result = ft_calloc(result_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (n < 0)
		result[i++] = '-';
	nbr = ft_abs(n);
	place_factor = ft_get_leading_place_factor(nbr);
	while (place_factor > 0)
	{
		result[i++] = (nbr / place_factor) + '0';
		nbr %= place_factor;
		place_factor /= 10;
	}
	result[i] = '\0';
	return (result);
}
