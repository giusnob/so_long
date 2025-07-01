/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giusnob <giusnob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:30:44 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/01 15:49:31 by giusnob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_xpm(void *mlx, const char *path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, (char *)path, w, h);
	if (!img)
		exit(ft_printf("Error: loading %s\n", path));
	return (img);
}

void	load_textures(t_game *g)
{
	int	w;
	int	h;

	g->img_wall        = load_xpm(g->mlx_ptr, SPRITE_WALL, &w, &h);
	g->img_floor       = load_xpm(g->mlx_ptr, SPRITE_FLOOR, &w, &h);
	g->img_collectible = load_xpm(g->mlx_ptr, SPRITE_COLLECT, &w, &h);
	g->img_exit        = load_xpm(g->mlx_ptr, SPRITE_EXIT, &w, &h);
	g->img_player_u    = load_xpm(g->mlx_ptr, SPRITE_PLAYER_U, &w, &h);
	g->img_player_d    = load_xpm(g->mlx_ptr, SPRITE_PLAYER_D, &w, &h);
	g->img_player_l    = load_xpm(g->mlx_ptr, SPRITE_PLAYER_L, &w, &h);
	g->img_player_r    = load_xpm(g->mlx_ptr, SPRITE_PLAYER_R, &w, &h);
}

void	destroy_textures(t_game *g)
{
	mlx_destroy_image(g->mlx_ptr, g->img_wall);
	mlx_destroy_image(g->mlx_ptr, g->img_floor);
	mlx_destroy_image(g->mlx_ptr, g->img_collectible);
	mlx_destroy_image(g->mlx_ptr, g->img_exit);
	mlx_destroy_image(g->mlx_ptr, g->img_player_u);
	mlx_destroy_image(g->mlx_ptr, g->img_player_d);
	mlx_destroy_image(g->mlx_ptr, g->img_player_l);
	mlx_destroy_image(g->mlx_ptr, g->img_player_r);
}
