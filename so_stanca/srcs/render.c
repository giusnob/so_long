/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:52:26 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/02 20:11:13 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *g, char c, int x, int y)
{
	void	*img;

	if (c == '1')
		img = g->img_wall;
	else if (c == '0')
		img = g->img_floor;
	else if (c == 'C')
		img = g->img_collectible;
	else if (c == 'E')
		img = g->img_exit;
	else if (c == 'P')
	{
		if (g->player_dir == DIR_UP)
			img = g->img_player_u;
		else if (g->player_dir == DIR_DOWN)
			img = g->img_player_d;
		else if (g->player_dir == DIR_LEFT)
			img = g->img_player_l;
		else
			img = g->img_player_r;
	}
	else
		return ;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			draw_tile(g, g->map.map[y][x], x + 1, y);
			x++;
		}
		y++;
	}
}

void	move_player(t_game *g, int dx, int dy)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (g->map.map[y][x] != 'P')
			x++;
		if (g->map.map[y][x] == 'P')
			break ;
		y++;
	}
	if (x + dx < 0 || x + dx >= g->map.width || y + dy < 0 || y + dy >= g->map.height ||
	    g->map.map[y + dy][x + dx] == '1')
		return ;
	if (g->map.map[y + dy][x + dx] == 'E' &&
	    count_collectibles(g->map.map, g->map.height) > 0)
		return ;
	if (g->map.map[y + dy][x + dx] == 'E' &&
	    count_collectibles(g->map.map, g->map.height) == 0)
	{
		ft_printf("You win in %d moves!\n", g->moves);
		free_game(g);
		exit(0);
	}
	g->map.map[y][x] = '0';
	g->map.map[y + dy][x + dx] = 'P';
	render_map(g);
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

