/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:46:49 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/02 22:44:48 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *g, const char *file)
{
	g->map.height = map_height(file) - 1;
	if (!load_map(file, &g->map))
		return (ft_printf("Error: failed to load map\n"), 0);
	map_width(&g->map);
	if (!check_map(g->map.map, g->map.height))
		return (0);
	if (!check_path(g->map.map, g->map.height, g->map.width))
		return (0);
	return (1);
}
