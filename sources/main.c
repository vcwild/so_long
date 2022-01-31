/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:09:12 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/31 14:23:41 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	allocate_primary_spaces(t_program *program)
{
	program->player.state = P_DOWN;
	program->player.prev_tile = EMPTY_SPACE;
	program->player.steps = 0;
	return (MLX_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (!valid_input_args(argc, argv[1]))
		return (SO_LONG_FAIL);
	allocate_primary_spaces(&program);
	if (!verify_valid_game_for(argv[1], &program))
		return (SO_LONG_FAIL);
	if (!get_player_position(&program))
		return (SO_LONG_FAIL);
	if (!verify_game_entities_quantity_for(&program))
		return (SO_LONG_FAIL);
	import_sprite_paths(&program);
	if (!so_long_launch(&program))
		return (SO_LONG_FAIL);
	return (MLX_SUCCESS);
}
