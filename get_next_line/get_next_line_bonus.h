/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:21:32 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/28 20:48:59 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
