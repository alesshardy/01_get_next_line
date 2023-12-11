/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:43:44 by apintus           #+#    #+#             */
/*   Updated: 2023/12/08 14:35:35 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill(int fd, char *data)
{
	int		bytes_read;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strcontains(data, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			if (data != NULL)
				free(data);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		data = ft_strjoin(data, buff);
	}
	free(buff);
	return (data);
}

char	*ft_extract_line(char *data)
{
	char	*line;
	size_t	len;
	int		i;

	if (data[0] == '\0')
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	len = i + (data[i] == '\n');
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	ft_strcpy_nl(line, data, 1);
	return (line);
}

char	*ft_update_data(char *old_data)
{
	char	*new_data;
	int		i;

	i = 0;
	while (old_data[i] != '\0' && old_data[i] != '\n')
		i++;
	if (old_data[i] == '\0')
	{
		free(old_data);
		return (NULL);
	}
	new_data = malloc(sizeof(char) * (ft_strlen(old_data + i) + 1));
	if (new_data == NULL)
		return (NULL);
	ft_strcpy_nl(new_data, old_data + i + 1, 0);
	free(old_data);
	return (new_data);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = ft_fill(fd, data);
	if (data == NULL)
		return (NULL);
	line = ft_extract_line(data);
	data = ft_update_data(data);
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int		fd1;
	char	*line;
	
	fd1 = open("files/file1", O_RDONLY);
	if (fd1 < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd1);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd1);
	return (0);
}*/
