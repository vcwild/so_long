/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:10:10 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/23 15:13:48 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_in_wall(t_player *player, char **grid)
{
	if (grid[player->pos.y][player->pos.x] == WALL)
		return (SO_LONG_SUCCESS);
	return (SO_LONG_FAIL);
}

int	player_in_exit(t_player *player, char **grid)
{
	if (grid[player->pos.y][player->pos.x] == MAP_EXIT)
		return (SO_LONG_SUCCESS);
	return (SO_LONG_FAIL);
}

int	player_in_collectible(t_player *player, char **grid)
{
	if (grid[player->pos.y][player->pos.x] == COLLECTIBLE)
		return (SO_LONG_SUCCESS);
	return (SO_LONG_FAIL);
}

void	handle_movement_not_in_wall(t_program *p)
{
	p->player.steps++;
	if (player_in_exit(&p->player, p->grid))
	{
		p->grid[p->player.pos.y][p->player.pos.x] = PLAYER_POSITION;
		p->player.prev_tile = MAP_EXIT;
		if (p->objects.collectible.qty == 0)
			p->objects.exit.qty = 0;
		return ;
	}
	if (player_in_collectible(&p->player, p->grid))
		p->objects.collectible.qty -= 1;
	p->grid[p->player.pos.y][p->player.pos.x] = PLAYER_POSITION;
	p->player.prev_tile = EMPTY_SPACE;
}
