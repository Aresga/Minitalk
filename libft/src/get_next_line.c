/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:43:59 by agaga             #+#    #+#             */
/*   Updated: 2025/01/09 16:06:26 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static char	*bytes_read(int fd, char *buffer, char **leftover)
{
	int		read_line;
	char	*prev_leftover;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (!(*leftover))
			*leftover = ft_strdup("");
		prev_leftover = *leftover;
		*leftover = ft_strjoin(prev_leftover, buffer);
		free(prev_leftover);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (*leftover);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*newleftover;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (NULL);
	newleftover = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*newleftover == '\0' || !newleftover[0])
	{
		free(newleftover);
		newleftover = NULL;
	}
	line[count + 1] = '\0';
	return (newleftover);
}

char	*get_next_line(int fd)
{
	char		*combined_data;
	char		*buffer;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	combined_data = bytes_read(fd, buffer, &leftover);
	free(buffer);
	buffer = NULL;
	if (!combined_data)
		return (NULL);
	leftover = extract(combined_data);
	return (combined_data);
}
