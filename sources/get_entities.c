/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:57:45 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/31 14:34:54 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_game_entities(t_program *program)
{
	int	row;
	int	col;

	program->objects.collectible.qty = 0;
	program->player.qty = 0;
	program->objects.exit.qty = 0;
	row = 1;
	while (row <= program->nrows - 2)
	{
		col = 0;
		while (col <= program->ncolumns - 2)
		{
			if (program->grid[row][col] == COLLECTIBLE)
				program->objects.collectible.qty += 1;
			if (program->grid[row][col] == PLAYER_POSITION)
				program->player.qty += 1;
			if (program->grid[row][col] == MAP_EXIT)
				program->objects.exit.qty += 1;
			col++;
		}
		row++;
	}
	return (SO_LONG_SUCCESS);
}

static int	handle_verify_entities(t_program *program)
{
	count_game_entities(program);
	if (program->player.qty < 1)
		return (print_so_long_error(ERR_NO_PLAYER));
	if (program->player.qty > 1)
		return (print_so_long_error(ERR_MULTIPLAYER));
	if (program->objects.collectible.qty < 1)
		return (print_so_long_error(ERR_NO_COLLECT));
	if (program->objects.exit.qty < 1)
		return (print_so_long_error(ERR_NO_EXIT));
	return (SO_LONG_SUCCESS);
}

int	verify_game_entities_quantity_for(t_program *program)
{
	if (handle_verify_entities(program))
		return (SO_LONG_SUCCESS);
	free_grid(program);
	return (SO_LONG_FAIL);
}
