/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:58:36 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/23 18:57:32 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_hook(int keycode, t_program *program)
{
	if (keycode == XK_w || keycode == XK_W)
		move_player_up(program);
	if (keycode == XK_s || keycode == XK_S)
		move_player_down(program);
	if (keycode == XK_a || keycode == XK_A)
		move_player_left(program);
	if (keycode == XK_d || keycode == XK_D)
		move_player_right(program);
	if (keycode == XK_Escape
		|| program->objects.exit.qty == 0)
	{
		if (program->objects.exit.qty == 0)
			printf("\033[32mYOU WIN!\n\033[0m");
		exit_game_gracefully(program);
	}
	draw_map(program);
	return (MLX_SUCCESS);
}
