/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaassila <yaassila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:21:11 by yaassila          #+#    #+#             */
/*   Updated: 2022/11/29 11:48:06 by yaassila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	gnl_line_len(const char *line)
{
	size_t	line_len;

	line_len = 0;
	while (line[line_len] != '\n' && line[line_len] != '\0')
		line_len++;
	if (line[line_len] == '\n')
		line_len++;
	return (line_len);
}

static char	*gnl_read_until_newline(int fd, char *buffer)
{
	char	*prev_text;
	char	*text;
	ssize_t	bytes_read;

	text = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!text)
		return (NULL);
	ft_strlcpy(text, buffer, ft_strlen(buffer) + 1);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read >= 0)
		{
			buffer[bytes_read] = '\0';
			prev_text = text;
			text = ft_strjoin(text, buffer);
			free(prev_text);
		}
	}
	return (text);
}

static char	*gnl_get_first_line(char *text)
{
	size_t	line_len;
	char	*line;

	line_len = gnl_line_len(text);
	if (line_len == 0)
		return (NULL);
	line = malloc((line_len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, text, line_len + 1);
	return (line);
}

static char	*gnl_remove_first_line(char *buffer)
{
	size_t	buffer_len;
	size_t	line_len;

	buffer_len = ft_strlen(buffer);
	if (buffer_len == 0)
		return (buffer);
	line_len = gnl_line_len(buffer);
	ft_memmove(buffer, &buffer[line_len], buffer_len - line_len + 1);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*text;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	text = gnl_read_until_newline(fd, buffer);
	if (!text)
		return (NULL);
	line = gnl_get_first_line(text);
	gnl_remove_first_line(buffer);
	free(text);
	return (line);
}
