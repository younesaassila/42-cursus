/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:03:09 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/15 15:06:05 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_contains(char const *set, char c)
{
	return (ft_strchr(set, c) != 0);
}

static char	*ft_strtrim_start(char const *s1, char const *set)
{
	size_t	first_idx;

	first_idx = 0;
	while (s1[first_idx] != '\0' && ft_set_contains(set, s1[first_idx]))
		first_idx++;
	return ((char *)s1 + first_idx);
}

static char	*ft_strtrim_end(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	last_idx;
	size_t	result_len;
	char	*result;

	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (ft_strdup(s1));
	last_idx = s1_len - 1;
	while (s1[last_idx] != '\0' && ft_set_contains(set, s1[last_idx]))
		last_idx--;
	result_len = last_idx + 1;
	result = ft_calloc(result_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, result_len + 1);
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	return (ft_strtrim_end(ft_strtrim_start(s1, set), set));
}
