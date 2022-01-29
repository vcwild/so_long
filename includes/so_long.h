/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:32:10 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/29 19:15:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "colors.h"
# include <unistd.h>
# include <libft.h>
# include <fcntl.h>

# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <sys/stat.h>

# define SO_LONG_H
# define SO_LONG_FAIL 0
# define SO_LONG_SUCCESS 1

# define COLOR_WHITE 0xFFFFFF

# define WINDOW_HEIGHT 360
# define WINDOW_WIDTH 640
# define MLX_ERROR 1
# define MLX_SUCCESS 0
# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define PLAYER_POSITION 'P'
# define SPRITE_SIZE 32

# define N_ERROR_MESSAGES 100

# define GNL_FOUND_LINEBREAK 1
# define GNL_FOUND_EOF 0
# define GNL_ERROR -1
# define MAX_FILE_DESCRIPTOR RLIMIT_NOFILE
# define BUFFER_SIZE 32

typedef enum e_position {
	P_UP,
	P_DOWN,
	P_LEFT,
	P_RIGHT,
}	t_position;

typedef enum e_error {
	ERR_READ_MAP,
	ERR_INVALID_ARGUMENTS,
	ERR_INVALID_MAP,
	ERR_MULTIPLAYER,
	ERR_NO_COLLECT,
	ERR_NO_EXIT,
	ERR_NO_PLAYER,
	ERR_PLAYER_NOT_FOUND,
	ERR_MEMORY_ALLOCATION,
	ERR_INVALID_ENTITIES,
}	t_error;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_sprite
{
	char	*path;
	void	*image;
	int		width;
	int		height;
	int		qty;
}	t_sprite;

typedef struct s_objects
{
	t_sprite	wall;
	t_sprite	exit;
	t_sprite	floor;
	t_sprite	collectible;
}	t_objects;

typedef struct s_player
{
	t_sprite	sprite[4];
	void		*image;
	t_point		pos;
	int			qty;
	int			steps;
	t_position	state;
	char		prev_tile;
	int			width;
	int			height;
}	t_player;

typedef struct s_enemy
{
	t_point		pos;
	t_sprite	sprite;
}	t_enemy;

typedef struct s_program
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			nrows;
	int			ncolumns;
	char		**grid;
	t_objects	objects;
	t_player	player;
}	t_program;

typedef int	t_dispatcher(t_program *program, int row, int col);

int				get_next_line(int fd, char **line);
int				get_player_position(t_program *p);
int				verify_game_entities_quantity_for(t_program *program);
int				load_empty_space(t_program *program, int col, int row);
int				load_wall(t_program *program, int col, int row);
int				load_exit(t_program *program, int col, int row);
int				load_collectible(t_program *program, int col, int row);
int				load_player_position(t_program *program, int col, int row);
void			free_grid(t_program *program);
int				print_so_long_error(t_error errornum);
int				valid_input_args(int argc, char *map_input_arg);
int				verify_valid_game_for(char *argv_1, t_program *program);
int				import_sprite_paths(t_program *program);
int				draw_image_in_map(t_program *program,
					void *image, int col, int row);
int				draw_steps(t_program *program);
int				draw_map(t_program *program);
int				exit_game_gracefully(t_program *program);
int				so_long_launch(t_program *program);
t_dispatcher	**get_dispatcher(void);
int				keypress_hook(int keycode, t_program *program);

int				player_in_wall(t_player *player, char **grid);
int				player_in_exit(t_player *player, char **grid);
int				player_in_collectible(t_player *player, char **grid);

void			handle_movement_not_in_wall(t_program *p);

int				destroy_sprites(t_program *program);

void			move_player_right(t_program *program);
void			move_player_left(t_program *program);
void			move_player_up(t_program *program);
void			move_player_down(t_program *program);

void			ft_strcopy(char *dst, char *src, size_t len);

int				load_sprites(t_program *program);

#endif
