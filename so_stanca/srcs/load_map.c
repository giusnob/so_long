/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:36:38 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/08 16:46:47 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	Open map file read-only.
static int	open_map_file(const char *path)
{
	int	fd;

	if (!path)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error: cannot open %s\n", path);
	return (fd);
}

//Allocate map->map array.
static int	alloc_map_array(t_map *map, int lines)
{
	map->map = malloc(sizeof(char *) * (lines + 1));
	if (!map->map)
		ft_printf("Error: malloc failed\n");
	return (map->map != NULL);
}

//Fill map->map with get_next_line, trim '\n'.
static int	fill_map(int fd, t_map *map, int lines)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		if (i < lines)
			map->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	printf("i: %d\n", i);
	map->map[lines] = NULL;
	return (i == lines);
}

int	load_map(const char *file, t_map *map)
{
	int	fd;
	int	ok;

	fd = open_map_file(file);
	if (fd < 0)
		return (0);
	close(fd);
	if (map->height <= 0)
		return (0);
	printf("height: %d\n", map->height);
	if (!alloc_map_array(map, map->height))
		return (0);
	fd = open_map_file(file);
	ok = (fd >= 0 && fill_map(fd, map, map->height));
	close(fd);
	return (ok);
}
