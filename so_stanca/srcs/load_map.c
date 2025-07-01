/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giusnob <giusnob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:36:38 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/01 15:39:37 by giusnob          ###   ########.fr       */
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

//Count lines by reading into buffer.
static int	get_line_count(int fd)
{
	char	buf[4096];
	int		cnt;
	ssize_t	ret;

	cnt = 0;
	while ((ret = read(fd, buf, sizeof(buf))) > 0)
		if (buf[ret - 1] == '\n')
			cnt++;
	if (ret < 0)
	{
		ft_printf("Error: reading map\n");
		return (-1);
	}
	return (cnt);
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
	while (i < lines && (line = get_next_line(fd)))
	{
		map->map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	map->map[i] = NULL;
	return (i == lines);
}

int	load_map(const char *file, t_map *map)
{
	int	fd;
	int	lines;
	int	ok;

	fd = open_map_file(file);
	if (fd < 0)
		return (0);
	lines = get_line_count(fd);
	close(fd);
	if (lines <= 0)
		return (0);
	if (!alloc_map_array(map, lines))
		return (0);
	map->height = lines;
	fd = open_map_file(file);
	ok = (fd >= 0 && fill_map(fd, map, lines));
	close(fd);
	return (ok);
}
