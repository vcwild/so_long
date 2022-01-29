/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:06:25 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/21 01:50:32 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_empty_space(t_program *program, int row, int col)
{
	draw_image_in_map(
		program,
		program->objects.floor.image,
		col,
		row);
	return (MLX_SUCCESS);
}

int	load_wall(t_program *program, int row, int col)
{
	draw_image_in_map(
		program,
		program->objects.wall.image,
		col,
		row);
	return (MLX_SUCCESS);
}

int	load_exit(t_program *program, int row, int col)
{
	draw_image_in_map(
		program,
		program->objects.exit.image,
		col,
		row);
	return (MLX_SUCCESS);
}

int	load_collectible(t_program *program, int row, int col)
{
	draw_image_in_map(
		program,
		program->objects.collectible.image,
		col,
		row);
	return (MLX_SUCCESS);
}

int	load_player_position(t_program *program, int row, int col)
{
	draw_image_in_map(
		program,
		program->player.image,
		col,
		row);
	return (MLX_SUCCESS);
}
