/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:38:22 by giusnob           #+#    #+#             */
/*   Updated: 2025/07/06 22:00:23 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	process_move(int dx, int dy, t_dir dir, t_game *g)
{
	printf("collect now in process: %d\n", g->collect);
	g->player_dir = dir;
	move_player(g, dx, dy);
	ft_printf("Moves: %d\n", ++g->moves);
}

int	handle_keypress(int key, t_game *g)
{
	printf("collect now in handle: %d\n", g->collect);
	if (key == KEY_ESC)
		ft_printf("Quit\n"), free_game(g), exit(0);
	else if (key == KEY_W)
		process_move(0, -1, DIR_UP, g);
	else if (key == KEY_S)
		process_move(0, 1, DIR_DOWN, g);
	else if (key == KEY_A)
		process_move(-1, 0, DIR_LEFT, g);
	else if (key == KEY_D)
		process_move(1, 0, DIR_RIGHT, g);
	return (0);
}

int	handle_key_release(int key, t_game *g)
{
	(void)key;
	(void)&g;
	return (0);
}

int	handle_destroy(t_game *g)
{
	free_game(g);
	exit(0);
	return (0);
}
