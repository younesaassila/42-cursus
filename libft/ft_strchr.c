/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:20:18 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/16 10:15:16 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;
	size_t	i;

	s_ptr = (char *)s;
	i = 0;
	while (s_ptr[i])
	{
		if (s_ptr[i] == (char)c)
			return (s_ptr + i);
		i++;
	}
	if (s_ptr[i] == (char)c)
		return (s_ptr + i);
	return (NULL);
}
