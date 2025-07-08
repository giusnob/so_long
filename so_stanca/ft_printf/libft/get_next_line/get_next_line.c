/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:27:11 by ginobile          #+#    #+#             */
/*   Updated: 2025/07/07 17:27:06 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_and_store(int fd, char *remainder)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (remainder);
}

static char	*extract_line(char *remainder)
{
	char	*line;
	size_t	i;

	if (!remainder[0])
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*trim_remainder(char *remainder)
{
	char	*new_rem;
	size_t	i;
	size_t	j;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_rem = malloc(sizeof(char) * (ft_strlen(remainder) - i));
	if (!new_rem)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		new_rem[j++] = remainder[i++];
	new_rem[j] = '\0';
	free(remainder);
	return (new_rem);
}

char	*get_next_line(int fd)
{
	static char	*remainder[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	remainder[fd] = read_and_store(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	line = extract_line(remainder[fd]);
	remainder[fd] = trim_remainder(remainder[fd]);
	return (line);
}

/* #include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	//fd = open(argv[1], O_RDONLY);
	fd = 0;
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
} */