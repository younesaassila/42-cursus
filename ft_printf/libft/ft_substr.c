/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:33:58 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/16 10:21:39 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	result_len;
	char	*result;

	if (len == 0 || start >= ft_strlen(s))
	{
		result = ft_calloc(1, sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	s_len = ft_strlen(s);
	if (start + len > s_len)
		result_len = s_len - start;
	else
		result_len = len;
	result = ft_calloc(result_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, result_len + 1);
	return (result);
}
