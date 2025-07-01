/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giusnob <giusnob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:52:26 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/01 15:37:21 by giusnob          ###   ########.fr       */
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
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
			draw_tile(g, g->map.map[y][x], x++, y);
		y++;
	}
}

