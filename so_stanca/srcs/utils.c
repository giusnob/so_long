/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:53:35 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/07 18:38:11 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_ber_extension(const char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len <= 4)
		return (0);
	return (ft_strncmp(path + len - 4, ".ber", 4) == 0);
}

void	map_width(t_map *map)
{
	int	len;

	if (!map || !map->map || !map->map[0])
		return ;
	len = ft_strlen(map->map[0]);
	map->width = len;
}

int	map_height(const char *s)
{
		int		fd;
		int		lines;
		int		nb;
		char	c;

		lines = 0;
		fd = open(s, O_RDONLY);
		if (!fd || fd < 0 || fd > 1024)
				return (-1);
		while (1)
		{
				nb = read(fd, &c, 1);
				if (c == '\n')
						lines++;
				if (nb == 0)
						break ;
				if (nb < 0)
						return (-1);
		}
		close (fd);
		return (lines);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->map[i++]);
	free(map->map);
}
/*
** Duplica la mappa (height righe + termine NULL)
*/
char	**copy_map(char **map, int height)
{
	char	**dup;
	int		i;

	dup = malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < height)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i++])
			break ;
	}
	if (i != height)
	{
		while (i-- > 0)
			free(dup[i]);
		free(dup);
		return (NULL);
	}
	dup[height] = NULL;
	return (dup);
}

// Libera la mappa duplicata
void	free_copy(char **dup, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(dup[i++]);
	free(dup);
}
void	free_game(t_game *g)
{
	destroy_textures(g);
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	mlx_destroy_display(g->mlx_ptr);
	free(g->mlx_ptr);
	free_map(&g->map);
}
