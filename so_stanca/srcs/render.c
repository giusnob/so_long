/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:52:26 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/08 17:36:38 by ginobile         ###   ########.fr       */
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
	t_point	new;
	char 	next;

	new.x = g->player_pos.x + dx;
	new.y = g->player_pos.y + dy;
	next = g->map.map[new.y][new.x];
	
	if (next == 'C' || next == '0')
	{
		if (next == 'C')
			g->collect--;
		g->map.map[g->player_pos.y][g->player_pos.x] = '0';
		g->map.map[new.y][new.x] = 'P';
		g->player_pos.x = new.x;
		g->player_pos.y = new.y;
	}
	else if (next == 'E' && g->collect == 0)
	{
		ft_printf("You win! Moves: %d\n", ++g->moves);
		free_game(g);
		exit(0);
	}
	render_map(g);
}

