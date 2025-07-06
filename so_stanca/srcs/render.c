/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:52:26 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/06 22:04:58 by ginobile         ###   ########.fr       */
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
			draw_tile(g, g->map.map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	move_player(t_game *g, int dx, int dy)
{
	int		new_x;
	int		new_y;
	int		x;
	int		y;
	char 	next;

	x = g->player_pos.x;
	y = g->player_pos.y;
	new_x = x + dx;
	new_y = y + dy;
	next = g->map.map[new_y][new_x];
	
	if (next == 'C')
	{
		g->collect--;
		g->map.map[y][x] = '0';
		g->map.map[new_y][new_x] = 'P';
		g->player_pos.x = new_x;
		g->player_pos.y = new_y;
	}
	else if (next == '0')
	{
		g->map.map[y][x] = '0';
		g->map.map[new_y][new_x] = 'P';
		g->player_pos.x = new_x;
		g->player_pos.y = new_y;
	}
	else if (next == 'E' && g->collect == 0)
	{
		ft_printf("You win! Moves: %d\n", ++g->moves);
		free_game(g);
		exit(0);
	}
	printf("valore y %d e valore x:%d\n", x, y);
	printf("collect now in move player: %d\n", g->collect);
	render_map(g);
}

