/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:33:14 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/08 18:48:39 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	parse_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error: usage ./so_long <map.ber>\n");
		return (0);
	}
	if (!has_ber_extension(argv[1]))
	{
		ft_printf("Error: file must end with .ber\n");
		return (0);
	}
	return (1);
}

static int	run_game(char *mapfile)
{
	t_game	g;

	ft_bzero(&g, sizeof(g));
	if (!validate_map(&g, mapfile))
		return (0);
	if (!init_game(&g))
		return (free_game(&g), 0);
	render_map(&g);
	mlx_hook(g.win_ptr, 2, 1L << 0, handle_keypress, &g);
	/* mlx_hook(g.win_ptr, 3, 1L << 1, handle_key_release, &g); */
	mlx_hook(g.win_ptr, 17, 0, handle_destroy, &g);
	mlx_loop(g.mlx_ptr);
	free_game(&g);
	return (1);
}

int	main(int argc, char **argv)
{
	if (!parse_args(argc, argv))
		return (1);
	if (!run_game(argv[1]))
		return (1);
	return (0);
}
