/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:08:25 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/23 15:07:57 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player_position(t_program *p)
{
	p->player.pos.y = 0;
	while (p->player.pos.y < p->nrows)
	{
		p->player.pos.x = 0;
		while (p->player.pos.x < p->ncolumns)
		{
			if (p->grid[p->player.pos.y][p->player.pos.x] == PLAYER_POSITION)
				return (SO_LONG_SUCCESS);
			p->player.pos.x++;
		}
		p->player.pos.y++;
	}
	return (print_so_long_error(ERR_PLAYER_NOT_FOUND));
}
