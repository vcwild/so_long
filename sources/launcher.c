/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:02:31 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/21 00:53:46 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long_launch(t_program *program)
{
	program->mlx_ptr = mlx_init();
	program->win_ptr = mlx_new_window(
			program->mlx_ptr,
			program->ncolumns * SPRITE_SIZE,
			program->nrows * SPRITE_SIZE,
			"So Long, and Thanks for All the Fish");
	mlx_key_hook(program->win_ptr, keypress_hook, program);
	mlx_hook(
		program->win_ptr,
		ClientMessage,
		ButtonPressMask,
		exit_game_gracefully,
		program);
	mlx_expose_hook(program->win_ptr, &draw_map, program);
	mlx_loop(program->mlx_ptr);
	return (0);
}
