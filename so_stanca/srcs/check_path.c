/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:45:55 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/08 17:18:02 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Trova la posizione iniziale del player ('P')
static int	find_player(char **map, int h, int *px, int *py)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	count_collectibles(char **map, int height)
{
	int	cnt;
	int	y;
	int	x;

	cnt = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'C')
				cnt++;
		y++;
	}
	return (cnt);
}


static void	flood(char **m, int x, int y)
{
	if (!m[y] || !m[y][x] || m[y][x] == '1' ||
			m[y][x] == 'E' || m[y][x] == 'F' || m[y][x] == '\n')
	{
		if (m[y][x] == 'E')
			m[y][x] = 'F';
		return ;
	}
	m[y][x] = 'F';
	flood(m, x + 1, y);
	flood(m, x - 1, y);
	flood(m, x, y + 1);
	flood(m, x, y - 1);
}
//Ritorna 1 se c'è ancora 'C'
static int	has_unreached(char **m, int h, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (m[y][x] == 'C' && m[y][x])
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

//verifica che tutte le 'C' (e l'Uscita) siano raggiungibili

int	check_path(t_map map, t_point *player_pos, int *collect)
{
	char	**tmp;
	int		px;
	int		py;

	tmp = copy_map(map.map, map.height);
	if (!tmp)
		return (ft_printf("Error: malloc failed\n"), 0);
	if (!find_player(tmp, map.height, &px, &py))
		return (free_copy(tmp, map.height), 0);
	*collect = count_collectibles(map.map, map.height);
	flood(tmp, px, py);
	if (has_unreached(tmp, map.height, map.width))
		return (free_copy(tmp, map.height),
			ft_printf("Error: unreachable element\n"), 0);
	free_copy(tmp, map.height);
	player_pos->x = px;
	player_pos->y = py;
	return (1);
}
