/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:36:17 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/16 10:31:05 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_tablen(char const *s, char c)
{
	size_t	len;
	int		within_word;
	size_t	i;

	len = 0;
	within_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			within_word = 0;
		}
		else if (!within_word)
		{
			within_word = 1;
			len++;
		}
		i++;
	}
	return (len);
}

static char	*ft_worddup(const char *s, char c)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	dup = ft_calloc(len + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len && s[i] != c)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_free_tab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	*tab = NULL;
}

static char	*ft_tabadd(const char *word_ptr, char c, char **tab, size_t *j)
{
	char	*word;

	word = ft_worddup(word_ptr, c);
	if (!word)
	{
		ft_free_tab(tab, *j);
		return (NULL);
	}
	tab[(*j)++] = word;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		within_word;
	size_t	i;
	size_t	j;

	tab = ft_calloc(ft_tablen(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	within_word = 0;
	i = -1;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			within_word = 0;
		else if (!within_word)
		{
			within_word = 1;
			if (!ft_tabadd((char *)s + i, c, tab, &j))
				return (NULL);
		}
	}
	tab[j] = NULL;
	return (tab);
}
