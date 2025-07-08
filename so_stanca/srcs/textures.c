/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:30:44 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/08 19:02:37 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_xpm(void *mlx, const char *path)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(mlx, (char *)path, &w, &h);
	if (!img)
	{
		ft_printf("Error: loading %s\n", path);
		return NULL;
	}
	return (img);
}

int	load_textures(t_game *g)
{
	g->img_wall        = load_xpm(g->mlx_ptr, SPRITE_WALL);
	if (!g->img_wall)
		return (0);
	g->img_floor       = load_xpm(g->mlx_ptr, SPRITE_FLOOR);
	if (!g->img_floor)
		return (0);
	g->img_collectible = load_xpm(g->mlx_ptr, SPRITE_COLLECT);
	if (!g->img_collectible)
		return (0);
	g->img_exit        = load_xpm(g->mlx_ptr, SPRITE_EXIT);
	if (!g->img_exit)
		return (0);
	g->img_player_u    = load_xpm(g->mlx_ptr, SPRITE_PLAYER_U);
	if (!g->img_player_u)
		return (0);
	g->img_player_d    = load_xpm(g->mlx_ptr, SPRITE_PLAYER_D);
	if (!g->img_player_d)
		return (0);
	g->img_player_l    = load_xpm(g->mlx_ptr, SPRITE_PLAYER_L);
	if (!g->img_player_l)
		return (0);
	g->img_player_r    = load_xpm(g->mlx_ptr, SPRITE_PLAYER_R);
	if (!g->img_player_r)
		return (0);
	return (1);
}

void	destroy_textures(t_game *g)
{
	if (g->mlx_ptr && g->img_wall)
		mlx_destroy_image(g->mlx_ptr, g->img_wall);
	if (g->mlx_ptr && g->img_floor)
		mlx_destroy_image(g->mlx_ptr, g->img_floor);
	if (g->mlx_ptr && g->img_collectible)
		mlx_destroy_image(g->mlx_ptr, g->img_collectible);
	if (g->mlx_ptr && g->img_exit)
		mlx_destroy_image(g->mlx_ptr, g->img_exit);
	if (g->mlx_ptr && g->img_player_u)
		mlx_destroy_image(g->mlx_ptr, g->img_player_u);
	if (g->mlx_ptr && g->img_player_d)
		mlx_destroy_image(g->mlx_ptr, g->img_player_d);
	if (g->mlx_ptr && g->img_player_l)
		mlx_destroy_image(g->mlx_ptr, g->img_player_l);
	if (g->mlx_ptr && g->img_player_r)
		mlx_destroy_image(g->mlx_ptr, g->img_player_r);
}
