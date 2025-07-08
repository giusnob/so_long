/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:28:12 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/07 17:52:12 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	Initialize MLX, window, textures; set hooks.
int	init_game(t_game *g)
{
	g->mlx_ptr = mlx_init();
	if (!g->mlx_ptr)
		return (0);
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->map.width * TILE_SIZE,
		g->map.height * TILE_SIZE, "so_long");
	if (!g->win_ptr)
		return (0);
	load_textures(g);
	g->moves = 0;
	g->player_dir = DIR_DOWN;
	return (1);
}
