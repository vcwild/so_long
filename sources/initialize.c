/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:59:18 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/23 15:08:02 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	import_sprite_paths(t_program *program)
{
	program->player.sprite[P_UP].path = "./img/player_up.xpm";
	program->player.sprite[P_DOWN].path = "./img/player_down.xpm";
	program->player.sprite[P_LEFT].path = "./img/player_left.xpm";
	program->player.sprite[P_RIGHT].path = "./img/player_right.xpm";
	program->objects.collectible.path = "./img/collectable.xpm";
	program->objects.exit.path = "./img/exit.xpm";
	program->objects.floor.path = "./img/floor.xpm";
	program->objects.wall.path = "./img/wall.xpm";
	return (MLX_SUCCESS);
}

// int	load_sprites(t_program *program)
// {
// 	t_objects	*objects;

// 	load_player_images(program);
// 	objects = program->objects;
// 	objects.collectible.image = create_sprite(program->mlx_ptr,
// 			objects.collectible.path);
// 	objects.exit.image = create_sprite(program->mlx_ptr,
// 			objects.exit.path);
// 	objects.floor.image = create_sprite(program->mlx_ptr, objects.floor.path);
// 	objects.wall.image = create_sprite(program->mlx_ptr, objects.wall.path);
// 	return (MLX_SUCCESS);
// }

int	load_sprites(t_program *program)
{
	program->player.image = mlx_xpm_file_to_image(program->mlx_ptr,
			program->player.sprite[program->player.state].path,
			&program->player.width,
			&program->player.height);
	program->objects.collectible.image = mlx_xpm_file_to_image(program->mlx_ptr,
			program->objects.collectible.path,
			&program->objects.collectible.width,
			&program->objects.collectible.height);
	program->objects.exit.image = mlx_xpm_file_to_image(program->mlx_ptr,
			program->objects.exit.path,
			&program->objects.exit.width,
			&program->objects.exit.height);
	program->objects.floor.image = mlx_xpm_file_to_image(program->mlx_ptr,
			program->objects.floor.path,
			&program->objects.floor.width,
			&program->objects.floor.height);
	program->objects.wall.image = mlx_xpm_file_to_image(program->mlx_ptr,
			program->objects.wall.path,
			&program->objects.wall.width,
			&program->objects.wall.height);
	return (MLX_SUCCESS);
}

t_dispatcher	**get_dispatcher(void)
{
	static t_dispatcher	*load[PLAYER_POSITION + 1];

	load[EMPTY_SPACE] = load_empty_space;
	load[WALL] = load_wall;
	load[MAP_EXIT] = load_exit;
	load[COLLECTIBLE] = load_collectible;
	load[PLAYER_POSITION] = load_player_position;
	return (load);
}
