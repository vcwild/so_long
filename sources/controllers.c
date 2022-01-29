/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:53:16 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/21 01:55:59 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_right(t_program *program)
{
	int	pos_x;

	pos_x = program->player.pos.x;
	program->player.pos.x += 1;
	program->player.state = P_RIGHT;
	if (!player_in_wall(&program->player, program->grid))
	{
		program->grid[program->player.pos.y][pos_x] = program->player.prev_tile;
		return (handle_movement_not_in_wall(program));
	}
	program->player.pos.x = pos_x;
	return ;
}

void	move_player_left(t_program *program)
{
	int	pos_x;

	pos_x = program->player.pos.x;
	program->player.pos.x -= 1;
	program->player.state = P_LEFT;
	if (!player_in_wall(&program->player, program->grid))
	{
		program->grid[program->player.pos.y][pos_x] = program->player.prev_tile;
		return (handle_movement_not_in_wall(program));
	}
	program->player.pos.x = pos_x;
	return ;
}

void	move_player_up(t_program *program)
{
	int	pos_y;

	pos_y = program->player.pos.y;
	program->player.pos.y -= 1;
	program->player.state = P_UP;
	if (!player_in_wall(&program->player, program->grid))
	{
		program->grid[pos_y][program->player.pos.x] = program->player.prev_tile;
		return (handle_movement_not_in_wall(program));
	}
	program->player.pos.y = pos_y;
	return ;
}

void	move_player_down(t_program *program)
{
	int	pos_y;

	pos_y = program->player.pos.y;
	program->player.pos.y += 1;
	program->player.state = P_DOWN;
	if (!player_in_wall(&program->player, program->grid))
	{
		program->grid[pos_y][program->player.pos.x] = program->player.prev_tile;
		return (handle_movement_not_in_wall(program));
	}
	program->player.pos.y = pos_y;
	return ;
}
