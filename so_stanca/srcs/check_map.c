/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giusnob <giusnob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:28:48 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/01 16:03:33 by giusnob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(char **map, int height)
{
	int	width;
	int	row;

	if (!map || height <= 0)
		return (0);
	width = ft_strlen(map[0]);
	row = 1;
	while (row < height)
	{
		if ((int)ft_strlen(map[row++]) != width)
			return (0);
	}
	return (1);
}

static int	validate_walls(char **map, int h, int w)
{
	int	row;
	int	col;

	col = 0;
	while (col < w)
	{
		if (map[0][col] != '1' ||
		    map[h - 1][col] != '1')
			return (ft_printf("Error: border not closed\n"), 0);
		col++;
	}
	row = 1;
	while (row < h - 1)
	{
		if (map[row][0] != '1' ||
		    map[row][w - 1] != '1')
			return (ft_printf("Error: border not closed\n"), 0);
		row++;
	}
	return (1);
}

static int	count_elem(char **map, int h, char target)
{
	int	cnt;
	int	y;
	int	x;

	cnt = 0;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == target)
				cnt++;
			x++;
		}
		y++;
	}
	return (cnt);
}

static int	validate_elements(char **map, int h)
{
	int	p;
	int	c;
	int	e;

	p = count_elem(map, h, 'P');
	c = count_elem(map, h, 'C');
	e = count_elem(map, h, 'E');
	if (p != 1)
		return (ft_printf("Error: need exactly 1 player\n"), 0);
	if (c < 1)
		return (ft_printf("Error: at least 1 collectible\n"), 0);
	if (e < 1)
		return (ft_printf("Error: at least 1 exit\n"), 0);
	return (1);
}

int	check_map(char **map, int h)
{
	int	w;

	if (!is_rectangular(map, h))
		return (ft_printf("Error: map not rectangular\n"), 0);
	w = ft_strlen(map[0]);
	if (!validate_walls(map, h, w))
		return (0);
	if (!validate_elements(map, h))
		return (0);
	return (1);
}
