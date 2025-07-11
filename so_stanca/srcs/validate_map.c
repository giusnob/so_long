/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:46:49 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/08 16:56:48 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *g, const char *file)
{
	g->map.height = map_height(file) - 1;
	if (!load_map(file, &g->map))
	{
		if (g->map.map != NULL)
			free_map(&g->map);
		return (ft_printf("Error: failed to load map\n"), 0);
	}
	map_width(&g->map);
	if (!check_map(g->map.map, g->map.height))
	{
		free_map(&g->map);
		return (0);
	}
	if (!check_path(g->map, &g->player_pos, &g->collect))
	{
		free_map(&g->map);
		return (0);
	}
	return (1);
}
