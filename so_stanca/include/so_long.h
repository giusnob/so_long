/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giusnob <giusnob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:58:04 by giusnob           #+#    #+#             */
/*   Updated: 2025/06/29 10:00:00 by ChatGPT          ###   ########.fr       */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ─── Libraries ─────────────────────────────────────────────────────────────
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <string.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

// ─── Window / Tile sizes ────────────────────────────────────────────────────
# define TILE_SIZE      64
# define MAX_MAP_HEIGHT 1024

// ─── Key codes ──────────────────────────────────────────────────────────────
# define KEY_ESC        65307
# define KEY_W          119
# define KEY_A          97
# define KEY_S          115
# define KEY_D          100

// ─── Asset paths ────────────────────────────────────────────────────────────
# define SPRITE_WALL    "imgs/wall.xpm"
# define SPRITE_FLOOR   "imgs/floor.xpm"
# define SPRITE_COLLECT "imgs/collectible.xpm"
# define SPRITE_EXIT    "imgs/exit.xpm"
# define SPRITE_PLAYER_U  "imgs/player_up.xpm"
# define SPRITE_PLAYER_D  "imgs/player_down.xpm"
# define SPRITE_PLAYER_L  "imgs/player_left.xpm"
# define SPRITE_PLAYER_R  "imgs/player_right.xpm"


// ─── Map structure ─────────────────────────────────────────────────────────
typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}				t_map;

typedef enum e_dir
{
	DIR_DOWN,
	DIR_UP,
	DIR_LEFT,
	DIR_RIGHT
}				t_dir;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

// ─── Main game structure ──────────────────────────────────────────────────
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	int		moves;

	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player_u;
	void	*img_player_d;
	void	*img_player_l;
	void	*img_player_r;

	int		collect;
	t_dir	player_dir;
	t_point	player_pos;
}				t_game;

// map loader & validator 
int		load_map(const char *path, t_map *map);
void	free_map(t_map *map);
void	map_width(t_map *map);

int		check_map(char **map, int height);
int		check_path(t_map map, t_point *player_pos, int *collect);
int		validate_map(t_game *g, const char *file);

// rendering 
void	render_map(t_game *g);

// input hooks
int		handle_keypress(int key, t_game *g);
int		handle_key_release(int key, t_game *g);
int		handle_destroy(t_game *g);

// textures
void	load_textures(t_game *g);
void	destroy_textures(t_game *g);

// utilities 
int		has_ber_extension(const char *path);
void	move_player(t_game *g, int dx, int dy);
int		count_collectibles(char **map, int height);
int		map_height(const char *s);
void	free_game(t_game *g);
int		init_game(t_game *g);

// helper per check_path
char	**copy_map(char **map, int height);
void	free_copy(char **dup, int height);

#endif