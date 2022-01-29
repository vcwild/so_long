/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:10:29 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/23 15:31:04 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_program *program)
{
	int	i;

	i = 0;
	while (program->grid[i] != NULL)
	{
		free(program->grid[i]);
		i++;
	}
	free(program->grid);
}

void	free_all_paths_from(t_player *player, t_objects *objects)
{
	free(player->sprite[P_UP].path);
	free(player->sprite[P_DOWN].path);
	free(player->sprite[P_LEFT].path);
	free(player->sprite[P_RIGHT].path);
	free(objects->collectible.path);
	free(objects->exit.path);
	free(objects->floor.path);
	free(objects->wall.path);
}

int	exit_game_gracefully(t_program *program)
{
	free_grid(program);
	mlx_destroy_window(program->mlx_ptr, program->win_ptr);
	mlx_destroy_display(program->mlx_ptr);
	free(program->mlx_ptr);
	exit(MLX_SUCCESS);
	return (MLX_SUCCESS);
}

int	destroy_sprites(t_program *program)
{
	mlx_destroy_image(program->mlx_ptr,
		program->objects.collectible.image);
	mlx_destroy_image(program->mlx_ptr,
		program->objects.exit.image);
	mlx_destroy_image(program->mlx_ptr,
		program->objects.wall.image);
	mlx_destroy_image(program->mlx_ptr,
		program->objects.floor.image);
	mlx_destroy_image(program->mlx_ptr,
		program->player.image);
	return (MLX_SUCCESS);
}

// int	free_image_memory(t_program *program)
// {
// 	t_objects	*objects;
// 	t_player	*player;

// 	free(program->player->sprite[P_UP].image);
// 	free(player->sprite[P_DOWN].image);
// 	free(player->sprite[P_LEFT].image);
// 	free(player->sprite[P_RIGHT].image);
// 	free(objects->collectible.image);
// 	free(objects->exit.image);
// 	free(objects->floor.image);
// 	free(objects->wall.image);
// 	return (MLX_SUCCESS);
// }
