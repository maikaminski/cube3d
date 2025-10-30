/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:16:36 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:31:19 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*raise_error(char *buf)
{
	if (buf)
		free(buf);
	return (NULL);
}

static char	*read_line(int fd, char *buf, char *buffer)
{
	char	*temp;
	int		line_bytes;

	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
			return (NULL);
	}
	line_bytes = 1;
	while (!ft_strchr(buffer, '\n') && line_bytes != 0)
	{
		line_bytes = read(fd, buf, BUFFER_SIZE);
		if (line_bytes == -1)
			return (raise_error(buffer));
		if (line_bytes == 0)
			break ;
		buf[line_bytes] = '\0';
		temp = buffer;
		buffer = ft_strjoin(temp, buf);
		free(temp);
		if (!buffer)
			return (raise_error(buffer));
	}
	return (buffer);
}

static char	*update_buffer(char *buffer)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (raise_error(buffer));
	j = i + 1;
	temp = ft_strdup(&buffer[j]);
	if (!temp)
		return (raise_error(temp));
	free(buffer);
	return (temp);
}

static char	*single_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, (i + 1));
	else
		line = ft_substr(buffer, 0, i);
	if (!line)
		return (raise_error(line));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buffer = read_line(fd, buf, buffer);
	free(buf);
	if (!buffer)
		return (NULL);
	line = single_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
