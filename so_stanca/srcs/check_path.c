/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giusnob <giusnob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:45:55 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/01 16:09:45 by giusnob          ###   ########.fr       */
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

//Trova la posizione iniziale del player ('P')
static void	flood(char **m, int x, int y)
{
	if (!m[y] || !m[y][x] ||
	    m[y][x] == '1' || m[y][x] == 'F' ||
	    m[y][x] == 'E' || m[y][x] == '\n')
		return ;
	m[y][x] = 'F';
	flood(m, x + 1, y);
	flood(m, x - 1, y);
	flood(m, x, y + 1);
	flood(m, x, y - 1);
}
//Ritorna 1 se c'è ancora 'C' o 'E' non raggiunti
static int	has_unreach(char **m, int h, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (m[y][x] == 'C' || m[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
//verifica che tutte le 'C' (e l'Uscita) siano raggiungibili
int	check_path(char **map, int h, int w)
{
	char	**tmp;
	int		px;
	int		py;

	tmp = copy_map(map, h);
	if (!tmp)
		return (ft_printf("Error: malloc failed\n"), 0);
	if (!find_player(tmp, h, &px, &py))
		return (free_copy(tmp, h), 0);
	flood(tmp, px, py);
	if (has_unreach(tmp, h, w))
		return (free_copy(tmp, h),
			ft_printf("Error: unreachable element\n"), 0);
	free_copy(tmp, h);
	return (1);
}
