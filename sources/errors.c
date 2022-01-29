/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:57:10 by vwildner          #+#    #+#             */
/*   Updated: 2022/01/20 18:57:25 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_so_long_error(t_error errornum)
{
	if (errornum == ERR_READ_MAP)
		printf("Error: %s", "Could not read the map");
	else if (errornum == ERR_INVALID_ARGUMENTS)
		printf("Error: %s", "Invalid arguments");
	else if (errornum == ERR_INVALID_MAP)
		printf("Error: %s", "Invalid map");
	else if (errornum == ERR_MULTIPLAYER)
		printf("Error: %s", "The game must have only 1 player");
	else if (errornum == ERR_NO_COLLECT)
		printf("Error: %s", "The game must have at least 1 collectible");
	else if (errornum == ERR_NO_EXIT)
		printf("Error: %s", "The game must have an exit");
	else if (errornum == ERR_NO_PLAYER)
		printf("Error: %s", "The game must have at least 1 player");
	else if (errornum == ERR_PLAYER_NOT_FOUND)
		printf("Error: %s", "Could not find the player");
	else if (errornum == ERR_MEMORY_ALLOCATION)
		printf("Error: %s", "Could not allocate memory for program");
	else if (errornum == ERR_INVALID_ENTITIES)
		printf("Error: %s", "Invalid entities found");
	else
		printf("Error: Unknown error");
	return (SO_LONG_FAIL);
}
