/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:49:19 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/16 10:15:13 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_ptr;
	char	*result;
	size_t	i;

	s_ptr = (char *)s;
	result = NULL;
	i = 0;
	while (s_ptr[i])
	{
		if (s_ptr[i] == (char)c)
			result = s_ptr + i;
		i++;
	}
	if (s_ptr[i] == (char)c)
		result = s_ptr + i;
	return (result);
}
