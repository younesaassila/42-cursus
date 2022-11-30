/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:00:28 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/15 15:05:59 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_ptr;
	size_t	little_len;
	size_t	i;
	size_t	j;

	big_ptr = (char *)big;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (big_ptr);
	i = 0;
	while (i < len && big_ptr[i])
	{
		j = 0;
		while (i + j < len && big_ptr[i + j] && big_ptr[i + j] == little[j])
			j++;
		if (j == little_len)
			return (big_ptr + i);
		i++;
	}
	return (NULL);
}
